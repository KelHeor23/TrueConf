#include "stdafx.h"
#define MAX_COUNT_FOR_DELETE 15
#define MAX_VALUE 9

namespace VecAndMap
{
	//vector filling
	void fillVec(std::vector<int> *, int);

	//map filling
	void fillMap(std::map<int, int> *, int);

	//remove from vector
	void deleteFromVec(std::vector<int> *);

	//remove from map
	void deleteFromMap(std::map<int, int> *);

	//vector and map synchronization
	void synchronization(std::vector<int> *, std::map<int, int> *);
}