nt p[N], r[n];
void make(int u){
p[u] = u; r[u] = 0;
}
void join(int u, int v){
if(r[u] < r[v]) swap(u, v);
p[v] = u;
if(r[u] == r[v]) r[u]++
}
int find(int u){
return u == p[u] ? u : p[u] = find(p[u]);
}
void Union(int u, int v){
join(find(u), find(v));
}
