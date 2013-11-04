package com.android.example;

import java.io.IOException;

import org.ksoap2.SoapEnvelope;
import org.ksoap2.serialization.SoapObject;
import org.ksoap2.serialization.SoapSerializationEnvelope;
import org.ksoap2.transport.AndroidHttpTransport;
import org.xmlpull.v1.XmlPullParserException;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;

public class WebserviceConsumer extends Activity {
   /** Called when the activity is first created. */

   private static final String NAMESPACE = "http://www.example.org/AndroidSampleWebservice/";
   private static final String METHOD_NAME = "complexInData";
   private static final String SOAP_ACTION = "http://www.example.org/AndroidSampleWebservice/getComplexData";
   private static final String URL = "http://172.25.108.49:8080/AndroidWebservice/AndroidSampleWebservice?wsdl";

   @Override
   public void onCreate(Bundle savedInstanceState) {
      Log.d("WS", "Inside onCreate");

      super.onCreate(savedInstanceState);
      setContentView(R.layout.main);

      Log
            .d("WS",
                  "--------------------- Webservice Part Begins ---------------------");
      Log.d("WS", "1. SoapObject Construction");

      SoapObject loSoapObject = new SoapObject(NAMESPACE, METHOD_NAME);

      // If this is not a direct type i.e. a primitive or string then you
      // have to construct another SoapObject and put in the place of the
      // obejct
      loSoapObject.addProperty("firstName", "Dwarka");
      loSoapObject.addProperty("lastName", "Damodaran");
      Log.d("WS", "Construction of SOAP Object End !!!");

      SoapSerializationEnvelope envelope = new SoapSerializationEnvelope(
            SoapEnvelope.VER11); // put all required data into a soap
                              // envelope
      Log.d("WS", "2. Envelop Created");
      envelope.setOutputSoapObject(loSoapObject); // prepare request
      Log.d("WS", "3. Request Into Envelop");
      AndroidHttpTransport httpTransport = new AndroidHttpTransport(URL);
      Log.d("WS", "4. Transport Created");
      httpTransport.debug = true; // this is optional, use it if you don't
                           // want to use a packet sniffer to check
                           // what the sent message was
                           // (httpTransport.requestDump)
      Log.d("WS", "5. Transport Level to True");
      try {
         httpTransport.call(SOAP_ACTION, envelope);
         if (envelope != null) 
         {
            SoapObject loresponse = (SoapObject) envelope.bodyIn;
            SoapObject logObject = (SoapObject)loresponse.getProperty("generalData");
            SoapObject loaObject = (SoapObject)loresponse.getProperty("addressData");
            SoapObject loacObject = (SoapObject)loresponse.getProperty("accountData");
            Log.d("WS", "logObject: "+logObject);
            Log.d("WS", "loaObject: "+loaObject);
            Log.d("WS", "loacObject: "+loacObject);
            
            Log.d("WS", "firstName: "+logObject.getProperty("firstName"));
            Log.d("WS", "lastName: "+logObject.getProperty("lastName"));
            Log.d("WS", "age: "+logObject.getProperty("age"));
            Log.d("WS", "sex: "+logObject.getProperty("sex"));
            
         } 
         else 
         {
            Log.d("WS", "Response Envelop Error");
         }

      } catch (IOException e) {
         e.printStackTrace();
      } catch (XmlPullParserException e) {
         e.printStackTrace();
      }
   }
}
