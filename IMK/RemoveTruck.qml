import QtQuick
import QtQuick.Controls

Window{
    id: removeTruck
    visible: false
    width: 300
    height: 200
    title: "Удалить грузовик"
    Column{
        spacing: 10
        padding: 10
        anchors.fill: parent
        Row{
            spacing: 50
            Text {
                text: "Гос номер"
                font.pixelSize: 18
            }
            TextField{
                id: plateNumber
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
                    let ok = db.removeTruck(
                            plateNumber.text
                            )
                    if (ok){
                        removeTruck.close()
                        clearFields()
                    }
                }
            }
            Button{
                font.pixelSize: 18
                text: "Отмена"
                palette.buttonText: "black"
                onClicked: removeTruck.close()
            }
        }
    }
    function clearFields()
    {
        origin.text = ""
        destination.text = ""
    }
}
