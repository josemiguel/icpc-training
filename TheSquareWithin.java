import java.util.Scanner;
import java.util.*;
import java.io.FileInputStream;

public class TheSquareWithin {
  public static void main(String[] args) {
  	try{
		Scanner sc = new Scanner(new FileInputStream(args[0]));
		int n;
		while(sc.hasNext()){
			n = Integer.valueOf(sc.next());
			System.out.println((n*(n+1)*(2*n+1))/6);
		}
	
			
	}catch(Exception ex){}
  }
}
