#include<iostream>
#include<map>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
int main(){
	string k;
	cin >> k;
	map<string,int> H;
	for(int i = 0; i < 10; i++){
		string s; cin >> s;
		H[s] = i;
	}
	for(int i = 0; i < 80; i+=10){
		cout<<H[k.substr(i,10)];
	}
	cout<<endl;

	return 0;

}
