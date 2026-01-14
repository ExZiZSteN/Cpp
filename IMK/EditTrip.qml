import QtQuick
import QtQuick.Controls

Window {
    id: addTripWindow
    width: 400
    height: 650
    title: "Обновить рейс"
    visible: false
    modality: Qt.ApplicationModal

    property var tripData
    Column {
        anchors.fill: parent
        spacing: 10
        padding: 10

        ComboBox {
            id: driverBox
            model: db.getDriversForTrip(tripData.driver_id)
            textRole: "text"
            valueRole: "id"
            width: parent.width - 20
            font.pixelSize: 20
        }

        ComboBox {
            id: truckBox
            model: db.getTrucksForTrip(tripData.truck_id)
            textRole: "text"
            valueRole: "id"
            width: parent.width - 20
            font.pixelSize: 20
        }

        ComboBox {
            id: cargoBox
            model: db.getCargosForTrip(tripData.cargo_id)
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
            text: "Дата выезда фактическая (yyyy-MM-dd)"
            font.pixelSize: 20
        }
        TextField {
            id: departureDateactual
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
        Text{
            text: "Дата приезда фактическая (yyyy-MM-dd)"
            font.pixelSize: 20
        }
        TextField {
            id: arrivalDateactual
            inputMask: "9999-99-99"
            width: parent.width - 20
            font.pixelSize: 20
        }
        Text{
            text: "Статус"
            font.pixelSize: 20
        }
        ComboBox{
            id: status
            model: [
                "Выполняется",
                "Запланирован",
                "Завершен",
            ]
            width: 150
            font.pixelSize: 18
        }

        Row{
            spacing: 20
            Button {
                text: "Обновить"
                onClicked: {
                    db.updateTrip(
                        driverBox.model[driverBox.currentIndex].id,
                        truckBox.model[truckBox.currentIndex].id,
                        cargoBox.model[cargoBox.currentIndex].id,
                        routeBox.model[routeBox.currentIndex].id,
                        departureDate.text,
                        arrivalDate.text,
                        departureDateactual.text,
                        arrivalDateactual.text,
                        status.currentValue,
                        tripData.id
                    )
                    db.changeOnUpdateTrip(
                        tripData.driver_id,
                        driverBox.model[driverBox.currentIndex].id,
                        tripData.truck_id,
                        truckBox.model[truckBox.currentIndex].id,
                        tripData.cargo_id,
                        cargoBox.model[cargoBox.currentIndex].id,
                        tripData.trip_status,
                        status.currentText
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
    function open(trip){
        tripData = trip
        driverBox.model = db.getDriversForTrip(trip.driver_id)
        truckBox.model = db.getTrucksForTrip(trip.truck_id)
        cargoBox.model = db.getCargosForTrip(trip.cargo_id)
        routeBox.model = db.getRoutesForTrip()
        driverBox.currentValue = trip.driver_id
        truckBox.currentValue = trip.truck_id
        cargoBox.currentValue = trip.cargo_id
        routeBox.currentValue = trip.route_id
        departureDate.text = Qt.formatDate(trip.departure_date,"yyyy-MM-dd")
        arrivalDate.text =  Qt.formatDate(trip.arrival_date,"yyyy-MM-dd")
        status.currentValue = trip.trip_status
        visible = true
    }
}
