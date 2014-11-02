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
#define MAX 1050
#define MID MAX/2

int tree[MAX];

void f(int val, int mid){
	tree[mid] += val;
	int izq,der;
	scanf("%d",&izq);
	if (izq !=-1){
		f(izq,mid-1);
	}
	scanf("%d",&der);
	if (der !=-1){
		f(der,mid+1);	
	}
}

int main(){
	int root;
	for(int r = 1;scanf("%d",&root) && root!=-1;r++){
		memset(tree,0,sizeof(tree));
		f(root,MID);
		bool p = false;
		printf("Case %d:\n",r);
		for(int i = 0; i < MAX ; i++){
			if (tree[i]){
				if (p) putchar(' ');
				p = true;
				printf("%d",tree[i]);
			}
		}
		putchar(10);putchar(10);
	}
	return 0;
}
