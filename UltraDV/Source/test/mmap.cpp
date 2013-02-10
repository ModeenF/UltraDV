//
// test multimap
//

#include<iostream>
#include<map>
#include <string>

using namespace std;

void printer(multimap<string, int> pN);

int main(){

multimap<string, int> phoneNums;


phoneNums.insert(pair<string, int>("Joe",123);
phoneNums.insert(pair<string, int>("Fred",444);
printer(phoneNums);

phoneNums.insert(pair<string, int>("Joe",369);
phoneNums.insert(pair<string, int>("Will",567);
phoneNums.insert(pair<string, int>("Joe",888);
phoneNums.insert(pair<string, int>("Fred",999);
printer(phoneNums);

cout<<"\n\n Frequency of diff names"<<endl;

cout<<"# of phone nums for Joe = "<<phoneNums.count("Joe")<<endl;
cout<<"# of phone nums for Fred = "<<phoneNums.count("Fred")<<endl;
cout<<"# of phone nums for Will = "<<phoneNums.count("Will")<<endl;

pair<multimap<string, int>::iterator, multimap<string, int>::iterator> ii;
multimap<string, int>::iterator it;
ii = phoneNums.equal_range("Joe");
cout<<"\n\nPrinting all Joe and then erasing them"<<endl;
for (it = ii.first; it!= ii.second; ++it){
	cout<<"Key "<<it->first<<"	Value = "<<it->second<<endl;
}
phoneNums.eraseii.first, ii.second);
printer(phoneNums);

return 0;
}

void printer(multimap<string, int> pN){
	cout<<"\n\nMultimap printer method"<<endl;
	cout<<"Map size = "<<pN.size()<<endl;
multimap<string, int>::iterator it = pN.begin();
while (it != pN.end()){
	cout <<"Key = "<<it->first<<"	Value = "<<it->second<,endl;
}
}


