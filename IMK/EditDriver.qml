import QtQuick
import QtQuick.Controls

Window {
    id: editDriver
    width: 450
    height: 500
    title: "Редактирование водителя"
    visible: false
    modality: Qt.ApplicationModal

    property var driverData

    Column{
            spacing: 10
            padding: 10
            anchors.fill: parent
            Row{
                spacing: 206
                Text{
                    text: "Фамилия"
                    font.pixelSize: 16
                }
                TextField{
                    id: surname
                    width: 150
                    font.pixelSize: 16
                }
            }
            Row{
                spacing: 236
                Text{
                    text: "Имя"
                    font.pixelSize: 18
                }
                TextField{
                    id: name
                    width: 150
                    font.pixelSize: 18
                }
            }
            Row{
                spacing: 197
                Text{
                    text :"Отчество"
                    font.pixelSize: 18
                }
                TextField{
                    id: middleName
                    width: 150
                    font.pixelSize: 18
                }
            }
            Row{
                spacing: 20
                Text {
                    text:"Дата рождения (YYYY-MM-DD)"
                    font.pixelSize: 18
                }
                TextField{
                    id: birthDate
                    inputMask: "9999-99-99"
                    width: 150
                    font.pixelSize: 18
                }
            }
            Row{
                spacing: 134
                Text{
                    text:"Номер телефона"
                    font.pixelSize: 18
                }
                TextField{
                    id: phone
                    inputMask: "+9(999)999-99-99"
                    width: 150
                    font.pixelSize: 18
                }
            }
            Row{
                spacing: 87
                Text {
                    text:"Номер удостоверения"
                    font.pixelSize: 18
                }
                TextField{
                    id: license
                    palette.button: "white"
                    width: 150
                    font.pixelSize: 18
                }
            }
            Row{
                spacing: 219
                Text{
                    text: "Статус"
                    font.pixelSize: 18
                }
                ComboBox{
                    id: status
                    model: [
                        "Свободен",
                        "В отпуске",
                        "В рейсе",
                        "На больничном"
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
                    let phoneN = phone.text
                    let actualphone = ""
                    for (let i = 0; i < phoneN.length; i++){
                        if (phoneN[i] >= '0' && phoneN[i] <= '9'){
                            actualphone += phoneN[i]
                        }
                    }
                    let ok = db.updateDriver(
                        driverData.license_number,
                        surname.text,
                        name.text,
                        middleName.text,
                        birthDate.text,
                        actualphone,
                        status.currentText
                    )
                    if (ok){
                        editDriver.close()
                    }
                }
            }
            Button{
                text: "Отмена"
                palette.buttonText: "black"
                onClicked: editDriver.close()
                font.pixelSize: 18
            }

            Button{
                font.pixelSize: 18
                text: "Удалить водителя"
                palette.buttonText: "black"
                onClicked:{
                    let phoneN = phone.text
                    let actualphone = ""
                    for (let i = 0; i < phoneN.length; i++){
                        if (phoneN[i] >= '0' && phoneN[i] <= '9'){
                            actualphone += phoneN[i]
                        }
                    }
                    let ok = db.removeDriver(
                            surname.text,
                            name.text,
                            actualphone
                            )
                    if (ok){
                        editDriver.close()
                    }
                }
            }
        }
    }
    function open(driver) {
        driverData = driver
        surname.text = driver.surname
        name.text = driver.name
        birthDate.text = Qt.formatDate(driver.birth_date,"yyyy-MM-dd")
        middleName.text = driver.middle_name
        license.text = driver.license_number
        phone.text = driver.phone_number
        status.currentValue = driver.driver_status
    }
}
