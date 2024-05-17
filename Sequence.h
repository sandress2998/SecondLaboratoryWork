#pragma once
#include <iostream>

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

    bool operator==(const Sequence<T>& sequence) const {
        if (this->getLength() != sequence.getLength()) return false;
        for (int i = 0; i < this->getLength(); ++i) {
            if ((*this)[i] != sequence[i]) {
                return false;
            }
        }
        return true;
    }

    friend std::ostream& operator<<( std::ostream& os, const Sequence<T>& value ) {
        if (value.getLength() == 0) return os;
        int i = 0;
        for (; i < value.getLength() - 1; ++i) {
            os << value.get(i) << " ";
        }
        os << value.get(i) << "\n";
        return os;
    }
};

