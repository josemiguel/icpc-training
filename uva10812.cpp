#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>


using namespace std;
#define mp make_pair 
#define All(v) v.begin(),v.end()
#define INF 1<<30
#define MAX
//int g[MAX][MAX];
//vector<vector<int> > g;
int n,m;

int main(){
	int runs;
	scanf("%d",&runs);
	
	for(int r = 1 ; r <= runs ; r++){
		scanf("%d%d",&n,&m);
		if ((n + m) % 2 == 0 && (n - m) % 2 == 0){
			int A1 = (n + m) / 2;
			int A2 = (n - m) / 2;
			int B1 = n - A1;
			int B2 = n - A2;
			
			if (A1 < 0 || A2 < 0 || B1 < 0 || B2 < 0){
				puts("impossible");
			}else{
				if (A1 == B2 && B1 == A2){
					int a[2] = {A1,B1};
					sort(a,a+2);
					printf("%d %d\n",A1,B1);				
					
				}else{
					puts("impossible");
				}
			}
			
		}else{
			puts("impossible");
		}
	}
	
	return 0;
}
