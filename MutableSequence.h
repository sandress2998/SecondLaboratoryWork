#pragma once

#include "Sequence.h"

template <class T>
class MutableSequence: public Sequence<T> {
public:
    virtual ~MutableSequence() = default;

    virtual void set(int index, const T& value) = 0; // в ImmutableSequence функция отсутствует

    virtual void append(const T& item) = 0;
    virtual void prepend(const T& item) = 0;
    virtual void insertAt(int index, const T& item) = 0;

    virtual T& operator[](int index) const = 0; // элемент возвращается по ссылке, т.е. его можно изменять
};


