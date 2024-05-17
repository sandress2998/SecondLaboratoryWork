#pragma once

#include <stdexcept>
#include "ImmutableSequence.h"
#include "Sequence.h"
#include "LinkedList.h"
#include "DynamicArray.h"

template <typename T>
class ImmutableListSequence: public ImmutableSequence<T> {
private:
    LinkedList<T>* list;
    ImmutableListSequence<T>* instance() const {
        return new ImmutableListSequence<T>(*this);
    }
public:
    ImmutableListSequence(const T* items, int size): list(new LinkedList<T>(items, size)) {}
    ImmutableListSequence(): list(new LinkedList<T>) {}
    ImmutableListSequence(int size): list(new LinkedList<T>(size)) {}
    ImmutableListSequence(const ImmutableListSequence<T>& other): list(new LinkedList<T>(*other.list)) {}
    ImmutableListSequence(const Sequence<T>& other): list(new LinkedList<T>(other)) {}
    ImmutableListSequence(const LinkedList<T>& other): list(new LinkedList<T>(other)) {}
    ImmutableListSequence(const DynamicArray<T>& other) {
        T helpArray[other.getSize()];
        for (int i = 0; i < other.getSize(); ++i) {
            helpArray[i] = other.get(i);
        }
        list = new LinkedList<T>(helpArray, other.getSize());
    }

    ~ImmutableListSequence() override {
        delete list;
    }

    T operator[] (int index) const override {
        return (*list)[index];
    }

    ImmutableListSequence<T>& operator=(const ImmutableListSequence<T>& other) {
        return *this;
    }

    T getFirst() const override {
        return list->getFirst();
    }

    T getLast() const override {
        return list->getLast();
    }

    T get(int index) const override {
        return (*list)[index];
    }

    int getLength() const override {
        return list->getLength();
    }

    ImmutableListSequence<T>* append(const T& item) const override {
        ImmutableListSequence<T>* result = instance();
        result->list->append(item);
        return result;
    }

    ImmutableListSequence<T>* prepend(const T& item) const override {
        ImmutableListSequence<T>* result = instance();
        result->list->prepend(item);
        return result;
    }

    ImmutableListSequence<T>* insertAt(int index, const T& item) const override {
        ImmutableListSequence<T>* result = instance();
        result->list->insertAt(index, item);
        return result;
    }

    ImmutableListSequence<T>* getSubsequence(int startIndex, int endIndex) const override {
        if (startIndex > endIndex || startIndex < 0 || endIndex >= this->getLength()) throw std::out_of_range("Entered indices are out of range.\n");
        return new ImmutableListSequence<T>(*this->list->getSubsequence(startIndex, endIndex));
    }

    ImmutableListSequence<T>* concat(const Sequence<T>& other) const override {
        LinkedList<T> bufList;
        int i = 0;
        int length = this->getLength();
        for (; i < length; ++i) {
            bufList.append((*this)[i]);
        }
        for (; i < length + other.getLength(); ++i) {
            bufList.append(other.get(i - length));
        }
        return new ImmutableListSequence<T>(bufList);
    }
};


