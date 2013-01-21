// list.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <list>

typedef struct txKeyValue{
	int     id;
	int     value;
} txKeyValue;

typedef std::list<txKeyValue> KeyValueList;
typedef KeyValueList::iterator KeyValueIt;

int _tmain(int argc, _TCHAR* argv[])
{
	KeyValueList kvlist;
	txKeyValue v0 = {0,10};
	txKeyValue v1 = {1,11};
	txKeyValue v2 = {2,110};
	txKeyValue v3 = {3,100};
	kvlist.push_back(v0);
	kvlist.push_back(v1);
	kvlist.push_back(v3);

	KeyValueIt v0It = kvlist.begin();
	KeyValueIt v1It = v0It; v0It++;
	KeyValueIt v2It = v0It; v2It++; v2It++;

	// The following code are not right 
	// the list iterator are not dereferencable
	//txKeyValue v2c = *v2It;
	//txKeyValue *pv2 = &(*v2It);

	kvlist.erase(v1It);

	printf("Key:%d--Value:%d \n", v0It->id, v0It->value );
	// printf("Key:%d--Value:%d \n", v2It->id, v2It->value );
	// printf("Key:%d--Value:%d \n", pv2->id, pv2->value );
	// printf("Key:%d--Value:%d \n", v1It->id, v1It->value );
	
	for ( KeyValueIt it=kvlist.begin(); it!=kvlist.end(); it++ ) {
		printf("Key:%d--value:%d \n", it->id, it->value);
	}

	return 0;
}

