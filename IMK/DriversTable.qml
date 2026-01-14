import QtQuick
import QtQuick.Controls

Window {
    width: 1000
    height: 500
    visible: false
    title: "Водители"
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
                    { title: "Фамилия", width: 90 },
                    { title: "Имя", width: 90 },
                    { title: "Отчество", width: 110 },
                    { title: "Дата рождения", width: 150 },
                    { title: "Номер телефона", width: 150 },
                    { title: "Номер удостоверения", width: 150 },
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
            id: driversList
            width: totalWidth.width
            height: parent.height - 120
            model: db.getDrivers()

            delegate: Rectangle {
                height: 40
                width: parent.width
                border.width: 1
                color: ListView.isCurrentItem
                              ? "#a8d8ff"
                              : (index % 2 === 0 ? "#f2f2f2" : "#ffffff")

                MouseArea {
                    anchors.fill: parent
                    onClicked: driversList.currentIndex = index

                    onDoubleClicked: {
                        let driver = driversList.model[index]
                        editDriverWindow.open(driver)
                        editDriverWindow.visible = true
                    }
                }
                Row {
                    spacing: 10

                    Text { text: modelData.surname; width: 90; font.pixelSize: 18}
                    Text { text: modelData.name; width: 90; font.pixelSize: 18 }
                    Text { text: modelData.middle_name; width: 110; font.pixelSize: 18 }
                    Text { text: Qt.formatDate(modelData.birth_date,"yyyy-MM-dd"); width: 150; font.pixelSize: 18 }
                    Text { text: modelData.phone_number; width: 150; font.pixelSize: 18 }
                    Text { text: modelData.license_number; width: 120; font.pixelSize: 18 }
                    Text { text: modelData.driver_status; width: 100; font.pixelSize: 18 }
                }
            }
        }
        Row{
            spacing: 10
            Button {
                text: "Обновить"
                palette.buttonText: "black"
                onClicked: driversList.model = db.getDrivers()
                font.pixelSize: 18
            }
            Button{
                text:"Добавить водителя"
                onClicked: addDriver.visible = true
                palette.buttonText: "black"
                font.pixelSize: 18
            }
            Button{
                text:"Удалить водителя"
                onClicked: removeDriver.visible = true
                palette.buttonText: "black"
                font.pixelSize: 18
            }
        }
    }
    AddDriver{
        id: addDriver
    }
    RemoveDriver{
        id: removeDriver
    }

    EditDriver{
        id: editDriverWindow
    }
}
