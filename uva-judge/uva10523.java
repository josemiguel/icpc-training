import java.util.*;
import java.math.*;

class Main{
	public static void main(String [] args){
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()){
			int N = sc.nextInt();
			BigInteger A = sc.nextBigInteger();
			BigInteger res = BigInteger.ZERO;
			for(int i = 1; i <= N; i++){
				String str = (new Integer(i)).toString();
				BigInteger tmp = A.pow(i).multiply(new BigInteger(str));
				res = res.add(tmp);
			}
			System.out.println(res);
		}
	}
}
