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
#define pq priority_queue

#define INF 1<<30
#define to first
#define we second

#define vii vector<vector<int> > ;
#define vi vector<int> ;
#define pii pair<int,int> ;
#define vpii vector<pair<int,int> > ;
#define gpii greater<pair<int,int> > ;

struct node{
	int res, pen, idx;
	int probs[11];
	bool corr[11];
	node(){res = pen = idx= 0; memset(probs,0,sizeof(probs));memset(corr,false,sizeof(corr));}
	node(int idx, int res, int pen): idx(idx), res(res), pen(pen){}
	void incress(int c, int p, int t, int l){
		idx = c;
		if (l == 'C' && !corr[p]){
			res++;
			pen += t + 20*probs[p];
			corr[p] = 1;
		}else if (l == 'I'){
			probs[p]++;
			
		}
		
	}
};

bool operator<(const node &b, const node &a){
	if (a.res < b.res){
		return true;
	}else if (a.res == b.res){
		if (a.pen > b.pen){
			return true;
		}else if (a.pen == b.pen){
			return a.idx > b.idx;
		}
	}
	return false;
}

int main(){
	int runs;
	scanf("%d",&runs);
	cin.ignore();
	cin.ignore();	
	for(int r = 1 ; r <= runs ; r++){
		if (r!=1) cout<<endl;
		string s;
		node nodes[105];
		bool exist[105] = {0};
		while(getline(cin,s) && s!=""){
			istringstream is(s);
			int c,p,t;
			char l;
			is>>c>>p>>t>>l;
			
			if (!exist[c]){
				nodes[c] = node();
				exist[c] = 1;
			}
			nodes[c].incress(c,p,t,l);

		}
		sort(nodes,nodes+105);
		for(int i = 0; i < 105 ; i++){
			if (nodes[i].idx){
				printf("%d %d %d\n",nodes[i].idx,nodes[i].res,nodes[i].pen);
			}
		}		
	}
	return 0;
}
