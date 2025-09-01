import QtQuick
import QtQuick.Controls

Rectangle {
    id: titlebar
    width: parent.width
    height: 40
    color: "transparent"
    property alias ismax: maxRestore.ismax

    //code 0 登录按钮 1 设置 2 最小化 3 最大化 4 恢复 5 关闭
    signal buttonClicked(var code)
    signal startDrag()
    signal pressed(var mouse)
    signal released(var mouse)
    signal positionChanged(var mouse)


    FontLoader{
        id: alipuhui
        source: "qrc:/font/alipuhuiMEDIUM.TTF"
    }

    Image{
        anchors.top: parent.top
        anchors.topMargin: 5
        anchors.left: parent.left
        anchors.leftMargin: 5
        source: "qrc:/pictures/logo.png"
    }

    Rectangle{
        height: 1
        width: parent.width
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        gradient: Gradient{
            orientation: Gradient.Horizontal
            GradientStop{color:"#3da3f1";position:0}
            GradientStop{color:"#245fcf";position:1}
        }
    }

    TapHandler{
        grabPermissions: TapHandler.TakeOverForbidden
        onTapped: if(tapCount===2) maxRestore.clicked()
        gesturePolicy: TapHandler.DragThreshold
    }
    DragHandler{
        grabPermissions: TapHandler.TakeOverForbidden
        onActiveChanged: titlebar.startDrag()
    }

    MouseArea{
        id:mouseArea
        anchors.fill: parent
        property bool ispressed: false
        onPressed: (mouse)=>{ispressed=true;titlebar.pressed(mouse)}
        onReleased: (mouse)=>{ispressed=false;titlebar.released(mouse)}
        onPositionChanged: (mouse)=>{if(ispressed)titlebar.positionChanged(mouse)}

        RoundButton{
            anchors.top: parent.top
            anchors.topMargin: 5
            anchors.right: parent.right
            anchors.rightMargin: 270
            width: 28;height: 28
            BorderImage {
                anchors.fill: parent
                source: "qrc:/pictures/headimg-default.png"
            }
            onClicked: titlebar.buttonClicked(0)
        }
        Text{
            id:loginStatus
            anchors.top: parent.top
            anchors.topMargin: 9
            anchors.right: parent.right
            anchors.rightMargin: 210
            font.pointSize: 14
            font.family: alipuhui.name
            color: "#DADAE5"
            text: "已登录"
        }

        Button{//设置按钮
            id: setting
            hoverEnabled: true
            property string normal: "qrc:/pictures/shezhi.png"
            property string hover: "qrc:/pictures/shezhi-hover.png"
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: parent.right
            anchors.rightMargin: 140
            width: 16
            height: 16
            background: Rectangle{
                implicitWidth: parent.width
                implicitHeight: parent.height
                color: "transparent"
                BorderImage {
                    source: (setting.hovered&&(setting.pressed===false)) ? setting.hover:setting.normal
                    anchors.fill: parent
                }
            }
            onClicked: titlebar.buttonClicked(1)
        }

        Button{//最小化按钮
            id: suoxiao
            hoverEnabled: true
            property string normal: "qrc:/pictures/suoxiao.png"
            property string hover: "qrc:/pictures/suoxiao-hover.png"
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: parent.right
            anchors.rightMargin: 100
            width: 16
            height: 16
            background: Rectangle{
                implicitWidth: parent.width
                implicitHeight: parent.height
                color: "transparent"
                BorderImage {
                    source: (suoxiao.hovered&&(suoxiao.pressed===false)) ? suoxiao.hover:suoxiao.normal
                    anchors.fill: parent
                }
            }
            onClicked: titlebar.buttonClicked(2)
        }

        Button{//最大化/恢复按钮
            id: maxRestore
            hoverEnabled: true
            property string normal: "qrc:/pictures/fangda.png"
            property string hover: "qrc:/pictures/fangda-hover.png"
            property string restore: "qrc:/pictures/huifu.png"
            property string restoreHover: "qrc:/pictures/huifu-hover.png"
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: parent.right
            anchors.rightMargin: 60
            width: 16
            height: 16
            property bool ismax: false
            property string maxSource: hovered?(pressed?normal:hover): normal
            property string restoreSource: (hovered && (pressed===false)) ? restore:restoreHover
            background: Rectangle{
                implicitWidth: parent.width
                implicitHeight: parent.height
                color: "transparent"
                BorderImage {
                    source: maxRestore.ismax?maxRestore.restoreSource:maxRestore.maxSource
                    anchors.fill: parent
                }
            }
            onClicked: {
                if(ismax){//点击的是恢复
                    titlebar.buttonClicked(4)
                }else{//需要最大化
                    titlebar.buttonClicked(3)
                }
            }
        }

        Button{//关闭按钮
            id: close
            hoverEnabled: true
            property string normal: "qrc:/pictures/close.png"
            property string hover: "qrc:/pictures/close-hover.png"
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: parent.right
            anchors.rightMargin: 20
            width: 16
            height: 16
            background: Rectangle{
                implicitWidth: close.width
                implicitHeight: close.height
                color: "transparent"
                BorderImage {
                    source: (close.hovered && (close.pressed===false)) ? close.hover:close.normal
                    anchors.fill: parent
                }
            }
            onClicked: titlebar.buttonClicked(5)
        }
    }
}
