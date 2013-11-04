import java.util.ArrayList;
import java.util.Scanner;

class Graph{
    int n_edges;
    ArrayList <Nodo> G;
    Graph(int n){
        n_edges = n;
        G = new ArrayList <Nodo> (n);    
        for(int i=0; i<n; i++)
            G.get(i).Hijos = new ArrayList <Integer> ();
    }
    void Lectura(){
        int p, q;
        Scanner sc = new Scanner(System.in);
        p = sc.nextInt();
        q = sc.nextInt();
        while(p+q>0){
            p--; q--;
            G.get(p).Hijos.add(q);            
            p = sc.nextInt();
            q = sc.nextInt();
        }
        for(int i=0; i<n_edges; i++){
            System.out.println("El nodo : " + (i+1));
            for(int j=0; j<(G.get(i)).Hijos.size(); j++)
                System.out.print( (G.get(i)).Hijos.get(j) + " ");
            System.out.println();
        }
    }
}





class Nodo{
    //int n_nodo;
    ArrayList <Integer> Hijos;
}





class Main {
    public static void main(String [] args){
        int n_edges;
        Graph G;
        System.out.println("Q pasa");
        Scanner sc = new Scanner(System.in);
        n_edges = sc.nextInt();        
        while(n_edges!=0){
            G= new Graph(n_edges);
            G.Lectura();
            n_edges = sc.nextInt();
        }
    }    
}

