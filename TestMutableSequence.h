#pragma once

#include <cassert>
#include "DynamicArray.h"
#include "LinkedList.h"
#include "Sequence.h"
#include "ImmutableArraySequence.h"

template<template<class> class MutableSequence>
class TestMutableSequence {
public:
    void testClass() {
        testConstructors();
        testGet();
        testSquareBrackets();
        testGetLength();
        testSet();
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
        MutableSequence<int> mutSeq_1(length);
        assert(mutSeq_1.getLength() == length);
        try {
            MutableSequence<int> mutSeq_except(-1);
            assert(false);
        } catch (std::out_of_range&) {}

        int m[7] = {0, 1, 2, 3, 4, 5, 6};
        MutableSequence<int> mutSeq_2(m, 7);
        assert(mutSeq_2.getLength() == 7);
        for (int i = 0; i < mutSeq_2.getLength(); ++i) {
            assert(mutSeq_2.get(i) == m[i]);
        }
        try {
            MutableSequence<int> mutSeq_except(m, -1);
            assert(false);
        } catch (std::out_of_range&) {}


        MutableSequence<int> mutSeq_3(mutSeq_2);
        assert(mutSeq_3.getLength() == mutSeq_2.getLength());
        for (int i = 0; i < mutSeq_3.getLength(); ++i) {
            assert(mutSeq_3.get(i) == mutSeq_3.get(i));
        }

        LinkedList<int> ll(m, 7);
        MutableSequence<int> mutSeq_4(ll);
        assert(mutSeq_4.getLength() == ll.getLength());
        for (int i = 0; i < mutSeq_4.getLength(); ++i) {
            assert(mutSeq_4.get(i) == ll.get(i));
        }

        DynamicArray<int> da(m,7);
        MutableSequence<int> mutSeq_5(ll);
        assert(mutSeq_5.getLength() == da.getSize());
        for (int i = 0; i < mutSeq_5.getLength(); ++i) {
            assert(mutSeq_5.get(i) == da.get(i));
        }

        MutableSequence<int> mutSeq_6;
        assert(mutSeq_6.getLength() == 0);

        ImmutableArraySequence<int> immutArrSeq(m ,7);
        MutableSequence<int> mutSeq_7(immutArrSeq);
        assert(mutSeq_7.getLength() == immutArrSeq.getLength());
        for (int i = 0; i < 7; ++i) {
            assert(mutSeq_7.get(i) == immutArrSeq.get(i));
        }

    }

    void testSet() {
        int length = 7;
        int m[7] = {0, 1, 2, 3, 4, 5, 6};
        MutableSequence<int> mutSeq(m, length);
        int index1 = 0;
        int index2 = 3;
        int index3 = 6;
        int value = 100;
        mutSeq.set(index1, value);
        mutSeq.set(index2, value);
        mutSeq.set(index3, value);
        assert(mutSeq.get(index1) == value && mutSeq.get(index2) == value && mutSeq.get(index3) == value);
        try {
           mutSeq.set(-1, 10);
            assert(false);
        } catch (std::out_of_range&) {}
        try {
            mutSeq.set(length, 10);
            assert(false);
        } catch (std::out_of_range&) {}
    }

    void testGet() {
        int length = 7;
        int m[7] = {0, 1, 2, 3, 4, 5, 6};
        MutableSequence<int> mutSeq(m, length);
        for (int i = 0; i < 7; ++i) {
            assert(mutSeq.get(i) == m[i]);
        }
        try {
           mutSeq.get(-1);
            assert(false);
        } catch (std::out_of_range&) {}
        try {
            mutSeq.get(length);
            assert(false);
        } catch (std::out_of_range&) {}
    }

    void testSquareBrackets() {
        int length = 7;
        int m[7] = {0, 1, 2, 3, 4, 5, 6};
        MutableSequence<int> da(m, length);
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
        MutableSequence<int> mutSeq(m, length);
        assert(mutSeq.getFirst() == m[0]);
        try {
            MutableSequence<int> mutSeq_except;
            mutSeq_except.getFirst();
            assert(false);
        } catch (std::out_of_range&) {}
    }

    void testGetLast() {
        int length = 7;
        int m[7] = {0, 1, 2, 3, 4, 5, 6};
        MutableSequence<int> mutSeq(m, length);
        assert(mutSeq.getLast() == m[6]);
        try {
            MutableSequence<int> mutSeq_except;
            mutSeq_except.getLast();
            assert(false);
        } catch (std::out_of_range&) {}
    }

    void testGetLength() {
        int length = 7;
        int m[7] = {0, 1, 2, 3, 4, 5, 6};
        MutableSequence<int> mutSeq(m, length);
        assert(mutSeq.getLength() == 7);
    }

    void testAppend() {
        int length = 7;
        int m[7] = {0, 1, 2, 3, 4, 5, 6};
        MutableSequence<int> mutSeq(m, length);
        int elem = 100;
        mutSeq.append(elem);
        assert(mutSeq.getLength() == 8);
        for (int i = 0; i < 7; ++i) {
            assert(mutSeq.get(i) == m[i]);
        }
        assert(mutSeq.get(7) == elem);

        MutableSequence<int> mutSeq_2;
        mutSeq_2.append(elem);
        assert(mutSeq_2.get(0) == elem);
    }

    void testPrepend() {
        int length = 7;
        int m[7] = {0, 1, 2, 3, 4, 5, 6};
        MutableSequence<int> mutSeq(m, length);
        int elem = 100;
        mutSeq.prepend(elem);
        assert(mutSeq.getLength() == 8);
        assert(mutSeq.get(0) == elem);
        for (int i = 1; i < 8; ++i) {
            assert(mutSeq.get(i) == m[i - 1]);
        }

        MutableSequence<int> mutSeq_2;
        mutSeq_2.prepend(elem);
        assert(mutSeq_2.get(0) == elem);
    }

    void testInsertAt() {
        int length = 7;
        int m[7] = {0, 1, 2, 3, 4, 5, 6};
        MutableSequence<int> mutSeq(m, length);
        int elem = 100;
        int index_1 = 0; // крайний случай
        int index_2 = 3;
        int index_3 = 9; // крайний случай
        length += 3;
        mutSeq.insertAt(index_1, elem);
        mutSeq.insertAt(index_2, elem);
        mutSeq.insertAt(index_3, elem);
        assert(mutSeq.getLength() == 10);
        int i = 0;
        assert(mutSeq.get(i++) == elem);
        for (; i < index_2; ++i) {
            assert(mutSeq.get(i) == m[i - 1]);
        }
        assert(mutSeq.get(i++) == elem);
        for (; i < mutSeq.getLength() - 1; ++i) {
            assert(mutSeq.get(i) == m[i - 2]);
        }
        assert(mutSeq.get(i) == elem);

        try {
            mutSeq.insertAt(-1, 10);
            assert(false);
        } catch (std::out_of_range) {}
        try {
            mutSeq.insertAt(length + 1, 10);
            assert(false);
        } catch (std::out_of_range&) {}

        MutableSequence<int> mutSeq_2;
        mutSeq_2.insertAt(0, elem);
        assert(mutSeq_2.get(0) == elem);
    }

    void testGetSubsequence() {
        int length = 7;
        int m[7] = {0, 1, 2, 3, 4, 5, 6};
        MutableSequence<int> mutSeq(m, length);
        int startIndex = 2;
        int endIndex = 5;
        Sequence<int>* result = mutSeq.getSubsequence(startIndex, endIndex);
        for (int i = startIndex; i <= endIndex; ++i) {
            assert(result->get(i - startIndex) == m[i]);
        }
        try {
            mutSeq.getSubsequence(0, length);
            assert(false);
        } catch (std::out_of_range&) {}
        try {
            mutSeq.getSubsequence(-1, 0);
            assert(false);
        } catch (std::out_of_range&) {}
        try {
            mutSeq.getSubsequence(1, 0);
            assert(false);
        } catch (std::out_of_range&) {}
    }

    void testConcat() {
        int m_1[7] = {0, 1, 2, 3, 4, 5, 6};
        MutableSequence<int> mutSeq_1(m_1, 7);
        int m_2[3] = {7, 8, 9};
        MutableSequence<int> mutSeq_2(m_2, 3);
        Sequence<int>* result = mutSeq_1.concat(mutSeq_2);
        int i = 0;
        for (; i < 7; ++i) {
            assert(result->get(i) == m_1[i]);
        }
        for (; i < 10; ++i) {
            assert(result->get(i) == m_2[i - 7]);
        }
    }
};
