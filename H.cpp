#include<cstdio>
#include<iostream>
#include<set>
#include<cmath>
#include<cstring>
using namespace std;

typedef long long Int;
double eucl(Int x1, Int x2, Int y1, Int y2){
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}


double E[105][105];
double dist[105 * 105];
int F[105];

struct dot{
	Int x, y;
	dot(){}
	dot(Int x, Int y ):x(x), y(y) {}
};

dot cat[105];

int main(){

	int N;
	Int px,py,lx,ly;

	while (cin >> N >> px >> py >> lx >> ly){
		if ( N == -1) break;
		N += 2;
		E[N-1][0] = E[0][N-1] = eucl(px,lx,py,ly);

		for ( int i = 1; i < N-1; i++){
			Int x, y;
			cin >> x >> y >> F[i];

			E[ 0 ][ i ] = eucl( x , px, y, py );
			E[ i ][ 0 ] = eucl( x , px, y, py ) - F[i];
			E[ i ][ N - 1 ] = fabs(eucl( x , lx, y, ly )-F[i]);
			E[ N - 1 ][ i ] = fabs(eucl( x , lx, y, ly ));
			cat[i] = dot( x, y );
		}


		for(int i = 1; i < N -1 ; i++){
			for(int j = 1; j < N-1; j++){
				if (  i ==  j ) continue;
				E[ i ][ j ] = fabs(eucl( cat[i].x, cat[j].x, cat[i].y, cat[j].y) - F[i]);
				E[ j ][ i ] = fabs(eucl( cat[i].x, cat[j].x, cat[i].y, cat[j].y) - F[j]);
			}
		}

		set<pair<double, int > > Q;
		Q.insert(make_pair( 0.0, 0 ) );

		for(int i = 0; i < 105*105; i++) dist[i] = -1000;

		dist[ 0 ] = 0 ;
		
		while ( !Q.empty() ){
			
			
			pair<double , int > cur = *Q.begin();
			
			int v = cur.second;
			double w = cur.first;

			Q.erase(Q.begin());

			if ( dist[ v ] < w ) continue;
			if ( v == N-1 ) break;

			for(int i = 1; i < N; i++){
				if ( i == v ) continue;
				double W = E[v][i];
				if (dist[i] < 0 or dist[i] >  w + W){
					dist[i] = w + W;
					Q.insert(make_pair( dist[i] , i ));
				}
			}
			
		}
		printf ( "%.2lf\n", dist[ N - 1 ] );
	}

	

	return 0;
}
