#pragma once

#include "Sequence.h" // для функции printSubsequence
#include "MutableListSequence.h"
#include "MutableArraySequence.h"
#include "MutableSequence.h"
// UI-оболочка(похожа ли?)

class UI_Sequence {

private:

    struct UserSequence {

    private:

        MutableSequence<int>* sequenceInt = nullptr;
        MutableSequence<double>* sequenceDouble = nullptr;
        MutableSequence<char>* sequenceChar = nullptr;

    public:

        ~UserSequence() {
            delete sequenceInt;
            delete sequenceDouble;
            delete sequenceChar;
        }

        int selectSequenceLength() {
            std::cout << "Select sequence length:\n";
            int selectedLength;
            std::cin >> selectedLength;
            while (selectedLength < 0) {
                std::cout << "You entered the invalid length. Try again\n\n";
                std::cin >> selectedLength;
            }
            return selectedLength;
        }

        UserSequence(int selectedSequence, int selectedType) {
            if (selectedType == 1 && selectedSequence == 1) {
                sequenceInt = new MutableArraySequence<int>(selectSequenceLength());
            } else if (selectedSequence == 2 && selectedType == 1) {
                sequenceInt = new MutableListSequence<int>(selectSequenceLength());
            } else if (selectedSequence == 1 && selectedType == 2) {
                sequenceDouble = new MutableArraySequence<double>(selectSequenceLength());
            } else if (selectedSequence == 2 && selectedType == 2) {
                sequenceDouble = new MutableListSequence<double>(selectSequenceLength());
            } else if (selectedSequence == 1 && selectedType == 3) {
                sequenceChar = new MutableArraySequence<char>(selectSequenceLength());
            } else if (selectedSequence == 2 && selectedType == 3) {
                sequenceChar = new MutableListSequence<char>(selectSequenceLength());
            }
        }

        void setValue() {
            int index;
            std::cout << "Enter the index of element: ";
            std::cin >> index;
            std::cout << "Enter the value of element number " << index << ": ";
            try {
                if (sequenceInt != nullptr) {
                    std::cin >> (*sequenceInt)[index];
                } else if (sequenceDouble != nullptr) {
                    std::cin >> (*sequenceDouble)[index];
                } else if (sequenceChar != nullptr) {
                    std::cin >> (*sequenceChar)[index];
                }
            } catch (const std::out_of_range& ex) {
                std::cout << "You entered the invalid index. Try again.\n\n";
                setValue();
            }
            std::cout << "\n\n";
        }
        void printValue() {
            int index;
            std::cout << "Enter the index of element: ";
            std::cin >> index;
            try {
                if (sequenceInt != nullptr) {
                    std::cout << sequenceInt->get(index) << std::endl;
                } else if (sequenceDouble != nullptr) {
                    std::cout << sequenceDouble->get(index) << std::endl;
                } else if (sequenceChar != nullptr) {
                    std::cout << sequenceChar->get(index) << std::endl;
                }
            } catch (const std::out_of_range& ex) {
                std::cout << "You entered the invalid index. Try again.\n\n";
                printValue();
            }
            std::cout << "\n\n";
        }

        void insertValue() {
            int index;
            std::cout << "Enter the index of element: ";
            std::cin >> index;
            std::cout << "Enter the value of element number " << index << ": ";
            try {
                if (sequenceInt != nullptr) {
                    int item;
                    std::cin >> item;
                    sequenceInt->insertAt(index, item);
                } else if (sequenceDouble != nullptr) {
                    double item;
                    std::cin >> item;
                    sequenceDouble->insertAt(index, item);
                } else if (sequenceChar != nullptr) {
                    char item;
                    std::cin >> item;
                    sequenceChar->insertAt(index, item);
                }
            } catch (const std::out_of_range& ex) {
                std::cout << "You entered the invalid index. Try again.\n\n";
                insertValue();
            }
            std::cout << "\n\n";
        }

        void appendValue() {
            std::cout << "Enter the value of element: ";
            if (sequenceInt != nullptr) {
                int item;
                std::cin >> item;
                sequenceInt->append(item);
            } else if (sequenceDouble != nullptr) {
                double item;
                std::cin >> item;
                sequenceDouble->append(item);
            } else if (sequenceChar != nullptr) {
                char item;
                std::cin >> item;
                sequenceChar->append(item);
            }
            std::cout << "\n\n";
        }

        void prependValue() {
            std::cout << "Enter the value of element: ";
            if (sequenceInt != nullptr) {
                int item;
                std::cin >> item;
                sequenceInt->prepend(item);
            } else if (sequenceDouble != nullptr) {
                double item;
                std::cin >> item;
                sequenceDouble->prepend(item);
            } else if (sequenceChar != nullptr) {
                char item;
                std::cin >> item;
                sequenceChar->prepend(item);
            }
            std::cout << "\n\n";
        }

        void printFirst() {
            if (sequenceInt != nullptr) {
                std::cout << sequenceInt->getFirst() << std::endl;
            } else if (sequenceDouble != nullptr) {
                std::cout << sequenceDouble->getFirst() << std::endl;
            } else if (sequenceChar != nullptr) {
                std::cout << sequenceChar->getFirst() << std::endl;
            }
            std::cout << "\n\n";
        }

        void printLast() {
            if (sequenceInt != nullptr) {
                std::cout << sequenceInt->getLast() << std::endl;
            } else if (sequenceDouble != nullptr) {
                std::cout << sequenceDouble->getLast() << std::endl;
            } else if (sequenceChar != nullptr) {
                std::cout << sequenceChar->getLast() << std::endl;
            }
            std::cout << "\n\n";
        }

        void printSequence() {
            if (sequenceInt != nullptr) {
                sequenceInt->print();
            } else if (sequenceDouble != nullptr) {
                sequenceDouble->print();
            } else if (sequenceChar != nullptr) {
                sequenceChar->print();
            }
            std::cout << "\n\n";
        }

        void printSubsequence() {
            int start;
            int end;
            std::cout << "Enter start and end indices of your subsequence: ";
            try {
                if (sequenceInt != nullptr) {
                    std::cin >> start >> end;
                    Sequence<int>* subsequenceInt = sequenceInt->getSubsequence(start, end);
                    subsequenceInt->print();
                    delete subsequenceInt;
                } else if (sequenceDouble != nullptr) {
                    std::cin >> start >> end;
                    Sequence<double>* subsequenceDouble = sequenceDouble->getSubsequence(start, end);
                    subsequenceDouble->print();
                    delete subsequenceDouble;
                } else if (sequenceChar != nullptr) {
                    std::cin >> start >> end;
                    Sequence<char>* subsequenceChar = sequenceChar->getSubsequence(start, end);
                    subsequenceChar->print();
                    delete subsequenceChar;
                }
            } catch (std::out_of_range) {
                std::cout << "You entered the invalid indices. Try again.\n\n";
                printSubsequence();
            }
            std::cout << "\n\n";
        }

        void initializeSequence() {
            std::cout << "Enter the values to initialize your sequence:\n";
            if (sequenceInt != nullptr) {
                for (int i = 0; i < sequenceInt->getLength(); ++i) {
                    int item;
                    std::cin >> item;
                    sequenceInt->set(i, item);
                }
            } else if (sequenceDouble != nullptr) {
                for (int i = 0; i < sequenceDouble->getLength(); ++i) {
                    double item;
                    std::cin >> item;
                    sequenceDouble->set(i, item);
                }
            } else if (sequenceChar != nullptr) {
                for (int i = 0; i < sequenceChar->getLength(); ++i) {
                    char item;
                    std::cin >> item;
                    sequenceChar->set(i, item);
                }
            }
            std::cout << "\n\n";
        }
    };

    int selectSequenceType() {
        std::cout << "Select the sequence you want to create:\n"
            << "MutableArraySequence --> enter 1,\n"
            << "MutableListSequence --> enter 2.\n";
        int selectedNumber;
        std::cin >> selectedNumber;
        while (selectedNumber > 2 || selectedNumber < 1) {
            std::cout << "You entered the invalid number. Try again.\n\n";
            std::cin >> selectedNumber;
        }
        return selectedNumber;
    }

    int selectElementType() {
        std::cout << "Select the type of elements in your sequence:\n"
            << "int --> enter 1,\n"
            << "double --> enter 2,\n"
            << "char --> enter 3.\n";
        int selectedNumber;
        std::cin >> selectedNumber;
        while (selectedNumber > 3 || selectedNumber < 1) {
            std::cout << "You entered the invalid number. Try again.\n\n";
            std::cin >> selectedNumber;
        }
        return selectedNumber;
    }

    void startSequence() {
            int selectedType = selectElementType();
            int selectedSequence = selectSequenceType();
            UserSequence userSequence(selectedSequence, selectedType);
            userSequence.initializeSequence();

            int numberOfAction;
            std::cout << "Now you can select what to do with your sequence:\n"
            << "0 --> printSequence,\n"
            << "1 --> printValue,\n"
            << "2 --> setValue,\n"
            << "3 --> insertValue,\n"
            << "4 --> appendValue,\n"
            << "5 --> prependValue,\n"
            << "6 --> printFirst,\n"
            << "7 --> printLast,\n"
            << "8 --> printSubsequence,\n"
            << "-1 --> end.\n\nEnter the number of action: ";

            std::cin >> numberOfAction;

            while (numberOfAction != -1) {
                switch (numberOfAction) {
                case 0:
                    userSequence.printSequence();
                    break;
                case 1:
                    userSequence.printValue();
                    break;
                case 2:
                    userSequence.setValue();
                    break;
                case 3:
                    userSequence.insertValue();
                    break;
                case 4:
                    userSequence.appendValue();
                    break;
                case 5:
                    userSequence.prependValue();
                    break;
                case 6:
                    userSequence.printFirst();
                    break;
                case 7:
                    userSequence.printLast();
                    break;
                case 8:
                    userSequence.printSubsequence();
                    break;
                }
                std::cout << "Enter the number of action: ";
                std::cin >> numberOfAction;
            }
            // после этого удаляется userSequence и срабатывает его деконструктор, так что удаляться и все Sequence(sequenceInt, sequenceDouble, sequenceChar)
        }

public:

    void start() {
        std::cout << "This is the program to work with the sequence. Let's start!\n\n\n";
        int action = 0;
        do {
            startSequence();
            std::cout << "If you want to end the program --> -2.\n" << "If you want to create new sequence --> enter any other number.\n";
            std::cin >> action;
        } while (action != -2);
        std::cout << "\nThe end of program.\n";
    }
};
