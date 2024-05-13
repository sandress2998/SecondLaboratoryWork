#pragma once

#include <cassert>
#include "DynamicArray.h"
#include "LinkedList.h"
#include "Sequence.h"
#include "MutableArraySequence.h"
#include "MutableListSequence.h"
#include "ImmutableArraySequence.h"
#include "ImmutableListSequence.h"

class TestDynamicArray {
public:

    void testClass() {
        testConstructors();
        testGet();
        testGetSize();
        testSet();
        testResize();
    }
    void testConstructors() {

        DynamicArray<int> da_1(5);
        assert(da_1.getSize() == 5);
        try {
            DynamicArray<int> da_except(-1);
            assert(false);
        } catch (std::out_of_range) {}

        int m[7] = {0, 1, 2, 3, 4, 5, 6};
        DynamicArray<int> da_2(m, 7);
        assert(da_2.getSize() == 7);
        for (int i = 0; i < da_2.getSize(); ++i) {
            assert(da_2.get(i) == m[i]);
        }
        try {
            DynamicArray<int> da_except(m, -1);
            assert(false);
        } catch (std::out_of_range) {}

        DynamicArray<int> da_3(da_2);
        assert(da_3.getSize() == da_2.getSize());
        for (int i = 0; i < da_3.getSize(); ++i) {
            assert(da_3.get(i) == da_3.get(i));
        }

        MutableListSequence<int> mls(m, 7);
        DynamicArray<int> da_4(mls);
        assert(da_4.getSize() == mls.getLength());
        for (int i = 0; i < da_4.getSize(); ++i) {
            assert(da_4.get(i) == mls.get(i));
        }

        LinkedList<int> ll(m, 7);
        DynamicArray<int> da_5(ll);
        assert(da_5.getSize() == ll.getLength());
        for (int i = 0; i < da_5.getSize(); ++i) {
            assert(da_5.get(i) == ll.get(i));
        }
    }

    void testSet() {
        int length = 7;
        int m[7] = {0, 1, 2, 3, 4, 5, 6};
        DynamicArray<int> da(m, length);
        int index1 = 0;
        int index2 = 3;
        int index3 = 6;
        int value = 100;
        da.set(index1, value);
        da.set(index2, value);
        da.set(index3, value);
        assert(da.get(index1) == value && da.get(index2) == value && da.get(index3) == value);
        try {
            da.set(-1, 10);
            assert(false);
        } catch (std::out_of_range) {}
        try {
            da.set(length, 10);
            assert(false);
        } catch (std::out_of_range) {}
    }

    void testGet() {
        int length = 7;
        int m[7] = {0, 1, 2, 3, 4, 5, 6};
        DynamicArray<int> da(m, length);
        for (int i = 0; i < 7; ++i) {
            assert(da.get(i) == m[i]);
        }
        try {
            da.get(-1);
            assert(false);
        } catch (std::out_of_range) {}
        try {
            da.get(length);
            assert(false);
        } catch (std::out_of_range) {}
    }

    void testGetSize() {
        int m[7] = {0, 1, 2, 3, 4, 5, 6};
        DynamicArray<int> da(m, 7);
        assert(da.getSize() == 7);
    }

    void testResize() {
        int length = 7;
        int m[7] = {0, 1, 2, 3, 4, 5, 6};
        DynamicArray<int> da(m, length);
        try {
            da.resize(-1);
            assert(false);
        } catch (std::out_of_range) {}

        da.resize(10);
        assert(da.getSize() == 10);
        for (int i = 0; i < 7; ++i) {
            assert(da.get(i) == m[i]);
        }
        da.resize(4);
        assert(da.getSize() == 4);
        for (int i = 0; i < 4; ++i) {
            assert(da.get(i) == m[i]);
        }
    }
};


class TestLinkedList {
public:

    void testClass() {
        testConstructors();
        testGet();
        testGetLength();
        testSet();
        testGetFirst();
        testGetLast();
        testAppend();
        testPrepend();
        testInsertAt();
        testConcat();
        testGetSubsequence();
    }

    void testConstructors() {

        LinkedList<int> ll_0;
        assert(ll_0.getLength() == 0);

        int m[7] = {0, 1, 2, 3, 4, 5, 6};
        LinkedList<int> ll_2(m, 7);
        assert(ll_2.getLength() == 7);
        for (int i = 0; i < ll_2.getLength(); ++i) {
            assert(ll_2.get(i) == m[i]);
        }
        try {
            LinkedList<int> ll_except(m, -1);
            assert(false);
        } catch (std::out_of_range) {}

        LinkedList<int> ll_3(ll_2);
        assert(ll_3.getLength() == ll_2.getLength());
        for (int i = 0; i < ll_3.getLength(); ++i) {
            assert(ll_3.get(i) == ll_3.get(i));
        }

        MutableListSequence<int> mls(m, 7);
        LinkedList<int> ll_4(mls);
        assert(ll_4.getLength() == mls.getLength());
        for (int i = 0; i < ll_4.getLength(); ++i) {
            assert(ll_4.get(i) == mls.get(i));
        }

        int length = 5;
        LinkedList<int> ll_5(length);
        assert(ll_5.getLength() == length);
        try {
            LinkedList<int> ll_except(-1);
            assert(false);
        } catch (std::out_of_range) {}
    }

    void testSet() {
        int length = 7;
        int m[7] = {0, 1, 2, 3, 4, 5, 6};
        LinkedList<int> ll(m, length);
        int index1 = 0;
        int index2 = 3;
        int index3 = 6;
        int value = 100;
        ll.set(index1, value);
        ll.set(index2, value);
        ll.set(index3, value);
        assert(ll.get(index1) == value && ll.get(index2) == value && ll.get(index3) == value);
        try {
            ll.set(-1, 10);
            assert(false);
        } catch (std::out_of_range) {}
        try {
            ll.set(length, 10);
            assert(false);
        } catch (std::out_of_range) {}
    }

    void testGet() {
        int length = 7;
        int m[7] = {0, 1, 2, 3, 4, 5, 6};
        LinkedList<int> ll(m, length);
        for (int i = 0; i < length; ++i) {
            assert(ll.get(i) == m[i]);
        }
        try {
            ll.get(-1);
            assert(false);
        } catch (std::out_of_range) {}
        try {
            ll.get(length);
            assert(false);
        } catch (std::out_of_range) {}
    }

    void testGetLength() {
        int m[7] = {0, 1, 2, 3, 4, 5, 6};
        LinkedList<int> ll(m, 7);
        assert(ll.getLength() == 7);
    }

    void testGetFirst() {
        int length = 7;
        int m[7] = {0, 1, 2, 3, 4, 5, 6};
        LinkedList<int> ll(m, length);
        assert(ll.getFirst() == m[0]);

        LinkedList<int> ll_except;
        try {
            ll_except.getFirst();
            assert(false);
        } catch (std::out_of_range) {}
    }

    void testGetLast() {
        int length = 7;
        int m[7] = {0, 1, 2, 3, 4, 5, 6};
        LinkedList<int> ll(m, length);
        assert(ll.getLast() == m[6]);

        LinkedList<int> ll_except;
        try {
            ll_except.getFirst();
            assert(false);
        } catch (std::out_of_range) {}
    }

    void testAppend() {
        int m[7] = {0, 1, 2, 3, 4, 5, 6};
        LinkedList<int> ll(m, 7);
        int elem = 100;
        ll.append(elem);
        assert(ll.getLength() == 8);
        for (int i = 0; i < 7; ++i) {
            assert(ll.get(i) == m[i]);
        }
        assert(ll.get(7) == elem);
    }

    void testPrepend() {
        int m[7] = {0, 1, 2, 3, 4, 5, 6};
        LinkedList<int> ll(m, 7);
        int elem = 100;
        ll.prepend(elem);
        assert(ll.getLength() == 8);
        assert(ll.get(0) == elem);
        for (int i = 1; i < 8; ++i) {
            assert(ll.get(i) == m[i - 1]);
        }
    }

    void testInsertAt() {
        int length = 7;
        int m[7] = {0, 1, 2, 3, 4, 5, 6};
        LinkedList<int> ll(m, 7);
        int elem = 100;
        int index_1 = 0; // крайний случай
        int index_2 = 3;
        int index_3 = 9; // крайний случай
        length += 3;
        ll.insertAt(index_1, elem);
        ll.insertAt(index_2, elem);
        ll.insertAt(index_3, elem);
        assert(ll.getLength() == 10);
        int i = 0;
        assert(ll.get(i++) == elem);
        for (; i < index_2; ++i) {
            assert(ll.get(i) == m[i - 1]);
        }
        assert(ll.get(i++) == elem);
        for (; i < ll.getLength() - 1; ++i) {
            assert(ll.get(i) == m[i - 2]);
        }
        assert(ll.get(i) == elem);

        try {
            ll.insertAt(-1, 10);
            assert(false);
        } catch (std::out_of_range) {}
        try {
            ll.insertAt(length + 1, 10);
            assert(false);
        } catch (std::out_of_range) {}
    }

    void testGetSubsequence() {
        int length = 7;
        int m[7] = {0, 1, 2, 3, 4, 5, 6};
        LinkedList<int> ll(m, length);
        int startIndex = 2;
        int endIndex = 5;
        LinkedList<int>* result = ll.getSubsequence(startIndex, endIndex);
        for (int i = startIndex; i <= endIndex; ++i) {
            assert(result->get(i - startIndex) == m[i]);
        }
        try {
            ll.getSubsequence(0, length);
            assert(false);
        } catch (std::out_of_range) {}
        try {
            ll.getSubsequence(-1, 0);
            assert(false);
        } catch (std::out_of_range) {}
        try {
            ll.getSubsequence(1, 0);
            assert(false);
        } catch (std::out_of_range) {}

    }

    void testConcat() {
        int m_1[7] = {0, 1, 2, 3, 4, 5, 6};
        LinkedList<int> ll_1(m_1, 7);
        int m_2[3] = {7, 8, 9};
        LinkedList<int> ll_2(m_2, 3);
        LinkedList<int>* result = ll_1.concat(&ll_2);
        int i = 0;
        for (; i < 7; ++i) {
            assert(result->get(i) == m_1[i]);
        }
        for (; i < 10; ++i) {
            assert(result->get(i) == m_2[i - 7]);
        }
    }
};

template<template<class> class MutableSequence>
class TestMutableSequence {
public:
    void testClass() {
        testConstructors();
        testGet();
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
        } catch (std::out_of_range) {}

        int m[7] = {0, 1, 2, 3, 4, 5, 6};
        MutableSequence<int> mutSeq_2(m, 7);
        assert(mutSeq_2.getLength() == 7);
        for (int i = 0; i < mutSeq_2.getLength(); ++i) {
            assert(mutSeq_2.get(i) == m[i]);
        }
        try {
            MutableSequence<int> mutSeq_except(m, -1);
            assert(false);
        } catch (std::out_of_range) {}


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
        } catch (std::out_of_range) {}
        try {
            mutSeq.set(length, 10);
            assert(false);
        } catch (std::out_of_range) {}
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
        } catch (std::out_of_range) {}
        try {
            mutSeq.get(length);
            assert(false);
        } catch (std::out_of_range) {}
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
        } catch (std::out_of_range) {}
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
        } catch (std::out_of_range) {}
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
        } catch (std::out_of_range) {}
    }
    void testGetSubsequence() {
        int length = 7;
        int m[7] = {0, 1, 2, 3, 4, 5, 6};
        MutableSequence<int> mutSeq(m, length);
        int startIndex = 2;
        int endIndex = 5;
        MutableSequence<int>* result = mutSeq.getSubsequence(startIndex, endIndex);
        for (int i = startIndex; i <= endIndex; ++i) {
            assert(result->get(i - startIndex) == m[i]);
        }
        try {
            mutSeq.getSubsequence(0, length);
            assert(false);
        } catch (std::out_of_range) {}
        try {
            mutSeq.getSubsequence(-1, 0);
            assert(false);
        } catch (std::out_of_range) {}
        try {
            mutSeq.getSubsequence(1, 0);
            assert(false);
        } catch (std::out_of_range) {}
    }
    void testConcat() {
        int m_1[7] = {0, 1, 2, 3, 4, 5, 6};
        MutableSequence<int> mutSeq_1(m_1, 7);
        int m_2[3] = {7, 8, 9};
        MutableSequence<int> mutSeq_2(m_2, 3);
        MutableSequence<int>* result = mutSeq_1.concat(mutSeq_2);
        int i = 0;
        for (; i < 7; ++i) {
            assert(result->get(i) == m_1[i]);
        }
        for (; i < 10; ++i) {
            assert(result->get(i) == m_2[i - 7]);
        }
    }
};


template<template<class> class ImmutableSequence>
class TestImmutableSequence {
public:

    void testClass() {
        testConstructors();
        testGet();
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
        } catch (std::out_of_range) {}

        int m[7] = {0, 1, 2, 3, 4, 5, 6};
        ImmutableSequence<int> immutSeq_2(m, 7);
        assert(immutSeq_2.getLength() == 7);
        for (int i = 0; i < immutSeq_2.getLength(); ++i) {
            assert(immutSeq_2.get(i) == m[i]);
        }
        try {
            ImmutableSequence<int> immutSeq_except(m, -1);
            assert(false);
        } catch (std::out_of_range) {}

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
        } catch (std::out_of_range) {}
        try {
            immutSeq.get(length);
            assert(false);
        } catch (std::out_of_range) {}
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
        } catch (std::out_of_range) {}
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
        } catch (std::out_of_range) {}
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
        } catch (std::out_of_range) {}

        try {
            immutSeq.insertAt(length + 1, elem);
            assert(false);
        } catch (std::out_of_range) {}
    }

    void testGetSubsequence() {
        int length = 7;
        int m[7] = {0, 1, 2, 3, 4, 5, 6};
        ImmutableSequence<int> immutSeq(m, length);
        int startIndex = 2;
        int endIndex = 5;
        ImmutableSequence<int>* result = immutSeq.getSubsequence(startIndex, endIndex);
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
        } catch (std::out_of_range) {}
    }

    void testConcat() {
        int m_1[7] = {0, 1, 2, 3, 4, 5, 6};
        ImmutableSequence<int> immutSeq_1(m_1, 7);
        int m_2[3] = {7, 8, 9};
        ImmutableSequence<int> immutSeq_2(m_2, 3);
        ImmutableSequence<int>* result = immutSeq_1.concat(immutSeq_2);
        int i = 0;
        for (; i < 7; ++i) {
            assert(result->get(i) == m_1[i]);
        }
        for (; i < 10; ++i) {
            assert(result->get(i) == m_2[i - 7]);
        }
    }
};

struct Test {
    TestMutableSequence<MutableArraySequence> testMutableArraySequence;
    TestMutableSequence<MutableListSequence> testMutableListSequence;
    TestImmutableSequence<ImmutableArraySequence> testImmutableArraySequence;
    TestImmutableSequence<ImmutableListSequence> testImmutableListSequence;
    TestDynamicArray testDynamicArray;
    TestLinkedList testLinkedList;

    void startTest() {
        testMutableArraySequence.testClass();
        testMutableListSequence.testClass();
        testImmutableArraySequence.testClass();
        testImmutableListSequence.testClass();
        testDynamicArray.testClass();
        testLinkedList.testClass();
    }
};
