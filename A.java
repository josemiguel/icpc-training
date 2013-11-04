import java.util.*;

class Main  {
	public static void main(String [] args){
		Scanner sc = new Scanner(System.in);
		int n = Integer.valueOf(sc.nextLine());
		
		do{
			String [] rule = new String[n+1];
			String [] rep = new String[n+1];			
			for(int i = 0; i < n; i++) {
				rule[i] = sc.nextLine();
				rep[i] = sc.nextLine();
			}
			String s = sc.nextLine();
			for(int i = 0; i < n; i++){
				while(true){
					String ant = s;
					s = s.replaceFirst(rule[i],rep[i]);
					if (ant.equals(s)) break;
				}
			}
			System.out.println(s);
			n = Integer.valueOf(sc.nextLine());
		}while(n != 0);
	
		
		
	}

}


