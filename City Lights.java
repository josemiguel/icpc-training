import *;

public class CityLights{
	
	public static int [] id = new int[10002];
	public static int [] sz = new int[10002];
	
	public static vector< pair<int, pair<int, int> > > edg;

	public static void Init(int n) {
		for (int i = 0; i < n; i++)
			CityLights.id[i] = i, CityLights.sz[i] = 1;
	}

	public static int Find(int i) {
		if (i == CityLights.id[i]) return i;
		return CityLights.id[i] = Find(id[i]);
	}

	public static void Union(int v, int w) {
		v = CityLights.Find(v); w = CityLights.Find(w);
		if (v == w) return;
		if (CityLights.sz[v] > CityLights.sz[w]) swap(v,w);
		CityLights.id[v] = w;
		if (CityLights.sz[v] == CityLights.sz[w]) CityLights.sz[w]++;
	}
	
	
	public static int kruskal(int n , int ne){
		int cost = 0;
		sort(edg.begin(),edg.end());
		Init(n);
		int k = 0;
		for (int i = 0; i < ne && k < n; i++) {
			if (Find(edg[i].second.first) != Find(edg[i].second.second)) {
				Union(edg[i].second.first,edg[i].second.second);
				cost += edg[i].first; k++;
			}
		}
		return cost;		
	}

	public static void main(String [] args){
		
	}
}
