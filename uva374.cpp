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

int bigmod(int b,int p,int m){
    if(p == 0) return 1;
    if(p % 2 == 0){
        int x = bigmod(b,p/2,m) % m;
        return (x*x) % m;
    }
    return ((b%m)*bigmod(b,p-1,m)) % m;
}

int main(){
	int b,p,m;
	while(scanf("%d%d%d",&b,&p,&m)!=-1){
		printf("%d\n",bigmod(b,p,m));
	}
	
	return 0;
}
