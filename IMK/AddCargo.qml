import QtQuick
import QtQuick.Controls

Window {
    id: addCargo
    width: 650
    height: 500
    title: "Добавление груза"
    visible: false
    Column{
            spacing: 10
            padding: 10
            anchors.fill: parent
            Row{
                spacing: 206
                Text{
                    text: "Описание"
                    font.pixelSize: 16
                }
                TextField{
                    id: description
                    width: 250
                    font.pixelSize: 16
                    maximumLength: 50
                }
            }
            Row{
                spacing: 175
                Text{
                    text: "Вес в тоннах"
                    font.pixelSize: 18
                }
                TextField{
                    id: weightTons
                    width: 150
                    font.pixelSize: 18
                }
            }
            Row{
                spacing: 172
                Text{
                    text :"Отправитель"
                    font.pixelSize: 18
                }
                TextField{
                    id: sender
                    width: 250
                    font.pixelSize: 18
                    maximumLength: 100
                }
            }
            Row{
                spacing: 180
                Text {
                    text:"Получатель"
                    font.pixelSize: 18
                }
                TextField{
                    id: receiver
                    width: 250
                    font.pixelSize: 18
                    maximumLength: 100
                }
            }
            Row{
                spacing: 249
                Text{
                    text:"Тип"
                    font.pixelSize: 18
                }
                ComboBox{
                    id: type
                    model: [
                        "",
                        "Хрупкий",
                        "Твердый",
                        "Опасный",
                        "Скоропортящийся"
                    ]
                    width: 150
                    font.pixelSize: 18
                }
            }
            Row{
                spacing: 227
                Text{
                    text: "Статус"
                    font.pixelSize: 18
                }
                ComboBox{
                    id: status
                    model: [
                        "",
                        "Доставлен",
                        "Не доставлен",
                        "В рейсе",
                    ]
                    width: 150
                    font.pixelSize: 18
                }
            }
        Row{
            Button{
                text: "Добавить"
                palette.buttonText: "black"
                font.pixelSize: 18
                onClicked: {
                    let ok = db.addCargo(
                        description.text,
                        weightTons.text,
                        sender.text,
                        receiver.text,
                        type.currentText,
                        status.currentText
                    )
                    if (ok){
                        editCargo.close()
                        clearFields()
                    }
                }
            }
            Button{
                text: "Отмена"
                palette.buttonText: "black"
                onClicked: editCargo.close()
                font.pixelSize: 18
            }
        }
    }
    function clearFields(){
        description.text = ""
        sender.text = ""
        weightTons.text = ""
        receiver.text = ""
        type.curentIndex = 0
        status.currentIndex = 0
    }
}
