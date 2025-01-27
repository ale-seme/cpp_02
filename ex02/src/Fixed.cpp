#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include <stdexcept>

const int Fixed::_fractionalBits = 8;
#define MAX_INT 2147483647 // 2^31 - 1
#define MIN_INT -2147483648 // -2^31

// Default constructor
Fixed::Fixed() : _fixedPoint(0) {}

// Integer constructor (converts to fixed-point by bit-shifting)
Fixed::Fixed(const int intValue) {
    if (intValue > (MAX_INT >> _fractionalBits) ||
        intValue < (MIN_INT >> _fractionalBits)) {
        throw std::overflow_error("Overflow in bit shift operation");
    }
    _fixedPoint = intValue << _fractionalBits;
}

// Float constructor
Fixed::Fixed(const float floatValue) {
    if (floatValue > (MAX_INT / static_cast<float>(1 << _fractionalBits)) ||
        floatValue < (MIN_INT / static_cast<float>(1 << _fractionalBits))) {
        throw std::overflow_error("Overflow in float to fixed-point conversion");
    }
    _fixedPoint = static_cast<int>(roundf(floatValue * (1 << _fractionalBits)));
}

// Copy constructor
Fixed::Fixed(const Fixed &other) : _fixedPoint(other._fixedPoint) {}

// Copy assignment operator
Fixed &Fixed::operator=(const Fixed &other) {
    if (this != &other) {
        _fixedPoint = other._fixedPoint;
    }
    return *this;
}

// Destructor
Fixed::~Fixed() {}

// Method that returns the fixedPoint value of the current object
int Fixed::getRawBits(void) const {
    return _fixedPoint;
}

// Method that sets the fixedPoint value with the received input
void Fixed::setRawBits(int const raw) {
    _fixedPoint = raw;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(_fixedPoint) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return _fixedPoint >> _fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &f) {
    out << f.toFloat();
    return out;
}

bool Fixed::operator>(const Fixed &other) const {
    return _fixedPoint > other._fixedPoint;
}

bool Fixed::operator<(const Fixed &other) const {
    return _fixedPoint < other._fixedPoint;
}

bool Fixed::operator>=(const Fixed &other) const {
    return _fixedPoint >= other._fixedPoint;
}

bool Fixed::operator<=(const Fixed &other) const {
    return _fixedPoint <= other._fixedPoint;
}

bool Fixed::operator==(const Fixed &other) const {
    return _fixedPoint == other._fixedPoint;
}

bool Fixed::operator!=(const Fixed &other) const {
    return _fixedPoint != other._fixedPoint;
}

Fixed Fixed::operator+(const Fixed &other) const {
    if ((_fixedPoint > 0 && other._fixedPoint > 0 && _fixedPoint > MAX_INT - other._fixedPoint) ||
        (_fixedPoint < 0 && other._fixedPoint < 0 && _fixedPoint < MIN_INT - other._fixedPoint)) {
        throw std::overflow_error("Overflow in addition operation");
    }
    Fixed result;
    result.setRawBits(this->_fixedPoint + other._fixedPoint);
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
    if ((_fixedPoint > 0 && other._fixedPoint < 0 && _fixedPoint > MAX_INT + other._fixedPoint) ||
        (_fixedPoint < 0 && other._fixedPoint > 0 && _fixedPoint < MIN_INT + other._fixedPoint)) {
        throw std::overflow_error("Overflow in subtraction operation");
    }
    Fixed result;
    result.setRawBits(this->_fixedPoint - other._fixedPoint);
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const {
    Fixed result;
    result.setRawBits((this->_fixedPoint * other._fixedPoint) >> _fractionalBits);
    return result;
}


Fixed Fixed::operator/(const Fixed &other) const {
    if (other._fixedPoint == 0) {
        throw std::runtime_error("Division by zero");
    }
    Fixed result;
    // Scale up before division to maintain precision
    result.setRawBits((this->_fixedPoint << _fractionalBits) / other._fixedPoint);
    return result;
}


Fixed &Fixed::operator++() {
    if (_fixedPoint == MAX_INT) {
        throw std::overflow_error("Overflow in increment operation");
    }
    _fixedPoint++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    if (_fixedPoint == MAX_INT) {
        throw std::overflow_error("Overflow in increment operation");
    }
    _fixedPoint++;
    return temp;
}

Fixed &Fixed::operator--() {
    if (_fixedPoint == MIN_INT) {
        throw std::overflow_error("Overflow in decrement operation");
    }
    _fixedPoint--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    if (_fixedPoint == MIN_INT) {
        throw std::overflow_error("Overflow in decrement operation");
    }
    _fixedPoint--;
    return temp;
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2) {
    return (f1 < f2 ? f1 : f2);
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2) {
    return (f1 < f2 ? f1 : f2);
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2) {
    return (f1 > f2 ? f1 : f2);
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2) {
    return (f1 > f2 ? f1 : f2);
}