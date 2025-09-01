import QtQuick
import QtQuick.Controls

Button {
    id: control
    implicitWidth: Math.max(
                       buttonBackground? buttonBackground.implicitWidth:0,
                       textItem.implictWidth+leftPadding+rightPadding)
    implicitHeight: Math.max(
                        buttonBackground? buttonBackground.implicitHeight:0,
                        textItem.implictHeight+topPadding+bottomPadding)
    leftPadding: 4
    rightPadding: 4
    text:"登录"
    Gradient{
        id: normalColor
        GradientStop{position: 0;color:"#3da3f1"}
        GradientStop{position: 0;color:"#244fcf"}
        orientation: Gradient.Horizontal
    }
    Gradient{
        id: pressedColor
        GradientStop{position: 0;color:"#244fcf"}
        GradientStop{position: 0;color:"#3da3f1"}
        orientation: Gradient.Horizontal
    }

    background: Rectangle{
        id: buttonBackground
        gradient: normalColor
        anchors.fill: parent
        opacity: enabled ? 1.0 : 0.3
        radius: 4
    }
    contentItem: Text{
        id:textItem
        text: control.text
        opacity: enabled? 1.0 : 0.3
        color: "white"
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.bold: true
        font.pixelSize: 12
    }
    states:[
        State{
            name: "normal"
            when: !control.down
            PropertyChanges {
                target: buttonBackground
                gradient: normalColor
            }
        },
        State{
            name: "down"
            when: control.down
            PropertyChanges {
                target: buttonBackground
                gradient: pressedColor
            }
        }
    ]
}
