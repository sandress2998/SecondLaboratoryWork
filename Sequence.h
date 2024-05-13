#pragma once

template <class T>
class Sequence {
public:
    virtual ~Sequence() = default;
    virtual T getFirst() const = 0;
    virtual T getLast() const = 0;
    virtual T get(int index) const = 0; // int

    virtual int getLength() const = 0;

    virtual Sequence<T>* getSubsequence(int startIndex, int endIndex) const = 0;
    virtual Sequence<T>* concat(const Sequence<T>& secondSequence) const = 0;

    virtual void print() const = 0;

    bool operator==(const Sequence<T>& sequence) const {
        if (this->getLength() != sequence.getLength()) return false;
        for (int i = 0; i < this->getLength(); ++i) {
            if ((*this)[i] != sequence[i]) {
                return false;
            }
        }
        return true;
    }
};

