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
        DynamicArray<T> result(*(this->array));
        int resSize = getLength() + 1;
        result.resize(resSize);
        result[resSize - 1] = item;
        return new ImmutableArraySequence(result);
    }

    ImmutableArraySequence<T>* prepend(const T& item) const override {
        DynamicArray<T> result(*(this->array));
        int resSize = getLength() + 1;
        result.resize(resSize);
        result[0] = item;
        for (int i = 1; i < resSize; ++i) {
            result[i] = get(i - 1);
        }
        return new ImmutableArraySequence(result);
    }

    ImmutableArraySequence<T>* insertAt(int index, const T& item) const override {
        DynamicArray<T> result(*(this->array));
        int resSize = getLength() + 1;
        result.resize(resSize);
        int i = 0;
        for (; i < index; ++i) {
            result[i] = get(i);

        }
        result[i++] = item;
        for (; i < resSize; ++i) {
            result[i] = get(i - 1);
        }
        return new ImmutableArraySequence(result);
    }

    void print() const override {
        array->printArray();
    }

    ImmutableArraySequence<T>* getSubsequence(int startIndex, int endIndex) const override {
        if (startIndex > endIndex || startIndex < 0 || endIndex >= this->getLength()) throw std::out_of_range("Entered indices are out of range.\n");
        DynamicArray<T> bufArray(endIndex - startIndex + 1);
        for (int i = 0; i < bufArray.getSize(); ++i) {
            bufArray[i] = get(i + startIndex);
        }
        return new ImmutableArraySequence<T>(bufArray);;
    }

    ImmutableArraySequence<T>* concat(const Sequence<T>& other) const override {
        DynamicArray<T> bufArray(getLength() + other.getLength());
        int i = 0;
        int length = getLength();
        for (; i < length; ++i) {
            (bufArray)[i] = get(i);
        }
        for (; i < length + other.getLength(); ++i) {
            (bufArray)[i] = other.get(i - length);
        }
        return new ImmutableArraySequence<T>(bufArray);
    }
};
