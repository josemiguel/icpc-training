#include<cstdio>
const int MAX = 900001;
long long sum[MAX];
long long prop[MAX];

void build_tree(int n,int L,int R){
	sum[n] = prop[n] = 0;
	if (L==R) return;
	int m = (L + R) >> 1;
	build_tree(2*n,L,m);
	build_tree(2*n+1,m+1,R);
}

void update(int n,int L,int R,int l,int r,int val){
	if (L==l && r==R ){
		prop[n]+=val;
		return;
	}
	if (prop[n]){
		sum[n] += prop[n]*(R-L+1);
		prop[2*n] += prop[n];
		prop[2*n+1] += prop[n];
		prop[n] = 0;
	}
	sum[n] += ((long long)val*(r-l+1));
	int m = (L + R) >> 1;
	if (m < l){ update(2*n+1,m+1,R,l,r,val); }
	else if (m >= r){ update(2*n,L,m,l,r,val); }
	else {
		update(2*n,L,m,l,m,val);
		update(2*n+1,m+1,R,m+1,r,val);
	}
}

long long query(int n,int L,int R,int l,int r){
	if (L == l && r == R){
		if (prop[n]){
			sum[n] += prop[n]*(R-L+1);
			if (l!=r){ prop[2*n] += prop[n]; prop[2*n+1]+= prop[n]; }
			prop[n] = 0;
		}
		return sum[n];
	}
	if (prop[n]){
		sum[n] += prop[n]*(R-L+1);
		prop[2*n] += prop[n];
		prop[2*n+1] += prop[n];
		prop[n] = 0;
	}
	int m = (L + R) >> 1;
	if (m < l){ return query(2*n+1,m+1,R,l,r); }
	else if (m >= r){ return query(2*n,L,m,l,r); }
	return query(2*n,L,m,l,m) + query(2*n+1,m+1,R,m+1,r);
}

int main(){
	int runs;
	int n;
	int q;
	int t;
	int a,b;
	int v;
	
	scanf("%d",&runs);
	while (runs--){
		scanf("%d",&n);
		build_tree(1,1,n);
		scanf("%d",&q);
		while (q--){
			scanf("%d",&t);
			if (t){ 
				scanf("%d %d",&a,&b);
				printf("%lld\n",query(1,1,n,a,b));
			}
			else {
				scanf("%d %d %d",&a,&b,&v);
				update(1,1,n,a,b,v);
			}
		}
	}
	return 0;
}
