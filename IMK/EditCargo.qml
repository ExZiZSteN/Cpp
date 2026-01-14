import QtQuick
import QtQuick.Controls

Window {
    id: editCargo
    width: 650
    height: 400
    title: "Редактирование груза"
    visible: false
    modality: Qt.ApplicationModal

    property var cargoData

    Column{
            spacing: 20
            padding: 20
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
                    width: 250
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
                        "Хрупкий",
                        "Твердый",
                        "Опасный",
                        "Скоропортящиеся"
                    ]
                    width: 250
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
                        "В пути",
                    ]
                    width: 250
                    font.pixelSize: 18
                }
            }
        Row{
            spacing: 20
            Button{
                text: "Сохранить"
                palette.buttonText: "black"
                font.pixelSize: 18
                onClicked: {
                    let ok = db.updateCargo(
                        cargoData.description,
                        cargoData.sender,
                        weightTons.text,
                        receiver.text,
                        type.currentText,
                        status.currentText
                    )
                    if (ok){
                        editCargo.close()
                    }
                }
            }
            Button{
                text: "Отмена"
                palette.buttonText: "black"
                onClicked: editCargo.close()
                font.pixelSize: 18
            }
            Button{
                font.pixelSize: 18
                text: "Удалить груз"
                palette.buttonText: "black"
                onClicked:{

                    let ok = db.removeCargo(
                            cargoData.description,
                            cargoData.sender
                            )
                    if (ok){
                        editCargo.close()
                    }
                }
            }
        }
    }
    function open(cargo) {
        cargoData = cargo
        description.text = cargo.description
        weightTons.text = cargo.weight_tons
        sender.text = cargo.sender
        receiver.text = cargo.receiver
        type.currentValue = cargo.type
        status.currentValue = cargo.cargo_status
    }
}
