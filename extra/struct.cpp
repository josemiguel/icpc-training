#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct item{
	int freq;
	string nombre;
	item(){}
	item(int _freq, string _nombre){
		freq = _freq;
		nombre = _nombre;
	}
	
};

bool operator <(const item &a, const item &b){
	if (a.freq == b.freq){
		return a.nombre < b.nombre;
	}
	return a.freq > b.freq;
}

int main(){

	item it1;
	
	it1.freq = 12;
	it1.nombre = "jose";
	
	item it2(12,"hugo");

	vector<item> items;
	items.push_back(item(15,"jose"));
	items.push_back(item(13,"alberto"));
	items.push_back(item(6,"jorge"));
	items.push_back(item(13,"juan"));
	
	sort(items.begin(),items.end());
	for(int i = 0; i < items.size(); i++){
		cout<<items[i].nombre<<" ("<<items[i].freq<<")"<<endl;
	}
	
}

