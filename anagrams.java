import java.math.BigInteger;
import java.util.Scanner;
import java.util.*;
import java.io.FileInputStream;


public class anagrams{

	public static String dameHash(String p)
	{
		char [] c = p.toCharArray();
		Arrays.sort(c);
		return new String(c);
	}

	public static void main(String [] args){
		try{
		Scanner fdict = new Scanner(new FileInputStream(args[0]));
		Scanner fpals = new Scanner(new FileInputStream(args[1]));		
		
		HashMap<String, ArrayList<String> > mapa = new HashMap<String,ArrayList<String> >();

		while(fdict.hasNext())
		{
		      String aux = fdict.next();

		      String hashh = dameHash(aux);
		      
		      ArrayList<String> arr = mapa.get(hashh);
		      if (arr != null){
		      	arr.add(aux);
		      }else{
		      	arr = new ArrayList<String>();
		      	arr.add(aux);
		      	mapa.put(hashh, arr);
		      }
		}
		String t;
		ArrayList<String> resps = new ArrayList<String> ();
		while(fpals.hasNext())
		{
		      String aux = fpals.next();
		      t = dameHash(aux);
		      resps = mapa.get(t);
		      if(resps==null) {System.out.println(0);continue;}
				System.out.println(resps.size());
		      for(String it : resps){
		      	System.out.println(it);
		      }
		}						
		}catch(Exception ex){}
	}
}

