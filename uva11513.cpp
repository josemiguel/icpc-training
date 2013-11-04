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
#define mp make_pair 
#define All(v) v.begin(),v.end()
#define INF 1<<30

string move[6] = {"H1","H2","H3","V1","V2","V3"};

struct node{
	int a[3][3];
};

int hash(node s){
	int n = 0;for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++) n = n*10 + s.a[i][j]; return n;
}

node nohash(int n){
	node s;for(int i = 2; i >= 0;i--) for(int j = 2; j >= 0; j--) s.a[i][j] = n%10, n/=10; return s;
}

int adj(int s,int i){
	node e = nohash(s);
	int tmp;
	if (i >=0 && i <=2) tmp = e.a[i][0], e.a[i][0] = e.a[i][1], e.a[i][1] = e.a[i][2], e.a[i][2] = tmp;
	else i= i-3,tmp = e.a[2][i], e.a[2][i] = e.a[1][i], e.a[1][i] = e.a[0][i], e.a[0][i] = tmp;
	return hash(e);
}

map<int,string> sol;
map<int,int> pai;

void bfs(){
	queue<int> q;
	q.push(123456789);
	pai[123456789] = -2;
	while(!q.empty()){
		int v = q.front();q.pop();
		for(int i = 0; i < 6; i++){
			int u = adj(v,i);
			if (!pai[u]){
				pai[u] = v;
				sol[u] = move[i];
				q.push(u);
			}		
		}
	}
}

int main(){
	bfs();
	while(1){
		int s = 0,a;
		for(int i = 0; i < 9;i++){
			scanf("%d",&a);
			if (!a) return 0;
			s = s*10 + a;
		}
		if (sol.find(s) != sol.end()){
			string res = "";
			for(int i = s; i != -2; i = pai[i]) res += sol[i];
			cout<<res.size()/2<<" "<<res<<endl;
		}else{
			cout<<"Not solvable"<<endl;
		}
	}
	return 0;
}
