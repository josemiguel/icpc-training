#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
#include<cstdio>
using namespace std ;
int dist[1<<16];
int mask[1<<16], n;

int main(){

	int T, m;

	scanf("%d",&T);
	
	for( int r = 1; r <= T; r++ ) {
		printf("Case %d: ",r);;

		scanf("%d %d",&n, &m);
		memset(mask, 0, sizeof mask);
		for( int i = 0; i < m; i++ ){
			for( int j = 0; j < n; j++ ){
				int bit;
				scanf("%d",&bit);
				mask[i] |= (bit<<j);
			}

		}

		queue<int> Q;
		Q.push((1<<n)-1);
		memset(dist,-1,sizeof dist);
		dist[(1<<n)-1] = 0;
		while( !Q.empty() ){
			int v = Q.front(); Q.pop();
			for( int i = 0; i < m; i++ ){
				int u = mask[i] ^ v;
				if ( dist[ u ] == -1 ) {
					dist[ u ] = dist[ v ] + 1;
					Q.push( u );
				}
			}
		}
		if (dist[ 0 ] == -1) {
			puts("IMPOSSIBLE");
		}else{
			printf("%d\n",dist[ 0 ]);
		}

	}

	return 0;
}
