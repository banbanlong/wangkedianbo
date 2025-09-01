import QtQuick
import QtQuick.VirtualKeyboard

Window {//Controller
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    opacity: 0.0

    //启动画面
    //TODO：加载数据库的数据
    ESplashScreen{
        id: splash
        interval: 1900
        onTimeout: {
            splash.visible = false
            splash.close()
            login.item.visible = true
        }
    }
    //登录窗口
    Loader{
        id: login
        asynchronous: true
        source: "ELoginWindow.qml"
        property bool isexit: true
        onLoaded: {
            //打印日志，设置参数
            console.log("ESplashScreen.qml load done!")
        }
    }
    Connections{
        target: login.item
        function onClose(){
            //主窗口，没有显示，则表示登录是通过启动画面打开的
            if(login.isexit){//这个登录是启动时打开的
                //退出程序
                console.log("ESplashScreen.qml timeout")
                Qt.exit(0)
            }else{
                login.item.visible = false
            }

            //else如果是主窗口打开的，那么直接关闭登录窗口即可，无需退出
        }
        function onLoginStatus(code:int,msg:string){
            console.log("code="+code+" msg="+msg)
            if(code === 0){
                //登录成功！
                //TODO: 1 隐藏登录窗口 2 显示主窗口
                player.item.visible = true
                login.item.visible = false
                login.isexit = false

            }else{
                //TODO: 显示错误信息
            }
        }
    }
    //主窗口
    Loader{
        id: player
        asynchronous: true
        source: "EPlayerWindow.qml"
        onLoaded:{
            console.log("EPlayerWindow.qml load done!")
        }
    }
    Connections{
        target: player.item
        function onCloseWnd(){
            //退出程序
            console.log("EPlayerWindow.qml close")
            Qt.exit(0)
        }
        function onRelogin(){
            console.log("EPlayerWindow.qml relogin")
            //login.source = "ELoginWindow.qml"
            login.item.visible = true
        }
        function onUpdateUserInfo(){
            console.log("用户信息更新！")
        }
        //
    }

}
