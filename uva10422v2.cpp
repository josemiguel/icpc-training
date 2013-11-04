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


int getX(int n){
	return (n & 56) >> 3;
}
int getY(int n){
	return n & 7;
}

void setX(int &n,int x){
	n &= (0xFFFC7 | x);
}

void setY(int &n,int y){
	n &= (0xFFFF8 | y);
}

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

int bfs(int start){
	queue<int> q;
	map<int,int> dist;
	dist[start] = 0;
	q.push(start);
	while(!q.empty()){
		int v = q.front(); q.pop();
		for(int i = 0; i < 8 ; i++){
			node u(v.mask,v.x + dx[i],v.y + dy[i]);
			u = v;
			int x = dx[i]+getX(v);
			setX(u,x);
			int y = dy[i]+getY(v);
			setY(u,y);
			
			
			
			if (x>=0 && y >= 0 && x<5 && y<5){
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
