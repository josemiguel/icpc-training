#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main(){
	#ifdef DEBUG
	freopen("std.in", "r", stdin);
	freopen("std.out", "w", stdout);
	#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	string s;int n;
	cin>>s>>n;
	if ( s == "front" && n == 1){
		cout<<"L"<<endl;
	}else if ( s == "front" && n == 2){
		cout<<"R"<<endl;
	}else if (s == "back" && n == 1){
		cout<<"R"<<endl;
	}else if ( s == "back" && n == 2){
		cout<<"L"<<endl;
	}
	return 0;
}
