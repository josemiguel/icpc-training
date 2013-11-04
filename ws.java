import java.util.*;

import java.util.ArrayList;
import java.util.List;

import org.ksoap2.SoapEnvelope;
import org.ksoap2.serialization.PropertyInfo;
import org.ksoap2.serialization.SoapObject;
import org.ksoap2.serialization.SoapPrimitive;
import org.ksoap2.serialization.SoapSerializationEnvelope;
import org.ksoap2.transport.HttpTransportSE;

class FacturaBL{
	
	private static final String NAMESPACE = "http://3e.pl/ADInterface";
	private static String URL="http://200.16.7.114/ADInterface/services/ADService?wsdl"; 
	private static final String METHOD_NAME = "login";
	private static final String SOAP_ACTION = "http://3e.pl/ADInterface/login";	
	
	public List<Factura> findAll(){
		List<Factura> lista = new ArrayList<Factura>();
			
			/*recupera la lista*/
		SoapObject request = new SoapObject(NAMESPACE, METHOD_NAME); 

	        
	        PropertyInfo propInfo1=new PropertyInfo();
	        propInfo1.name="user";
	        propInfo1.type=PropertyInfo.STRING_CLASS;
	        
	        PropertyInfo propInfo2=new PropertyInfo();
	        propInfo2.name="pass";
	        propInfo2.type=PropertyInfo.STRING_CLASS;
	        
	        PropertyInfo propInfo3=new PropertyInfo();
	        propInfo3.name="lang";
	        propInfo3.type=PropertyInfo.STRING_CLASS;
	        
	        PropertyInfo propInfo4=new PropertyInfo();
	        propInfo4.name="ClientID";
	        propInfo4.type=PropertyInfo.STRING_CLASS;
	        
	        PropertyInfo propInfo5=new PropertyInfo();
	        propInfo5.name="RoleID";
	        propInfo5.type=PropertyInfo.STRING_CLASS;
	        
	        PropertyInfo propInfo6=new PropertyInfo();
	        propInfo6.name="WareHouseID";
	        propInfo6.type=PropertyInfo.STRING_CLASS;
	        
	        	        
	        PropertyInfo propInfo7=new PropertyInfo();
	        propInfo7.name="OrgID";
	        propInfo7.type=PropertyInfo.STRING_CLASS;
	        
	        PropertyInfo propInfo8=new PropertyInfo();
	        propInfo8.name="stage";
	        propInfo8.type=PropertyInfo.STRING_CLASS;
	        
	        request.addProperty(propInfo1, "John Smith");
	        request.addProperty(propInfo2, "John Smith");
	        request.addProperty(propInfo3, "John Smith");
	        request.addProperty(propInfo4, "John Smith");
	        request.addProperty(propInfo5, "John Smith");
	        request.addProperty(propInfo6, "John Smith");
	        request.addProperty(propInfo7, "John Smith");
	        request.addProperty(propInfo8, "John Smith");
	        
	        
	        SoapSerializationEnvelope envelope = new SoapSerializationEnvelope(SoapEnvelope.VER11); 

	        envelope.setOutputSoapObject(request);
	       HttpTransportSE androidHttpTransport = new HttpTransportSE(URL);

	        try {
	         androidHttpTransport.call(SOAP_ACTION, envelope);
	        
	          SoapPrimitive  resultsRequestSOAP = (SoapPrimitive) envelope.getResponse();
	          

	         System.out.println(((SoapObject) envelope.getResponse()).getAttributeCount());
	         
	         
	         
	       
	        } catch (Exception e) {
	      	  e.printStackTrace();
	         
	        }
			return lista;
			
	}
	
	public static void main(String [] args){
			(new FacturaBL()).findAll();
	}
}

