#pragma once
#include <iostream>
#include <cmath>

/**
 * @brief Класс Point представляет точку на плоскости (2D)
 */
class Point
{
    protected:
        /**
         * @brief X-координата точки
         */
        double x_ {};
        /**
        * @brief Y-координата точки
        */
        double y_ {};
    public:
        /**
        * @brief Конструктор точки на плоскости
        *
        * @param x Значение координаты X
        * @param y Значение координаты Y
        */
        Point(double x = 0, double y = 0){
            x_= x;
            y_ = y;
        };
        /**
        * @brief Вывод координат точки на экран
        */
        void cordinates(){
            std::cout << "{"<< x_ << ";" << y_ << "}" << std::endl;
        }
};

/**
 * @brief Класс Point3D представляет точку в трёхмерном пространстве
 */
class Point3D : protected Point{
    private:
        /**
         * @brief Z-координата точки
         */
        double z_ {};
    public:
        /**
         * @brief Конструктор трёхмерной точки
         *
         * @param x Координата X
         * @param y Координата Y
         * @param z Координата Z
         */
        Point3D(double x = 0, double y = 0, double z = 0) : Point(x,y){
            this->z_ = z;
        }
        /**
        * @brief Вывод координат трёхмерной точки
        */
        void cordinates(){
            std::cout << "{" << x_ << ";" << y_ << ";" << z_ << "}"<< std::endl;
        }
        /**
        * @brief Вычисляет расстояние между двумя точками в 3D
        *
        * @param p2 Вторая точка
        * @return Евклидово расстояние между точками
        */
        double distance(Point3D& p2){
            return sqrt(pow((x_ - p2.x_),2) + pow((y_ - p2.y_),2)  + pow((z_ - p2.z_),2));
        }
};