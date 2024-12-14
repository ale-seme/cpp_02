#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_fractionalBits = 8;

//Default constructor
Fixed::Fixed(): _fixedPoint(0){
	//std::cout << "Default constructor called" << std::endl;
}

//Integer constructor (converts to fixed-point by multiplying by 2^8)
Fixed::Fixed(const int intValue){
if (intValue > (std::numeric_limits<int>::max() >> _fractionalBits) ||
	intValue < (std::numeric_limits<int>::min() >> _fractionalBits))
	throw std::overflow_error("Overflow in bit shift operation");
_fixedPoint = intValue << _fractionalBits;
	//std::cout << "Int constructor called" << std::endl;
};

//Float constructor 
Fixed::Fixed(const float floatValue){
	if (floatValue > (std::numeric_limits<float>::max() / static_cast<float> (1 << _fractionalBits)) ||
		floatValue < (std::numeric_limits<float>::max() / static_cast<float> (1 << _fractionalBits)))
		throw std::overflow_error("Overflow in float to fixed-point conversion");
_fixedPoint = static_cast<int>(roundf(floatValue * (1 << _fractionalBits)));
	//std::cout << "Float constructor called" << std::endl; 
}

//Copy constructor
Fixed::Fixed(const Fixed &other): _fixedPoint(other._fixedPoint){
	//std::cout << "Copy constructor called" << std::endl;
}

//Copy assignment operator
Fixed &Fixed::operator=(const Fixed &other){
if (this != &other)
{
	_fixedPoint = other._fixedPoint;
}
//std::cout << "Copy assignment operator called" << std::endl;
return (*this);
}

//Destructor
Fixed::~Fixed(){
	//std::cout << "Destructor called" << std::endl;
}

//Method that returns the fixedPoint value of the current object
int Fixed::getRawBits( void ) const{
	//std::cout << "getRawBits member function called" << std::endl;
	return (_fixedPoint);
}

//Method that sets the fixedPoint value with the received input
void Fixed::setRawBits( int const raw ){
	//std::cout << "setRawBits member function called" << std::endl;
	_fixedPoint = raw;
}

//Method that transforms the fixed point to a float and returns it's value
float Fixed::toFloat(void) const {
    return static_cast<float>(_fixedPoint) / (1 << _fractionalBits);
}

//Method that returns the int value of the fixedPoint 
int Fixed::toInt( void ) const {
	return (_fixedPoint >> _fractionalBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &f){
	out << f.toFloat();
	return (out);
}


Fixed Fixed::operator+(const Fixed&other)
{
	if ((_fixedPoint > 0 && other._fixedPoint > 0 && _fixedPoint > std::numeric_limits<int>::max() - other._fixedPoint) ||
		(_fixedPoint > 0 && other._fixedPoint > 0 && _fixedPoint > std::numeric_limits<int>::min() - other._fixedPoint))
		throw std::overflow_error("Overflow in addition operation");
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed &other)
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed &other){
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other){
	if (other._fixedPoint == 0)
		throw std::runtime_error("Division by zero");
	return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed &Fixed::operator++(){
	
	this->_fixedPoint++;
	return (*this);
}

Fixed Fixed::operator++(int){
	Fixed temp = *this;

	this->_fixedPoint++;
	return (temp);
}

Fixed &Fixed::operator--(){
	this->_fixedPoint--;
	return (*this);
}
Fixed Fixed::operator--(int){
	Fixed temp = *this;
	this->_fixedPoint--;
	return (temp);
}


bool Fixed::operator>(const Fixed& other) const{
	return (_fixedPoint > other._fixedPoint);
}

bool Fixed::operator<(const Fixed& other) const {
	return (_fixedPoint < other._fixedPoint);
}

bool Fixed::operator>=(const Fixed& other) const {
	return (_fixedPoint >= other._fixedPoint);
}

bool Fixed::operator<=(const Fixed& other) const {
	return (_fixedPoint <= other._fixedPoint);
}

bool Fixed::operator==(const Fixed& other) const {
	return (_fixedPoint == other._fixedPoint);
}

bool Fixed::operator!=(const Fixed& other) const {
	return (_fixedPoint != other._fixedPoint);
}


Fixed &Fixed::min(Fixed &f1, Fixed &f2){
	return (f1 < f2 ? f1 : f2);
}
const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2){
	return (f1 < f2 ? f2 : f1);
}
Fixed &Fixed::max(Fixed &f1, Fixed &f2){
	return (f1 > f2 ? f1 : f2);
}
const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2){
	return (f1 > f2 ? f1 : f2);
}