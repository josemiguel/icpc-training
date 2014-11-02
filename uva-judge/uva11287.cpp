#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 32000
vector<bool> b(MAX,true);
vector<int> p;
vector<int> a;
int main(){
	
		
	b[0] = b[1] = false;
	for(int i = 2 ; i <= MAX; i++){
		if (b[i]){
			p.push_back(i);
			for(int j = i*i; j <= MAX; j+=i) b[j] = false;
		}
	}
	for(int i = 1; i < p.size(); i++) a.push_back(p[i] - p[i-1]);
	a.push_back(-1);
	int lo,hi;
	while(cin>>lo>>hi && lo+hi){
		while(p[lo] > lo - 1) lo--;
		while(p[hi] < hi + 1) hi++;
		cout<<lo<<" "<<hi<<endl;
	}
	
	return 0;
}
