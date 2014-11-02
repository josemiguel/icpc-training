import java.util.*;
import java.math.*;

class Main{
	public static void main(String [] args){
		Scanner sc = new Scanner(System.in);
		
		while(sc.hasNext()){
			int b = sc.nextInt();
			if (b == 0) break;
			BigInteger p = sc.nextBigInteger();
			BigInteger m = sc.nextBigInteger();
			BigInteger res;
			
			if (b != 10){
				p = Main.to10(p,b);
				m = Main.to10(m,b);
				//System.out.println(m+ " "+p+" "+Main.toB(p,b));
				res = Main.toB(p.mod(m),b);
			}else{
				res = p.mod(m);
			}
			System.out.println(res);
		}
	}
	public static BigInteger to10(BigInteger p, int b){
		BigInteger res = BigInteger.ZERO;
		int F = 1;
		while(true){
			res = res.add(p.mod(BigInteger.valueOf(10)).multiply(BigInteger.valueOf(F)));
			p = p.divide(BigInteger.valueOf(10));
			if (p.equals(BigInteger.ZERO)) break;
			F *= b;
		}
		return res;
	}
	public static BigInteger toB(BigInteger p, int b){
		BigInteger res = BigInteger.ZERO;
		int F = 1;
		while(true){
			res = res.add(p.mod(BigInteger.valueOf(b)).multiply(BigInteger.valueOf(F)));
			p = p.divide(BigInteger.valueOf(b));
			if (p.equals(BigInteger.ZERO)) break;
			F *= 10;
		}
		return res;
	}	
}
