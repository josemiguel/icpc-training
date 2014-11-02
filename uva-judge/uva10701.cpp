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

int n;

char pre[100], in[100];
int idx[100];

struct node{
	int val;
	node *izq,*der;
	node(){}
	node(int val): val(val){}
};

void insertBST(node *&root, int val){
	if (root == NULL) root = new node(val);
	else{
		if (val < root->val){
			insertBST(root->der,val);
		}else if (val > root->val){
			insertBST(root->izq,val);
		}
	}
}

void postBST(node *root){
	if (root->der != NULL){
		postBST(root->der);
	}
	

		
	if (root->izq !=NULL){
		postBST(root->izq);
	}
	
		putchar(in[root->val]);
}


int main(){
	int runs;
	scanf("%d",&runs);
	
	for(int r = 1 ; r <= runs ; r++){
		scanf("%d%s%s",&n,pre,in);
		for(int i = 0; i < n ;i++){
			idx[in[i]] = i;
		}
		node *tree = NULL;
		for(int i = 0; i < n ; i++){
			insertBST(tree,idx[pre[i]]);
		}
		postBST(tree);
		putchar(10);		
	}
	

	
	
	
	return 0;
}
