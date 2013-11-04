#include<iostream>
#include<vector>
#include<algorithm>
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second

using namespace std;
int main(){
	int n;
	while(scanf("%d",&n) && n){
		vector<pii> ps(n);
		for(int i = 0  ; i < n ; i++){
			int u,v;
			scanf("%d%d",&u,&v);
			ps[i] = mp(u,v);

		}
		int res = -1;
		for(int i = 0 ; i < n  ; i++){
	
			vector<double> ds;
			for(int j = 0 ; j < n; j++){
				if (ps[i].x == ps[j].x && ps[j].y == ps[j].y) continue;
				ds.push_back(((double)(ps[i].x - ps[j].x))/(ps[i].y - ps[j].y));
			}
			int best = 2, k = 2;
			sort(ds.begin(),ds.end());
			for(int i = 1  ; i < n   ;i++){
		
				if (ds[i-1] == ds[i]){
					k++;
					if (k > best){
						best = k;
					}
				}else{
					k = 2;
				}
			}
			res = max(best,res);
		}
		printf("%d\n",res);
	}

	return 0;
}

