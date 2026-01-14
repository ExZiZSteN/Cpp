# Разработка графическоого интерфейса для базы данных "Дальнобойщики"

## Используемый технологии 
- Qt 6.10 (Qt Quick application)
- PostgreSQL
- C++
- Qt SQL

## Описание базы данных
База данных предназначена для хранения информации о водителях, грузовиках, грузах, маршрутов и рейсов

Основные таблицы:
- drivers
- (`text` surname, `text` name, `text` middle_name, `date` birth_date, `text` phone_number, `text` license_number, `text` driver_status, `serial` id)
- trucks
- (`text` brand, `text` model, `int` year, `numeric` capasity_tons, `text` plate_number, `text` truck_status, `serial` id)
- cargos
- (`text`, description, `numeric` weight_tons, `text` sender, `text` receiver, `text` type, `text` cargo_status, `serial` id)
- routes
- (`text`, origin, `text` destination, `serial` id)
- trips
- (`int` driver_id, `int` truck_id, `int` cargo_id, `int` route_id, `date` departure_date, `date` departure_date_actual, `date` arrival_date, `date` arrival_date_actual, `text`, status, `serial` id)



## Архитектура приложения
Приложение построено по принципу разделения логики и интерфейса.  
Вся работа с базой данных реализована в классе Databasemanager.

## Работа с рейсами
При добавлении рейса пользователь выбирает водителя, грузовик, груз и маршрут.  
В базу данных сохраняются их идентификаторы, а статусы связанных сущностей автоматически обновляются.

## Обновление рейсов
При изменении рейса учитываются:
- смена водителя, грузовика или груза;
- изменение статуса рейса.

Все изменения выполняются в рамках транзакции.

## Транзакции
Использование транзакций позволяет:
- сохранить целостность данных;
- избежать частичных обновлений;
- откатить изменения при ошибке.

## Пользовательский интерфейс
Интерфейс реализован на QML и включает:
- таблицы для просмотра данных;
- формы добавления и редактирования;
- выпадающие списки для выбора связанных сущностей.
