#pragma once

#include <stdexcept>
#include <iostream>
#include "Sequence.h"
/// Functionally complements ListSequence

template <typename T>
class DynamicArray;

template <typename T>
class Node {
public:
    Node* next;
    T value;
    Node(): next(nullptr) {}
    Node(T value): next(nullptr), value(value) {}
};

template <typename T>
class LinkedList {
private:
    int size = 0;
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;

    // метод для получения полного доступа к i-ому Node
    Node<T>& getNode(int index) const {
        if (index < 0 || index >= size) throw std::out_of_range("The entered index is out of range.\n");
        if (head == nullptr) throw std::out_of_range("There was a request to get an element from the empty collection.\n");
        Node<T>* bufNode = head;
        for (int i = 0; i < index; ++i) {
            bufNode = bufNode->next;
        }
        return *bufNode;
    }
public:
    LinkedList(const T* items, int size) {
        if (size < 0) throw std::out_of_range("Entered invalid size.\n");
        for (int i = 0; i < size; ++i){
            append(items[i]);
        }
    }

    LinkedList(const Sequence<T>& other) {
        for (int i = 0; i < other.getLength(); ++i) {
            append(other.get(i));
        }
    }

    LinkedList() {}

    LinkedList(const LinkedList<T>& other) {
        for (int i = 0; i < other.getLength(); ++i) {
            append(other[i]);
        }
    }

    LinkedList(int size) {
        if (size < 0) throw std::out_of_range("Entered invalid size.\n");
        if (size > 0) {
            head = new Node<T>;
            tail = head;
        }
        for (int i = 1; i < size; ++i) {
            tail->next = new Node<T>;
            tail = tail->next;
        }
        this->size = size;
    }

    // сделать конструктор LinkedList(const DynamicArray<T>& other) не получится, т.к. файлы LinkedList.h и DynamicArray.h будут содержать друг друга

    ~LinkedList() {
        if (head != nullptr) {
            Node<T>* bufNode = head->next;
            while (bufNode != nullptr) {
                delete head;
                head = bufNode;
                bufNode = bufNode -> next;
            }
            delete head;
        }
    }

    T& operator[](int index) const { // можно изменять элемент по ссылке
        // getNode(index) выбросит исключение
        return getNode(index).value;
    }
    bool operator==(const LinkedList<T>& linkedList) const {
        if (this->getLength() == linkedList.getLength()){
            for (int i = 0; i < this->getLength(); ++i) {
                if ((*this)[i] != linkedList[i]) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }

    // Переделано
    LinkedList<T>& operator=(const LinkedList<T>& other) {
        // сначала удаляем все элементы
        if (head != nullptr) {
            Node<T>* bufNode = head->next;
            while (bufNode != nullptr) {
                delete head;
                head = bufNode;
                bufNode = bufNode -> next;
            }
            delete head;
        }
        // заново создаем все элементы
        head = nullptr;
        tail = nullptr;
        size = 0;
        for (int i = 0; i < other.getLength(); ++i) {
            this->append(other[i]);
        }
        return (*this);
    }

    T getFirst() const {
        if (head == nullptr) throw std::out_of_range("There was a request to get an element from the empty collection.\n");
        return head->value;
    }

    T getLast() const {
        if (head == nullptr) throw std::out_of_range("There was a request to get an element from the empty collection.\n");
        return tail->value;
    }

    T get(int index) const {
        return getNode(index).value;
    }

    LinkedList<T>* getSubsequence(int startIndex, int endIndex) const {
        if (startIndex > endIndex || startIndex < 0 || endIndex >= this->getLength()) throw std::out_of_range("Entered indices are out of range.\n");
        LinkedList<T>* result_ll = new LinkedList<T>;
        Node<T>* bufNode = &getNode(startIndex);
        for (int i = startIndex; i <= endIndex; ++i) {
            result_ll->append(bufNode->value);
            bufNode = bufNode->next;
        }
        return result_ll;
    }

    int getLength() const {
        return size;
    }

    void set(int index, const T& value) const {
        // конструкция (*this)[index] выбросывает исключение
        (*this)[index] = value;
    }

    void append(const T& item) {
        if (size == 0) {
            head = new Node<T>(item);
            tail = head;
            ++size;
        } else {
            tail->next = new Node<T>(item);
            tail = tail->next;
            ++size;
        }
    }

    void prepend(const T& item) { // добавляет элемент в начало списка
        if (size == 0) {
            head = new Node<T>(item);
            tail = head;
            ++size;
        } else {
            Node<T>* nodeBuf = head;
            head = new Node<T>(item);
            head->next = nodeBuf;
            ++size;
        }
    }

    void insertAt(int index, const T& item) { // вставляет элемент в заданную позицию
        if (index < 0 || index > size) throw std::out_of_range("The entered index is out of range.\n");
        if (index == 0) {
            prepend(item);
        } else if (index == size) {
            append(item);
        } else {
            Node<T>* bufNode = new Node<T>(item);
            bufNode->next = &getNode(index);
            getNode(index - 1).next = bufNode;
            ++size;
        }
    }

    void printList() const {
        for (int i = 0; i < size; ++i) {
            std::cout << getNode(i).value << " ";
        }
        std::cout << "\n";
    }

    LinkedList<T>* concat(LinkedList<T>* second_ll) const { // сцепляет два списка
        LinkedList<T>* result_ll = new LinkedList<T>;
        for (int i = 0; i < size; ++i) {
            result_ll->append(getNode(i).value);
        }
        for (int j = 0; j < second_ll->getLength(); ++j) {
            result_ll->append(second_ll->get(j));
        }
        return result_ll;
    }
};
