#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	string s;
	cin >>n >> s;
	for( int i = 0; 2*i < s.size(); i++ ){
		int j = i + n/2;
		if ( s[i]!=s[j] ){
			if ( s[j] =='L'){
				cout << j+1 << " " << i+1 << endl;
			}else{
			
				cout << i+1 << " " << j+1 << endl;
			}
		}else{
			cout << i+1 << " " << j+1 << endl;
		}
	}

	return 0;
}
