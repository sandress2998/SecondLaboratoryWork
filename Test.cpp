#include "Test.h"
#include "TestDynamicArray.h"
#include "TestLinkedList.h"
#include "TestMutableSequence.h"
#include "TestImmutableSequence.h"
#include "MutableArraySequence.h"
#include "MutableListSequence.h"
#include "ImmutableArraySequence.h"
#include "ImmutableListSequence.h"

void Test::startTest() {
    testMutableArraySequence();
    testMutableListSequence();
    testImmutableArraySequence();
    testImmutableListSequence();
    testDynamicArray();
    testLinkedList();
}

void Test::testDynamicArray() {
    TestDynamicArray testDynamicArray;
    testDynamicArray.testClass();
}

void Test::testLinkedList() {
    TestLinkedList testLinkedList;
    testLinkedList.testClass();
}

void Test::testMutableArraySequence() {
    TestMutableSequence<MutableArraySequence> testMutableArraySequence;
    testMutableArraySequence.testClass();
}

void Test::testMutableListSequence() {
    TestMutableSequence<MutableListSequence> testMutableListSequence;
    testMutableListSequence.testClass();
}

void Test::testImmutableArraySequence() {
    TestImmutableSequence<ImmutableArraySequence> testImmutableArraySequence;
    testImmutableArraySequence.testClass();
}

void Test::testImmutableListSequence() {
    TestImmutableSequence<ImmutableListSequence> testImmutableListSequence;
    testImmutableListSequence.testClass();
}
