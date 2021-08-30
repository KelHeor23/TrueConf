#include "VecAndMap.h"

void VecAndMap::fillVec(std::vector<int> *vec, int count)
{
	try
	{
		vec->reserve(count);
		for (int i = 0; i < count; i++)
			vec->push_back(rand() % MAX_VALUE + 1);
	}
	catch (const std::exception& err)
	{
		std::string err_message = "Error in fillVec \n" + std::string(err.what());
		throw std::exception(err.what());
	}
}

void VecAndMap::fillMap(std::map<int, int> *map, int count)
{
	try
	{
		for (int i = 0; i < count; i++)
			map->emplace(i, rand() % MAX_VALUE + 1);
	}
	catch (const std::exception& err)
	{
		std::string err_message = "Error in fillMap \n" + std::string(err.what());
		throw std::exception(err.what());
	}
}

void VecAndMap::deleteFromVec(std::vector<int>* vec)
{
	if (vec->empty())
		throw std::exception("vector is empty");

	int count = rand() % vec->size() % MAX_COUNT_FOR_DELETE;

	try
	{
		for (int i = 0; i < count; i++)	
			vec->pop_back();
	}
	catch (const std::exception& err)
	{
		std::string err_message = "Error in deleteFromVec \n" + std::string(err.what());
		throw std::exception(err.what());
	}
}

void VecAndMap::deleteFromMap(std::map<int, int> *map)
{
	if (map->empty())
		throw std::exception("map is empty");

	int count = rand() % map->size() % MAX_COUNT_FOR_DELETE;

	try
	{
		for (int i = 0; i < count; i++)		
			map->erase(map->size() - 1);		
	}
	catch (const std::exception& err)
	{
		std::string err_message = "Error in deleteFromMap \n" + std::string(err.what());
		throw std::exception(err.what());
	}
}

void VecAndMap::synchronization(std::vector<int> *vec, std::map<int, int> *map)
{
	if (vec->empty() && map->empty())
		return;
	else if (vec->empty())
		throw std::exception("vector is empty");
	else if (map->empty())
		throw std::exception("map is empty");
	try
	{
		//remove unnecessary elements from map
		auto it = map->begin();
		while (it != map->end())
		{
		if (find(vec->begin(), vec->end(), it->second) == vec->end())
			it = map->erase(it);
		else
			it++;
		}

		//remove unnecessary elements from vector
		auto it_vec = vec->begin();
		while(it_vec != vec->end())
		{
			bool flag = false;
			for (auto& elem : *map)
			{
				if (elem.second == *it_vec)
				{
					flag = true;
					break;
				}
			}
			if (!flag)
				it_vec = vec->erase(it_vec);
			else
				it_vec++;
		}
	}
	catch (const std::exception& err)
	{
		std::string err_message = "Error in synchronization \n" + std::string(err.what());
		throw std::exception(err.what());
	}
}