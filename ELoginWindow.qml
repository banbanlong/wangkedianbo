import QtQuick
import QtQuick.Controls

Window {
    id: login
    title: qsTr("易道云播放器")
    flags: Qt.FramelessWindowHint|Qt.Window
    visible: true
    opacity: 0
    width: 340
    height: 510
    x: Screen.width/2 - width/2
    y: Screen.height/2 - height/2
    signal close()


    signal tryLogin(var account, var password ,var autologin, var remember)
    property alias account: accountEdit.text
    property alias password: pwdEdit.text
    property alias autologin: autoLogin.checked
    property alias remember: rememberCheck.checked


    Rectangle{
        anchors.fill: parent
        color: "#27282f"
        gradient: Gradient{
            GradientStop{position:0;color:"#27282f"}
            GradientStop{position:1;color:"#3f414c"}
            orientation: Gradient.Vertical //垂直方向
        }
        Popup{
            id: errorMsg
            anchors.centerIn: parent
            width: 300
            height: 200
            modal: true
            closePolicy: Popup.NoAutoClose
            property alias text: content.text
            Rectangle{
                anchors.fill: parent
                gradient: Gradient{
                    GradientStop{position:0;color:"#87888f"}
                    GradientStop{position:1;color:"#9fa1ac"}
                    orientation: Gradient.Vertical //垂直方向
                }
                Label{
                    id: content
                    text:""
                    font.pixelSize: 16
                    anchors.fill: parent
                    verticalAlignment: Label.AlignVCenter
                    horizontalAlignment: Label.AlignHCenter
                }
                Button{
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 20
                    anchors.horizontalCenter: content.horizontalCenter
                    text: "确定"
                    onClicked: errorMsg.close()
                }
            }
        }

        Button{
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.rightMargin: 10
            anchors.topMargin: 10
            width: 16
            height: 16
            display: AbstractButton.IconOnly
            icon{
                width: 16;height: 16
                source: hovered ? "qrc:/pictures/close-hover.png":"qrc:/pictures/close.png"
            }
            onClicked: {
                login.close()
            }
        }

        Image{
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 35
            width: 141
            height: 28
            source: "qrc:/pictures/logo.png"
            fillMode: Image.PreserveAspectFit
        }

        Image{
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 100
            width: 72
            height: 72
            source: "qrc:/pictures/headimg-login.png"
            fillMode: Image.PreserveAspectFit
        }


        //图标 账号名 密码 登录
        Column{
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 100
            anchors.left: parent.left
            anchors.leftMargin: 38
            width: 265
            height: 226
            spacing: 30
            Column{
                width: 265
                spacing: 15
                Text{
                    id: accountText
                    color: "white"
                    text: qsTr("账号")
                    font.pixelSize: 12
                }
                Rectangle{
                    border.width: 1
                    border.color: "white"
                    height: 23
                    width: parent.width
                    color: "transparent"
                    TextEdit{
                        id: accountEdit
                        anchors.leftMargin: 5
                        anchors.fill: parent
                        color: "lightgray"
                        text: qsTr("请输入账号")
                        font.pixelSize: 12
                        verticalAlignment: Text.AlignVCenter
                        onFocusChanged:{
                            if(focus && (text === "请输入账号")){
                                text = ""
                            }else if(!focus && (text === "")){
                                text = "请输入账号"
                            }
                        }
                    }
                }
            }
            Column{
                width: 265
                spacing: 15
                Text{
                    id: pwdText
                    color: "white"
                    text: qsTr("密码")
                    font.pixelSize: 12
                }
                Rectangle{
                    border.width: 1
                    border.color: "white"
                    height: 23
                    width: parent.width
                    color: "transparent"
                    TextInput{
                        id: pwdEdit
                        anchors.leftMargin: 5
                        anchors.fill: parent
                        color: "lightgray"
                        text: qsTr("请输入密码")
                        font.pixelSize: 12
                        verticalAlignment: Text.AlignVCenter
                        passwordCharacter: "*"
                        onTextChanged: {
                            if(text!==qsTr("请输入密码")){
                                echoMode = TextInput.Password //密码模式
                            }else{
                                echoMode = TextInput.Normal
                            }
                        }
                        onFocusChanged: {
                            if(focus && (text==="请输入密码")){
                                text = ""
                                echoMode = TextInput.Password //密码模式
                            }else if(!focus && text===""){
                                text = "请输入密码"
                                echoMode = TextInput.Normal
                            }
                        }
                    }
                }
            }
            Row{
                width: parent.width
                height: 34
                spacing: 40
                Rectangle{
                    height: parent.height
                    width: 100
                    color: "transparent"
                    Row{
                        spacing: 20
                        CheckBox{
                            id: autoLogin
                            display: AbstractButton.IconOnly
                            width: 25
                            height: 25
                            indicator.width: 25
                            indicator.height: 25
                            onCheckedChanged: {
                                if(checked){//勾选自动登录的时候，同时应该勾选记住密码，否则无法自动记录数据
                                    rememberCheck.checked = true
                                }
                            }
                        }
                        Text{
                            anchors.verticalCenter: parent.verticalCenter
                            font.bold: true
                            text: qsTr("自动登录")
                            color: "white"
                            font.pointSize: 12
                            MouseArea{
                                anchors.fill: parent
                                onClicked: {
                                    autoLogin.checked = !autoLogin.checked
                                }
                            }
                        }
                    }
                }
                Rectangle{
                    height: parent.height
                    width: 100
                    color: "transparent"
                    Row{
                        spacing: 20
                        CheckBox{
                            id: rememberCheck
                            display: AbstractButton.IconOnly
                            width: 25
                            height: 25
                            indicator.width: 25
                            indicator.height: 25
                            onCheckedChanged: {
                                if(!checked){//勾选自动登录的时候，同时应该勾选记住密码，否则无法自动记录数据
                                    autoLogin.checked = false
                                }
                            }
                        }
                        Text{
                            anchors.verticalCenter: parent.verticalCenter
                            font.bold: true
                            text: qsTr("记住密码")
                            color: "white"
                            font.pointSize: 12
                            MouseArea{
                                anchors.fill: parent
                                onClicked: {
                                    rememberCheck.checked = !rememberCheck.checked
                                }
                            }
                        }
                    }
                }
            }
            ELoginButton{
                id: loginButton
                anchors.horizontalCenter: parent.horizontalCenter
                width: parent.width
                height: 30
                text: qsTr("登录")
                onClicked: {
                    if((pwdEdit.text === "")||(pwdEdit.text ==="请输入密码")){
                        //提示用户，密码不正确
                        errorMsg.text = "密码错误，请输入正确的密码"
                        errorMsg.open()
                        return
                    }
                    if((accountEdit.text === "")||(accountEdit.text ==="请输入账号")){
                        //提示用户，账号不正确
                        errorMsg.text = "账号错误，请输入正确的账号"
                        errorMsg.open()
                        return
                    }

                    login.tryLogin(accountEdit.text,pwdEdit.text,autoLogin.checked,rememberCheck.checked)
                }
            }
        }
    }
}
