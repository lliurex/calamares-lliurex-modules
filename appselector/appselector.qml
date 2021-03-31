import QtQuick 2.6
import QtQuick.Layouts 1.1
import QtQuick.Controls 2.6 as QQC2
import org.kde.plasma.core 2.0 as PlasmaCore
import org.kde.kirigami 2.5 as Kirigami

QQC2.Pane
{
    width: 400
    height: 400
    
    QQC2.StackView {
        id: stack
        
        anchors.fill:parent
        
        //index: 0
        initialItem: page1
    }
    
    //Component.onCompleted: stack.push(page1)
    
    Connections {
        target: config
        
        function onStepChanged() {

            if (config.step==0) {
                stack.replace(page1,QQC2.StackView.PopTransition);
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
            //anchors.fill: parent
            QQC2.Label {
                Layout.fillWidth: true
                text: "Select apps"
            }
            
            ListView {
                id: layoutsView
                Layout.fillWidth: true
                Layout.fillHeight: true
                
                property var ratio: 0.15
                
                model: config.appsModel
                
                focus: true
            
                delegate:
                    QQC2.CheckBox {
                        
                        text: modelData.name
                        icon.name: modelData.iconName
                        icon.width: 32
                        icon.height: 32
                        
                        checked: modelData.checked
                        
                        onToggled: {
                            modelData.checked=checked;
                        }
                    }
                }
        }
    }
    
    Component {
        id: page2
        
        ColumnLayout {
            spacing: Kirigami.Units.smallSpacing
            //anchors.fill: parent
            QQC2.Label {
                Layout.fillWidth: true
                text: "Select services"
            }
            
            ListView {
                id: layoutsView
                Layout.fillWidth: true
                Layout.fillHeight: true
                
                property var ratio: 0.15
                
                model: config.servicesModel
                
                focus: true
            
                delegate:
                    QQC2.CheckBox {
                        text: modelData.name
                        icon.name: modelData.iconName
                        icon.width: 32
                        icon.height: 32
                        
                        checked: modelData.checked
                        
                        onToggled: {
                            modelData.checked=checked;
                        }
                    }
                }
        }
    }
    
}
