import QtQuick
import QtQuick.VirtualKeyboard
import Edoyun

Window {//Controller
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    opacity: 0.0
    //数据库
    ESqlite3{
        id: sqlite3
    }
    //网络
    ENetwork{
        id: client
        host: "127.0.0.1"
        port: 8000

        signal updateList(var lessions)

        Component.onCompleted:{
            client.start()
            var data={//首次连接，获取AES密钥
                "time":Qt.formatDateTime(new Date(),"yyyy-MM-dd HH:mm:ss.zzz")
            }
            client.send(0,data)
        }
        onReceive:(cmd/*int*/,data/*json*/)=>{//在这里接收
                      if(cmd === 1){
                          console.log("data="+JSON.stringify(data))
                          var lessions = data["lessions"]
                          client.updateList(lessions)
                          login.opacity = 0
                          player.item.visible = true
                      }
                  }
        onError:(err)=>{
                    console.log("error="+err)
                }
        onConnected:{
            console.log("连接成功！")
        }
    }

    //启动画面
    //TODO：加载数据库的数据
    ESplashScreen{
        id: splash
        interval: 1900
        onTimeout: {
            splash.visible = false
            splash.close()
            sqlite3.init()
            var account = sqlite3.read("account")
            var password = sqlite3.read("password")
            var autologin = sqlite3.read("autologin")
            var remember = sqlite3.read("remember")
            console.log("account:"+account)
            console.log("password:"+password)
            console.log("autologin:"+autologin)
            console.log("remember:"+remember)

            if(remember === "true"){
                //设置登录的记住密码状态
                login.account = account
                login.password = password
                login.remember = true
                login.autologin = autologin
                if(autologin === "true"){
                    //设置登录的自动登录状态
                    login.account = account
                    login.password = password
                    login.autologin = true
                    login.remember = true
                    //开启登录流程！//code: 0 ok 其他是失败 msg 是错误信息 成功的话呢为"登录成功！" 失败的话，包含错误原因
                }
            }
            login.opacity = 1
        }
    }
    //登录窗口
    ELoginWindow{
        id: login
        property bool isexit: true
        onClose:{
            //主窗口，没有显示，则表示登录是通过启动画面打开的
            if(login.isexit){//这个登录是启动时打开的
                //退出程序
                console.log("ESplashScreen.qml timeout")
                Qt.exit(0)
            }else{
                login.opacity = 0
            }

            //else如果是主窗口打开的，那么直接关闭登录窗口即可，无需退出
        }
        onTryLogin:(account,password,autologin,remember)=>{
                       //尝试通过网络登录，如果成功，则记录
                       var data = {
                           "account": account,
                           "password": password,
                           "time":Qt.formatDateTime(new Date(),"yyyy-MM-dd HH:mm:ss.zzz")
                       }
                       console.log("data="+data)
                       client.send(1, data)
                       console.log("account:"+account)
                       console.log("password:"+password)
                       console.log("autologin:"+autologin)
                       console.log("remember:"+remember)
                       if(remember){
                           sqlite3.write("remember", "true")
                           sqlite3.write("autologin",autologin ? "true":"false")
                           sqlite3.write("account",account)
                           sqlite3.write("password",password)
                       }else{
                           sqlite3.write("remember", "false")
                       }

                       //如果成功，则设置透明度为0
                       //isexit = false
                   }
    }


    //主窗口
    Loader{
        id: player
        asynchronous: true
        source: "EPlayerWindow.qml"
        onLoaded:{
            console.log("EPlayerWindow.qml load done!")
            client.updateList.connect(player.item.onUpdateList)
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
            login.opacity = 1.0
        }
        function onUpdateUserInfo(){
            console.log("用户信息更新！")
        }
        //
    }

}
