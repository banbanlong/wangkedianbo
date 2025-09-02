import QtQuick
import QtQuick.Controls
import Edoyun

Window {
    id: player
    title: qsTr("易道云播放器")
    width: 1500  //Screen {width/height desktopAvailableWidth/Height}
    height: 800
    flags: Qt.FramelessWindowHint|Qt.Window
    visible: false
    signal relogin()
    signal updateUserInfo()
    signal closeWnd()

    function onUpdateList(lessions)
    {
        console.log("lessions="+lessions)
        if(lessions.length>0){
            lessionList.listModel.clear()
            for(var i=0;i<lessions.length;i++){
                lessionList.listModel.insert(i, lessions[i])
            }
        }
    }

    Rectangle{
        anchors.fill: parent
        gradient: Gradient{
            orientation: Gradient.Horizontal
            GradientStop{position:0;color:"#27282f"}
            GradientStop{position:1;color:"#282a35"}
        }
        ETitlebar{
            id:titlebar
            width: parent.width
            height: 40
            ismax: player.visibility === Window.Maximized
            property point win: Qt.point(0,0)
            property point offset: Qt.point(0,0)
            onButtonClicked: (button)=>{
                                 if(button===0){
                                     player.relogin()
                                 }else if(button === 1){
                                     console.log("设置按钮按下")
                                 }else if(button === 2){
                                     console.log("最小化")
                                     player.visibility = Window.Minimized
                                 }else if(button === 3){
                                     console.log("最大化")
                                     player.visibility = Window.Maximized
                                     lessionList.visible = false
                                 }else if(button === 4){
                                     console.log("恢复")
                                     player.visibility = Window.Windowed
                                     lessionList.visible = true
                                 }else if(button === 5){
                                     console.log("关闭按钮按下")
                                     player.closeWnd()
                                     Qt.exit(0)
                                 }
                             }
            onPressed: (mouse)=>{
                           if(player.visibility===Window.Windowed){
                               offset.x = mouse.x+player.x
                               offset.y = mouse.y+player.y
                               win.x = player.x
                               win.y = player.y
                           }
                       }
            onReleased: (mouse)=>{
                            if(player.visibility===Window.Windowed){
                                var cur = Qt.point(mouse.x+player.x,mouse.y+player.y)
                                player.x = win.x+cur.x-offset.x
                                player.y = win.y+cur.y-offset.y
                            }
                        }

            onPositionChanged: (mouse)=>{
                                   if(player.visibility===Window.Windowed){
                                       var cur = Qt.point(mouse.x+player.x,mouse.y+player.y)
                                       player.x = win.x+cur.x-offset.x
                                       player.y = win.y+cur.y-offset.y
                                   }
                               }
        }
        Rectangle{
            width: player.width
            height: player.height-titlebar.height
            anchors.top: titlebar.bottom
            color: "black"
            EdoyunVideo{
                id: videoplayer
                anchors.fill: parent
                autoplay: true
                //url:"http://vfx.mtime.cn/Video/2021/07/09/mp4/210709172715355157.mp4"
                url:"file:///E:/Project/CxxProject/EdoyunPlayer/Win通用安装教程.mp4"
            }
        }

        EHandset{
            id: handset
            anchors.left: parent.left
            anchors.bottom: parent.bottom

            onPlay: {
                videoplayer.play()
                updateStatus.running = true

            }
            onPause: {
                videoplayer.pause()
            }
            onStop:{
                videoplayer.stop()
            }
            onProcess: (position)=>{
                           console.log("position++:"+position)
                           videoplayer.position = position
                           console.log("position:"+videoplayer.position)
                       }
            onNext:{
                var count = lessionList.listModel.count
                if(lessionList.currentIndex<count-1){
                    lessionList.currentIndex += 1
                }else{
                    lessionList.currentIndex = 0
                }
                videoplayer.url = lessionList.currentUrl
                updateStatus.running = true
            }
            onPrevious: {
                var count = lessionList.listModel.count
                if(lessionList.currentIndex>0){
                    lessionList.currentIndex -= 1
                }else{
                    lessionList.currentIndex = count-1
                }
                videoplayer.url = lessionList.currentUrl
                updateStatus.running = true
            }

            Timer{
                id:updateStatus
                interval: 200
                repeat: true
                onTriggered: {
                    //更新手柄的进度条
                    handset.curTime = videoplayer.getCurTime()
                    handset.maxTime = videoplayer.getMaxTime()
                    handset.status = videoplayer.status
                    //console.log("timer position:"+videoplayer.position)
                    if(handset.pressed==false){
                        if(videoplayer.position > 0.0){
                            handset.degree = 360*videoplayer.position
                            //console.log("degree:"+handset.degree)
                        }else{
                            handset.degree = 0
                            //console.log("++degree:"+handset.degree)
                        }
                    }
                    //console.log("timer position:"+videoplayer.position)
                    if(videoplayer.status > 4){
                        console.log("status:"+videoplayer.status)
                        running = false
                        handset.degree = 0
                    }
                }
            }
        }

        ELessionList{
            id: lessionList
            width: 300
            height: player.height - titlebar.height
            anchors.top: titlebar.bottom
            anchors.right: parent.right
            onDoubleClicked:{
                videoplayer.url = lessionList.currentUrl
                updateStatus.running = true
            }
        }
    }
}
