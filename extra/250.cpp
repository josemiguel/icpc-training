#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


vector<int> pos;
vector<int> S[10];
int N;

void F(int num, int len){
	//cout << num <<endl;
	if (len > 8) return;

	if (len>=1 &&  S[len-1].size()) {

		return;
	}
	
	if (num % N	== 0 && len != 0){

		S[len].push_back( num );
//		cout << num << endl;
		return;
	}
	

	for(int i = 0; i < pos.size(); i++){
		if (len == 0 && pos[i]==0) continue;
		if (S[len-1].size() == 0) F( num*10 + pos[i] , len + 1 );
		
	}

}




int met(int _N, vector<int> forb){
	N = _N;
	for(int j = 0; j <= 9; j++){
		bool cagao = false;
		for(int i = 0; i < forb.size(); i++){
			if ( j == forb[i] ) {cagao = true; break;}
		}
		if (!cagao){

			pos.push_back(j);
		}
	}

	F(0,0);
	
	int res = 1<<30;
	for(int j = 1; j <= 8; j++){
		for(int i = 0; i < S[j].size(); i++){
			res = min( res, S[j][i] );
		}
	}
	return res;
}
int arr[]={1,3,4,5,6,7,8,9,-1};
int main(){

	vector<int> forb;

	for(int i = 0 ; arr[i] >= 0; i++) forb.push_back(arr[i]);
	sort(forb.begin(),forb.end());	
	int n = 9;
	
	
	if (forb[0] == 0 && n % 10 == 0){
	 cout <<"IMPOSSIBLE"<<endl;
	 return 0;
	 }
	
	
	int res = met(n,forb);
	
	
	if (res == 1<<30){
		cout <<"IMPOSSIBLE"<<endl;
	}else{
		cout << res << endl;
	}


	return 0;
	
	
}
