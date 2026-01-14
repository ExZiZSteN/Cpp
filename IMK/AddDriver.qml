import QtQuick
import QtQuick.Controls

Window{
    id: addDriver
    title: "Добавление водителя"
    visible: false
    height: 350
    width: 500
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
                        "",
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
            spacing: 10

            Button{
                text: "Добавить"
                font.pixelSize: 18
                palette.buttonText: "black"
                onClicked: {
                    let phoneN = phone.text
                    let actualphone = ""
                    for (let i = 0; i < phoneN.length; i++){
                        if (phoneN[i] >= '0' && phoneN[i] <= '9'){
                            actualphone += phoneN[i]
                        }
                    }
                    console.log(actualphone)
                    let ok = db.addDriver(
                            surname.text,
                            name.text,
                            middleName.text,
                            birthDate.text,
                            actualphone,
                            license.text,
                            status.currentText
                            )
                    if (ok){
                        addDriver.close()
                        clearFields()
                    }
                }
            }
            Button{
                text: "Отмена"
                font.pixelSize: 18
                palette.buttonText: "black"
                onClicked: addDriverDialog.close()
            }
        }
    }

    function clearFields(){
        surname.text = ""
        name.text = ""
        middleName.text = ""
        birthDate.text = ""
        phone.text = ""
        license.text = ""
        status.currentIndex = 0
    }
}

