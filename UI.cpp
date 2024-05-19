#include "StartUI.h"
#include "UI.h"

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
