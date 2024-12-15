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


Fixed b(Fixed( 5.2f ) * Fixed(2));

std::cout << "value of b: " << b << std::endl;

Fixed c = Fixed (20.4f) / Fixed(4);

std::cout << "value of c " << c << std::endl;

Fixed d(c);

std::cout << "value of d: " << d << " is the same of c: " << c << std::endl;


Fixed e = c + d;
Fixed f = e - d;

std::cout << "value of f: " << f << " is the same of d: " << c << std::endl;

if (b >= c * 2)
    std::cout << b << " >= " << c * 2 << std::endl;
if (b > c/2)
    std::cout << b << " > " << c / 2 << std::endl;
if (c <= b)
    std::cout << b << " <= " << c << std::endl;
if (b < c)
    std::cout << b << " < " << c << std::endl;
if (b == c)
    std::cout << b << " == " << c << std::endl;
else if (b != c)
    std::cout << b << " != " << c << std::endl;


std::cout << std::endl << "NOW ORIGINAL TEST FROM THE SUBJECT:" << std::endl << std::endl;


Fixed g;
Fixed const h(Fixed(5.05f ) * Fixed (2));
Fixed const i( 42.42f );
Fixed const l( h );

std::cout << g << std::endl;
std::cout << ++g << std::endl;
std::cout << g << std::endl;
std::cout << g++ << std::endl;
std::cout << g << std::endl;

std::cout << "The minimum between " << i << " and " << d << " is: " << Fixed::min(i, l) << std::endl;
std::cout << "The maximum between " << i << " and " << d << " is: " << Fixed::max(i, l) << std::endl;

Fixed test1(5.01f);

Fixed test2(5.009f);

if (test1 > test2)
    std::cout << test1 << " > " << test2 << std::endl;

}
catch (const std::exception &e){
    std::cerr << "Exception caught: " << e.what() << std::endl;
    return 1;
}
return (0);

}