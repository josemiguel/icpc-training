#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>

using namespace std;

int main(){

	int r;
	cin>>r;
	while(r--){
		string s;
		cin>>s;
		
		for(int i = 0; i < s.size(); i++){
			string K;
			K += s[0];
			for(int j = i+1; j < s.size(); j++){
				K += s[j];
				
			}
		}
		
	}

	return 0;
}
