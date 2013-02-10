//
// samekey.cpp
//
//multimap sample

#define assert(param)
//class bad_alloc();
//#define bad_alloc()

//#define runtime_error()

using namespace std;
#include <new>
#include <iostream>
#include <string>
#include <map>
#include "../../Headers/realtime_allocator.h"

typedef multimap<string, int> StringToIntMap;
typedef StringToIntMap::iterator mapIter;

int main(){

StringToIntMap mymap;

mymap.insert(make_pair("Group2", 11));
mymap.insert(make_pair("Group1", 3));
mymap.insert(make_pair("Group2", 10));
mymap.insert(make_pair("Group1", 1));
mymap.insert(make_pair("Group2", 12));
mymap.insert(make_pair("Group1", 2));

cout << "mymap contains:" << endl;

mapIter m_it, s_it;

for (m_it = mymap.begin(); m_it != mymap.end(); m_it = s_it){
	string theKey = (*m_it).first;
	
	cout << endl;
	cout << " key '" << theKey << "'" <<endl;

	pair<mapIter, mapIter> keyRange = mymap.equal_range(theKey);

	for (s_it = keyRange.first; s_it != keyRange.second; ++s_it){
		cout << "	value = " << (*s_it).second << endl;
	}
}
return 0;

}


