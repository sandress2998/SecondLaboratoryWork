#pragma once

#include <cassert>
#include "DynamicArray.h"
#include "LinkedList.h"
#include "Sequence.h"
#include "MutableArraySequence.h"

template<template<class> class ImmutableSequence>
class TestImmutableSequence {
public:
    void testClass() {
        testConstructors();
        testGet();
        testSquareBrackets();
        testGetLength();
        testAppend();
        testPrepend();
        testInsertAt();
        testConcat();
        testGetSubsequence();
        testGetFirst();
        testGetLast();
    }

    void testConstructors() {
        int length = 5;
        ImmutableSequence<int> immutSeq_1(length);
        assert(immutSeq_1.getLength() == length);
        try {
            ImmutableSequence<int> immutSeq_except(-1);
            assert(false);
        } catch (std::out_of_range&) {}

        int m[7] = {0, 1, 2, 3, 4, 5, 6};
        ImmutableSequence<int> immutSeq_2(m, 7);
        assert(immutSeq_2.getLength() == 7);
        for (int i = 0; i < immutSeq_2.getLength(); ++i) {
            assert(immutSeq_2.get(i) == m[i]);
        }
        try {
            ImmutableSequence<int> immutSeq_except(m, -1);
            assert(false);
        } catch (std::out_of_range&) {}

        ImmutableSequence<int> immutSeq_3(immutSeq_2);
        assert(immutSeq_3.getLength() == immutSeq_2.getLength());
        for (int i = 0; i < immutSeq_3.getLength(); ++i) {
            assert(immutSeq_3.get(i) == immutSeq_3.get(i));
        }

        LinkedList<int> ll(m, 7);
        ImmutableSequence<int> immutSeq_4(ll);
        assert(immutSeq_4.getLength() == ll.getLength());
        for (int i = 0; i < immutSeq_4.getLength(); ++i) {
            assert(immutSeq_4.get(i) == ll.get(i));
        }

        DynamicArray<int> da(m,7);
        ImmutableSequence<int> immutSeq_5(ll);
        assert(immutSeq_5.getLength() == da.getSize());
        for (int i = 0; i < immutSeq_5.getLength(); ++i) {
            assert(immutSeq_5.get(i) == da.get(i));
        }

        ImmutableSequence<int> immutSeq_6;
        assert(immutSeq_6.getLength() == 0);

        MutableArraySequence<int> mutArrSeq(m ,7);
        ImmutableSequence<int> immutSeq_7(mutArrSeq);
        assert(immutSeq_7.getLength() == mutArrSeq.getLength());
        for (int i = 0; i < 7; ++i) {
            assert(immutSeq_7.get(i) == mutArrSeq.get(i));
        }
    }

    void testGet() {
        int length = 7;
        int m[7] = {0, 1, 2, 3, 4, 5, 6};
        ImmutableSequence<int> immutSeq(m, length);
        for (int i = 0; i < 7; ++i) {
            assert(immutSeq.get(i) == m[i]);
        }
        try {
            immutSeq.get(-1);
            assert(false);
        } catch (std::out_of_range&) {}
        try {
            immutSeq.get(length);
            assert(false);
        } catch (std::out_of_range&) {}
    }

    void testSquareBrackets() {
        int length = 7;
        int m[7] = {0, 1, 2, 3, 4, 5, 6};
        ImmutableSequence<int> da(m, length);
        for (int i = 0; i < 7; ++i) {
            assert(da[i] == m[i]);
        }

        try {
            da[-1];
            assert(false);
        } catch (std::out_of_range&) {}
        try {
            da[length];
            assert(false);
        } catch (std::out_of_range&) {}
    }

    void testGetFirst() {
        int length = 7;
        int m[7] = {0, 1, 2, 3, 4, 5, 6};
        ImmutableSequence<int> immutSeq(m, length);
        assert(immutSeq.getFirst() == 0);
        try {
            ImmutableSequence<int> immutSeq_except;
            immutSeq_except.getFirst();
            assert(false);
        } catch (std::out_of_range&) {}
    }

    void testGetLast() {
        int length = 7;
        int m[7] = {0, 1, 2, 3, 4, 5, 6};
        ImmutableSequence<int> immutSeq(m, length);
        assert(immutSeq.getLast() == 6);
        try {
            ImmutableSequence<int> immutSeq_except;
            immutSeq_except.getLast();
            assert(false);
        } catch (std::out_of_range&) {}
    }

    void testGetLength() {
        int length = 7;
        int m[7] = {0, 1, 2, 3, 4, 5, 6};
        ImmutableSequence<int> immutSeq(m, length);
        assert(immutSeq.getLength() == 7);
    }

    void testAppend() {
        int length = 7;
        int m[7] = {0, 1, 2, 3, 4, 5, 6};
        ImmutableSequence<int> immutSeq(m, length);
        int elem = 100;
        Sequence<int>* immutSeq_2 = immutSeq.append(elem);
        assert(immutSeq_2->getLength() == 8);
        assert(immutSeq.getLength() == 7);
        for (int i = 0; i < immutSeq.getLength(); ++i) {
            assert(immutSeq.get(i) == m[i]);
            assert(immutSeq_2->get(i) == m[i]);
        }
        assert(immutSeq_2->get(7) == elem);
        delete immutSeq_2;

        ImmutableSequence<int> immutSeq_3; // пустая последовательность
        ImmutableSequence<int>* immutSeq_4 = immutSeq_3.append(elem);
        assert(immutSeq_4->get(0) == elem);
        delete immutSeq_4;
    }

    void testPrepend() {
        int length = 7;
        int m[7] = {0, 1, 2, 3, 4, 5, 6};
        ImmutableSequence<int> immutSeq(m, length);
        int elem = 100;
        Sequence<int>* immutSeq_2 = immutSeq.prepend(elem);
        assert(immutSeq.getLength() == 7);
        assert(immutSeq_2->getLength() == 8);
        assert(immutSeq_2->get(0) == elem);
        for (int i = 1; i < 8; ++i) {
            assert(immutSeq.get(i - 1) == m[i - 1]);
            assert(immutSeq_2->get(i) == m[i - 1]);
        }
        delete immutSeq_2;

        ImmutableSequence<int> immutSeq_3; // пустая последовательность
        ImmutableSequence<int>* immutSeq_4 = immutSeq_3.prepend(elem);
        assert(immutSeq_4->get(0) == elem);
        delete immutSeq_4;
    }

    void testInsertAt() {
        int length = 7;
        int m[7] = {0, 1, 2, 3, 4, 5, 6};
        ImmutableSequence<int> immutSeq(m, length);

        Sequence<int>* immutSeq_2;
        int elem = 100;
        int index = 3;
        immutSeq_2 = immutSeq.insertAt(index, elem);
        assert(immutSeq.getLength() == 7);
        assert(immutSeq_2->getLength() == 8);
        int i = 0;
        for (; i < index; ++i) {
            assert(immutSeq_2->get(i) == m[i]);
            assert(immutSeq.get(i) == m[i]);
        }
        assert(immutSeq_2->get(i++) == elem);
        for (; i < immutSeq_2->getLength(); ++i) {
            assert(immutSeq_2->get(i) == m[i - 1]);
            assert(immutSeq.get(i - 1) == m[i - 1]);
        }
        delete immutSeq_2;

        // крайний случай
        elem = 100;
        index = 0;
        immutSeq_2 = immutSeq.insertAt(index, elem);
        assert(immutSeq.getLength() == 7);
        assert(immutSeq_2->getLength() == 8);
        i = 0;
        assert(immutSeq_2->get(i++) == elem);
        for (; i < immutSeq_2->getLength(); ++i) {
            assert(immutSeq_2->get(i) == m[i - 1]);
            assert(immutSeq.get(i - 1) == m[i - 1]);
        }
        delete immutSeq_2;

        // крайний случай
        elem = 100;
        index = 7;
        immutSeq_2 = immutSeq.insertAt(index, elem);
        assert(immutSeq.getLength() == 7);
        assert(immutSeq_2->getLength() == 8);
        i = 0;
        for (; i < index; ++i) {
            assert(immutSeq_2->get(i) == m[i]);
            assert(immutSeq.get(i) == m[i]);
        }
        assert(immutSeq_2->get(i++) == elem);
        delete immutSeq_2;

        try {
            immutSeq.insertAt(-1, elem);
            assert(false);
        } catch (std::out_of_range&) {}

        try {
            immutSeq.insertAt(length + 1, elem);
            assert(false);
        } catch (std::out_of_range&) {}


        ImmutableSequence<int> immutSeq_3; // пустая последовательность
        ImmutableSequence<int>* immutSeq_4 = immutSeq_3.insertAt(0, elem);
        assert(immutSeq_4->get(0) == elem);
        delete immutSeq_4;
    }

    void testGetSubsequence() {
        int length = 7;
        int m[7] = {0, 1, 2, 3, 4, 5, 6};
        ImmutableSequence<int> immutSeq(m, length);
        int startIndex = 2;
        int endIndex = 5;
        Sequence<int>* result = immutSeq.getSubsequence(startIndex, endIndex);
        for (int i = startIndex; i <= endIndex; ++i) {
            assert(result->get(i - startIndex) == m[i]);
        }
        try {
            immutSeq.getSubsequence(0, length);
            assert(false);
        } catch (std::out_of_range) {}
        try {
            immutSeq.getSubsequence(-1, 0);
            assert(false);
        } catch (std::out_of_range) {}
        try {
            immutSeq.getSubsequence(1, 0);
            assert(false);
        } catch (std::out_of_range&) {}
    }

    void testConcat() {
        int m_1[7] = {0, 1, 2, 3, 4, 5, 6};
        ImmutableSequence<int> immutSeq_1(m_1, 7);
        int m_2[3] = {7, 8, 9};
        ImmutableSequence<int> immutSeq_2(m_2, 3);
        Sequence<int>* result = immutSeq_1.concat(immutSeq_2);
        int i = 0;
        for (; i < 7; ++i) {
            assert(result->get(i) == m_1[i]);
        }
        for (; i < 10; ++i) {
            assert(result->get(i) == m_2[i - 7]);
        }
    }
};
