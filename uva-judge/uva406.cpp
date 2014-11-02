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

vector <bool> prime(1001, true);

void sieve(){
	prime[0] = false;
   	prime[1] = false;
   	for(int i = 2; i*i <= 1001; i++)
   		if(prime[i])
        	for(int j = i*i; j <= 1001; j += i)
            	prime[j] = false;
}

int main(){
	sieve();
	int n,c;
	for(int r = 1 ; scanf("%d%d",&n,&c) != -1; r++){
		int k = 0;
		int rang[1002];

		for(int i = 1; i <= n; i++){
			if (prime[i]){
				rang[k++] = i;
			}
		}
		printf("%d %d:",n,c);
		int mid = k/2;
		int ini,fin;
		if (mid - c < 0 || mid +c > n){
			printf(" 1");
			ini = 0;
			fin = k;
		}else{

			ini = mid - c;
			fin = mid + c - !(k%2) ;
		}
		
		for(int i = ini; i < fin; i++){
			printf(" %d",rang[i]);
		}
		putchar(10); putchar(10);
	}
	
	return 0;
}
