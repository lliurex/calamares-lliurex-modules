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
            spacing: Kirigami.Units.largeSpacing*4
            //anchors.fill: parent
            QQC2.Label {
                id: label
                Layout.fillWidth: true
                text: config.translate("Select apps")
            }
            
            Connections {
                target: config
                
                function onAppsModelChanged() {
                    label.text=config.translate("Select apps");
                }
            }
            
            ListView {
                id: layoutsView
                Layout.fillWidth: true
                Layout.fillHeight: true
                spacing: Kirigami.Units.largeSpacing*2
                
                model: config.appsModel
                
                focus: true
                
                QQC2.ScrollBar.vertical: QQC2.ScrollBar {}
            
                delegate:
                    ColumnLayout {
                        
                        RowLayout {
                            spacing: Kirigami.Units.smallSpacing
                            
                            QQC2.CheckBox {
                                icon.name: modelData.iconName
                                icon.width: 32
                                icon.height: 32
                                
                                checked: modelData.checked
                                
                                onToggled: {
                                    modelData.checked=checked;
                                }
                            }
                            QQC2.Label {
                                text: "<b>"+modelData.displayName+"</b>"
                            }
                        }
                        
                        QQC2.Label {
                            text: modelData.translation
                        }
                    }
                }
        }
    }
    
    Component {
        id: page2
        
        ColumnLayout {
            spacing: Kirigami.Units.largeSpacing*4
            //anchors.fill: parent
            QQC2.Label {
                id: label
                Layout.fillWidth: true
                text: config.translate("Select services")
            }
            
            Connections {
                target: config
                
                function onAppsModelChanged() {
                    label.text=config.translate("Select services");
                }
            }
            
            ListView {
                id: layoutsView
                Layout.fillWidth: true
                Layout.fillHeight: true
                spacing: Kirigami.Units.largeSpacing*2
                
                model: config.servicesModel
                
                focus: true
                
                QQC2.ScrollBar.vertical: QQC2.ScrollBar {}
            
                delegate:
                    ColumnLayout {
                        
                        RowLayout {
                            spacing: Kirigami.Units.smallSpacing
                            
                            QQC2.CheckBox {
                                icon.name: modelData.iconName
                                icon.width: 32
                                icon.height: 32
                                
                                checked: modelData.checked
                                
                                onToggled: {
                                    modelData.checked=checked;
                                }
                            }
                            QQC2.Label {
                                text: "<b>"+modelData.displayName+"</b>"
                            }
                        }
                        
                        QQC2.Label {
                            text: modelData.translation
                        }
                    }
                }
        }
    }
    
}
