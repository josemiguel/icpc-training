#include<iostream>
#include<map>
#include<vector>
#include<sstream>
#include<cstdio>
#include<string>
#include<algorithm>

using namespace std;
#define MAX 1000000
vector<bool> b(MAX+4,true);
vector<int> p;
void criba(){
	b[0] = b[1] = false;
	for(int i = 2; i*i <= MAX; i++){
		if (b[i]){
			for(int j = i*i; j <= MAX; j+=i) b[j] = false;
		}
	}
	bool f = 0;
	int ant = 0;
	for(int i = 0; i <= MAX; i++) if (b[i]) p.push_back(i);
}

int main(){
	ios_base::sync_with_stdio(false);
	criba();
	int r;
	cin>>r;
	while(r--){
		int a,b;
		cin>>a>>b;
		if (a == b) {cout<<"No jumping champion"<<endl; continue;}
		int lo;
		for(lo = 0; p[lo] < a; lo++);
		map<int,int> h;
		for(int i = lo; i < p.size()-1 && p[i+1] <= b; i++) h[p[i+1]-p[i]]++;
		
		int best = 0, res = 0;
		bool f = false;
		for(map<int,int>::iterator it = h.begin(); it != h.end(); it++)	{
			if (best < it->second){
				best = it->second;
				res = it->first;
			}
		}
		int c = 0;
		for(map<int,int>::iterator it = h.begin(); it != h.end(); it++){
			if (it->second == best) c++;
			if (c > 1) { f = true; break;}
		}
		if (!f  && best>=1)cout<<"The jumping champion is "<<res<<endl;
		else cout<<"No jumping champion"<<endl;
	}
	return 0;
}
