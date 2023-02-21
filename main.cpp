

#include <iostream>
#include "MyVector.hpp"

using std::cout, std::endl;

int main()
{

	MyVector<int> vec;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);

	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}

	return 0;
}
