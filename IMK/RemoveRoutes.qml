import QtQuick
import QtQuick.Controls

Window{
    id: removeRoute
    visible: false
    width: 400
    height: 300
    title: "Удалить маршрут"
    Column{
        spacing: 10
        padding: 10
        anchors.fill: parent
        Row{
            spacing: 50
            Text {
                text: "Пункт отправления"
                font.pixelSize: 18
            }
            TextField{
                id: origin
                width: 150
                font.pixelSize: 18
            }
        }
        Row{
            spacing: 60
            Text{
                text: "Пункт назначения"
                font.pixelSize: 18
            }
            TextField{
                id: destination
                width: 150
                font.pixelSize: 18
            }
        }
        Row{
            spacing: 10
            Button{
                font.pixelSize: 18
                text: "Удалить"
                palette.buttonText: "black"
                onClicked:{
                    let ok = db.removeRoute(
                            origin.text,
                            destination.text
                            )
                    if (ok){
                        removeRoute.close()
                        clearFields()
                    }
                }
            }
            Button{
                font.pixelSize: 18
                text: "Отмена"
                palette.buttonText: "black"
                onClicked: removeRoute.close()
            }
        }
    }
    function clearFields()
    {
        origin.text = ""
        destination.text = ""
    }
    function open(route){
        origin.text = route.origin
        destination.text = route.destination
        visible = true
    }
}
