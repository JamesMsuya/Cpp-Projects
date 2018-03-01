/**
 *
 * @author Gme Jemsy
 * @param <T>
 */
import java.io.IOException;
import java.util.Scanner;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.HashMap;
import java.util.List;
import java.util.Vector;


public class BigramMap<T> implements Bigram<T>{
    
    private HashMap< Pair<T,T> , Integer> gramMap;
    
    private int data;

    public  BigramMap(){
        this.gramMap = new HashMap< >();
    
    }
            
    public BigramMap(int dataType){
        this.gramMap = new HashMap< >();
        data= dataType;
         }
        
    @Override
    public void readFile(String filename)throws Exception {
        
        Pair<T,T> value = new Pair<>();     
        Path input = Paths.get(filename);
    
        
        try{
            Scanner scanner = new Scanner(input);
            
             if(scanner.hasNext()){
               
                if (data==1 && scanner.hasNextInt()){
                    value.setSecond((T)(Integer)scanner.nextInt());
                }
                
                 if (data==2 && scanner.hasNext()){
                    value.setSecond((T)(String)scanner.next());
                }
                 
                if (data==3 && scanner.hasNextDouble()){
                     value.setSecond((T)(Double)scanner.nextDouble());
                }

               
            }
           
        while(scanner.hasNext()){
            
                if (data==1){
                    if(scanner.hasNextInt()){
                        value.setFirst(value.getSecond());
                        value.setSecond((T)(Integer)scanner.nextInt());
                       
                        if(isEqual(value)){  
                            
                        }
                        else{
                            gramMap.put((Pair<T, T>) value.clone(), 1);
                        }        
                    }     
                    else{ 
                        Exception m = new Exception("Error!! \nFile contains bad Data");
                        throw(m);
                    }                        
                }
                
                 if (data==2){
                    if(scanner.hasNext()){                      
                        value.setFirst(value.getSecond());
                        value.setSecond((T)(String)scanner.next());

                        if(isEqual(value)){  

                        }
                        else{
                            gramMap.put((Pair<T, T>) value.clone(), 1);
                        }        
                    }   
                    else{ 
                        Exception m = new Exception("Error!! \nFile contains bad Data");
                        throw(m);
                    }
                }
                 
                if (data==3){
                    if(scanner.hasNextDouble()){
                        value.setFirst(value.getSecond());
                        value.setSecond((T)(Double)scanner.nextDouble());
                            
                        if(isEqual(value)){  

                        }
                        else{
                            gramMap.put((Pair<T, T>) value.clone(), 1);
                        }        
                    }   
                    else{ 
                        Exception m = new Exception("Error!! \nFile contains bad Data");
                        throw(m);
                    }                  
                }

               
              
        }
        }  
        catch (IOException e) {
            Exception sasa= new Exception("Error!!\nFile not found");
            throw(sasa);
        }
        
    }
            
    @Override
    public int numGrams(){
    int total=0;
        for (Integer value : gramMap.values()) {
                total+=value;
        }
      return total;  
    }
            
    @Override
    public  int numOfGrams(T first,T second){
        Pair <T,T> value = new Pair<>(first,second);
        if(data==1){
            for ( Pair<T,T>key : gramMap.keySet()){
                if(key.getFirst()==value.getFirst()&& key.getSecond()==value.getSecond()){
                    return( gramMap.get(key)) ;
                }
            }
        }
        
        if(data==2){        
            for ( Pair<T,T>key : gramMap.keySet()){
                if(key.getFirst().equals(value.getFirst()) && key.getSecond().equals(value.getSecond())){
                    return( gramMap.get(key)) ;
                }
            }
        }
        
        if(data==3){
            for (Pair<T,T>key : gramMap.keySet()){
                if((java.lang.Double.compare((Double)key.getFirst(),(Double)value.getFirst()) == 0)&&
                        (java.lang.Double.compare((Double)key.getSecond(),(Double)value.getSecond())==0)){
                    
                        return(gramMap.get(key));
                }
            }
        }
        return 0;
    }
    
    @Override
    public String toString(){
       List <Pair <Pair<T,T>,Integer> > sorted= new Vector< >() ;
       Pair <Pair<T,T>,Integer> temp = new Pair<>();
       String print = "";
       
       for ( Pair<T,T>key : gramMap.keySet()){        
         temp.setFirst(key);
         temp.setSecond(gramMap.get(key));
           try {
               sorted.add((Pair<Pair<T, T>, Integer>) temp.clone());
           } catch (CloneNotSupportedException ex) {
               System.out.println(ex);
           }
        }
       
       for(int i=0;i <sorted.size();i++){
            for(int n=0;n < sorted.size()-1;n++){
                if(sorted.get(n+1).getSecond() > sorted.get(n).getSecond()){
                    Pair <Pair<T,T>,Integer> temp1 = new Pair<> (sorted.get(n));
                    sorted.set(n,sorted.get(n+1));
                    sorted.set(n+1, temp1); 
                }
            }
        }
        for(int i=0;i < sorted.size();i++){
            print +=("<"+sorted.get(i).getFirst().getFirst()+","+sorted.get(i).getFirst().getSecond()+"> - "+sorted.get(i).getSecond()+"\n");
        }

     return  (print);
   }
  
    public boolean isEqual(Pair<T,T>value){
        if(data==1){
            for (Pair<T,T>key : gramMap.keySet()){
                if(key.getFirst()==value.getFirst()&& key.getSecond()==value.getSecond()){
                    gramMap.put(key,gramMap.get(key)+1);

                    return true;
                }
            }
       
        }
        if(data==2){
           for (Pair<T,T>key : gramMap.keySet()){
                if(key.getFirst().equals(value.getFirst()) && key.getSecond().equals(value.getSecond())){
                    gramMap.put(key,gramMap.get(key)+1);
                    return true;
                } 
            }
        }
        if(data==3){
            for (Pair<T,T>key : gramMap.keySet()){
                if((java.lang.Double.compare((Double)key.getFirst(),(Double)value.getFirst()) == 0)&&
                        (java.lang.Double.compare((Double)key.getSecond(),(Double)value.getSecond())==0)){
                    gramMap.put(key,gramMap.get(key)+1);

                    return true;
                }
            }
        }
        return false;
    }
}