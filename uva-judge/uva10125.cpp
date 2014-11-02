#include<iostream>
#include<cstring>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
#define INF 1LL << 60
typedef long long Int;
vector< pair<Int,pair<int,int> > > S;
#define MAX 1001

Int sum[MAX][MAX], dif[MAX][MAX];
int a[MAX];
pair<Int,pair<int,int> > mp( Int a, int b, int c){
	return make_pair(a,make_pair( b, c ));
}


pair<int,int> Find( Int sum ){
	int lo = 0 , hi = S.size()-1;
	while( lo < hi ){
		int mid = (lo+hi) / 2;
		if ( sum  == S[mid].first)  {
//			cout << sum <<" "<< a[S[mid].second.first]<<" "<<a[S[mid].second.second]<< endl;
			return S[mid].second;
		}
		if ( sum > S[mid].first) lo = mid + 1;
		else hi = mid - 1;
	}
	return make_pair(-1,-1);
}

int main(){
	int N;
	while(cin >> N && N){
		for(int i = 0; i < N; i++) {
			cin >> a[i];
		}
		S.clear();
		sort( a, a + N );

		for( int i = 0; i < N; i++){
			for( int j = i + 1 ; j < N; j++){
				sum[i][j] = a[i] + a[j];
				dif[i][j] = a[i] - a[j];
				dif[j][i] = a[j] - a[i];
				S.push_back( mp(dif[i][j],i,j) );
				S.push_back( mp(dif[j][i],j,i) );
			}
		}

		Int best = -INF;
		sort( S.begin(), S.end() );
		for(int i = 0; i < N; i++){
			for(int j = i + 1 ; j < N; j++){
				pair<int,int> ij = Find( sum[i][j] );
				if ( ij.first == -1 ) continue;
				if ( ij.first == i || ij.second == i ) continue;
				if ( ij.first == j || ij.second == j) continue;
				if ( a[ ij.first ] > best ){
//					cout << sum[i][j] <<" "<< a[i]<<" "<<a[j]<<endl;
//					cout << dif[ij.first][ij.second] << " " <<a[ij.first] <<" "<<a[ij.second] <<endl;
//					cout <<"nicagando ps"<<endl;
					best = a[ ij.first ];
				}
			}
		}


		if ( best != -INF){
			cout << best << endl;
		}else{
			cout <<"no solution"<< endl;
		}
	}

	return 0;
}
