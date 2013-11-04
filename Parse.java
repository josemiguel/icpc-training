import java.awt.image.BufferedImage;
import java.io.BufferedWriter;
import java.io.*;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;
import javax.imageio.ImageIO;

/**
 *
 * @author jmj
 */
class Parse {
    public static void parseFileRNV(String filetoParse, String pathImagenes){


        try {

			File f = new File(filetoParse);
			BufferedReader sc = new BufferedReader( new FileReader( f ) );
			String cabecera="Nombre,ApellidoPaterno,ApellidoMaterno,DNI,Ubicacion";
	                System.out.println(cabecera);
                        int contador=0;
            for(int idx = 1;  ; idx++){



                String  linea = sc.readLine();
                if (linea == null) break;
                //"EDD0001058","N1","N2","A1","A2","F04FE0..."
                String dni = "", nombre = "",appaterno = "",apmaterno = "";
                String [] toks = linea.split(",");
                dni = toks[0];
                nombre = toks[1] + toks[2];
                appaterno = toks[3];
                apmaterno = toks[4];
                String firma = toks[5];

                contador++;
                if (contador==22) contador=1;

                String path=null;

                while(dni.length() != 15) dni = dni + "0";//yo necesito 15 caracteres. pq valido eso. //cambiar
                String tmp = nombre+","+appaterno+","+apmaterno+","+dni+",15";
		//todo lo estoy guardando en la ubicacion 15 asi q hay q verificar q lo guardemos..

                path = "./huellas/huella"+contador+".jpg";
                //cargar la imagen
                File imagenFile = new File(path);
                BufferedImage nuevaImagen=null;


                try {
                    nuevaImagen=ImageIO.read(imagenFile);
                }
                catch(Exception e){
                }

                //guardar la  huella

                String nuevoPath="./HuellasGeneradas/h"+dni+".jpg";
                File outputFilePrueba = new File(nuevoPath);


                try{

                ImageIO.write(nuevaImagen,"jpg",outputFilePrueba);
                }catch (Exception e){
                   
                }


                try{
                    FileOutputStream fos1 = new FileOutputStream(pathImagenes+"f"+dni+".jpg");
                    fos1.write(parse(firma));
                    System.out.println(tmp);
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
        parseFileRNV(args[0],args[1]);
    }

}
