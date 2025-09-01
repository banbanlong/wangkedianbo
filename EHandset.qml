import QtQuick
import QtQuick.Controls
import QtQuick.Shapes

Rectangle {
    id: handset
    height: 200
    width: 200
    radius: 100
    color: "transparent"

    FontLoader{
        id: alipuhui
        source: "qrc:/font/alipuhuiMEDIUM.TTF"
    }

    signal play()
    signal pause()
    signal stop()
    signal next()
    signal previous()
    signal process(var p)


    //当前时间进度
    property alias curTime: current_time.text
    //最大时间进度
    property alias maxTime: max_time.text
    //进度条旋转的度数
    property alias degree: circle.degree
    //播放状态 0 初始状态 1 Opening 2 Buffering 3 Playing播放状态 4 暂停状态 5 停止 6 Ended 7 Error
    property int status: 0
    property bool pressed: mouseArea.pressed && (handset.status>0)

    MouseArea{
        id: mouseArea
        anchors.fill: parent
        hoverEnabled: true

        onPositionChanged: {
            if(pressed && (handset.status>0)){
                var pt0 = Qt.point(mouseX,mouseY)
                var pt1 = Qt.point(circle.width/2,circle.height/2)
                var dis = distance(pt0,pt1)
                if((dis>0.6*(circle.width/2))&&(dis<0.95*(circle.height/2))){//控制触发进度调节的范围
                    circle.degree = getDegree(pt0, pt1)//设置进度
                }
            }
        }
        onReleased: {
            if(handset.status>0){
                var pt0 = Qt.point(mouseX,mouseY)
                var pt1 = Qt.point(circle.width/2,circle.height/2)
                circle.degree = getDegree(pt0, pt1);
                console.log("onReleased:"+circle.degree)
                handset.process(circle.degree/360)
            }
        }
        function distance(pt0,pt1)
        {
            return Math.sqrt((pt0.x-pt1.x)*(pt0.x-pt1.x)+(pt0.y-pt1.y)*(pt0.y-pt1.y))
        }
        function getDegree(pt0, ptc)
        {
            if(pt0.x===ptc.x){
                if(pt0.y<ptc.y)return 0
                if(pt0.y>=ptc.y)return 180
            }
            if(pt0.y === ptc.y){
                if(pt0.x<=ptc.x)return 270
                if(pt0.x>ptc.x) return 90
            }
            var arg = 90 + Math.atan2(pt0.y-ptc.y,pt0.x-ptc.x)*180/Math.PI
            if(arg<0) arg += 360
            return arg
        }

        Rectangle{
            width: parent.width
            height: parent.height
            radius: handset.radius
            opacity: 1.0
            scale: 1.0
            color: "transparent"
            BorderImage {
                source: "qrc:/pictures/playermenu/background.png"
                anchors.fill: parent
            }
            Shape{
                id: circle
                anchors.fill: parent
                property real degree: 0
                layer{
                    enabled: true
                    smooth: true
                    samples: 8
                }
                ShapePath{
                    id: path
                    fillColor: "transparent"
                    strokeWidth: 4
                    capStyle: ShapePath.RoundCap

                    SequentialAnimation on strokeColor {
                        loops: Animation.Infinite

                        ColorAnimation {
                            from: "cyan"
                            to: "darkturquoise"
                            duration: 800
                        }
                        ColorAnimation {
                            from: "darkturquoise"
                            to: "greenyellow"
                            duration: 800
                        }
                        ColorAnimation {
                            from: "greenyellow"
                            to: "cyan"
                            duration: 800
                        }
                    }

                    startX: circle.width/2
                    startY: circle.height/2
                    PathAngleArc{
                        centerX: path.startX+2.5;centerY: path.startY
                        radiusX: handset.radius - path.strokeWidth/2 - 13
                        radiusY: handset.radius - path.strokeWidth/2 - 13
                        startAngle: -90
                        sweepAngle: circle.degree
                    }
                }
            }



            Rectangle{
                width: 61;height: 13
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottom: parent.verticalCenter
                anchors.bottomMargin: 53
                color: "transparent"
                Text{
                    id: current_time
                    anchors.horizontalCenter: parent.horizontalCenter
                    text: "00:00:00"
                    font.bold: true
                    font.family: alipuhui.name
                    font.pixelSize: 13
                    horizontalAlignment: Text.AlignHCenter
                    color: "white"
                }
            }
            Rectangle{
                width: 61;height: 13
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottom: parent.verticalCenter
                anchors.bottomMargin: 40
                color: "transparent"
                Text{
                    id: max_time
                    anchors.horizontalCenter: parent.horizontalCenter
                    text: "00:00:00"
                    font.bold: true
                    font.family: alipuhui.name
                    font.pixelSize: 13
                    horizontalAlignment: Text.AlignHCenter
                    color: "#3e3e46"
                }
            }

            RoundButton{//播放按钮
                id: player_play
                width: 71
                height: 71
                anchors.centerIn: parent

                //是否正在播放
                //property bool playing: handset.status == 3
                property string play_normal: "qrc:/pictures/playermenu/play.png"
                property string play_hover: "qrc:/pictures/playermenu/play-hover.png"
                property string play_press: "qrc:/pictures/playermenu/play-press.png"
                property string pause_normal: "qrc:/pictures/playermenu/pause.png"
                property string pause_hover: "qrc:/pictures/playermenu/pause-hover.png"
                property string pause_press: "qrc:/pictures/playermenu/pause-press.png"
                property string normal: (handset.status==3)?pause_normal:play_normal
                property string hover: (handset.status==3)?pause_hover:play_hover
                property string press: (handset.status==3)?pause_press:play_press
                property string source: pressed?press:(hovered?hover:normal)

                display: AbstractButton.IconOnly
                icon{
                    source: player_play.source
                    width: parent.width
                    height: parent.height
                }

                onClicked: {
                    if(handset.status==3)
                        handset.pause()
                    else
                        handset.play()
                }
            }

            RoundButton{//停止按钮
                id: player_stop
                width: 35
                height: 35
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: player_play.verticalCenter
                anchors.topMargin: 40
                property string normal: "qrc:/pictures/playermenu/stop.png"
                property string hover: "qrc:/pictures/playermenu/stop-hover.png"
                display: AbstractButton.IconOnly
                icon{
                    source: player_stop.hovered?player_stop.hover:player_stop.normal
                    width: parent.width
                    height: parent.height
                }
                onClicked: handset.stop()
            }
            RoundButton{//上一个按钮
                id: player_previous
                width: 35
                height: 35
                anchors.right: parent.horizontalCenter
                anchors.rightMargin: 40
                anchors.verticalCenter: player_play.verticalCenter

                property string normal: "qrc:/pictures/playermenu/previous.png"
                property string hover: "qrc:/pictures/playermenu/previous-hover.png"
                display: AbstractButton.IconOnly
                icon{
                    source: player_previous.hovered?player_previous.hover:player_previous.normal
                    width: parent.width
                    height: parent.height
                }
                onClicked: handset.previous()
            }
            RoundButton{//下一个按钮
                id: player_next
                width: 35
                height: 35
                anchors.left: parent.horizontalCenter
                anchors.leftMargin: 40
                anchors.verticalCenter: player_play.verticalCenter
                property string normal: "qrc:/pictures/playermenu/next.png"
                property string hover: "qrc:/pictures/playermenu/next-hover.png"
                display: AbstractButton.IconOnly
                icon{
                    source: player_next.hovered?player_next.hover:player_next.normal
                    width: parent.width
                    height: parent.height
                }
                onClicked: handset.next()
            }
        }
    }
}
