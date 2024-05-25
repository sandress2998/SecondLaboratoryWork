#include "UI.h"
#include "Sequence.h" // для функции printSubsequence
#include "MutableListSequence.h"

// UI-оболочка(похожа ли?)
template <typename T>
struct UserSequence {

private:

    MutableListSequence<T>* sequence = new MutableListSequence<T>;

public:

    ~UserSequence() {
        delete sequence;
    }

    UserSequence() = default;

    void setValue() {
        int index;
        std::cout << "Enter the index of element: ";
        std::cin >> index;
        std::cout << "Enter the value of element number " << index << ": ";
        try {
            std::cin >> (*sequence)[index];
        } catch (const std::out_of_range& ex) {
            std::cout << ex.what();
        }
        std::cout << "\n\n";
    }

    void printValue() {
        int index;
        std::cout << "Enter the index of element: ";
        std::cin >> index;
        try {
            std::cout << sequence->get(index) << std::endl;
        } catch (const std::out_of_range& ex) {
            std::cout << ex.what();
        }
        std::cout << "\n\n";
    }
    void insertValue() {
        int index;
        std::cout << "Enter the index of element: ";
        std::cin >> index;
        std::cout << "Enter the value of element number " << index << ": ";
        try {
            T item;
            std::cin >> item;
            sequence->insertAt(index, item);
        } catch (const std::out_of_range& ex) {
            std::cout << ex.what();
        }
        std::cout << "\n\n";
    }

    void appendValue() {
        std::cout << "Enter the value of element: ";
        T item;
        std::cin >> item;
        sequence->append(item);
        std::cout << "\n\n";
    }

    void prependValue() {
        std::cout << "Enter the value of element: ";
        T item;
        std::cin >> item;
        sequence->prepend(item);
        std::cout << "\n\n";
    }

    void printFirst() {
        try {
            std::cout << sequence->getFirst();
        } catch(std::out_of_range& ex) {
            std::cout << ex.what();
        }
        std::cout << "\n\n";
    }

    void printLast() {
        try {
            std::cout << sequence->getLast();
        } catch(std::out_of_range& ex) {
            std::cout << ex.what();
        }
            std::cout << "\n\n";
        }

    void printSequence() {
        if (sequence->getLength() == 0) {
            std::cout << "Sequence is empty.\n";
            return;
        }
        std::cout << (*sequence);
        std::cout << "\n\n";
    }

    void printSubsequence() {
        int start;
        int end;
        std::cout << "Enter start and end indices of your subsequence: ";
        try {
            std::cin >> start >> end;
            Sequence<T>* subsequence = sequence->getSubsequence(start, end);
            std::cout << (*subsequence);
            delete subsequence;
        } catch (std::out_of_range& ex) {
            std::cout << ex.what();
        }
        std::cout << "\n\n";
    }
};

template <typename T>
class UI_Sequence {

private:

    void startSequence() {
        UserSequence<T> userSequence;

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
        // после этого удаляется userSequence и срабатывает его деконструктор.
    }

public:

    void start() {
        int action = 0;
        do {
            startSequence();
            std::cout << "If you want to end the program --> -2.\n" << "If you want to create new sequence --> enter any other number.\n";
            std::cin >> action;
        } while (action != -2);
        std::cout << "\nThe end of program.\n";
    }
};

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
    std::cout << "\n";
    return selectedNumber;
}

void startUI() {
    std::cout << "This is the program to work with the sequence. Let's start!\n\n\n";
    int selectedType = selectElementType();
    if (selectedType == 1) {
        UI_Sequence<int> ui;
        ui.start();
    } else if (selectedType == 2) {
        UI_Sequence<double> ui;
        ui.start();
    } else if (selectedType == 3) {
        UI_Sequence<char> ui;
        ui.start();
    }
}
