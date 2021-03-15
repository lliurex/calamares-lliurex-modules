import QtQuick 2.6
import QtQuick.Layouts 1.1
import QtQuick.Controls 2.6 as QQC2
import org.kde.plasma.core 2.0 as PlasmaCore
import org.kde.kirigami 2.5 as Kirigami

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
    
    ColumnLayout {
        spacing: Kirigami.Units.smallSpacing
        anchors.fill: parent
        Text {
            Layout.fillWidth: true
            text: "Select a default layout"
        }
        
        ListView {
            id: layoutsView
            Layout.fillWidth: true
            Layout.fillHeight: true
            
            property var ratio: 0.15
            
            model: layoutsModel
            highlightFollowsCurrentItem: true
            
            highlight:
                Rectangle { 
                    anchors.horizontalCenter: parent.horizontalCenter
                    color: "#bfdcf1"
                    border.color: "#3daee9"
                    border.width: 2
                    radius: 5
                }
            
            focus: true
        
            delegate:
                Item {
                    id: itm
                    anchors.horizontalCenter: parent.horizontalCenter
                    
                    width:(1920*layoutsView.ratio)+64
                    height:(1080*layoutsView.ratio)+32
                    
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                                layoutsView.currentIndex = index
                                console.log(name);
                                config.layout=name;
                            }
                        
                    }
                        
                    Column {
                        id: chld
                        anchors.horizontalCenter: itm.horizontalCenter
                        anchors.verticalCenter: itm.verticalCenter
                        spacing: Kirigami.Units.smallSpacing
                        
                        Image {
                            anchors.horizontalCenter: parent.horizontalCenter
                            width: 1920*layoutsView.ratio
                            height: 1080*layoutsView.ratio
                            source: image
                        }
                        Text {
                            text: name
                            anchors.horizontalCenter: parent.horizontalCenter
                        }
                    }
                }
            }
    }
}
