import QtQuick
import QtQuick.Controls

Window {
    width: totalWidth.width + 50
    height: 500
    visible: false
    title: "Груз"
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
                    { title: "Описаник", width: 200 },
                    { title: "Вес (тонн)", width: 100 },
                    { title: "Отправитель", width: 250 },
                    { title: "Получатель", width: 250 },
                    { title: "Тип", width: 160 },
                    { title: "Статус", width: 170 }
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
            id: cargosList
            width: totalWidth.width
            height: parent.height - 120
            model: db.getCargos()

            delegate: Rectangle {
                height: 40
                width: parent.width
                border.width: 1
                color: ListView.isCurrentItem
                              ? "#a8d8ff"
                              : (index % 2 === 0 ? "#f2f2f2" : "#ffffff")

                MouseArea {
                    anchors.fill: parent
                    onClicked: cargosList.currentIndex = index

                    onDoubleClicked: {
                        let cargo = cargosList.model[index]
                        editCargoWindow.open(cargo)
                        editCargoWindow.visible = true
                    }
                }
                Row {
                    spacing: 20

                    Text { text: modelData.description; width: 200; font.pixelSize: 18}
                    Text { text: modelData.weight_tons; width: 50; font.pixelSize: 18 }
                    Text { text: modelData.sender; width: 250; font.pixelSize: 18 }
                    Text { text: modelData.receiver; width: 250; font.pixelSize: 18 }
                    Text { text: modelData.type; width: 160; font.pixelSize: 18 }
                    Text { text: modelData.cargo_status; width: 100; font.pixelSize: 18 }
                }
            }
        }
        Row{
            spacing: 10
            Button {
                text: "Обновить"
                palette.buttonText: "black"
                onClicked: cargosList.model = db.getCargos()
                font.pixelSize: 18
            }
            Button{
                text: "Добавить Груз"
                palette.buttonText: "black"
                font.pixelSize: 18
                onClicked: addCargo.visible = true
            }
        }
    }
    EditCargo{
        id: editCargoWindow
    }
    AddCargo{
        id: addCargo
    }
    function update(){
        cargosList.model = db.getCargos()
    }
}
