import java.util.*;
import java.math.*;

class Main{
	public static void main(String [] args){
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()){
			int n = sc.nextInt();
			for(int i = 0; i < n; i++){
				BigInteger p = sc.nextBigInteger();	sc.next();
				BigInteger q = sc.nextBigInteger();
				BigInteger GCD = p.gcd(q);
				System.out.println(p.divide(GCD) + " / " + q.divide(GCD));
			}
		}
	}
}
