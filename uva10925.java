import java.util.*;
import java.math.*;

class Main{
	public static void main(String [] args){
		Scanner sc = new Scanner(System.in);
		
		for(int r = 1;sc.hasNext();r++){
			int N = sc.nextInt(),F = sc.nextInt();
			if (N == 0 && F == 0) break;
			BigInteger s = BigInteger.ZERO;
			for(int i = 0; i < N; i++){
				s = s.add(sc.nextBigInteger());
			}

			BigInteger res = s.divide(BigInteger.valueOf(F));
			
			System.out.println("Bill #"+r+" costs "+s.toString()+": each friend should pay "+res.toString()+"\n");
		}
	}
}
