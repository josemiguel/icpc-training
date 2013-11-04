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

struct node{
	int val;
	node *izq;
	node *der;
	node(){
		val = -1;
		izq = der = NULL;
		seen = false;
	}
	bool seen;
};

struct cmp_str 
{
   bool operator()(char const *a, char const *b) 
   {
      return std::strcmp(a, b) < 0;
   }
};

int main(){
	char nodo[100];
	while(scanf("%s",nodo)!=-1){
		char pos[50]={0};
		int v[100][50] = {0},val;
		char *p[100][50] = {0};
		int d[100]	= {0};
		map<char *, int, cmp_str> _nodes;
		
		int cc = sscanf(nodo,"(%d,%[LR]",&val,pos);
		if (cc==1) strcpy(pos,"");
		int len = strlen(pos);
		int maxlen = len;	

		v[len][d[len]] = val;
		p[len][d[len]] = strdup(pos);
		
		_nodes[strdup(pos)]++;
		
		d[len]++;
		bool completo = true;
		while(scanf("%s",nodo)){
			if (!(cc = sscanf(nodo,"(%d,%[LR]",&val,pos))) break;
			if (cc==1) strcpy(pos,"");
			len = strlen(pos);
			v[len][d[len]] = val;
			p[len][d[len]] = strdup(pos);
			
			int inc = ++_nodes[strdup(pos)];
			
			if (inc > 1) completo = false;
			
			d[len]++;
			maxlen = max(maxlen,len);
		}

		node *Tree = new node;
		Tree->val = v[0][0];

		for(int k = 0; k <= maxlen ; k++){
			
			if (!d[k] || !completo) {completo = false;break;}
			for(int i = 0; i < d[k]; i++){
				node *tmp = Tree;	
				for(int j = 0; j < k ;j++){
					if (p[k][i][j]=='L'){
						if (!tmp->izq)
							tmp->izq = new node;
						tmp = tmp->izq;

					}else if (p[k][i][j]=='R'){
						
						if (!tmp->der)
							tmp->der = new node;
						tmp = tmp->der;
					}
					
				}
				tmp->val = v[k][i];
			}
		}

		if (completo){
			queue<node *> q;
			q.push(Tree);
			Tree->seen = true;
			printf("%d",Tree->val);
			int p = 0;
			while(!q.empty()){
				node *v = q.front();q.pop();
				if (v->val > 0 && p)
					printf(" %d",v->val);
				if (v->izq != NULL){
					if (!v->izq->seen){
						v->izq->seen = true;
						q.push(v->izq);
					}
				}
				if (v->der != NULL){
					if (!v->der->seen){
						v->der->seen = true;				
						q.push(v->der);
					}
				}
				p++;
			}
			putchar(10);
		}else {
			printf("not complete\n");
		}
	}
	return 0;
}
