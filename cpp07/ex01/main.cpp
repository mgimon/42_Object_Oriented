
#include "iter.hpp"

int main(void)
{
	int			ints[] = {2, 4, 6};
	std::string strings[] = {"Show", "must", "go", "on"};

	::iter(ints, 3, printFunc);
	::iter(strings, 4, printFunc);

	return (0);
}
