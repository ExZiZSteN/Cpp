cmake_minimum_required(VERSION 3.16)

project(DataBase VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)
find_package(Qt6 REQUIRED COMPONENTS Sql)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(appDataBase
    main.cpp
)

qt_add_qml_module(appDataBase
    URI DataBase
    QML_FILES
        Main.qml
        SOURCES databasemanager.h databasemanager.cpp
        QML_FILES AddDriver.qml
        QML_FILES RemoveRoutes.qml
        QML_FILES RemoveDriver.qml
        SOURCES
        QML_FILES DriversTable.qml
        QML_FILES EditDriver.qml
        QML_FILES CargosTable.qml
        QML_FILES EditCargo.qml
        QML_FILES AddCargo.qml
        QML_FILES RoutesTable.qml
        QML_FILES AddRoute.qml
        QML_FILES TrucksTable.qml
        QML_FILES EditTruck.qml
        QML_FILES AddTruck.qml
        QML_FILES RemoveTruck.qml
        QML_FILES TripsTable.qml
        QML_FILES AddTrip.qml
        QML_FILES EditTrip.qml
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appDataBase PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appDataBase
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appDataBase
    PRIVATE Qt6::Quick
)
target_link_libraries(appDataBase
    PRIVATE Qt6::Sql
)


include(GNUInstallDirs)
install(TARGETS appDataBase
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
