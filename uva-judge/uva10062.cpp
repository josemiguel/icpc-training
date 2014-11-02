#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

struct node{
	int c;int f;
	node(){}
	node(int c, int f): c(c), f(f) {}
};

bool operator < (const node &a, const node &b){
	if (a.f == b.f){
		return a.c > b.c;
	}
	return a.f < b.f;
}

int F[300],E[300];

int main(){
	int r = 0;
	while(true){
		if (r) putchar(10);
		r = 1;
		vector<node> a;
		char c;
		memset(F,0,sizeof F); memset(E,0,sizeof E);
		while((c = getchar()) && c != '\n' && c != '\r' && c != -1) F[c]++, E[c] = true;
		for(int i = 0; i < 300; i++) if (E[c]) a.push_back(node(i,F[i]));
		sort(a.begin(),a.end());
		
		for(int i = 0; i < a.size(); i++){
			printf("%d %d\n",a[i].c,a[i].f);
		}
		
		if (c == -1) return 0;
	}
	return 0;
}
