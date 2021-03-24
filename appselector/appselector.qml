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
        id: appsModel
        ListElement {
            name: "Inkscape"
            iconName: "inkscape"
        }
        
        ListElement {
            name: "Gimp"
            iconName: "gimp"
        }
        
        ListElement {
            name: "Firefox"
            iconName: "firefox"
        }
        
        ListElement {
            name: "OpenScad"
            iconName: "openscad"
        }
    }
    
    ListModel {
        id: servicesModel
        ListElement {
            name: "Alfa"
            iconName: "folder"
        }
        
        ListElement {
            name: "Beta"
            iconName: "trash"
        }
    }
    
    QQC2.StackView {
        id: stack
        
        anchors.fill:parent
        
        //index: 0
        initialItem: page1
    }
    
    //Component.onCompleted: stack.push(page1)
    
    Connections {
        target: config
        
        onStepChanged: {
            console.log("miau");
            console.log(stack.index);
            console.log(stack.depth);
            if (config.step==0) {
                
                
                if (stack.index==-1) {
                    stack.replace(page1,QQC2.StackView.PopTransition);
                }
                else {
                    stack.replace(page1,QQC2.StackView.Immediate);
                }
            }
            if (config.step==1) {
                stack.replace(page2,QQC2.StackView.PushTransition);
            }
        }
    }
    
    Component {
        id: page1
        
        ColumnLayout {
            spacing: Kirigami.Units.smallSpacing
            anchors.fill: parent
            QQC2.Label {
                Layout.fillWidth: true
                text: "All your base are belong to us"
            }
            
            ListView {
                id: layoutsView
                Layout.fillWidth: true
                Layout.fillHeight: true
                
                property var ratio: 0.15
                
                model: appsModel
                
                focus: true
            
                delegate:
                    QQC2.CheckBox {
                        text: name
                        icon.name: iconName
                        icon.width: 32
                        icon.height: 32
                    }
                }
        }
    }
    
    Component {
        id: page2
        
        ColumnLayout {
            spacing: Kirigami.Units.smallSpacing
            anchors.fill: parent
            QQC2.Label {
                Layout.fillWidth: true
                text: "Select your destiny"
            }
            
            ListView {
                id: layoutsView
                Layout.fillWidth: true
                Layout.fillHeight: true
                
                property var ratio: 0.15
                
                model: servicesModel
                
                focus: true
            
                delegate:
                    QQC2.CheckBox {
                        text: name
                        icon.name: iconName
                        icon.width: 32
                        icon.height: 32
                    }
                }
        }
    }
    
}
