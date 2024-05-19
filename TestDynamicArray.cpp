#include <cassert>
#include "DynamicArray.h"
#include "LinkedList.h"
#include "Sequence.h"
#include "MutableListSequence.h"
#include "TestDynamicArray.h"

void TestDynamicArray::testClass() {
    testConstructors();
    testGet();
    testSquareBrackets();
    testGetSize();
    testSet();
    testResize();
}

void TestDynamicArray::testConstructors() {

    DynamicArray<int> da_1(5);
    assert(da_1.getSize() == 5);
    try {
        DynamicArray<int> da_except(-1);
        assert(false);
    } catch (std::out_of_range&) {}

    int m[7] = {0, 1, 2, 3, 4, 5, 6};
    DynamicArray<int> da_2(m, 7);
    assert(da_2.getSize() == 7);
    for (int i = 0; i < da_2.getSize(); ++i) {
        assert(da_2.get(i) == m[i]);
    }
    try {
        DynamicArray<int> da_except(m, -1);
        assert(false);
    } catch (std::out_of_range&) {}

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

void TestDynamicArray::testSet() {
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
    } catch (std::out_of_range&) {}
    try {
        da.set(length, 10);
        assert(false);
    } catch (std::out_of_range&) {}
}

void TestDynamicArray::testGet() {
    int length = 7;
    int m[7] = {0, 1, 2, 3, 4, 5, 6};
    DynamicArray<int> da(m, length);
    for (int i = 0; i < 7; ++i) {
        assert(da.get(i) == m[i]);
    }

    try {
        da.get(-1);
        assert(false);
    } catch (std::out_of_range&) {}
    try {
        da.get(length);
        assert(false);
    } catch (std::out_of_range&) {}
}


void TestDynamicArray::testSquareBrackets() {
    int length = 7;
    int m[7] = {0, 1, 2, 3, 4, 5, 6};
    DynamicArray<int> da(m, length);
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

void TestDynamicArray::testGetSize() {
    int m[7] = {0, 1, 2, 3, 4, 5, 6};
    DynamicArray<int> da(m, 7);
    assert(da.getSize() == 7);
}

void TestDynamicArray::testResize() {
    int length = 7;
    int m[7] = {0, 1, 2, 3, 4, 5, 6};
    DynamicArray<int> da(m, length);
    try {
        da.resize(-1);
        assert(false);
    } catch (std::out_of_range&) {}

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
