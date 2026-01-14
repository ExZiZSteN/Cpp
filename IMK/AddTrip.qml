import QtQuick
import QtQuick.Controls

Window {
    id: addTripWindow
    width: 400
    height: 500
    title: "Добавить поездку"
    visible: false
    modality: Qt.ApplicationModal

    Column {
        anchors.fill: parent
        spacing: 10
        padding: 10

        ComboBox {
            id: driverBox
            model: db.getDriversForTrip()
            textRole: "text"
            valueRole: "id"
            width: parent.width - 20
            font.pixelSize: 20
        }

        ComboBox {
            id: truckBox
            model: db.getTrucksForTrip()
            textRole: "text"
            valueRole: "id"
            width: parent.width - 20
            font.pixelSize: 20
        }

        ComboBox {
            id: cargoBox
            model: db.getCargosForTrip()
            textRole: "text"
            valueRole: "id"
            width: parent.width - 20
            font.pixelSize: 20
        }

        ComboBox {
            id: routeBox
            model: db.getRoutesForTrip()
            textRole: "text"
            valueRole: "id"
            width: parent.width - 20
            font.pixelSize: 20
        }

        Text{
            text: "Дата выезда (yyyy-MM-dd)"
            font.pixelSize: 20
        }
        TextField {
            id: departureDate
            width: parent.width - 20
            inputMask: "9999-99-99"
            font.pixelSize: 20
        }
        Text{
            text: "Дата приезда (yyyy-MM-dd)"
            font.pixelSize: 20
        }
        TextField {
            id: arrivalDate
            inputMask: "9999-99-99"
            width: parent.width - 20
            font.pixelSize: 20
        }
        Row{
            Button {
                text: "Добавить"
                onClicked: {
                    db.addTrip(
                        driverBox.currentValue,
                        truckBox.currentValue,
                        cargoBox.currentValue,
                        routeBox.currentValue,
                        departureDate.text,
                        arrivalDate.text
                    )
                    addTripWindow.close()
                }
                font.pixelSize: 20
                palette.buttonText: "black"
            }
            Button {
                text: "Отмена"
                font.pixelSize: 20
                onClicked: addTripWindow.close
                palette.buttonText: "black"
            }
        }
    }
    function open(){
        driverBox.model = db.getDriversForTrip()
        truckBox.model = db.getTrucksForTrip()
        cargoBox.model = db.getCargosForTrip()
        routeBox.model = db.getRoutesForTrip()
        visible = true
    }
}
