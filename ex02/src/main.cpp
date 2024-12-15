#include "Fixed.hpp"
#include <iostream>

// Fixed a;
// Fixed const b( 10 );
// Fixed const c( 42.42f );
// Fixed const d( b );
// a = Fixed( 1234.4321f );
// std::cout << "a is " << a << std::endl;
// std::cout << "b is " << b << std::endl;
// std::cout << "c is " << c << std::endl;
// std::cout << "d is " << d << std::endl;
// std::cout << "a is " << a.toInt() << " as integer" << std::endl;
// std::cout << "b is " << b.toInt() << " as integer" << std::endl;
// std::cout << "c is " << c.toInt() << " as integer" << std::endl;
// std::cout << "d is " << d.toInt() << " as integer" << std::endl;


int main( void ) {

try {
Fixed a;


Fixed const b( Fixed( 5.2f ) * Fixed(__INT_MAX__) );

std::cout << "value of b: " << b << std::endl;

Fixed c = Fixed (3.3434f) / Fixed(4);

Fixed d = c;

Fixed e = c + d;

Fixed f = e - d;
    if (b >= c * 2)
    std::cout << b << " >= " << c << std::endl;
if (b > c)
    std::cout << b << " > " << c << std::endl;
if (b <= c)
    std::cout << b << " <= " << c << std::endl;
if (b < c)
    std::cout << b << " < " << c << std::endl;
if (b == c)
    std::cout << b << " == " << c << std::endl;
else if (b != c)
    std::cout << b << " != " << c << std::endl;


std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;

std::cout << "The minimum between " << c << " and " << d << " is: " << Fixed::min(c, d) << std::endl;
std::cout << "The maximum between " << c << " and " << d << " is: " << Fixed::max(c, d) << std::endl;
}
catch (const std::exception &e){
    std::cerr << "Exception caught: " << e.what() << std::endl;
    return 1;
}
return (0);

}