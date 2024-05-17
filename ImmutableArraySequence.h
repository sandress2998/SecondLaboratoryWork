#pragma once

#include <stdexcept>
#include "Sequence.h"
#include "ImmutableSequence.h"
#include "DynamicArray.h"
#include "LinkedList.h"

template <typename T>
class ImmutableArraySequence: public ImmutableSequence<T> {
private:
    DynamicArray<T>* array;
    ImmutableArraySequence<T>* instance() const {
        return new ImmutableArraySequence<T>(*this);
    }
public:
    ImmutableArraySequence(const T* arrayToCopy, int size): array(new DynamicArray<T>(arrayToCopy, size)) {}
    ImmutableArraySequence(int size): array(new DynamicArray<T>(size)) {}
    ImmutableArraySequence(): array(new DynamicArray<T>(0)) {}
    ImmutableArraySequence(const LinkedList<T>& other): array(new DynamicArray<T>(other)) {}
    ImmutableArraySequence(const DynamicArray<T>& other): array(new DynamicArray<T>(other)) {}
    ImmutableArraySequence(const ImmutableArraySequence<T>& other): array(new DynamicArray<T>(*(other.array))) {}
    ImmutableArraySequence(const Sequence<T>& other): array(new DynamicArray<T>(other)) {}

    ~ImmutableArraySequence() override {
        delete array;
    }

    T operator[](int index) const override {
        return (*array)[index];
    }

    ImmutableArraySequence<T>& operator=(const ImmutableArraySequence<T>& other) {
        return *this;
    }

    T getFirst() const override {
        return (*array)[0];
    }

    T getLast() const override {
        return (*array)[getLength() - 1];
    }

    T get(int index) const override {
        return (*array)[index];
    }

    int getLength() const override {
        return array->getSize();
    }

    ImmutableArraySequence<T>* append(const T& item) const override {
        MutableArraySequence<T> other(*this);
        other.append(item);
        return new ImmutableArraySequence(other);
    }

    ImmutableArraySequence<T>* prepend(const T& item) const override {
        MutableArraySequence<T> other(*this);
        other.prepend(item);
        return new ImmutableArraySequence(other);
    }

    ImmutableArraySequence<T>* insertAt(int index, const T& item) const override {
        MutableArraySequence<T> other(*this);
        other.insertAt(index, item);
        return new ImmutableArraySequence(other);
    }

    ImmutableArraySequence<T>* getSubsequence(int startIndex, int endIndex) const override {
        MutableArraySequence<T> other(*this);
        return new ImmutableArraySequence<T>(*other.getSubsequence(startIndex, endIndex));;
    }

    ImmutableArraySequence<T>* concat(const Sequence<T>& other) const override {
        MutableArraySequence<T> buf(*this);
        return new ImmutableArraySequence<T>(*buf.concat(other));
    }
};
