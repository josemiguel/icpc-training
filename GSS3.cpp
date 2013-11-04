#include<cstdio>

struct node{
	int tsum;
	int rsum;
	int lsum;
	int msum;
	int left;
	int right;
}seg_tree[250001];
int A[50005];

inline int max(int a,int b){
	return (a > b)? a:b;
}

void set_seg_tree(int n,int l,int r){
	seg_tree[n].msum = 0;
	seg_tree[n].left = l;
	seg_tree[n].right = r;
	if (l < r){
		int m = (l + r) >> 1;
		set_seg_tree(2*n,l,m);
		set_seg_tree(2*n + 1,m + 1, r);
	}
}

void update(int n){
	seg_tree[n].tsum = seg_tree[2*n].tsum + seg_tree[2*n + 1].tsum;
	seg_tree[n].rsum = max( seg_tree[2*n + 1].rsum , seg_tree[2*n + 1].tsum + seg_tree[2*n].rsum );
	seg_tree[n].lsum = max( seg_tree[2*n].lsum , seg_tree[2*n].tsum + seg_tree[2*n + 1].lsum );
	seg_tree[n].msum = max( seg_tree[2*n].rsum + seg_tree[2*n + 1].lsum , max( seg_tree[2*n].msum , seg_tree[2*n + 1].msum  ) );
}

void insert(int n,int p,int val){
	if (seg_tree[n].left == seg_tree[n].right){
		seg_tree[n].tsum = seg_tree[n].msum = seg_tree[n].lsum = seg_tree[n].rsum = val;
		return;
	}
	int m = (seg_tree[n].left + seg_tree[n].right) >> 1;
	if (p <= m) insert(2*n,p,val);
	else insert(2*n + 1,p,val);
	update(n);
}

node maximal_sum(int n,int l,int r){
	if (seg_tree[n].left==l && seg_tree[n].right==r) return seg_tree[n];
	int m = (seg_tree[n].left + seg_tree[n].right) >> 1;
	if (r <= m) return maximal_sum(2*n,l,r);
	if (l > m) return maximal_sum(2*n + 1,l,r);
	node ln,rn,tmp;
	ln = maximal_sum(2*n,l,m);
	rn = maximal_sum(2*n + 1,m+1,r);
	
	tmp.tsum = ln.tsum + rn.tsum;
	tmp.rsum = max( rn.rsum , rn.tsum + ln.rsum );
	tmp.lsum = max( ln.lsum , ln.tsum + rn.lsum );
	tmp.msum = max( ln.rsum + rn.lsum , max( ln.msum , rn.msum  ) );
	
	return tmp;
}

int main(){
	int n,q;
	int a,b,c;
	scanf("%d",&n);
	set_seg_tree(1,1,n);
	for (int i=1; i <= n; ++i){ scanf("%d",&A[i]); insert(1,i,A[i]); }
	scanf("%d",&q);
	for (int i=0; i < q; ++i){
		scanf("%d %d %d",&a,&b,&c);
		if (a==0){
			insert(1,b,c);
		}
		else {
			printf("%d\n",maximal_sum(1,b,c).msum);
		}
	}
	return 0;
}

