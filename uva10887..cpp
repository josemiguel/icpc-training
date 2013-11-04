#include<iostream>
#include<cstdio>
#include<string>
#include<set>
#include<vector>
using namespace std;
#define N 10007
set<string> buck[N];
//string dic[1505*1505];
string A[1505],B[1505];

int hash(string s){
	int pot = 1, res = 0;
	for(int i = 0; i < s.size(); i++){
		res += (pot*(s[i]-'a')) % N;
		pot = pot * 27 % N;
	}
	return res % N;
}

void add(string s) { buck[hash(s)].insert(s); }
bool exist(string s) { return buck[hash(s)].count(s) >= 1; } 

int main(){
	int r ;
	cin>>r;
	for(int rr = 1; rr <= r; rr++){
		int aa,bb;
		cin>>aa>>bb;
		for(int i = 0; i < aa; i++) cin>>A[i];
		int k = 0;
		set<string> K;
		for(int i = 0; i < bb; i++){
			string b;
			cin>>b;		
			for(int j = 0; j < aa; j++) {
				//dic[k++] = A[i]+B[i];
				K.insert(A[j]+b);
			}
		}
		int res = K.size();
		printf("Case %d: %d\n",rr,res);
	}

	return 0;
}
