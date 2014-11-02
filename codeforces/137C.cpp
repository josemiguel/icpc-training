#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define mp make_pair
#define pii pair<int,int> 
bool over( pii a, pii b){
	return a.second > b.second;
}



int main(){

	int n;
	cin >> n;
	vector<pair<int,int> > v;

	for(int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		v.push_back(mp(x,y));
	}

	sort( v.begin(), v.end() );
	int res = 0;
	for(int i = 1,t = 0; i < n; i++){
		if ( over(v[t],v[i]) ){
			res++;
		}else{
			t = i;
		}
	}
	cout << res << endl;

	return 0;
}
