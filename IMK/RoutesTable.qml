import QtQuick
import QtQuick.Controls

Window {
    width: 300
    height: 500
    visible: false
    title: "Маршруты"
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
                    { title: "Брэнд", width: 100 },
                    { title: "Модель", width: 100 },
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
            id: routesList
            width: totalWidth.width
            height: parent.height - 120
            model: db.getRoutes()

            delegate: Rectangle {
                height: 40
                width: parent.width
                border.width: 1
                color: ListView.isCurrentItem
                              ? "#a8d8ff"
                              : (index % 2 === 0 ? "#f2f2f2" : "#ffffff")

                MouseArea {
                    anchors.fill: parent
                    onClicked: routesList.currentIndex = index

                    onDoubleClicked: {
                        let route = routesList.model[index]
                        removeRoutes.open(route);
                    }
                }
                Row {
                    spacing: 20

                    Text { text: modelData.origin; width: 100; font.pixelSize: 18}
                    Text { text: modelData.destination; width: 100; font.pixelSize: 18 }}
                }
            }
            Row{
                spacing: 10
                Button {
                    text: "Обновить"
                    palette.buttonText: "black"
                    onClicked: routesList.model = db.getRoutes()
                    font.pixelSize: 18
                }
                Button{
                    text: "Добавить"
                    palette.buttonText: "black"
                    font.pixelSize: 18
                    onClicked: addRoute.visible = true
                }
                Button{
                    text: "Удалить"
                    palette.buttonText: "black"
                    font.pixelSize: 18
                    onClicked: removeRoutes.visible = true
                }
            }
        }
        AddRoute{
            id: addRoute
        }
        RemoveRoutes{
            id: removeRoutes
        }
    }
