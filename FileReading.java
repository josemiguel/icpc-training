import java.util.Scanner;
import java.util.*;
import java.io.FileInputStream;

public class FileReading{
	public static void main(String [] args){
	try{
		Scanner sc = new Scanner(new FileInputStream(args[1]));
		String pal = args[0];
		String aux;
		int r = 1;
		boolean found = false;
		while(sc.hasNext()){
				
			if (sc.next().equals(pal)){
				found = true;
				break;
			}
			r++;
		}
		System.out.println(found?r:0);
	}catch(Exception ex){}
	}
}

