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
			id[i] = i;
			sz[i] = 1;
		}
	}

	public static int Find(int i) {
		if (i == id[i]) return i;
		return id[i] = Find(id[i]);
	}

	public static void Union(int v, int w) {
		v = Find(v); w = Find(w);
		if (v == w) return;
		int tmp = 0;
		if (sz[v] > sz[w]) {
			tmp = v;
			v = w;
			w = tmp;
		}
		id[v] = w;
		if (sz[v] == sz[w]) sz[w]++;
	}
	
	
	public static long kruskal(int n , int ne){
		long cost = 0;
		
		
		Collections.sort(edg, new Comparator<triple>(){
			public int compare(triple o1, triple o2) {
		        return o1.w - o2.w;
		    }

		});
		Init(n);
		int k = 0;
		for (int i = 0; i < ne && k < n; i++) {
			triple a = edg.get(i);
			if (Find(a.u) != Find(a.v)) {
				Union(a.u,a.v);
				cost += a.w; 
				k++;
			}
		}
		return cost;		
	}

	public static void main(String [] args){
		try{
			Scanner sc = new Scanner(new FileInputStream(args[0]));
			int n = sc.nextInt();
			int m = sc.nextInt();
			for (int i = 0; i < m; i++) {
				int u,v,peso;
				u = sc.nextInt();
				v = sc.nextInt();
				peso = sc.nextInt();
				edg.add(new triple(peso,u,v));
		}
			System.out.println(kruskal(n,m));
		}catch(Exception ex){}
	}
}
