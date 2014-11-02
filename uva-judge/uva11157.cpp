#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

int main(){
	int runs;
	scanf("%d",&runs);

	for(int r = 1; r <= runs; r++){

		int res = 0, n, d ;
		
		scanf("%d %d",&n,&d);
		vector<int> v;
		v.push_back(0);
		for(int i = 0; i < n; i++){
			int k; char c;
			cin>>c;
			bool e = false;
			if (c == 'B') e = true;
			cin>>c>>k;
			if (e)	v.push_back(k);
		}
		v.push_back(d);
		for(int i = 1; i < v.size(); i++){
			res = max(res,v[i] - v[i-1]);
		}


		printf("Case %d: %d\n",r,res);
	}
}

