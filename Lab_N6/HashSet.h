#pragma once
#include <string>
#include <iostream>


/**
 * @brief Узел списка
 * 
 * @tparam V тип данных значения
 */
template<typename V>
class Node{
    public:
        /** @brief Значения узла */
        V value_;

        /** @brief Указатель на следующий узел */
        Node<V>* next_;

        /** @brief Конструктор узла списка 
         * 
         * @param value значение узла
        */
        Node(const V& value){
            value_ = value;
            next_ = nullptr;
        }
};


/**
 * @brief Класс HashSet реализует односвязный список
 * 
 * Хранит все значения узлов. Хранятся только уникальные значения
 * 
 * @tparam T тип данных значения узла
 */
template<typename T>
class HashSet{
    private:
        /** @brief Указатель на первый элемент списка */
        Node<T>* head_;
    public:
        /** @brief Стандартный конструктор, создает пустой односвязный список */
        HashSet() : head_(nullptr) {};

        /** @brief Проверяет наличе значения в списке
         * 
         * @param value значение для поиска
         * @return true если значение есть
         * @return false если значения нет
        */
        bool contains(const T& value) const{
            Node<T>* curr = head_;
            while (curr){
                if (curr->value_ == value){
                    return true;
                }
                curr = curr->next_;
            }
            return false;
        }

        /** @brief Вставка в конец односвязного списка
         * 
         * @param value Значение для добавеления
         */
        void insert(const T& value){
            if (contains(value)){
                return;
            }
            else{
                if (head_ == nullptr){
                    head_ = new Node<T>(value);
                    return;
                }
                else{
                    Node<T>* current = head_;
                    while (current->next_ != nullptr){
                        current = current->next_;
                    }
                    current->next_ = new Node<T>(value);
                }
            }
        }

        /** @brief Удаление значения из списка 
         * 
         * @param value Значение, которое нужно удалить
        */
        void pop(const T& value){
            if (!contains(value)){
                return;
            }
            else{
                Node<T>* curr = head_;
                Node<T>* prev = nullptr;
                while(curr){
                    if (curr->value_ == value){
                        if (prev == nullptr){
                            head_ = curr->next_;
                            delete curr;
                            return;
                        }
                        else{
                            prev->next_ = curr->next_;
                            delete curr;
                            return;
                        }
                    }
                    else{
                        prev = curr;
                        curr = curr->next_;
                    }
                }
            }
        }

        /** @brief Объединение двух списков 
         * @param hashSet Односвязный список с которым объединяем
         * @return HashSet<T> Односвязный список с элементами двух списков
        */
        HashSet<T> Union(const HashSet<T>& hashSet){
            HashSet<T> result;
            Node<T>* curr = this->head_;
            while (curr) {
                result.insert(curr->value_);
                curr = curr->next_;
            }
            curr = hashSet.head_;
            while (curr) {
                result.insert(curr->value_);
                curr = curr->next_;
            }
            
            return result;
        }
        /** @brief Исключает элменты второго списка их первого 
         * @param hashSet Односвязный список значения которого необходимо исключить
         * @return HashSet<T> Односвязный список с элементами первого списка, которых нет во втором списке
        */
        HashSet<T> Except(const HashSet<T>& hashSet){
            HashSet<T> result;
            Node<T>* curr = head_;
            while (curr) {
                if (!hashSet.contains(curr->value_)){
                    result.insert(curr->value_);
                }
                curr = curr->next_;
            }
            return result;
        }
        /** @brief Получает обшие элементы для двух списков
         * @param hashSet Односвязный список, для которого ищем общие элементы
         * @return HashSet<T> Односвязный список с общими элементами из двух списков
        */
        HashSet<T> Intersect(const HashSet<T>& other){
            HashSet<T> newSet;
            Node<T>* curr = head_;

            while (curr){
                if (other.contains(curr->value_)){
                    newSet.insert(curr->value_);
                }
                curr = curr->next_;
            }
            return newSet;
        }
        /** @brief Переопределение оператора вывода
         * Выводит все значения узлов
         * @tparam U тип данных значений односвязного списка
         * @param out Поток вывода
         * @param hashSet Односвязный список
         */
        template<typename U>
        friend std::ostream& operator<<(std::ostream& out, const HashSet<U>& hashSet);
        

};

/**
 * @brief Вывод Односвязного списка в поток
 * 
 * @tparam V тип данных значений Односвязного списка
 * @param out Поток вывода
 * @param hashSet Односвязный список
 * @return std::ostream& Поток вывода
 */
template<typename U>
std::ostream& operator<<(std::ostream& out, const HashSet<U>& hashSet){
    Node<U>* current = hashSet.head_;
    while (current){
        out << current->value_ << " ";
        current = current->next_;
    }
    return out;
}