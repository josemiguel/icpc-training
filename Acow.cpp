#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<queue>
#include<stack> 
#include<string>
#include<cctype>
#include<set>
#include<map>
#include<numeric>

#define mp make_pair
#define oo (1<<20)
#define ones(x) __builtin_popcount(x)
#define clr(x) memset((x),0,sizeof(x))
#define rclr(x) memset((x),-1,sizeof(x))
#define All(v) (v).begin(),(v).end()
#define rAll(v) (v).rbegin(),(v).rend()
#define x first
#define y second
#define pb push_back
#define eps (1e-9)
#define sz size()
#define MAX 30

#define REP(i,a,n) for(int i = a; i < n; i++)
#define rep(i,n) REP(i,0,n)
#define dec(i,n) for(int i = n-1; i >= 0; i--)
#define DEC(i,a,n) for(int i = n-1; i >= a; i--)

using namespace std;

struct state{
	int a,b,c;
	state(){}
	state(int a,int b, int c):a(a),b(b),c(c){}
};

bool operator == (state const &a, state const &b){
	return a.a == b.a && a.b == b.b && a.c == b.c;
}

bool operator != (state const &a, state const &b){
	return !(a.a == b.a && a.b == b.b && a.c == b.c);
}


void pre(){
	for(int i = 1; i <= 20; i++){
		
	}
}


state pai[65][65][65];

int main(){
	int a,b,c;

	while(scanf("%d %d %d",&a,&b,&c)!=-1){
		if ((a+b+c)%3){
			printf("%4d%4d%4d\n",a,b,c);
			puts("============");
			continue;
		}
		queue<state> Q;
		Q.push(state(a,b,c));
		rep(i,65) rep(j,65) rep(k,65) pai[i][j][k] = state(-1,-1,-1);
		pai[a][b][c] = state(-2,-2,-2);
		while(!Q.empty()){
			state v = Q.front();Q.pop();
			int aa = v.a;
			int bb = v.b;
			int cc = v.c;
			if (aa == bb && bb == cc) break;
			if (aa < bb) {
				state u = state(aa*2,bb-aa,cc);
				if (pai[u.a][u.b][u.c] == state(-1,-1,-1)){
					pai[u.a][u.b][u.c] = v;
					Q.push(u);
				}
			}
			if (aa < cc){
				state u = state(aa*2,bb,cc-aa);
				if (pai[u.a][u.b][u.c] == state(-1,-1,-1))	{
					pai[u.a][u.b][u.c] = v;
					Q.push(u);
				}
			}
			if (bb < aa){
				state u = state(aa-bb,bb*2,cc);
				if (pai[u.a][u.b][u.c] == state(-1,-1,-1))	{
					pai[u.a][u.b][u.c] = v;
					Q.push(u);
				}
			}
			if (bb < cc){
				state u = state(aa,bb*2,cc-bb);
				if (pai[u.a][u.b][u.c] == state(-1,-1,-1))	{
					pai[u.a][u.b][u.c] = v;
					Q.push(u);

				}
			}
			if (cc < aa){
				state u = state(aa-cc,bb,cc*2);
				if (pai[u.a][u.b][u.c] == state(-1,-1,-1))	{
					pai[u.a][u.b][u.c] = v;
					Q.push(u);
				}
			}
			if (cc < bb){
				state u = state(aa,bb-cc,cc*2);
				if (pai[u.a][u.b][u.c] == state(-1,-1,-1))	{
					pai[u.a][u.b][u.c] = v;
					Q.push(u);
				}
			}
		}
	
		int s = (a+b+c) / 3;
		state end(s,s,s);
		vector<state> v;
		if (pai[end.a][end.b][end.c] == state(-1,-1,-1)){
			printf("%4d%4d%4d\n",a,b,c);
			puts("============");
			continue;
		}
		for(state pos = end;  ; ){
			if (pos == state(-2,-2,-2) ) break;
			v.push_back(pos);
			pos = pai[pos.a][pos.b][pos.c];
		}
		dec(i,v.sz)	printf("%4d%4d%4d\n",v[i].a,v[i].b,v[i].c);
		puts("============");
	}
	return 0;
}
