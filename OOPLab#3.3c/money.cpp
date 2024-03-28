#include "money.h"
#include <sstream>

Money::Money() : hryvnia(0), kopiyka(0) {}
Money::Money(long h, unsigned char k) : hryvnia(h), kopiyka(k) {}
Money::Money(const Money& other) : hryvnia(other.hryvnia), kopiyka(other.kopiyka) {}


void Money::Init(long h, unsigned char k) {
    hryvnia = h;
    kopiyka = k;
}

void Money::Read() {
    std::cout << "Enter grvn: ";
    std::cin >> hryvnia;
    std::cout << "Enter kop: ";
    std::cin >> kopiyka;
}

void Money::Display() {
    std::cout << "Sum: " << hryvnia << "," << (int)kopiyka << " грн" << std::endl;
}

std::string Money::toString() {
    std::stringstream ss;
    ss << hryvnia << "," << static_cast<int>(kopiyka) << " грн";
    return ss.str();
}

Money Money::operator+(const Money& other) const {
    Money result;
    result.hryvnia = hryvnia + other.hryvnia;
    result.kopiyka = kopiyka + other.kopiyka;
    if (result.kopiyka >= 100) {
        result.hryvnia++;
        result.kopiyka -= 100;
    }
    return result;
}

Money Money::operator/(int divisor) const {
    Money result;
    long totalKopiyka = hryvnia * 100 + kopiyka;
    totalKopiyka /= divisor;
    result.hryvnia = totalKopiyka / 100;
    result.kopiyka = totalKopiyka % 100;
    return result;
}

Money Money::operator/(double divisor) const {
    Money result;
    double totalKopiyka = hryvnia * 100 + kopiyka;
    totalKopiyka /= divisor;
    result.hryvnia = static_cast<long>(totalKopiyka / 100);
    result.kopiyka = static_cast<unsigned char>(totalKopiyka) % 100;
    return result;
}

Money& Money::operator=(const Money& other) {
    if (this != &other) {
        hryvnia = other.hryvnia;
        kopiyka = other.kopiyka;
    }
    return *this;
}

Money& Money::operator++() {
    kopiyka++;
    if (kopiyka >= 100) {
        hryvnia++;
        kopiyka = 0;
    }
    return *this;
}

Money Money::operator++(int) {
    Money temp(*this);
    ++(*this);
    return temp;
}

Money& Money::operator--() {
    if (kopiyka == 0) {
        if (hryvnia > 0) {
            hryvnia--;
            kopiyka = 99;
        }
        else {
            kopiyka = 0;
        }
    }
    else {
        kopiyka--;
    }
    return *this;
}

Money Money::operator--(int) {
    Money temp(*this);
    --(*this);
    return temp;
}

std::istream& operator>>(std::istream& in, Money& money) {
    std::cout << "Enter grvn: ";
    in >> money.hryvnia;
    std::cout << "Enter kop: ";
    in >> money.kopiyka;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Money& money) {
    out << "Sum: " << money.hryvnia << "," << (int)money.kopiyka << " грн";
    return out;
}
