#include "money.h"

int main() {
    Money money1, money2, money3, money4, money5, money6;

    std::cout << "Enter the first amount:\n";
    std::cin >> money1;

    std::cout << "Enter the second amount:\n";
    std::cin >> money2;

    std::cout << "\nEntered amounts:\n";
    std::cout << "money1: " << money1 << std::endl;
    std::cout << "money2: " << money2 << std::endl;

    money3 = money1 + money2;
    std::cout << "\nResult of addition:\n";
    std::cout << "money1 + money2: " << money3 << std::endl;

    int divisor1;
    std::cout << "\nEnter an integer to divide the first amount by:\n";
    std::cin >> divisor1;
    money4 = money1 / divisor1;
    std::cout << "Result of dividing the first amount by " << divisor1 << ": " << money4 << std::endl;

    double divisor2;
    std::cout << "\nEnter a floating-point number to divide the second amount by:\n";
    std::cin >> divisor2;
    money5 = money2 / divisor2;
    std::cout << "Result of dividing the second amount by " << divisor2 << ": " << money5 << std::endl;

    std::cout << "\nIncrement and decrement operations:\n";
    std::cout << "money1++, before: " << money1 << std::endl;
    money1++;
    std::cout << "money1++, after: " << money1 << std::endl;

    std::cout << "++money2, before: " << money2 << std::endl;
    ++money2;
    std::cout << "++money2, after: " << money2 << std::endl;

    std::cout << "money1--, before: " << money1 << std::endl;
    money1--;
    std::cout << "money1--, after: " << money1 << std::endl;

    std::cout << "--money2, before: " << money2 << std::endl;
    --money2;
    std::cout << "--money2, after: " << money2 << std::endl;

    std::cout << "\nAmounts as strings:\n";
    std::cout << "money1: " << money1.toString() << std::endl;
    std::cout << "money2: " << money2.toString() << std::endl;
    std::cout << "money3: " << money3.toString() << std::endl;
    std::cout << "money4: " << money4.toString() << std::endl;
    std::cout << "money5: " << money5.toString() << std::endl;

    return 0;
}
