import QtQuick
import QtQuick.Controls

Window {
    width: 700
    height: 500
    visible: false
    title: "Грузовики"

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
                    { title: "Брэнд", width: 90 },
                    { title: "Модель", width: 90 },
                    { title: "Год", width: 110 },
                    { title: "Грузподемность (тонн)", width: 150 },
                    { title: "Гос номер", width: 120 },
                    { title: "Статус", width: 100 }
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
                    }
                }
            }
        }
        ListView {
            id: trucksList
            width: totalWidth.width
            height: parent.height - 120
            model: db.getTrucks()

            delegate: Rectangle {
                height: 40
                width: parent.width
                border.width: 1
                color: ListView.isCurrentItem
                              ? "#a8d8ff"
                              : (index % 2 === 0 ? "#f2f2f2" : "#ffffff")

                MouseArea {
                    anchors.fill: parent
                    onClicked: trucksList.currentIndex = index

                    onDoubleClicked: {
                        let truck = trucksList.model[index]
                        editTruckWindow.open(truck)
                        editTruckWindow.visible = true
                    }
                }
                Row {
                    spacing: 0

                    Text { text: modelData.brand; width: 90; font.pixelSize: 18}
                    Text { text: modelData.model; width: 90; font.pixelSize: 18 }
                    Text { text: modelData.year; width: 110; font.pixelSize: 18 }
                    Text { text: modelData.capasity_tons; width: 150; font.pixelSize: 18 }
                    Text { text: modelData.plate_number; width: 120; font.pixelSize: 18 }
                    Text { text: modelData.truck_status; width: 100; font.pixelSize: 18 }
                }
            }
        }
        Row{
            spacing: 10
            Button {
                text: "Обновить"
                palette.buttonText: "black"
                onClicked: trucksList.model = db.getTrucks()
                font.pixelSize: 18
            }
            Button{
                text:"Добавить грузовик"
                onClicked: addTruck.visible = true
                palette.buttonText: "black"
                font.pixelSize: 18
            }
            Button{
                text:"Удалить грузовик"
                onClicked: removeTruck.visible = true
                palette.buttonText: "black"
                font.pixelSize: 18
            }
        }
    }
    AddTruck{
        id: addTruck
    }
    RemoveTruck{
        id: removeTruck
    }

    EditTruck{
        id: editTruckWindow
    }
}
