
#include <iostream>

template <typename T>

void add(T a, T b)
{
	std::cout << "the sum of " << a << " and " << b << " is: ";
	std::cout << a + b << std::endl;
}

int		main( void )
{
	add(1, 2);
	add(5.2, 10.3);
	return (0);
}


