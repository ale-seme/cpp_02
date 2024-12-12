#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_fractionalBits = 8;

//Default constructor
Fixed::Fixed(): _fixedPoint(0){
	std::cout << "Default constructor called" << std::endl;
}

//Integer constructor (converts to fixed-point by multiplying by 2^8)
Fixed::Fixed(const int intValue) : _fixedPoint(intValue << _fractionalBits){
	std::cout << "Int constructor called" << std::endl;
};

Fixed::Fixed(const float floatValue){
	_fixedPoint = static_cast<int>(roundf(floatValue * (1 << _fractionalBits)));
	std::cout << "Float constructor called" << std::endl; 
}

Fixed::Fixed(const Fixed &other): _fixedPoint(other._fixedPoint){
	std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other){
if (this != &other)
{
	_fixedPoint = other._fixedPoint;
}
std::cout << "Copy assignment operator called" << std::endl;
return (*this);
}


Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}


int Fixed::getRawBits( void ) const{
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixedPoint);
}

void Fixed::setRawBits( int const raw ){
	std::cout << "setRawBits member function called" << std::endl;
	_fixedPoint = raw;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(_fixedPoint) / (1 << _fractionalBits);
}

int Fixed::toInt( void ) const {
	return (_fixedPoint >> _fractionalBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &f){
	out << f.toFloat();
	return (out);
}

int &Fixed::min(Fixed &Fixed1, Fixed &Fixed2){
	return (Fixed1._fixedPoint > Fixed2._fixedPoint ? Fixed2._fixedPoint : Fixed1._fixedPoint);
}
const int &Fixed::min(const Fixed &Fixed1, const Fixed &Fixed2){
	return (Fixed1._fixedPoint > Fixed2._fixedPoint ? Fixed2._fixedPoint : Fixed1._fixedPoint);
}
int &Fixed::max(Fixed &Fixed1, Fixed &Fixed2){
	return (Fixed1._fixedPoint < Fixed2._fixedPoint ? Fixed2._fixedPoint : Fixed1._fixedPoint);
}
const int &Fixed::max(const Fixed &Fixed1, const Fixed &Fixed2){
	std::cout << "all the values involved:" << Fixed1._fixedPoint << std::endl;
	
	return (Fixed1._fixedPoint < Fixed2._fixedPoint ? Fixed2._fixedPoint : Fixed1._fixedPoint);
}

bool Fixed::operator>(const Fixed& other){
	return (_fixedPoint > other._fixedPoint);
}

bool Fixed::operator<(const Fixed& other){
	return (_fixedPoint < other._fixedPoint);
}

bool Fixed::operator>=(const Fixed& other){
	return (_fixedPoint >= other._fixedPoint);
}

bool Fixed::operator<=(const Fixed& other){
	return (_fixedPoint <= other._fixedPoint);
}

bool Fixed::operator==(const Fixed& other){
	return (_fixedPoint == other._fixedPoint);
}

bool Fixed::operator!=(const Fixed& other){
	return (_fixedPoint != other._fixedPoint);
}