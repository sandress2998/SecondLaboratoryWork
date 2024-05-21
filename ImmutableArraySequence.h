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

    void add(const T& item) {
        array->append(item);
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

    const T& operator[](int index) const override {
        return (*array)[index];
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
        ImmutableArraySequence<T>* result = instance();
        result->array->append(item);
        return result;
    }

    ImmutableArraySequence<T>* prepend(const T& item) const override {
        ImmutableArraySequence<T>* result = instance();
        result->array->prepend(item);
        return result;
    }

    ImmutableArraySequence<T>* insertAt(int index, const T& item) const override {
        ImmutableArraySequence<T>* result = instance();
        result->array->insertAt(index, item);
        return result;
    }

    ImmutableArraySequence<T>* getSubsequence(int startIndex, int endIndex) const override {
        if (startIndex < 0 || endIndex >= getLength() || startIndex > endIndex) throw std::out_of_range("Entered indices are out of range.\n");
        ImmutableArraySequence<T>* result = new ImmutableArraySequence<T>;
        for (int i = startIndex; i <= endIndex; ++i) {
            result->add(get(i));
        }
        return result;
    }

    ImmutableArraySequence<T>* concat(const Sequence<T>& other) const override {
        ImmutableArraySequence<T>* result = new ImmutableArraySequence<T>;
        int i = 0;
        for (; i < getLength(); ++i) {
            result->add(get(i));
        }
        for (; i < getLength() + other.getLength(); ++i) {
            result->add(other.get(i - getLength()));
        }
        return result;
    }
};
