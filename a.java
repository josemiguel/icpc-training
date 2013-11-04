import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 *
 * @author jmj
 */
class Parse {
    public static void parseFileRNV(String filetoParse,String pathArchivo, String pathImagenes){

        FileWriter fw = null;
        try {

            fw = new FileWriter(pathArchivo);
            BufferedWriter bw = new BufferedWriter(fw);
            PrintWriter out = new PrintWriter(bw);
            
            Scanner sc = new Scanner(new FileInputStream(filetoParse));
            for(int idx = 1; sc.hasNext() ; idx++){
                String  linea = sc.nextLine();
                //"EDD0001058","N1","N2","A1","A2","F04FE0..."
                String dni = "", nombre = "",appaterno = "",apmaterno = "";
                String [] toks = linea.split(",");
                dni = toks[0];
                nombre = toks[1] + toks[2];
                appaterno = toks[3];
                apmaterno = toks[4];
                String firma = toks[5];
                
                while(dni.length() != 15) dni = dni + "0";
                
                try{
                    FileOutputStream fos1 = new FileOutputStream(pathImagenes+"firma"+idx+".jpeg");
                    fos1.write(parse(firma));
                    out.println(dni+","+nombre+","+appaterno+","+apmaterno+",Ancash,Huaraz,Yungay,firma"+idx+".jpeg,huella"+idx+".jpeg");
                }catch(Exception ex){}
                
            }

        }catch(Exception ex){ex.printStackTrace();}
    }

    public static byte[] parse(String s) {
        byte[] b = new byte[s.length() / 2];
        for (int i = 0; i < b.length; i++){
          int index = i * 2;
          int v = Integer.parseInt(s.substring(index, index + 2), 16);
          b[i] = (byte)v;
        }
        return b;
    }

    public static void main(String [] args){
        parseFileRNV(args[0],args[1],args[2]);
    }

}

