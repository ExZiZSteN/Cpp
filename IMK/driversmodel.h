#ifndef DRIVERSMODEL_H
#define DRIVERSMODEL_H
#include <QAbstractListModel>


class DriversModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum Roles {
        SurnameRole = Qt::UserRole +1,
        NameRole,
        MiddleNameRole,
        BirthDateRole,
        PhoneRole,
        LicenseRole,
        StatusRole
    };
    explicit DriversModel(QObject* parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE void loadDrivers();

private:
    struct Driver {
        QString surname;
        QString name;
        QString middle;
        QString birthDate;
        QString phone;
        QString license;
        QString status;
    };

    QList<Driver> m_drivers;
};
#endif // DRIVERSMODEL_H
