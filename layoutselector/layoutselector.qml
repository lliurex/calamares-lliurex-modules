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
            displayName: "Default"
            name: "default"
            image: "qrc:/preview-default.svg"
        }
        
        ListElement {
            displayName: "Classic"
            name: "classic"
            image: "qrc:/preview-classic.svg"
        }
        
    }
    
    ColumnLayout {
        spacing: Kirigami.Units.smallSpacing
        anchors.fill: parent
        
        Connections {
            target: config
            
            function onTranslationsChanged() {
                label.text=config.translate("Select a default layout");
                
                layoutsModel.clear();
                layoutsModel.append({"displayName":config.translate("Default"),"name":"default","image":"qrc:/preview-default.svg"});
                layoutsModel.append({"displayName":config.translate("Classic"),"name":"classic","image":"qrc:/preview-classic.svg"});
                layoutsView.forceLayout();
            }
        }
        
        Text {
            Layout.fillWidth: true
            id: label
            text: config.translate("Select a default layout")
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
                            text: displayName
                            anchors.horizontalCenter: parent.horizontalCenter
                        }
                    }
                }
            }
    }
}
