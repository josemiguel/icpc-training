/**
	Hash para string
*/
#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;
#define N 10007
#define MAX 120005
set<string> buck[N];
string dic[MAX];
int hash(string s){
	int pot = 1, res = 0; for(int i = 0; i < s.size(); i++){
		res = res + ((s[i]-'a')*pot) % N;
		pot = pot*27 % N;
	}
	return res % N;
}
void add(string s){ buck[hash(s)].insert(s); }
bool exist(string s){ return buck[hash(s)].count(s) >= 1;}

int main(){
	int n = 0;while(cin>>dic[n++]) add(dic[n-1]);
	for(int i = 0; i < n; i++){
		int sz  = dic[i].length();
		for(int j = 1; j < sz-1; j++){
			string a = dic[i].substr(0,j);
			string b = dic[i].substr(j,sz);
			if (exist(a)){
				if (exist(b)) {
					cout<<dic[i]<<endl; 
					break;
				}
			}
		}
	}
	
	
	return 0;
}
