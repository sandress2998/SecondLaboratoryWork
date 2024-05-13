#pragma once

#include "Sequence.h"

template <class T>
class ImmutableSequence: public Sequence<T> {
public:
    virtual ~ImmutableSequence() = default;

    virtual ImmutableSequence<T>* append(const T& item) const = 0;
    virtual ImmutableSequence<T>* prepend(const T& item) const = 0;
    virtual ImmutableSequence<T>* insertAt(int index, const T& item) const = 0;

    virtual T operator[](int index) const  = 0; // отличие от MutableSequence - возвращается копия
};
