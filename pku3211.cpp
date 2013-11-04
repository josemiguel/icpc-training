#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std ;

int main(){

	int M,N;

	map<string,vector<int> > H;
	while(cin >> M >> N && M+N){
		string s,dic[M];
		for(int i = 0; i < M; i++) cin >> dic[i];
		
		for(int i = 0; i < N; i++){
			int t;
			cin >> t >> s;
			H[s].push_back(t);
		}
		int res = 0;

		

		for(int i = 0; i < M; i++){
			vector<int> p = H[dic[i]];
			for(int i = p.size()-1; i >= 0; i-=2){
				if ( i ) res += max(p[i],p[i-1]);
				else res += p[i];
			}
		}
		cout<< res << endl;

	}

	return 0;
}
