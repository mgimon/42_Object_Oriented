#include "Templates.hpp"

int main(void)
{
    int a = 2;
    int b = 3;
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
    std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";

    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
    std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

    return 0;
}

/*
int main(void)
{
	int x = 4;
	int y = 0;
	std::string	name = "Mr Robert";
	std::string empty = "";
	char a = 'a';
	char W = 'W';

	std::cout << std::endl;

	::swap(x, y);
	std::cout << "x: " << x << ", y: " << y << std::endl;

	::swap(name, empty);
	std::cout << "name: " << name << ", empty: " << empty << std::endl;

	::swap(a, W);
	std::cout << "a: " << a << ", W: " << W << std::endl;

	std::cout << std::endl;

	std::cout << "min: " << ::min(x, y) << std::endl;
	std::cout << "min: " << ::min(name, empty) << std::endl;
	std::cout << "min: " << ::min(a, W) << std::endl;

	std::cout << std::endl;

	std::cout << "max: " << ::max(x, y) << std::endl;
	std::cout << "max: " << ::max(name, empty) << std::endl;
	std::cout << "max: " << ::max(a, W) << std::endl;

	std::cout << std::endl;

	return (0);
}
*/
