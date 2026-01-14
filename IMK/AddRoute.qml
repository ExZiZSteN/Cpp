import QtQuick
import QtQuick.Controls


Window {
    id: addRouteWindow
    width: 300
    height: 200
    visible: false
    title: "Добавление маршрута"
    Column{
        padding: 20
        spacing: 10
        Text{
            text: "Пункт отправления"
            font.pixelSize: 20
        }
        TextField{
            id: origin
            font.pixelSize: 20
        }
        Text{
            text: "Пункт назначения"
            font.pixelSize: 20
        }
        TextField{
            id: destination
            font.pixelSize: 20
        }
        Row{
            Button{
                text: "Добавить"
                font.pixelSize: 20
                palette.buttonText: "black"
                onClicked: {
                    let ok = db.addRoute(
                            origin.text,
                            destination.text
                            )
                    if (ok){
                        addRouteWindow.close()
                        clearFiled()
                    }
                }
            }
            Button{
                text: "Отмена"
                font.pixelSize: 20
                palette.buttonText: "black"
                onClicked: addRouteWindow.close()
            }
        }
    }
    function clearFiled(){
        origin.text = ""
        destination.text = ""
    }
}
