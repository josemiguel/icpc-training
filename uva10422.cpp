#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<numeric>
#include<cctype>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<queue>
#include<set>
#include<map>

using namespace std;

int dx[] = {-1,1,2,2,1,-1,-2,-2};
int dy[] = {2,2,1,-1,-2,-2,-1,1};

struct node{
	int mask,x,y,dist;
	node(int a=0, int b = 0, int c = 0){
		mask = a; x = b; y = c;
	}
	bool operator <(const node& B) const{
		if(mask != B.mask) return mask < B.mask;
		if(x != B.x) return x < B.x;
		return y < B.y;
	}
};

int bit(int n, int pos){
	return (n >> pos) & 1;
}

void put(int &n, int pos, int b){
	int mask;
	mask = 1 << pos;	
	if (b){
		n |= mask;
	}else{
		mask = ~mask;
		n &= mask;
	}
}

int bfs(node start){
	queue<node> q;
	map<node,int> dist;
	dist[start] = 0;
	q.push(start);
	while(!q.empty()){
		node v = q.front(); q.pop();
		for(int i = 0; i < 8 ; i++){
			node u(v.mask,v.x + dx[i],v.y + dy[i]);
			if (u.x>=0 && u.y >= 0 && u.x<5 && u.y<5){
				put(u.mask,v.x*5+v.y,bit(v.mask,u.x*5+u.y));
				put(u.mask,u.x*5+u.y,0);
				if (!dist[u] && dist[u]<=10){
					q.push(u);
					int d = (dist[u] = dist[v] + 1);
					if (d > 10) return -1;
					if (u.mask == 549855 && u.x == 2 && u.y == 2) return d;
				}
			}
		}
	}
}


int main(){
	int n;
	scanf("%d",&n);
	getchar();	
	while(n--){
		node start;
		for(int i = 0; i < 5 ;i++){
			for(int j = 0; j < 5 ; j++){
				char c = getchar();
				if (c==' '){
					c = '0';
					start.x = i; start.y = j;
				}
				put(start.mask,i*5+j,c-'0');
			}
			getchar();
		}
		int moves = 0;
		if(start.mask == 549855) printf("Solvable in %d move(s).\n",moves);
		else{
			moves = bfs(start);
			if (moves >= 0){
				printf("Solvable in %d move(s).\n",moves);
			}else{
				puts("Unsolvable in less than 11 move(s).");
			}
		}
	}
	return 0;
}
