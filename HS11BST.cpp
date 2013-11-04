#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<map>
using namespace std ;
#define INF 1<<29
map<int,int> tree;
int maxlvl ;
map<int,vector<int> > h;

void insert( int x, int pos, int lvl ){
	if ( tree.count( pos) ){
		if ( x > tree[pos] ){
			insert( x , 2 * pos + 1, lvl + 1);
		}else if ( x < tree[pos] ){
			insert( x , 2 * pos , lvl + 1);
		}
		return ;
	}else{
		tree[pos] = x;	
		h[ lvl ].push_back( x );

		maxlvl = max( maxlvl, lvl );
	}
}

int main(){
	int n;
	while( scanf("%d",&n) != EOF ){
		tree.clear();
		maxlvl = 0;
		h.clear();

		for( int i = 0; i < n; i++ ) {
			int x;	scanf("%d",&x );
			insert( x, 1, 0 );
		}

		vector<int> res = h[ maxlvl - 1];
		sort( res.begin(), res.end() );
		for( int i = 0; i < res.size();i++){
			printf("%d\n",res[i]);
		}
	}
	return 0;
}
