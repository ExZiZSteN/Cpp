import QtQuick
import QtQuick.Controls
Window{
    id: removeDriver
    visible: false
    width: 400
    height: 300
    title: "Удалить водителя"
    Column{
        spacing: 10
        padding: 10
        anchors.fill: parent
        Row{
            spacing: 115
            Text {
                text: "Фамилия"
                font.pixelSize: 18
            }
            TextField{
                id: surname
                width: 150
                font.pixelSize: 18
            }
        }
        Row{
            spacing: 152
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
            spacing: 50
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
            spacing: 10
            Button{
                font.pixelSize: 18
                text: "Удалить"
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
                        removeDriver.close()
                        clearFields()
                    }
                }
            }
            Button{
                font.pixelSize: 18
                text: "Отмена"
                palette.buttonText: "black"
                onClicked: removeDriver.close()
            }
        }
    }
    function clearFields()
    {
        surname.text = ""
        name.text = ""
        phone.text = ""
    }
}
