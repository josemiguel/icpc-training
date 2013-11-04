#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

char a[4005];
string s;
int sz;
int stable(){
	sz = -1;
	int moves = 0;
	for(int i = 0; i < s.size(); i++){
		if (s[i] == '{') a[++sz] = s[i];
		else{
			if (sz == -1) a[++sz] = '{', moves++;
			else --sz;
		}
	}
	return moves + (sz == -1 ? 0 : (sz+1) / 2);
}

int main(){
	int r=1;
	while(getline(cin,s) && s[0] != '-'){
		printf("%d. %d\n",r++,stable());

	}
}
