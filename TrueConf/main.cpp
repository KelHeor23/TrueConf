#include "stdafx.h"
#include "VecAndMap.h"

int main()
{
	std::vector<int> vec;
	std::map<int, int> map;

	try
	{
		VecAndMap::fillVec(&vec, 1);
		VecAndMap::fillMap(&map, 1);

		VecAndMap::deleteFromVec(&vec);
		VecAndMap::deleteFromMap(&map);

		VecAndMap::synchronization(&vec, &map);
	}
	catch (std::exception err)
	{
		std::cout << err.what();
	}

	return 0;
}