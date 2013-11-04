#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <bitset>
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
#define pq priority_queue

#define INF 1<<30
#define to first
#define we second

#define vii vector<vector<int> > ;
#define vi vector<int> ;
#define pii pair<int,int> ;
#define vpii vector<pair<int,int> > ;
#define gpii greater<pair<int,int> > ;

int W[1000][1000];
int C[1000];

int main(){

	int n, e, q;
	for(int r = 1 ; scanf("%d%d%d",&n,&e,&q) && n+e+q ; r++){
		printf("Case #%d\n",r);
		int u,v,w;		
		for(int i = 0; i < n ; i++) scanf("%d",&C[i]);
		
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				if (i == j) W[i][j] = 0;
				else W[i][j] = 1<<10;

		
		for(int i = 0; i < e ; i++){
			scanf("%d%d%d",&u,&v,&w);
			u--; v--;
			W[u][v] = w + C[u];
			W[v][u] = w + C[v];
		}
		for(int i = 0; i < n ; i++){
			for(int j = 0; j < n ; j++)
				cout<<W[i][j]<<"\t ";
			cout<<endl;
		}
		cout<<endl;
		
		for(int k = 0; k < n ; k++)
			for(int i = 0; i < n ; i++)
				for(int j = 0; j < n ; j++){
					W[i][j] = min(W[i][j], W[i][k] + W[k][j]);
				}
				
		for(int i = 0; i < n ; i++){
			for(int j = 0; j < n ; j++)
				cout<<W[i][j]<<"\t ";
			cout<<endl;
		}						

					
		while(q--){
			scanf("%d%d",&u,&v);
			u--; v--;
			if (W[u][v] == 1<<10){
				printf("-1\n");
			}else
				printf("%d\n",W[u][v]);
		}
	}

	return 0;
}
