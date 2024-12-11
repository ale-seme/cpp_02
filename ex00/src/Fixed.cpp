#include "Fixed.hpp"
#include <iostream>

const int Fixed::_fractionalBits = 8;

Fixed::Fixed(): _fixedPoint(0){
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other): _fixedPoint(other._fixedPoint){
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other){
if (this != &other)
{
    _fixedPoint = other._fixedPoint;
}
std::cout << "Fixed Point Number assignment operator called!" << std::endl;
return (*this);
}

int Fixed::getRawBits( void ) const{
    std::cout << "getRawBits member function called" << std::endl;
    return (_fixedPoint);
}

void Fixed::setRawBits( int const raw ){
    std::cout << "setRawBits member function called" << std::endl;
    _fixedPoint = raw;
}