import QtQuick
import QtQuick.Controls

Rectangle {//作业：抽屉模式  倍速 设置页面
    id: listView
    color: "#49484D"
    //列表头的文本
    property alias listModel: lessionList.model
    property alias currentIndex: lessionList.currentIndex
    property alias currentUrl: lessionList.currentUrl


    signal doubleClicked()


    FontLoader{
        id: alipuhui
        source: "qrc:/font/alipuhuiMEDIUM.TTF"
    }

    Rectangle{//表头
        id: header
        width: parent.width
        height: 50
        color: "#5e5e61"
        //列表的图标
        RoundButton{
            hoverEnabled: false
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: 5
            radius: 20
            display: AbstractButton.IconOnly
            icon.source: "qrc:/pictures/shezhi.png"
        }
        //列表头  文字
        Text{
            id: listHeaderTitle
            text: lessionModel.get(lessionList.currentIndex).title
            width: 240
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: 50
            elide: Text.ElideRight
            color: "white"
            font.pointSize: 14
            font.family: alipuhui.name
        }
    }
    ListView{
        id: lessionList
        anchors.top: header.bottom
        height: parent.height-header.height
        width: parent.width
        property string currentUrl: lessionModel.get(currentIndex).url
        model: ListModel{
            id: lessionModel
            ListElement{
                time:"00:02:16"
                title:"huang_move"
                url:"file:///C:/Users/banchenglong/Desktop/keyan/data/huang_move.mp4"
            }
            ListElement{
                time:"00:00:30"
                title:"dongtaiMP4"
                url: "file:///C:/Users/banchenglong/Desktop/keyan/data/dongtai.mp4"
            }
            ListElement{
                time:"00:01:40"
                title:"03 同步信号 m3u8格式"
                url:"http://playertest.longtailvideo.com/adaptive/bipbop/gear4/prog_index.m3u8"
            }
            ListElement{
                time:"00:00:05"
                title:"04 big buck bunny flv格式"
                url:"https://sample-videos.com/video123/flv/720/big_buck_bunny_720p_1mb.flv"
            }
            ListElement{
                time:"00:30:01"
                title:"05 同步信号 m3u8格式"
                url:"http://devimages.apple.com/iphone/samples/bipbop/bipbopall.m3u8"
            }
            ListElement{
                time:"01:38:20"
                title:"06 电影INBRED m3u8格式"
                url:"https://qq.sd-play.com/20220310/jMEPNAwK/index.m3u8"
            }
            ListElement{
                time:"00:03:25"
                title:"07 将进酒（自定义服务器测试） m3u8格式"
                url:"http://127.0.0.1:8080/jjj.m3u8"
            }
        }
        delegate: Rectangle {
            //列表项
            id: listItem
            width: lessionList.width
            height: 30
            color: "transparent"

            MouseArea{
                id: listMouseArea
                anchors.fill: parent
                hoverEnabled: true
                onClicked: {
                    lessionList.currentIndex = index
                    //console.log("list clicked")
                }
                onDoubleClicked: {
                    lessionList.currentIndex = index
                    listView.doubleClicked()
                    //console.log("list double clicked")
                }
                property bool hovered: false
                onEntered: {
                    hovered = true
                }
                onExited: {
                    hovered = false
                }
            }
            Row{
                id: itemRow
                anchors.verticalCenter: parent.verticalCenter
                width: parent.width
                property bool isCurrent: listItem.ListView.isCurrentItem
                Rectangle{
                    width: parent.width
                    height: 40
                    color: "transparent"
                    Text{
                        anchors.verticalCenter: parent.verticalCenter
                        width: parent.width - 35
                        font.family: alipuhui.name
                        font.pixelSize: 14
                        color: itemRow.isCurrent ? "#3da3f1":"#dadadb"
                        text: time + " " + title
                        elide: Text.ElideRight
                    }
                    Image{
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.right: parent.right
                        anchors.rightMargin: 7
                        width: 20
                        height: 12
                        property string videoHover: "qrc:/pictures/video-hover.png"
                        property string videoSelected: "qrc:/pictures/video-onclick.png"
                        property string videoDefault: "qrc:/pictures/video-default.png"
                        source: itemRow.isCurrent? videoSelected:(listMouseArea.hovered?videoHover:videoDefault)
                    }
                }
            }
        }
        highlight: Rectangle{color:"#37383d"}
        focus: true
    }
}
