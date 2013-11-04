import java.util.Scanner;
import java.util.*;
import java.io.FileInputStream;

public class TheSquareWithin {
  public static void main(String[] args) {
  	try{
		Scanner sc = new Scanner(new FileInputStream(args[0]));

		BigInteger F = sc.nextBigInteger();
		BigInteger a = sc.nextBigInteger();
		BigInteger b = sc.nextBigInteger();
		System.out.println(F.subtract(b).subtract(a).divide(BigInteger.valueOf(3)));
	}catch(Exception ex){}
  }
}
