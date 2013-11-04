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
#include<cmath>
#include<stack>
#include<queue>
#include<set>
#include<map>

using namespace std;
#define mp make_pair 
#define x first
#define y second
#define pdd pair<double,double>
#define MAXN 1005
int ve,m;

double dst(pdd a, pdd b){
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

int main(){

	while(scanf("%d%d",&ve,&m)!=-1 && ve+m){
		ve *= 60.000000 * m;
		double xs,ys,xt,yt;
		scanf("%lf%lf%lf%lf",&xs,&ys,&xt,&yt);
		getchar();
		int t = 0;
		pdd puntos[MAXN];
		puntos[t++] = mp(xs,ys);
		puntos[t++] = mp(xt,yt);
		char s[100];
		
		while(fgets(s,100,stdin) && s[0]!='\n'){
			double xa,ya;
			sscanf(s,"%lf %lf",&xa,&ya);
			puntos[t++] = mp(xa,ya);
		}
		
		queue<int> q; 
		q.push(0);
		int dist[MAXN] = {0};
		dist[0] = 1;
		while(!q.empty()){
			int v = q.front();q.pop();
			if (v == 1) break;
			for(int u = 0; 	u < t ; u++){
				if (!dist[u])
					if((dst(puntos[u],puntos[v]) < ve)){
						q.push(u);
						dist[u] = dist[v] + 1;
					}
			}
		}
		int holes = dist[1] - 2;
		if (holes > 0){
			printf("Yes, visiting %d other holes.\n",holes);
		}else{
			puts("No.");
		}
	}	
	return 0;
}
