#pragma once

#include <iostream>
#include <stdexcept>
#include "Sequence.h"
#include "LinkedList.h"
/// Functionally complements ArraySequence

template <typename T>
class DynamicArray {
protected:
    int size;
    T* array = nullptr;
public:
    // конструктор для копирования массива
    DynamicArray(const T* arrayToCopy, int size): size(size) {
        if (size < 0) throw std::out_of_range("Entered invalid size.\n");
        array = new T[size];
        for (int i = 0; i < size; ++i) {
            array[i] = arrayToCopy[i];
        }
    }
    // конструктор создания массива определенной длины
    DynamicArray(int size): size(size) {
        if (size < 0) throw std::out_of_range("Entered invalid size.\n");
        array = new T[size];
    }
    // конструктор копирования
    DynamicArray(const DynamicArray<T>& other): size(other.getSize()), array(new T[other.getSize()]) {
        for (int i = 0; i < size; ++i) {
            set(i, other.get(i));
        }
    }

    DynamicArray(const LinkedList<T>& other): size(other.getLength()), array(new T[other.getLength()]) {
        for (int i = 0; i < size; ++i) {
            set(i, other.get(i));
        }
    }

    DynamicArray(const Sequence<T>& other): size(other.getLength()), array(new T[other.getLength()]) {
        for (int i = 0; i < size; ++i) {
            set(i, other.get(i));
        }
    }

    ~DynamicArray() {
        delete[] array;
    }

    T& operator[](int index) const {
        if (index >= size || index < 0) throw std::out_of_range("The entered index is out of range.\n");
        return array[index];
    }

    bool operator==(const DynamicArray<T>& other) const {
        if (this->getLength() == other.getLength()){
            for (int i = 0; i < this->getLength(); ++i) {
                if ((*this)[i] != other[i]) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }

    // Переделано
    DynamicArray<T>& operator=(const DynamicArray<T>& other) {
        delete array;
        array = new T[other.getSize()];
        for (int i = 0; i < other.getSize(); ++i) {
            array[i] = other.get(i);
        }
        return *this; // возвращаем обновленный *this как rvalue;
    }

    T get(int index) const { // возвращает rvalue
        if (index >= size || index < 0) throw std::out_of_range("The entered index is out of range.\n");
        return array[index];
    }

    int getSize() const {
        return size;
    }
    void set(int index, const T& value) {
        // исключение выбросит конструкция (*this)[index]
        (*this)[index] = value; // здесь все нормально, происходит стандартное присваивание. Т.е. value копируется в array[index]
    }

    void resize(int newSize) {
        if (newSize < 0) throw std::out_of_range("Entered invalid size.\n");
        T* helpArray = new T[newSize];
        int minSize = newSize < size ? newSize : size;
        for (int i = 0; i < minSize; ++i) {
            helpArray[i] = array[i];
        }
        delete[] array;
        array = helpArray;
        size = newSize;
        if (size == 0) array = nullptr;
    }

    void printArray() const {
        for (int i = 0; i < size; ++i) {
            std::cout << array[i] << " ";
        }
        std::cout << "\n";
    }
};
