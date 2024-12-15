#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include <stdexcept>

const int Fixed::_fractionalBits = 8;
#define MAX_INT 2147483647 // 2^31 - 1
#define MIN_INT -2147483648 // -2^31

// Default constructor
Fixed::Fixed() : _fixedPoint(0) {
    // std::cout << "Default constructor called" << std::endl;
}

// Integer constructor (converts to fixed-point by bit-shifting)
Fixed::Fixed(const int intValue) {
    // Check for overflow before bit shifting
    if (intValue > (MAX_INT >> _fractionalBits) ||
        intValue < (MIN_INT >> _fractionalBits)) {
        throw std::overflow_error("Overflow in bit shift operation");
    }
    _fixedPoint = intValue << _fractionalBits;
    // std::cout << "Int constructor called" << std::endl;
}

// Float constructor
Fixed::Fixed(const float floatValue) {
    // Check for overflow before converting
    if (floatValue > (MAX_INT / static_cast<float>(1 << _fractionalBits)) ||
        floatValue < (MIN_INT / static_cast<float>(1 << _fractionalBits))) {
        throw std::overflow_error("Overflow in float to fixed-point conversion");
    }
    _fixedPoint = static_cast<int>(roundf(floatValue * (1 << _fractionalBits)));
    // std::cout << "Float constructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed &other) : _fixedPoint(other._fixedPoint) {
    // std::cout << "Copy constructor called" << std::endl;
}

// Copy assignment operator
Fixed &Fixed::operator=(const Fixed &other) {
    if (this != &other) {
        _fixedPoint = other._fixedPoint;
    }
    // std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

// Destructor
Fixed::~Fixed() {
    // std::cout << "Destructor called" << std::endl;
}

// Method that returns the fixedPoint value of the current object
int Fixed::getRawBits(void) const {
    // std::cout << "getRawBits member function called" << std::endl;
    return _fixedPoint;
}

// Method that sets the fixedPoint value with the received input
void Fixed::setRawBits(int const raw) {
    // std::cout << "setRawBits member function called" << std::endl;
    _fixedPoint = raw;
}

// Method that transforms the fixed point to a float and returns its value
float Fixed::toFloat(void) const {
    return static_cast<float>(_fixedPoint) / (1 << _fractionalBits);
}

// Method that returns the int value of the fixedPoint
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
    // Check for overflow
    if ((_fixedPoint > 0 && other._fixedPoint > 0 && _fixedPoint > MAX_INT - other._fixedPoint) ||
        (_fixedPoint < 0 && other._fixedPoint < 0 && _fixedPoint < MIN_INT - other._fixedPoint)) {
        throw std::overflow_error("Overflow in addition operation");
    }
    return Fixed(this->_fixedPoint + other._fixedPoint);
}

Fixed Fixed::operator-(const Fixed &other) const {
    // Check for overflow
    if ((_fixedPoint > 0 && other._fixedPoint < 0 && _fixedPoint > MAX_INT + other._fixedPoint) ||
        (_fixedPoint < 0 && other._fixedPoint > 0 && _fixedPoint < MIN_INT + other._fixedPoint)) {
        throw std::overflow_error("Overflow in subtraction operation");
    }
    return Fixed(this->_fixedPoint - other._fixedPoint);
}

Fixed Fixed::operator*(const Fixed &other) const {
    // Convert to float, multiply, and convert back to fixed-point
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const {
    if (other._fixedPoint == 0) {
        throw std::runtime_error("Division by zero");
    }
    // Convert to float, divide, and convert back to fixed-point
    return Fixed(this->toFloat() / other.toFloat());
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