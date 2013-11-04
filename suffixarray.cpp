int t;
int p[MAXN], r[MAXN], h[MAXN];

bool comp(int i,int j){ return p[i+t] < p[j+t]; }

void suff_arr(string &s ){
       int n = s.size();
       vint bc(256,0);
       f(i,0,n) bc[s[i]]++;
       f(i,1,256) bc[i] += bc[i-1];
       f(i,0,n) r[--bc[s[i]]] = i;
       f(i,0,n) p[i] = bc[s[i]];
       for(t=1; t<n; t*=2 ){
               for(int i=0,j=1; j<n; i=j++){
                       while( j<n && p[r[i]]==p[r[j]] ) j++;
                       if( j-i==1 ) continue;
                       int *ini = r+i, *fin = r+j;
                       sort(ini, fin, comp);
                       int num = i, pri = p[*ini+t], pk;
                       for(; ini<fin; p[*ini++] = num ){
                               if( ((pk=p[*ini+t]) == pri) || (i<=pri && pk<j) ){}
                               else pri = pk, num = ini-r;
                       }
               }
       }
}

void lcp(string &s){
       int k = 0, n = s.size();
       f(i,0,n)if( p[i] ){
               int j = r[p[i]-1];
               while( s[i+k] == s[j+k] ) k++;
               h[p[i]-1] = k;
               if( k ) k--;
       }
       h[n-1] = 0;
}
