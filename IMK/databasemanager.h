#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H
#include <QObject>
#include <QSqlDatabase>
#include <QVariantList>

class DatabaseManager : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseManager(QObject *parent = nullptr);

    Q_INVOKABLE bool connectToDb();

    //Вывод всех записей
    Q_INVOKABLE QVariantList getDrivers();
    Q_INVOKABLE QVariantList getCargos();
    Q_INVOKABLE QVariantList getRoutes();
    Q_INVOKABLE QVariantList getTrucks();
    Q_INVOKABLE QVariantList getTrips();

    //Добавление новых записей
    Q_INVOKABLE bool addDriver(
        const QString &surname,
        const QString &name,
        const QString &middleName,
        const QString &birthDate,
        const QString &phone,
        const QString &license,
        const QString &status
        );
    Q_INVOKABLE bool addCargo(
        const QString &description,
        const QString &weight_tons,
        const QString &sender,
        const QString &receiver,
        const QString &type,
        const QString &status
        );
    Q_INVOKABLE bool addRoute(
        const QString &origin,
        const QString &destination
        );
    Q_INVOKABLE bool addTruck(
        const QString &brand,
        const QString &model,
        const QString &year,
        const QString &capasityTons,
        const QString &plateNumber,
        const QString &status
        );
    Q_INVOKABLE bool addTrip(
        const int &driverId,
        const int &truckId,
        const int &cargoId,
        const int &routeId,
        const QString &departureDate,
        const QString &arrivalDate
        );


    //Удаление записей
    Q_INVOKABLE bool removeRoute(
        const QString &origin,
        const QString &destination
        );
    Q_INVOKABLE bool removeDriver(
        const QString &surname,
        const QString &name,
        const QString &phoneNumber
        );
    Q_INVOKABLE bool removeCargo(
        const QString &description,
        const QString &sender
        );
    Q_INVOKABLE bool removeTruck(
        const QString &palte_number
        );


    //Обнавление записей
    Q_INVOKABLE bool updateDriver(
        const QString &license_number,
        const QString &surname,
        const QString &name,
        const QString &middleName,
        const QString &birthDate,
        const QString &phone,
        const QString &status
        );
    Q_INVOKABLE bool updateCargo(
        const QString &description,
        const QString &sender,
        const QString &weightTons,
        const QString &receiver,
        const QString &type,
        const QString &status
        );
    Q_INVOKABLE bool updateTruck(
        const QString &plateNumber,
        const QString &brand,
        const QString &model,
        const QString &year,
        const QString &capasityTons,
        const QString &status
        );
    Q_INVOKABLE bool updateTrip(
        const int &driverId,
        const int &truckId,
        const int &cargoId,
        const int &routeId,
        const QString &departureDate,
        const QString &arrivalDate,
        const QString &departureDateActual,
        const QString &arrivalDateActual,
        const QString &status,
        const int &tripId
        );

    //Для поездки удобный просмотр типо
    Q_INVOKABLE QVariantList getDriversForTrip();
    Q_INVOKABLE QVariantList getDriversForTrip(int currentDriverId);
    Q_INVOKABLE QVariantList getTrucksForTrip();
    Q_INVOKABLE QVariantList getTrucksForTrip(int currentTruckId);
    Q_INVOKABLE QVariantList getCargosForTrip();
    Q_INVOKABLE QVariantList getCargosForTrip(int currentCargoId);
    Q_INVOKABLE QVariantList getRoutesForTrip();


    Q_INVOKABLE bool changeOnUpdateTrip(
        const int &oldDriverId,
        const int &newDriverId,
        const int &oldTruckId,
        const int &newTruckId,
        const int &oldCargoId,
        const int &newCargoId,
        const QString &oldTripStaus,
        const QString &newTripStatus
        );
};
#endif // DATABASEMANAGER_H
