#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<numeric>
#include<cctype>
#include<cstdio>
#include<cstdlib>
#include<sstream>
#include<fstream>
#include<string>
#include<stack>
#include<queue>
#include<set>
#include<map>
using namespace std;

#define N 10000
map<string, int> buck[N];
vector<string> cads;
vector<int> dist;
int p = 10007;

int hash(string& s){
	int pot = 1;
	int res = 0;
	for(int i = 0; i < s.size(); i++){
		res = (res + (s[i] - 'A') * pot) % p;
		pot = pot * 27 % p;
	}
	return res % N;
}
void add(string &s, int n){
	buck[hash(s)][s] = n;
}

int find(string &s){
	int h = hash(s);
	if(buck[h].count(s)) return buck[h][s];
	else return -1;
}


int main(int nargs, char **args){

	int n = 0;
	vector<string> cads;
	filebuf fb;
  	fb.open (args[1],ios::in);
	istream fin(&fb);
	string s;
	while(fin >> s){
		if(find(s) == -1){
			cads.push_back(s);
			add(s, n++);
		}
	}
	fb.close();			

		
	fb.open (args[2],ios::in);
	istream tin(&fb);
	string a,b;
	int g[200][200];
	for(int i = 0; i < n+1 ; i++) for(int j = 0; j < n+1 ; j++ ) g[i][j] = 1000;
	
	dist = vector<int>(cads.size(), -1);
	queue<int> q;
	q.push(0);
	dist[0] = 0;
	while(!q.empty()){
		int u = q.front(); q.pop();
		int sz = cads[u].size();
		s = cads[u]; //temporal
		for(int i = 0; i < sz; i++) 
			for(char c = 'A'; c <= 'Z'; c++){
				s[i] = c;//cambia 
				int pos = find(s); //busca la posicion en cads
				if(pos != -1 && dist[pos] == -1){ //si no encontro y si no ha sido visitado
				dist[pos] = dist[u] + 1; //distancia
				g[u][pos] = g[pos][u] = 1;
				q.push(pos);
				}
			s[i] = cads[u][i];//regresa al estado inicial
		}
	} 	
	
	for(int k = 0; k < n ; k++)
		for(int i = 0; i < n ; i++)
			for(int j = 0; j < n ; j++)
				g[i][j] = min(g[i][j],g[i][k]+g[k][j]);
	
	while(tin>>a>>b){
		int start = find(a);
		int end = find(b);
		cout<<g[start][end]+1<<endl;//distancia desde start a end
	}
	
	
	return 0;
}
