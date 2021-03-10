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
        
        model: layoutsModel
        highlightFollowsCurrentItem: true
        
        highlight: Rectangle { color: "#bfdcf1"; radius: 5 }
        focus: true
        
        delegate:
            Item {
                width:200
                height:140
                
                //color: (layoutsModel.currentIndex==index) ? "#bfdcf1" : "#f9f9f9"
                MouseArea {
                    anchors.fill: parent
                    onClicked: layoutsView.currentIndex = index
                }
                    
                Column {
                    Image { 
                        width: 192
                        height: 108
                        source: image
                    }
                    Text {
                        text: name
                    }
                }
            }
    }
}
