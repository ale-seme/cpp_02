#ifndef FIXED_HPP
#define FIXED_HPP
#include <ostream>

/*I need to create a class in Orthodox Canonical Form that represents a fixed-point-number

Default constructor
Copy constructor
Copy assignment operator
Destructor

*/

class Fixed{

	private:
	int					_fixedPoint;
	static const int	_fractionalBits;

	public:

	Fixed();//default constructor
	Fixed(const int intValue);
	Fixed(const float floatValue);

	Fixed(const Fixed &other);//copy constructor
	Fixed &operator=(const Fixed &other);//operator = overload
	bool operator>(const Fixed &other);
	bool operator<(const Fixed &other);
	bool operator>=(const Fixed &other);
	bool operator<=(const Fixed &other);
	bool operator!= (const Fixed &other);
	bool operator==(const Fixed &other);


	~Fixed();//Destructor

	float toFloat( void ) const;
	int toInt( void ) const;
	
	int getRawBits( void ) const;
	void setRawBits( int const raw );

	static int &min(Fixed &Fixed1, Fixed &Fixed2);
	static const int &min(const Fixed &Fixed1, const Fixed &Fixed2);

	static int &max(Fixed &Fixed1, Fixed &Fixed2);
	static const int &max(const Fixed &Fixed1, const Fixed &Fixed2); 

	
};

std::ostream &operator<<(std::ostream &out, const Fixed &f);


#endif