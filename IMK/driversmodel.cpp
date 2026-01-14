#include "driversmodel.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
DriversModel::DriversModel(QObject *parent) : QAbstractListModel(parent) {}

int DriversModel::rowCount(const QModelIndex &) const{
    return m_drivers.count();
}

QVariant DriversModel::data(const QModelIndex &index, int role) const{
    if (!index.isValid()){
        return {};
    }

    const Driver &d = m_drivers[index.row()];
    switch (role) {
    case SurnameRole: return d.surname;
    case NameRole: return d.name;
    case MiddleNameRole: return d.middle;
    case PhoneRole: return d.phone;
    case LicenseRole: return d.license;
    case StatusRole: return d.status;
    }

    return {};
}

QHash<int, QByteArray> DriversModel::roleNames() const {
    return {
        {SurnameRole, "surname"},
        {NameRole, "name"},
        {MiddleNameRole, "middle"},
        {PhoneRole, "phone"},
        {LicenseRole, "license"},
        {StatusRole, "status"}
    };
}
void DriversModel::loadDrivers()
{
    beginResetModel();
    m_drivers.clear();

    QSqlQuery query(
        "SELECT surname, name, middle_name, birth_date, phone_number, license_number, driver_status "
        "FROM truck_drivers.drivers "
        "ORDER BY surname"
        );

    while (query.next()) {
        m_drivers.append({
            query.value(0).toString(),
            query.value(1).toString(),
            query.value(2).toString(),
            query.value(3).toString(),
            query.value(4).toString(),
            query.value(5).toString(),
            query.value(6).toString()
        });
    }

    endResetModel();
}
