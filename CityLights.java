import java.math.BigInteger;
import java.util.Scanner;
import java.util.*;
import java.io.FileInputStream;


public class cityLights{
	
	public static int [] id = new int[10002];
	public static int [] sz = new int[10002];
	
	public static class triple{
		public int w, u, v;
		public triple(int w, int u, int v){
			this.w = w;
			this.u = u;
			this.v = v;
		}
	}
	
	
	public static List<triple> edg = new ArrayList<triple>();

	public static void Init(int n) {
		for (int i = 0; i < n; i++){
			cityLights.id[i] = i;
			cityLights.sz[i] = 1;
		}
	}

	public static int Find(int i) {
		if (i == cityLights.id[i]) return i;
		return cityLights.id[i] = Find(id[i]);
	}

	public static void Union(int v, int w) {
		v = cityLights.Find(v); w = cityLights.Find(w);
		if (v == w) return;
		int tmp = 0;
		if (cityLights.sz[v] > cityLights.sz[w]) {
			v = tmp;
			v = w;
			w = tmp;
		}
		cityLights.id[v] = w;
		if (cityLights.sz[v] == cityLights.sz[w]) cityLights.sz[w]++;
	}
	
	
	public static int kruskal(int n , int ne){
		int cost = 0;
		
		
		Collections.sort(edg, new Comparator<triple>(){
			public int compare(triple o1, triple o2) {
		        return o2.w - o1.w;
		    }

		});

		
		Init(n);
		int k = 0;
		for (int i = 0; i < ne && k < n; i++) {
			if (Find(edg.get(i).u) != Find(edg.get(i).v)) {
				Union(edg.get(i).u,edg.get(i).v);
				cost += edg.get(i).w; k++;
			}
		}
		return cost;		
	}

	public static void main(String [] args){
		try{
		Scanner sc = new Scanner(new FileInputStream(args[0]));
		int n = Integer.valueOf(sc.next());
		int m = Integer.valueOf(sc.next());	
		for (int i = 0; i < m; i++) {
			int u,v,peso;
		
			u = Integer.valueOf(sc.next());
			v = Integer.valueOf(sc.next());
			peso = Integer.valueOf(sc.next());				
			edg.add(new triple(peso,u,v));
		}
		System.out.println(kruskal(n,m));
		}catch(Exception ex){}
	}
}
