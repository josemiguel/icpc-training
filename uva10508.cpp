#include<iostream>
#include<cctype>
#include<queue>
#include<cstring>
#include<map>
#include<vector>
#include<set>
#include<string>
using namespace std;

#define N 100007
map<string,int> buck[N];
vector<string> dic;

int hash(string s){
	int pot = 1, res = 0;
	for(int i = 0; i < s.size(); i++){
		res += (pot*(s[i]-'a')) % N;
		pot = pot * 27 % N;
	}
	return res % N;
}

void add(string s,int n) { buck[hash(s)][s] = n; }
int find(string s) { 
	return buck[hash(s)][s];
}
inline void to_low(string &s){ for(int i = 0; i < s.size(); i++) s[i]=tolower(s[i]);}
vector<bool> seen;

int main(){
	int n,m;
	while(cin>>n>>m){
		dic = vector<string> (n+1);
		for(int i = 1; i <= n; i++)	{
			cin>>dic[i];
			to_low(dic[i]);
			add(dic[i],i);
		}
		seen = vector<bool>(n+1,false);
		seen[1] = true;
		int v = 1;
		cout<<dic[1]<<endl;
		while(v!=2){
			string s = dic[v];		
			for(int j = 0; j < m; j++){
				char act = s[j];
				for(int c = 'a'; c <= 'z' ; c++){
					if (c == act) continue;
					s[j] = c;
					int u = find(s);s = dic[v];
					if (!u || seen[u]) continue;
					cout<<dic[u]<<endl;					
					seen[u] = true;
					v = u;
					break;
				}
			}
		}
	}
	return 0;
}


