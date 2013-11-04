#include<iostream>
#include<string>
#include<map>
using namespace std;

int main(){
	int n;
	cin >> n;
	map<string,int > H;
	while ( n-- ){
		string name;
		cin >> name;
		++H[name];
	}
	string res ;
	int best = 0;
	for(map<string,int>::iterator it = H.begin();
	it != H.end(); it++){
		if( it->second > best) {
			best = it->second;
			res = it->first;
		}
	}
	cout << res << endl;
	return 0;
}
