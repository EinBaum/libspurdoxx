#include <iostream>
#include "Pr0Wolf29/libspurdoxx.hpp"
#include <vector>

int main(void)
{
	std::vector<std::string> sv = {
		"The quick brown fox jumped over the lazy dog.",
		"Test, test. Test. Test,",
		"test",
		" "
	};

	for(const std::string &s : sv)
	{
		std::cout << to_spurdo(s) << std::endl;
	}

	return 0;
}
