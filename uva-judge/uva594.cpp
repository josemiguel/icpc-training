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


struct node{
	char b[4];
};

int main(){
	node n;
	while(scanf("%d",&n)!=-1){
		node nn = n;
		reverse(n.b,n.b+4);
		printf("%d converts to %d\n",nn,n);
	}
	
	return 0;
}
