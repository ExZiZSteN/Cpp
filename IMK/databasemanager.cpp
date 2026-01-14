#include "databasemanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDate>

DatabaseManager::DatabaseManager(QObject *parent) : QObject(parent) {}

bool DatabaseManager::connectToDb()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setDatabaseName("DB");
    db.setUserName("postgres");
    db.setPort(5432);
    db.setPassword("1234");

    if (!db.open()){
        qDebug() << db.lastError().text();
        return false;
    }
    return true;
}


QVariantList DatabaseManager::getDrivers()
{
    QVariantList list;
    QSqlQuery query;

    query.exec("SELECT * FROM truck_drivers.drivers");

    while (query.next())
    {
        QVariantMap row;
        row["surname"] = query.value(0);
        row["name"] = query.value(1);
        row["middle_name"] = query.value(2);
        row["birth_date"] = query.value(3);
        row["phone_number"] = query.value(4);
        row["license_number"] = query.value(5);
        row["driver_status"] = query.value(6);
        row["id"] = query.value(7);
        list << row;
    }
    return list;
}

QVariantList DatabaseManager::getCargos()
{
    QVariantList list;
    QSqlQuery query;
    query.exec("SELECT * FROM truck_drivers.cargos");

    while (query.next())
    {
        QVariantMap row;
        row["description"] = query.value(0);
        row["weight_tons"] = query.value(1);
        row["sender"] = query.value(2);
        row["receiver"] = query.value(3);
        row["type"] = query.value(4);
        row["cargo_status"] = query.value(5);
        row["id"] = query.value(6);
        list << row;
    }
    return list;
}

QVariantList DatabaseManager::getRoutes()
{
    QVariantList list;
    QSqlQuery query;
    query.exec("SELECT * FROM truck_drivers.routes");
    while (query.next())
    {
        QVariantMap row;
        row["origin"] = query.value(0);
        row["destination"] = query.value(1);
        row["id"] = query.value(2);
        list << row;
    }
    return list;
}

QVariantList DatabaseManager::getTrucks()
{
    QVariantList list;
    QSqlQuery query;
    query.exec("SELECT * FROM truck_drivers.trucks");
    while (query.next())
    {
        QVariantMap row;
        row["brand"] = query.value(0);
        row["model"] = query.value(1);
        row["year"] = query.value(2);
        row["capasity_tons"] = query.value(3);
        row["plate_number"] = query.value(4);
        row["truck_status"] = query.value(5);
        row["id"] = query.value(6);
        list << row;
    }
    return list;
}

QVariantList DatabaseManager::getTrips()
{
    QVariantList list;
    QSqlQuery query;
    query.exec(
        "SELECT "
        "t.id, "
        "t.driver_id, "
        "t.truck_id, "
        "t.cargo_id, "
        "t.route_id, "
        "d.surname || ' ' || d.name || ' ' || COALESCE(d.middle_name, '') AS driver_name, "
        "tr.plate_number AS truck_plate, "
        "c.description AS cargo_description, "
        "r.origin || ' -> ' || r.destination AS route_name, "
        "t.departure_date, "
        "t.departure_date_actual, "
        "t.arrival_date, "
        "t.arrival_date_actual, "
        "t.trip_status "
        "FROM truck_drivers.trips t "
        "JOIN truck_drivers.drivers d ON d.id = t.driver_id "
        "JOIN truck_drivers.trucks tr ON tr.id = t.truck_id "
        "JOIN truck_drivers.cargos c ON c.id = t.cargo_id "
        "JOIN truck_drivers.routes r ON r.id = t.route_id "
        "ORDER BY t.id"
        );
    while (query.next())
    {
        QVariantMap row;
        row["id"] = query.value("id");
        row["driver_id"] = query.value("driver_id");
        row["truck_id"] = query.value("truck_id");
        row["cargo_id"] = query.value("cargo_id");
        row["route_id"] = query.value("route_id");
        row["driver_name"] = query.value("driver_name");
        row["truck_plate"] = query.value("truck_plate");
        row["cargo_description"] = query.value("cargo_description");
        row["route_name"] = query.value("route_name");
        row["departure_date"] = query.value("departure_date");
        row["departure_date_actual"] = query.value("departure_date_actual");
        row["arrival_date"] = query.value("arrival_date");
        row["arrival_date_actual"] = query.value("arrival_date_actual");
        row["trip_status"] = query.value("trip_status");
        list << row;
    }
    return list;
}



bool DatabaseManager::addDriver(
    const QString &surname,
    const QString &name,
    const QString &middleName,
    const QString &birthDate,
    const QString &phone,
    const QString &license,
    const QString &status)
{
    QDate birthDate1 = QDate::fromString(birthDate,"yyyy-MM-dd");
    QSqlQuery query;
    query.prepare(
        "INSERT INTO truck_drivers.drivers"
        "(surname,name,middle_name,birth_date,phone_number,license_number,driver_status)"
        "VALUES (:surname, :name, :middle_name, :birth_date, :phone, :license, :status)"
        );
    query.bindValue(":surname", surname);
    query.bindValue(":name", name);
    query.bindValue(":middle_name", middleName);
    query.bindValue(":birth_date", birthDate1);
    query.bindValue(":phone", phone);
    query.bindValue(":license", license);
    query.bindValue(":status", status);

    if (!query.exec()){
        qDebug() << "Error with add driver: " << query.lastError().text();
        qDebug() << "SQL error:" << query.lastError().databaseText();
        qDebug() << "Driver error:" << query.lastError().driverText();
        return false;
    }
    return true;
}

bool DatabaseManager::addCargo(
    const QString &description,
    const QString &weight_tons,
    const QString &sender,
    const QString &receiver,
    const QString &type,
    const QString &status)
{
    QSqlQuery query;
    query.prepare(
        "INSERT INTO truck_drivers.cargos(description,weight_tons,sender,receiver,type,cargo_status)"
        "VALUES (?,?,?,?,?,?)"
        );
    query.addBindValue(description);
    query.addBindValue(weight_tons);
    query.addBindValue(sender);
    query.addBindValue(receiver);
    query.addBindValue(type);
    query.addBindValue(status);
    if (!query.exec()){
        qDebug() << "Error with add driver: " << query.lastError().text();
        qDebug() << "SQL error:" << query.lastError().databaseText();
        qDebug() << "Driver error:" << query.lastError().driverText();
        return false;
    }
    return true;
}

bool DatabaseManager::addRoute(
    const QString &origin,
    const QString &destination)
{
    QSqlQuery query;
    query.prepare(
        "INSERT INTO truck_drivers.routes"
        "(origin,destination)"
        "VALUES (?,?)"
        );
    query.addBindValue(origin);
    query.addBindValue(destination);
    if (!query.exec()){
        qDebug() << "Error with add driver: " << query.lastError().text();
        qDebug() << "SQL error:" << query.lastError().databaseText();
        qDebug() << "Driver error:" << query.lastError().driverText();
        return false;
    }
    return true;
}

bool DatabaseManager::addTruck(
    const QString &brand,
    const QString &model,
    const QString &year,
    const QString &capasityTons,
    const QString &plateNumber,
    const QString &status)
{
    QSqlQuery query;
    query.prepare(
        "INSERT INTO truck_drivers.trucks"
        "(brand,model,year,capasity_tons,plate_number,truck_status)"
        "VALUES"
        "(?,?,?,?,?,?)"
        );
    query.addBindValue(brand);
    query.addBindValue(model);
    query.addBindValue(year);
    query.addBindValue(capasityTons);
    query.addBindValue(plateNumber);
    query.addBindValue(status);
    if (!query.exec()){
        qDebug() << "Error with add driver: " << query.lastError().text();
        qDebug() << "SQL error:" << query.lastError().databaseText();
        qDebug() << "Driver error:" << query.lastError().driverText();
        return false;
    }
    return true;
}

bool DatabaseManager::addTrip(
    const int &driverId,
    const int &truckId,
    const int &cargoId,
    const int &routeId,
    const QString &departureDate,
    const QString &arrivalDate)
{
    QSqlQuery query;
    query.prepare(
        "INSERT INTO truck_drivers.trips"
        "(driver_id, truck_id, cargo_id, route_id, departure_date, arrival_date, trip_status)"
        "VALUES (?, ?, ?, ?, ?, ?, 'Запланирован')"
        );
    QDate departureDate1 = QDate::fromString(departureDate,"yyyy-MM-dd");
    QDate arrivalDate1 = QDate::fromString(arrivalDate,"yyyy-MM-dd");
    query.addBindValue(driverId);
    query.addBindValue(truckId);
    query.addBindValue(cargoId);
    query.addBindValue(routeId);
    query.addBindValue(departureDate1);
    query.addBindValue(arrivalDate1);
    if (!query.exec()){
        qDebug() << "Error with add Trip: " << query.lastError().text();
        qDebug() << "SQL error:" << query.lastError().databaseText();
        qDebug() << "Driver error:" << query.lastError().driverText();
        return false;
    }
    QSqlQuery driver;
    driver.prepare(
        "UPDATE truck_drivers.drivers "
        "SET driver_status = 'В рейсе' "
        "WHERE id = ?"
        );
    driver.addBindValue(driverId);
    if (!driver.exec()){
        qDebug() << "Update driver status error: " << query.lastError().text();
        qDebug() << "SQL error:" << query.lastError().databaseText();
        qDebug() << "Driver error:" << query.lastError().driverText();
        return false;
    }
    QSqlQuery cargo;
    cargo.prepare(
        "UPDATE truck_drivers.cargos "
        "SET cargo_status = 'В рейсе' "
        "WHERE id = ?"
        );
    cargo.addBindValue(cargoId);
    if (!cargo.exec()){
        qDebug() << "Update cargo status error: " << query.lastError().text();
        qDebug() << "SQL error:" << query.lastError().databaseText();
        qDebug() << "Driver error:" << query.lastError().driverText();
        return false;
    }
    QSqlQuery truck;
    truck.prepare(
        "UPDATE truck_drivers.trucks "
        "SET truck_status = 'В рейсе' "
        "WHERE id = ?"
        );
    truck.addBindValue(truckId);
    if (!truck.exec()){
        qDebug() << "Update truck status error: " << query.lastError().text();
        qDebug() << "SQL error:" << query.lastError().databaseText();
        qDebug() << "Driver error:" << query.lastError().driverText();
        return false;
    }

    return true;
}


bool DatabaseManager::removeRoute(
    const QString &origin,
    const QString &destination)
{
    QSqlQuery query;
    query.prepare(
        "DELETE FROM truck_drivers.routes "
        "WHERE origin = :origin AND destination = :destination"
        );
    query.bindValue(":origin",origin);
    query.bindValue(":destination",destination);

    if (!query.exec()){
        qDebug() << "Error with remove: " << query.lastError().text();
        qDebug() << "SQL error:" << query.lastError().databaseText();
        qDebug() << "Driver error:" << query.lastError().driverText();
        return false;
    }
    return true;
}

bool DatabaseManager::removeDriver(
    const QString &surname,
    const QString &name,
    const QString &phoneNumber)
{
    QSqlQuery query;
    query.prepare(
        "DELETE FROM truck_drivers.drivers "
        "WHERE surname = :surname AND name = :name AND phone_number = :phoneNumber"
        );
    query.bindValue(":surname",surname);
    query.bindValue(":name",name);
    query.bindValue(":phoneNumber",phoneNumber);

    if (!query.exec()){
        qDebug() << "Error with remove: " << query.lastError().text();
        qDebug() << "SQL error:" << query.lastError().databaseText();
        qDebug() << "Driver error:" << query.lastError().driverText();
        return false;
    }
    return true;
}

bool DatabaseManager::removeCargo(
    const QString &description,
    const QString &sender
    )
{
    QSqlQuery query;
    query.prepare(
        "DELETE FROM truck_drivers.cargos "
        "WHERE description = :description AND sender = :sender"
        );
    query.bindValue(":description",description);
    query.bindValue(":sender",sender);
    if (!query.exec()){
        qDebug() << "Error with remove: " << query.lastError().text();
        qDebug() << "SQL error:" << query.lastError().databaseText();
        qDebug() << "Driver error:" << query.lastError().driverText();
        return false;
    }
    return true;
}

bool DatabaseManager::removeTruck(
    const QString &plateNumber)
{
    QSqlQuery query;
    query.prepare(
        "DELETE FROM truck_drivers.trucks "
        "WHERE plate_number = ?"
        );
    query.addBindValue(plateNumber);
    if (!query.exec()){
        qDebug() << "Error with remove: " << query.lastError().text();
        qDebug() << "SQL error:" << query.lastError().databaseText();
        qDebug() << "Driver error:" << query.lastError().driverText();
        return false;
    }
    return true;
}


bool DatabaseManager::updateDriver(
    const QString &license,
    const QString &surname,
    const QString &name,
    const QString &middleName,
    const QString &birthDate,
    const QString &phone,
    const QString &status
    ) {
    QSqlQuery query;
    query.prepare(
        "UPDATE truck_drivers.drivers "
        "SET surname = ?, name = ?, middle_name = ?, birth_date = ?, phone_number = ?, driver_status = ? "
        "WHERE license_number = ?"
    );
    QDate birthDate1 = QDate::fromString(birthDate,"yyyy-MM-dd");
    query.addBindValue(surname);
    query.addBindValue(name);
    query.addBindValue(middleName);
    query.addBindValue(birthDate1);
    query.addBindValue(phone);
    query.addBindValue(status);
    query.addBindValue(license);
    if (!query.exec()){
        qDebug() << "Error with update: " << query.lastError().text();
        qDebug() << "SQL error:" << query.lastError().databaseText();
        qDebug() << "Driver error:" << query.lastError().driverText();
        return false;
    }
    return true;
}
bool DatabaseManager::updateCargo(
    const QString &description,
    const QString &sender,
    const QString &weightTons,
    const QString &receiver,
    const QString &type,
    const QString &status)
{
    QSqlQuery query;
    query.prepare(
        "UPDATE truck_drivers.cargos "
        "SET weight_tons = ?, receiver = ?, cargo_status = ? "
        "WHERE description = ? AND sender = ?"
        );
    query.addBindValue(weightTons);
    query.addBindValue(receiver);
    query.addBindValue(status);
    query.addBindValue(description);
    query.addBindValue(sender);
    if (!query.exec()){
        qDebug() << "Error with remove: " << query.lastError().text();
        qDebug() << "SQL error:" << query.lastError().databaseText();
        qDebug() << "Driver error:" << query.lastError().driverText();
        return false;
    }
    return true;
}
bool DatabaseManager::updateTruck(
    const QString &plateNumber,
    const QString &brand,
    const QString &model,
    const QString &year,
    const QString &capasityTons,
    const QString &status)
{
    QSqlQuery query;
    query.prepare(
        "UPDATE truck_drivers.trucks "
        "SET brand = ?, model = ?, year = ?, capasity_tons = ?, truck_status = ? "
        "WHERE plate_number = ?"
        );
    query.addBindValue(brand);
    query.addBindValue(model);
    query.addBindValue(year);
    query.addBindValue(capasityTons);
    query.addBindValue(status);
    query.addBindValue(plateNumber);
    if (!query.exec()){
        qDebug() << "Error with remove: " << query.lastError().text();
        qDebug() << "SQL error:" << query.lastError().databaseText();
        qDebug() << "Driver error:" << query.lastError().driverText();
        return false;
    }
    return true;
}

bool DatabaseManager::updateTrip(
    const int &driverId,
    const int &truckId,
    const int &cargoId,
    const int &routeId,
    const QString &departureDate,
    const QString &arrivalDate,
    const QString &departureDateActual,
    const QString &arrivalDateActual,
    const QString &status,
    const int &tripId)
{
    QSqlQuery query;
    query.prepare(
        "UPDATE ON truck_drivers.trips "
        "SET driver_id = ?, truck_id = ?, cargo_id = ?, route_id = ?, departure_date = ?, departure_date_actual = ?, arrival_date = ?, arrival_date_actual = ?, trip_status = ? "
        "WHERE id = ?"
        );
    QDate departureDate1 = QDate::fromString(departureDate,"yyyy-MM-dd");
    QDate arrivalDate1 = QDate::fromString(arrivalDate,"yyyy-MM-dd");
    QDate departureDateActual1 = QDate::fromString(departureDateActual,"yyyy-MM-dd");
    QDate arrivalDateActual1 = QDate::fromString(arrivalDateActual,"yyyy-MM-dd");
    query.addBindValue(driverId);
    query.addBindValue(truckId);
    query.addBindValue(cargoId);
    query.addBindValue(routeId);
    query.addBindValue(departureDate1);
    query.addBindValue(departureDateActual1);
    query.addBindValue(arrivalDate1);
    query.addBindValue(arrivalDateActual1);
    query.addBindValue(status);
    query.addBindValue(tripId);
    if (!query.exec()){
        qDebug() << "Error with update trip: " << query.lastError().text();
        qDebug() << "SQL error:" << query.lastError().databaseText();
        qDebug() << "Driver error:" << query.lastError().driverText();
        return false;
    }
    return true;
}


QVariantList DatabaseManager::getDriversForTrip(){
    QVariantList list;
    QSqlQuery query;
    query.prepare(R"(
        SELECT id,
        surname || ' ' || name || ' ' || COALESCE(middle_name,'') AS fio
        FROM truck_drivers.drivers
        WHERE driver_status = 'Свободен'
    )");
    query.exec();
    QVariantMap empty;
    empty["id"] = -1;
    empty["text"] = "-- выберите водителя --";
    list << empty;
    while (query.next()){
        QVariantMap row;
        row["id"] = query.value("id");
        row["text"] = query.value("fio");
        list << row;
    }
    return list;
}

QVariantList DatabaseManager::getRoutesForTrip()
{
    QVariantList list;
    QSqlQuery query(R"(
        SELECT id, origin || ' -> ' || destination AS text
        FROM truck_drivers.routes
    )");
    QVariantMap empty;
    empty["id"] = -1;
    empty["text"] = "-- выберите маршрут --";
    list << empty;
    while (query.next()){
        QVariantMap row;
        row["id"] = query.value("id");
        row["text"] = query.value("text");
        list << row;
    }
    return list;
}

QVariantList DatabaseManager::getTrucksForTrip(){
    QVariantList list;
    QSqlQuery query(R"(
        SELECT id, brand || ' ' || model || ' (' || capasity_tons || ' т)' AS text
        FROM truck_drivers.trucks
        WHERE truck_status = 'Свободен'
    )");
    QVariantMap empty;
    empty["id"] = -1;
    empty["text"] = "-- выберите грузовик --";
    list << empty;
    while (query.next()){
        QVariantMap row;
        row["id"] = query.value("id");
        row["text"] = query.value("text");
        list << row;
    }
    return list;
}

QVariantList DatabaseManager::getCargosForTrip(){
    QVariantList list;
    QSqlQuery query(R"(
        SELECT id, description || ' (' || weight_tons || ' т)' AS text
        FROM truck_drivers.cargos
        WHERE cargo_status = 'Не доставлен'
    )");
    QVariantMap empty;
    empty["id"] = -1;
    empty["text"] = "-- выберите груз --";
    list << empty;
    while (query.next()){
        QVariantMap row;
        row["id"] = query.value("id");
        row["text"] = query.value("text");
        list << row;
    }
    return list;
}

QVariantList DatabaseManager::getDriversForTrip(int currentDriverId)
{
    QVariantList list;
    QSqlQuery query;
    query.prepare(R"(
        SELECT id,
        surname || ' ' || name || ' ' || COALESCE(middle_name,'') AS text
        FROM truck_drivers.drivers
        WHERE driver_status = 'Свободен'
           OR id = :id
    )");
    query.bindValue(":id", currentDriverId);
    query.exec();

    while (query.next()) {
        QVariantMap row;
        row["id"] = query.value("id");
        row["text"] = query.value("text");
        list << row;
    }
    return list;
}

QVariantList DatabaseManager::getTrucksForTrip(int currentTruckId){
    QVariantList list;
    QSqlQuery query;
    query.prepare(R"(
        SELECT id, brand || ' ' || model || ' (' || capasity_tons || ' т)' AS text
        FROM truck_drivers.trucks
        WHERE truck_status = 'Свободен'
        OR id = :id
    )");
    query.bindValue(":id",currentTruckId);
    query.exec();
    QVariantMap empty;
    empty["id"] = -1;
    empty["text"] = "-- выберите грузовик --";
    list << empty;
    while (query.next()){
        QVariantMap row;
        row["id"] = query.value("id");
        row["text"] = query.value("text");
        list << row;
    }
    return list;
}

QVariantList DatabaseManager::getCargosForTrip(int currentCargoId){
    QVariantList list;
    QSqlQuery query;
    query.prepare(R"(
        SELECT id, description || ' (' || weight_tons || ' т)' AS text
        FROM truck_drivers.cargos
        WHERE cargo_status = 'Не доставлен'
        OR id = :id
    )");
    query.bindValue(":id",currentCargoId);
    query.exec();
    QVariantMap empty;
    empty["id"] = -1;
    empty["text"] = "-- выберите груз --";
    list << empty;
    while (query.next()){
        QVariantMap row;
        row["id"] = query.value("id");
        row["text"] = query.value("text");
        list << row;
    }
    return list;
}


bool DatabaseManager::changeOnUpdateTrip(
    const int &oldDriverId,
    const int &newDriverId,
    const int &oldTruckId,
    const int &newTruckId,
    const int &oldCargoId,
    const int &newCargoId,
    const QString &oldTripStatus,
    const QString &newTripStatus)
{
    QSqlDatabase db = QSqlDatabase::database();

    if (!db.transaction()) {
        qDebug() << "Cannot start transaction";
        return false;
    }

    QSqlQuery query(db);

    auto execQuery = [&](const QString &sql, int id) -> bool {
        query.prepare(sql);
        query.addBindValue(id);
        if (!query.exec()) {
            qDebug() << "SQL error:" << query.lastError().text();
            return false;
        }
        return true;
    };



    if (oldDriverId != newDriverId) {
        if (!execQuery(
                "UPDATE truck_drivers.drivers "
                "SET driver_status = 'Свободен' WHERE id = ?",
                oldDriverId)) {
            db.rollback();
            return false;
        }
    }

    if (oldTruckId != newTruckId) {
        if (!execQuery(
                "UPDATE truck_drivers.trucks "
                "SET truck_status = 'Свободен' WHERE id = ?",
                oldTruckId)) {
            db.rollback();
            return false;
        }
    }

    if (oldCargoId != newCargoId) {
        if (!execQuery(
                "UPDATE truck_drivers.cargos "
                "SET cargo_status = 'Не доставлен' WHERE id = ?",
                oldCargoId)) {
            db.rollback();
            return false;
        }
    }



    if (oldTripStatus != newTripStatus) {

        if (newTripStatus == "Выполняется") {

            if (!execQuery(
                    "UPDATE truck_drivers.drivers "
                    "SET driver_status = 'В рейсе' WHERE id = ?",
                    newDriverId)
                || !execQuery(
                    "UPDATE truck_drivers.trucks "
                    "SET truck_status = 'В рейсе' WHERE id = ?",
                    newTruckId)
                || !execQuery(
                    "UPDATE truck_drivers.cargos "
                    "SET cargo_status = 'В пути' WHERE id = ?",
                    newCargoId)) {

                db.rollback();
                return false;
            }

        } else if (newTripStatus == "Завершен") {

            if (!execQuery(
                    "UPDATE truck_drivers.drivers "
                    "SET driver_status = 'Свободен' WHERE id = ?",
                    newDriverId)
                || !execQuery(
                    "UPDATE truck_drivers.trucks "
                    "SET truck_status = 'Свободен' WHERE id = ?",
                    newTruckId)
                || !execQuery(
                    "UPDATE truck_drivers.cargos "
                    "SET cargo_status = 'Доставлен' WHERE id = ?",
                    newCargoId)) {

                db.rollback();
                return false;
            }
        }
    }

    db.commit();
    return true;
}
