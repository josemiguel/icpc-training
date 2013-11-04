import java.util.*;

class ParameterSubstitution{
	public String processParams(String code, String[] params){
		code = 
		try{
			for(int i = 1; i <= params.length; i++){
				code = code.replace("$"+i,params[i-1]);
			}
	
		}catch(Exception ex){
			System.out.println(ex);
		}
		return code;		
	}
}
