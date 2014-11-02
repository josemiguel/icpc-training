#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define N 101

long long fibo[N];
bool exist[N];
map<long long,int> rfibo;

void init(){
	fibo[0] = fibo[1] = 1;
	rfibo[fibo[1]] = 1;
	for(int i = 2; i < N ; i++){
		fibo[i] = fibo[i-1] + fibo[i-2];
		rfibo[fibo[i]] = i;
	}
}

int main(){
	int runs,n;
	string s,ss;		
	
	init();
	cin>>runs;
	for(int r = 1 ; r <= runs ; r++){
		memset(exist,false,sizeof(exist));
		cin>>n;
		int cp[N] = {0};
		int lenfibo = -1;
		for(int i = 0; i < n && cin>>cp[i]; i++) {
			exist[rfibo[cp[i]]] = true; 
			lenfibo = max(lenfibo,rfibo[cp[i]]);
		}
		cin.ignore();
		getline(cin,s);
		for(int i = 0; i < s.size(); i++) if (!isalpha(s[i]) || !isupper(s[i])) s.erase(s.begin()+i),i--;
		ss.resize(lenfibo);
		for(int i = 0; i < lenfibo; i++) ss[i]=' ';
		for(int i = 0; i < s.size();i++){
			ss[rfibo[cp[i]]-1] = s[i];
		}
		cout<<ss<<endl;
	}
	return 0;
}
