#include<iostream>
#include<cmath>
#include<cstdio>
#include<vector>
using namespace std;

int main(){

	int runs;
	scanf("%d",&runs);
	int r = 0;
	while(runs--){
		if (r) cout<<endl;
		r = 1;
		int n;
		cin>>n;
		pair<int,int> ptr(0,0);
		string cad;
		cin>>cad;
		vector<pair<int,int> > v(n+1);
		for(int i = 1; i <= n; i++){
			switch (cad[i-1]){
				case 'N':
					v[i] = make_pair(v[i-1].first, v[i-1].second + 1);
					break;
				case 'S':
					v[i] = make_pair(v[i-1].first, v[i-1].second - 1);
					break;
				case 'E':
					v[i] = make_pair(v[i-1].first+1, v[i-1].second);
					break;
				case 'W':
					v[i] = make_pair(v[i-1].first-1, v[i-1].second );
					break;
			}
		}

		/*for(int i = 1; i <= n; i++){
			cout<<v[i].first<<" "<<v[i].second<<endl;
		}*/
		int b, e;
		int best = 1<<30;
		for(int i = 1; i <= n; i++){
			for(int j = i + 3; j <= n; j++){
				int dist_x = 0;
				int dist_y = 0;
				
				if (v[i].second == v[j].second)	dist_x = fabs(v[i].first - v[j].first);
				if (v[i].first == v[j].first) dist_y = fabs(v[i].second - v[j].second);
				int dist = max(dist_x,dist_y);
				if (dist < best && dist){
					best = dist;
					b = i;
					e = j;
				}
				if (dist == best &&  j > e){
					e = j;
				}
				
			}
		
		}
		char dir;
		if (v[b].first > v[e].first) dir = 'W';
		if (v[b].first < v[e].first) dir = 'E';
		if (v[b].second > v[e].second) dir = 'N';
		if (v[b].second < v[e].second) dir = 'S';
		printf("%d %d %d %c\n",best, b,e,dir);

	
	}

	return 0;
}
