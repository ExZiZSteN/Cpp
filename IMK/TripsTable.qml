import QtQuick
import QtQuick.Controls

Window {
    id: tripsWindow
    width: totalWidth.width + 50
    height: 500
    visible: false
    title: "Рейсы"

    Column {
        anchors.fill: parent
        spacing: 10
        padding: 20
        Row {
            id: totalWidth
            height: 40
            spacing: 0

            Repeater {
                model: [
                    { title: "Водитель", width: 250 },
                    { title: "Грузовик", width: 180 },
                    { title: "Груз", width: 180 },
                    { title: "Маршрут", width: 180 },
                    { title: "План выезд", width: 110 },
                    { title: "Факт выезд", width: 110 },
                    { title: "План приб.", width: 110 },
                    { title: "Факт приб.", width: 110 },
                    { title: "Статус", width: 110 }
                ]

                delegate: Rectangle {
                    width: modelData.width
                    height: 40
                    color: "#dcdcdc"
                    border.width: 1

                    Text {
                        anchors.centerIn: parent
                        text: modelData.title
                        font.bold: true
                        font.pixelSize: 16
                    }
                }
            }
        }

        ListView {
            id: tripsList
            width: totalWidth.width
            height: parent.height - 120
            model: db.getTrips()

            delegate: Rectangle {
                width: tripsList.width
                height: 40
                border.width: 1

                color: ListView.isCurrentItem
                       ? "#a8d8ff"
                       : (index % 2 === 0 ? "#f2f2f2" : "#ffffff")

                MouseArea {
                    anchors.fill: parent
                    onClicked: tripsList.currentIndex = index
                    onDoubleClicked: {
                        let trip = tripsList.model[index]
                        editTripWindow.open(trip)
                        editTripWindow.visible = true
                    }
                }

                Row {
                    spacing: 0

                    Text { text: modelData.driver_name; width: 250;font.pixelSize: 16 }
                    Text { text: modelData.truck_plate; width: 180;font.pixelSize: 16 }
                    Text { text: modelData.cargo_description; width: 180;font.pixelSize: 16 }
                    Text { text: modelData.route_name; width: 180;font.pixelSize: 16 }

                    Text {
                        width: 110
                        text: Qt.formatDate(modelData.departure_date, "yyyy-MM-dd")
                        font.pixelSize: 16
                    }

                    Text {
                        width: 110
                        text: modelData.departure_date_actual
                              ? Qt.formatDate(modelData.departure_date_actual, "yyyy-MM-dd")
                              : "-"
                        font.pixelSize: 16
                    }

                    Text {
                        width: 110
                        text: Qt.formatDate(modelData.arrival_date, "yyyy-MM-dd")
                        font.pixelSize: 16
                    }

                    Text {
                        width: 110
                        text: modelData.arrival_date_actual
                              ? Qt.formatDate(modelData.arrival_date_actual, "yyyy-MM-dd")
                              : "-"
                        font.pixelSize: 16
                    }

                    Text { text: modelData.trip_status; width: 110; font.pixelSize: 16 }
                }
            }
        }
        Row{
            spacing: 20
            Button {
                text: "Обновить"
                palette.buttonText: "black"
                onClicked: tripsList.model = db.getTrips()
                font.pixelSize: 16
            }
            Button{
                text: "Запланировать рейс"
                palette.buttonText: "black"
                onClicked: addTrip.open()
                font.pixelSize: 16
            }
        }
    }
    AddTrip{
        id:addTrip
    }
    EditTrip{
        id: editTripWindow
    }
}
