import QtQuick
import QtQuick.Controls


Window {
    width: 300
    height: 480
    visible: true
    title: qsTr("База данных Дальнобойщиков")
    color: "white"

    Column{
        padding: 20
        spacing: 20
        anchors.centerIn: parent
        Button{
            id: btn1
            width: 200
            height: 40
            hoverEnabled: false
            background: Rectangle{
                color: btn1.down ? "#aaeafa" : "#f5f9fa"
                border.color: "black"
                radius: 5
                Text{
                    anchors.centerIn: parent
                    text: "Показать водителей"
                    font.pixelSize: 18
                    font.family: "SansSerif"
                }
            }
            onClicked: driversTable.visible = true
        }
        Button{
            id: btn2
            width: 200
            height: 40
            hoverEnabled: false
            background: Rectangle{
                color: btn2.down ? "#aaeafa" : "#f5f9fa"
                border.color: "black"
                radius: 5
                Text{
                    anchors.centerIn: parent
                    text: "Показать грузы"
                    font.pixelSize: 18
                    font.family: "SansSerif"
                }
            }
            onClicked: cargosTable.visible = true
        }

        Button{
            id: btn3
            width: 200
            height: 40
            hoverEnabled: false
            background: Rectangle{
                color: btn3.down ? "#aaeafa" : "#f5f9fa"
                border.color: "black"
                radius: 5
                Text{
                    anchors.centerIn: parent
                    text: "Показать маршруты"
                    font.pixelSize: 18
                    font.family: "SansSerif"
                }
            }
            onClicked: routesTable.visible = true
        }
        Button{
            id: btn4
            width: 200
            height: 40
            hoverEnabled: false
            background: Rectangle{
                color: btn4.down ? "#aaeafa" : "#f5f9fa"
                border.color: "black"
                radius: 5
                Text{
                    anchors.centerIn: parent
                    text: "Показать грузовики"
                    font.pixelSize: 18
                    font.family: "SansSerif"
                }
            }
            onClicked: trucksTable.visible = true
        }
        Button{
            id: btn5
            width: 200
            height: 40
            hoverEnabled: false
            background: Rectangle{
                color: btn5.down ? "#aaeafa" : "#f5f9fa"
                border.color: "black"
                radius: 5
                Text{
                    anchors.centerIn: parent
                    text: "Показать рейсы"
                    font.pixelSize: 18
                    font.family: "SansSerif"
                }
            }
            onClicked: tripsTable.visible = true
        }
    }
    DriversTable{
        id: driversTable
    }
    CargosTable{
        id: cargosTable
    }
    RoutesTable{
        id: routesTable
    }
    TrucksTable{
        id: trucksTable
    }
    TripsTable{
        id: tripsTable
    }
}
