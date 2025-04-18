import QtQuick 2.6
import QtQuick.Layouts 1.1
import QtQuick.Controls 2.6 as QQC2
import org.kde.plasma.core 2.0 as PlasmaCore
import org.kde.kirigami 2.5 as Kirigami

QQC2.Pane
{
    id:paneContainer
    width: parent.width
    height: parent.height

    ColumnLayout {
        Layout.fillWidth: true
        Layout.fillHeight: true
        spacing: Kirigami.Units.mediumSpacing
        anchors.fill: parent
        QQC2.Label {
            id: label
            Layout.fillWidth: true
            text: config.translate("EDUCATION LEVEL")
            font.bold:true
        }
        QQC2.Label {
            id: explanation
            Layout.fillWidth: true
            text: config.translate("Select your educational level, and LliureX 25 will be configured with the most suitable software for you.")
            wrapMode:Text.WordWrap
        }

        Connections {
            target: config
            
            function onAppsModelChanged() {
                label.text=config.translate("EDUCATION LEVEL");
            }
        }
        Item{
            id:gridContainer
            width:parent.width
            Layout.minimumHeight:parent.height/2
            Layout.fillHeight:true
            Layout.leftMargin:15
            Layout.rightMargin:15
            Layout.alignment:Qt.AlignHCenter

            GridView{
                id:layoutsView
                width:gridContainer.width
                height:gridContainer.height
                cellWidth:180
                cellHeight:210
                model: config.appsModel
                focus: true
                QQC2.ScrollBar.vertical: QQC2.ScrollBar {}
                delegate:appDelegate

                Component{
                    id:appDelegate
                    Item{
                        id:base
                        width:layoutsView.cellWidth
                        height:layoutsView.cellHeight
                        MouseArea{
                            id:mouseContainer
                            anchors.fill:parent
                            hoverEnabled:true
                            onEntered:{
                                rectContainer.border.color="#add8e6"
                            }
                            onExited:{
                                rectContainer.border.color="transparent"
                            }
                            onClicked:{
                                modelData.checked=!checked;
                            }
                        }
                        Rectangle{
                            id:rectContainer
                            color:checked?"#87cefa":"#c0c0c0"
                            radius:10
                            border.color:"transparent"
                            border.width:5
                            anchors{
                                fill:parent
                                margins:10
                                centerIn:parent
                            }
                            Column{
                                spacing: Kirigami.Units.mediumSpacing*2
                                anchors{
                                    margins:15
                                    centerIn:parent
                                }
                                Image{
                                    source:modelData.iconName
                                    width:80
                                    height:80
                                    fillMode:Image.PreserveAspectFit
                                    anchors.horizontalCenter:parent.horizontalCenter

                                }
                                Text{
                                    width:rectContainer.width-20
                                    text:modelData.translation
                                    horizontalAlignment:Text.AlignHCenter
                                    wrapMode:Text.WordWrap
                                }
                            }
                        }

                    }

                }

            }
           
        }
    }
  
}
