#include<iostream>
#include<vector>
#include<set>
using namespace std;
typedef long long Int;
#define MOD 1000000007LL
#define MAX 102000008
#define sq 10004
int p[sq],pp[MAX];
void pre( ){
	pp[0]=pp[1]=1;
	int k = 0;
	for(int i = 2; i*i < MAX; i++){
		if (!pp[i]){
			p[k++] = i;
			for(int j = i*i; j*j < MAX; j+=i){
				pp[j] = 1;
			}
		}	
	}
	cout << k<< endl;
}

int main(){
	int runs,n;
	cin >> runs;
	pre();
	while( runs--){
		cin >> n;
		Int sum = ((n * ( n + 1) % MOD) * ( 2 * n % MOD+ 1)) % MOD;
		sum *= (3 * n * n % MOD + ((3*n % MOD) - 1 % MOD)%MOD) % MOD;
		sum /= 30;
		set<int> S;	
		vector<int> v;
		int N = n,i;

		for(i = 0; p[i] <= n ; i++){
			cout << p[i] << " " << i << endl;
			v.push_back( p[ i ]);
			if ( n % p[i] == 0)
				S.insert( p[ i ] );
		}
		cout << i << endl;
		while( true ){
			
			bool b = false;
			for(set<int>::iterator it = S.begin(); it!=S.end(); it++){
				
				int t = *it;
				for(int i = 0; i < v.size(); i++){
					if ( t * v[ i ]  > N ) continue;
					if ( S.count( t*v[i])) continue;
					b = true;
					S.insert( t * v[ i ] );
				}
			}
			if ( !b ) break;
		}

		for(set<int>::iterator it = S.begin(); it!=S.end(); it++){
			
			int s = *it;
			s = (s * s * s * s % MOD );
		
			sum -= s % MOD;
		}
		cout << sum%MOD << endl;
	
	}

	return 0;
}
