#pragma once
#include <iostream>
#include <vector>

/**
 * @brief Узел словаря (односвязный список)
 * 
 * @tparam K тип данных узла
 * @tparam V тип данных занчения
 */
template<typename K, typename V>
class DictNode {
public:
    /** @brief Ключ Словаря */ 
    K key;

    /** @brief Значение, по ключу */
    V value;

    /** @brief Указать на следующий узел */
    DictNode* next;

    /**
     * @brief Конструктор узла словаря
     * 
     * @param k ключа
     * @param v значение
     */
    DictNode(const K& k, const V& v) : key(k), value(v), next(nullptr) {}
};

/**
 * @brief Класс Dictionary реализует словарь
 * 
 * Хранит пары ключ-значение. Значение в виде односвязного списка.
 * Для одного ключа может храниться несколько значений.
 * 
 * @tparam K тип данных ключа
 * @tparam V тип данных значения
 */
template<typename K, typename V>
class Dictionary {
private:
    /** @brief Указатель на первый элемент словаря */
    DictNode<K, V>* head_;

public:
    /**
     * @brief Конструктор по умолчанию
     * Создает пустой словарь
     */
    Dictionary() : head_(nullptr) {}

    /**
     * @brief Проверяет наличие ключа в словаре
     * 
     * @param key Ключ для поиска
     * @return true если ключ найден
     * @return false если ключ отсутсвует
     */
    bool contains(const K& key) const {
        DictNode<K, V>* curr = head_;
        while (curr) {
            if (curr->key == key)
                return true;
            curr = curr->next;
        }
        return false;
    }

    /**
     * @brief Добавляет значение по ключу
     * 
     * Если ключ уже существует, значение добавляется
     * в контейнер значений этого ключа.
     * Если ключ отсутсвует - создается новый элемент.
     * 
     * @param key Ключ словаря
     * @param val добавляемое значение
     */
    void insert(const K& key, const typename V::value_type& val) {
        DictNode<K, V>* curr = head_;
        while (curr) {
            if (curr->key == key) {
                curr->value.push_back(val);
                return;
            }
            curr = curr->next;
        }

        V vec;
        vec.push_back(val);
        DictNode<K, V>* newNode = new DictNode<K, V>(key, vec);
        newNode->next = head_;
        head_ = newNode;
    }

    /**
     * @brief Перегрузка оператора вывода
     * 
     * Выводит все ключи и связанные с ними значения.
     * 
     * @param out Поток вывода
     * @param dict Словарь для вывода
     * @return std::ostream& Поток вывода
    */
    template<typename C, typename B>
    friend std::ostream& operator<<(std::ostream& out, const Dictionary<C, B>& dict);
};

/**
 * @brief Вывод словаря в поток
 * 
 * @tparam K тип данных ключа
 * @tparam V тип данных значения
 * @param out Поток вывода
 * @param dict Словарь
 * @return std::ostream& Поток вывода
 */
template<typename K, typename V>
std::ostream& operator<<(std::ostream& out, const Dictionary<K, V>& dict) {
    DictNode<K, V>* curr = dict.head_;

    while (curr) {
        out << curr->key << " : [ ";
        for (const auto& v : curr->value) {
            out << v << " ";
        }
        out << "]\n";
        curr = curr->next;
    }

    return out;
}
