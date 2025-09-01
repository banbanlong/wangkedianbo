import QtQuick
import QtMultimedia

Window {
    id: splashWindow
    //16:9
    width: 800;height: 450
    flags: Qt.FramelessWindowHint
    visible: true
    property alias interval: timer.interval

    signal timeout()

    Timer{
        id: timer
        interval: 2000
        repeat: false
        triggeredOnStart: false
        running: true
        onTriggered: {
            music.stop()
            splashWindow.timeout()

        }
    }
    Image {
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit
        source: "qrc:/pictures/splash.png"
        sourceSize: Qt.size(1920, 1080)
        smooth: true
    }

    MediaPlayer {
        id: music
        source: "qrc:/music/ringing.wav"
        audioOutput: AudioOutput { }
    }

    NumberAnimation on opacity {
        duration: timer.interval
        from: 1.0
        to: 0.0
        easing.type: Easing.InOutQuint
        running: true
    }

    Component.onCompleted: {
        music.play()
    }

}
