#ifndef FIXED_HPP
#define FIXED_HPP

/*I need to create a class in Orthodox Canonical Form that represents a fixed-point-number

Default constructor
Copy constructor
Copy assignment operator
Destructor

*/

class Fixed{

    private:
    int                 _fixedPoint;
    static const int    _fractionalBits;

    public:

    Fixed();
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);
    ~Fixed();
	
    int getRawBits( void ) const;
	void setRawBits( int const raw );
};


#endif