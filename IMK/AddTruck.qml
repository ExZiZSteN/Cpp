import QtQuick
import QtQuick.Controls

Window {
    id: addTruckWindow
    width: 450
    height: 500
    title: "Добавить грузовик"
    visible: false

    Column{
            spacing: 10
            padding: 10
            anchors.fill: parent
            Row{
                spacing: 206
                Text{
                    text: "Брэнд"
                    font.pixelSize: 16
                }
                TextField{
                    id: brand
                    width: 150
                    font.pixelSize: 16
                }
            }
            Row{
                spacing: 186
                Text{
                    text: "Модель"
                    font.pixelSize: 18
                }
                TextField{
                    id: model
                    width: 150
                    font.pixelSize: 18
                }
            }
            Row{
                spacing: 147
                Text{
                    text : "Год выпуска"
                    font.pixelSize: 18
                }
                TextField{
                    id: year
                    width: 150
                    font.pixelSize: 18
                }
            }

            Row{
                spacing: 40
                Text{
                    text:"Грузоподъемность (тонн)"
                    font.pixelSize: 18
                }
                TextField{
                    id: capasityTons
                    width: 150
                    font.pixelSize: 18
                }
            }
            Row{
                spacing: 163
                Text {
                    text:"Гос номер"
                    font.pixelSize: 18
                }
                TextField{
                    id: plateNumber
                    palette.button: "white"
                    width: 150
                    font.pixelSize: 18
                }
            }
            Row{
                spacing: 197
                Text{
                    text: "Статус"
                    font.pixelSize: 18
                }
                ComboBox{
                    id: status
                    model: [
                        "",
                        "Свободен",
                        "В рейсе",
                        "На ремонте"
                    ]
                    width: 150
                    font.pixelSize: 18
                }
            }
        Row{
            Button{
                text: "добавить"
                palette.buttonText: "black"
                font.pixelSize: 18
                onClicked: {
                    let ok = db.addTruck(
                        brand.text,
                        model.text,
                        year.text,
                        capasityTons.text,
                        plateNumber.text,
                        status.currentText
                    )
                    if (ok){
                        addTruckWindow.close()
                        clearFields()
                    }
                }
            }
            Button{
                text: "Отмена"
                palette.buttonText: "black"
                onClicked: addTruckWindow.close()
                font.pixelSize: 18
            }
        }

    }
    function clearFields(){
        brand.text = ""
        model.text = ""
        year.text = ""
        capasityTons.text = ""
        plateNumber.text = ""
        status.currentIndex = 0
    }
}
