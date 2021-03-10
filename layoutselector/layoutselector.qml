import QtQuick 2.6
import QtQuick.Controls 2.6 as QQC2

QQC2.Pane
{
    width: 400
    height: 400
    
    ListModel {
        id: layoutsModel
        ListElement {
            name: "Classic"
            image: "qrc:/preview-classic.svg"
            }
            
            ListElement {
            name: "Default"
            image: "qrc:/preview-default.svg"
        }
    }
    
    ListView {
        id: layoutsView
        width: parent.width-5; height: parent.height-5
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        property var ratio: 0.15
        
        model: layoutsModel
        highlightFollowsCurrentItem: true
        
        highlight: 
            Rectangle { 
                anchors.horizontalCenter: parent.horizontalCenter
                color: "#bfdcf1"
                radius: 5
                //width: (1920*ratio)+10
                //height:(1080*ratio)+32
            }
            
        focus: true
        
        delegate:
            Item {
                id: itm
                anchors.horizontalCenter: parent.horizontalCenter
                
                width:(1920*layoutsView.ratio)+64
                height:(1080*layoutsView.ratio)+32
                
                //color: (layoutsModel.currentIndex==index) ? "#bfdcf1" : "#f9f9f9"
                MouseArea {
                    anchors.fill: parent
                    onClicked: layoutsView.currentIndex = index
                }
                    
                Column {
                    id: chld
                    anchors.horizontalCenter: itm.horizontalCenter
                    anchors.verticalCenter: itm.verticalCenter
                    Image {
                        anchors.horizontalCenter: parent.horizontalCenter
                        width: 1920*layoutsView.ratio
                        height: 1080*layoutsView.ratio
                        source: image
                    }
                    Text {
                        text: name
                        //color: "#ffffff"
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                }
            }
    }
}
