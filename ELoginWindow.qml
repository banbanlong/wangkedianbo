import QtQuick
import QtQuick.Controls

Window {
    id: login
    title: qsTr("易道云播放器")
    flags: Qt.FramelessWindowHint|Qt.Window
    visible: true
    width: 340
    height: 510
    signal close()
    //code: 0 ok 其他是失败 msg 是错误信息 成功的话呢为"登录成功！" 失败的话，包含错误原因
    signal loginStatus(var code,var msg)

    Rectangle{
        anchors.fill: parent
        color: "#27282f"
        gradient: Gradient{
            GradientStop{position:0;color:"#27282f"}
            GradientStop{position:1;color:"#3f414c"}
            orientation: Gradient.Vertical //垂直方向
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
            anchors.bottomMargin: 50
            anchors.left: parent.left
            anchors.leftMargin: 38
            width: 265
            height: 226
            spacing: 30
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
                }
            }

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
                TextEdit{
                    id: pwdEdit
                    anchors.leftMargin: 5
                    anchors.fill: parent
                    color: "lightgray"
                    text: qsTr("请输入密码")
                    font.pixelSize: 12
                    verticalAlignment: Text.AlignVCenter
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
                            width: 20
                            height: 20
                            indicator.width: 20
                            indicator.height: 20
                        }
                        Text{
                            anchors.verticalCenter: parent.verticalCenter
                            font.bold: true
                            text: qsTr("自动登录")
                            color: "white"
                            font.pointSize: 12
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
                            id: remember
                            display: AbstractButton.IconOnly
                            width: 20
                            height: 20
                            indicator.width: 20
                            indicator.height: 20
                        }
                        Text{
                            anchors.verticalCenter: parent.verticalCenter
                            font.bold: true
                            text: qsTr("记住密码")
                            color: "white"
                            font.pointSize: 12
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
                        //TODO: 网络通信
                        login.loginStatus(0,"登录成功！")
                    }
                }
            }
        }
    }
}
