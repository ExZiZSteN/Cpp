import QtQuick
import QtQuick.Controls

Window {
    id: editTruck
    width: 450
    height: 350
    title: "Редактирование грузовика"
    visible: false
    modality: Qt.ApplicationModal

    property var truckData

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
                        "Свободен",
                        "В рейсе",
                        "На ремонте"
                    ]
                    width: 150
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
                    let ok = db.updateTuck(
                        truckData.plate_number,
                        brand.text,
                        model.text,
                        year.text,
                        capasityTons.text,
                        status.currentText
                    )
                    if (ok){
                        editTruck.close()
                    }
                }
            }
            Button{
                text: "Отмена"
                palette.buttonText: "black"
                onClicked: editTruck.close()
                font.pixelSize: 18
            }
            Button{
                font.pixelSize: 18
                text: "Удалить грузовик"
                palette.buttonText: "black"
                onClicked:{
                    let ok = db.removeTruck(
                            plateNumber.text
                            )
                    if (ok){
                        editTruck.close()
                    }
                }
            }
        }
    }
    function open(truck) {
        truckData = truck
        brand.text = truck.brand
        model.text = truck.model
        capasityTons.text = truck.capasity_tons
        year.text = truck.year
        plateNumber.text = truck.plate_number
        status.currentValue = truck.truck_status
    }
}
