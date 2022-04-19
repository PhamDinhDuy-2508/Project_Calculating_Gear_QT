import QtQuick 2.0
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.3
import QtQml.Models 2.2
import QtQuick.Controls 1.4

Item {
    property alias rectangle: rectangle
    Rectangle{
        id : rec_main
        x: 0
        y: 0
        width: 974
        height:  550
        color:  Qt.rgba(255, 206, 255, 0.0)
        border.width: 0
        transformOrigin: Item.Center
        Rectangle{
            id : button1
            width: 159
            height: 50
            color:  Qt.rgba(255,123, 255, 0.4)
            anchors.bottom:  rec_main.bottom
            radius:10
            Text {
                id: name
                text: qsTr("<-")
                anchors.horizontalCenter: button1.horizontalCenter
                anchors.verticalCenter:  button1.verticalCenter
            }
            MouseArea{
                id: mouse_area1
                anchors.rightMargin: 0
                anchors.fill: parent
                hoverEnabled  :  true
                acceptedButtons: Qt.LeftButton | Qt.RightButton
                cursorShape: Qt.PointingHandCursor
                onClicked: {
                    pop_function_page() ;
                }
                onEntered: {
                    parent.color = Qt.rgba(255, 206, 255, 0.2)
                }
                onExited: {
                    parent.color =Qt.rgba(255, 123, 255, 0.4)
                }
            }
        }
        Rectangle {
            id: rectangle
            x: 8
            y: 56
            width: 160
            height: 43
            color:  "#16873c"
            radius: 10
            border.color: "#1ad88a"
            clip: true
            border.width: 0
            MouseArea {
                id: mouseArea
                x: 0
                y: 0
                width: 160
                height: 43
                anchors.fill: parent
                hoverEnabled  :  true
                acceptedButtons: Qt.LeftButton | Qt.RightButton
                cursorShape: Qt.PointingHandCursor
                onClicked: {
                    stackView.pop()
                   stackView.push(material)
                }

                onEntered: {
                   parent.color ="#16573c"
                }
                onExited: {
                     parent.color ="#16873c"
                }
            }
            Image {
                id: image
                x: 129
                y: 0
                width: 31
                height: 43
                fillMode: Image.PreserveAspectFit
                source: "qrc:/../../dowload/Anh_cua_app+do_an/Add.png"

            }
            Text {
                id: element
                x: 0
                y: 0
                width: 160
                height: 43
                color: "#e7e0e0"
                text: qsTr("  chọn vật liệu ")
                font.pointSize: 12
                font.wordSpacing: 0.3
                font.bold: true
                font.family: "Times New Roman"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignLeft
            }
        }
        Rectangle {
            id: rectangle1
            x: 8
            y: 140
            width: 160
            height: 43
            color: "#16873c"
            radius: 10
            border.width: 0
            clip: true

            MouseArea {
                id: mouseArea1
                x: 0
                y: 0
                width: 160
                height: 43
                anchors.rightMargin: -5
                anchors.bottomMargin: 3
                anchors.leftMargin: 5
                anchors.topMargin: -3
                anchors.fill: parent
                hoverEnabled: true
                acceptedButtons: Qt.LeftButton | Qt.RightButton
                cursorShape: Qt.PointingHandCursor
            }

            Image {
                id: image1
                x: 129
                y: 0
                width: 31
                height: 43
                source: "qrc:/../../dowload/Anh_cua_app+do_an/Add.png"
                fillMode: Image.PreserveAspectFit
            }

            Text {
                id: element1
                x: 0
                y: 0
                width: 160
                height: 43
                color: "#e7e0e0"
                text: "Thông Số của Bộ Truyền"
                font.bold: true
                font.wordSpacing: 0.3
                font.family: "Times New Roman"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignLeft
                font.pointSize: 9
            }
        }

        Rectangle {
            id: rectangle2
            x: 8
            y: 220
            width: 160
            height: 43
            color: "#16873c"
            radius: 10
            border.width: 0
            clip: true

            MouseArea {
                id: mouseArea2
                x: 0
                y: 0
                width: 160
                height: 43
                anchors.topMargin: 0
                anchors.fill: parent
                hoverEnabled: true
                anchors.leftMargin: 5
                anchors.rightMargin: -5
                acceptedButtons: Qt.LeftButton | Qt.RightButton
                anchors.bottomMargin: 0
                cursorShape: Qt.PointingHandCursor
            }

            Image {
                id: image2
                x: 129
                y: 3
                width: 31
                height: 43
                source: "qrc:/../../dowload/Anh_cua_app+do_an/Add.png"
                fillMode: Image.PreserveAspectFit
            }

            Text {
                id: element2
                x: 0
                y: 0
                width: 160
                height: 43
                color: "#e7e0e0"
                text: "Thông Số ăn khớp"
                font.bold: true
                font.wordSpacing: 0.3
                font.family: "Times New Roman"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignLeft
                font.pointSize: 12
            }
        }        
        Rectangle {
            id: rectangle3
            x: 174
            y: 8
            width: 790
            height: 542
            color:Qt.rgba(255, 123, 255, 0.0)
            StackView {
                id: stackView
                x: 0
                y: 0
                width: 725
                height: 542
                initialItem: info
            }
            Component{
                id:info
                Info_page_Spur{}
            }
            Component{
                id : material
                Choice_material{}
            }
        }
    }    
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:800}
}
##^##*/
