/**
 *
 * @author James Msuya
 */

import java.io.IOException;
import java.lang.reflect.Array;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Arrays;
import java.util.Scanner;


public  class BigramDyn<T> implements Bigram<T>{

    private int data;
    
    private int size;
   
    private Pair< Pair<T,T>, Integer> [] gramDyn;
    Pair< Pair<T,T>, Integer> hell= new Pair <>();

    public  BigramDyn(){
        this.size = 0;
           
    }
            
    public BigramDyn(int dataType){
        this.size = 0;
        
        this.gramDyn = (Pair< Pair<T,T>, Integer>[]) Array.newInstance( hell.getClass() , size);
        data= dataType;
         }
        
    @Override
    public void readFile(String filename)throws Exception{
        
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
 
           Pair< Pair<T,T>, Integer> temp []= (Pair< Pair<T,T>, Integer> []) Array.newInstance(hell.getClass() , size);
           System.arraycopy(gramDyn, 0, temp, 0, size);

            if (data==1){
                    if(scanner.hasNextInt()){
                        value.setFirst(value.getSecond());
                        value.setSecond((T)(Integer)scanner.nextInt());
                        
                       if(itContains(value)){
                       
                        }
                        else{
                            size+=1; 
                            gramDyn = (Pair< Pair<T,T>, Integer>[]) Array.newInstance(hell.getClass() , size);
                            System.arraycopy(temp, 0, gramDyn, 0, size-1);
                            hell.setFirst((Pair<T, T>) value.clone());
                            hell.setSecond(1);
                            gramDyn[size-1]=(Pair<Pair<T, T>, Integer>) hell.clone();
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
                       if(itContains(value)){
                       
                        }
                        else{
                            size+=1; 
                            gramDyn = (Pair< Pair<T,T>, Integer>[]) Array.newInstance(hell.getClass() , size);
                            System.arraycopy(temp, 0, gramDyn, 0, size-1);
                            hell.setFirst((Pair<T, T>) value.clone());
                            hell.setSecond(1);
                            gramDyn[size-1]=(Pair<Pair<T, T>, Integer>) hell.clone();
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
                        
                        if(itContains(value)){
                       
                        }
                        else{
                            size+=1; 
                            gramDyn = (Pair< Pair<T,T>, Integer>[]) Array.newInstance(hell.getClass() , size);
                            System.arraycopy(temp, 0, gramDyn, 0, size-1);
                            hell.setFirst((Pair<T, T>) value.clone());
                            hell.setSecond(1);
                            gramDyn[size-1]=(Pair<Pair<T, T>, Integer>) hell.clone();
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
     
    public boolean itContains(Pair<T,T> value) throws CloneNotSupportedException{
        Pair< Pair<T,T>, Integer> temp3= new Pair <>();
        for (int i=0;i< size;i++) {
           if (gramDyn[i].getFirst().getFirst().equals(value.getFirst()) && gramDyn[i].getFirst().getSecond().equals( value.getSecond())) {
                temp3.setFirst((Pair<T, T>) value.clone());
                temp3.setSecond(gramDyn[i].getSecond() + 1);
                gramDyn[i]=temp3;
                    return true;
            }
        }
        return false;
    }
            
    @Override
    public int numGrams(){
        int total=0;
        for(int i=0;i < gramDyn.length;i++){
            total += gramDyn[i].getSecond();
        }
        return total;
    }
            
    @Override
    public  int numOfGrams(T first,T second){
        Pair<T,T> temp2= new Pair <>(first,second);
        for(int i=0;i < gramDyn.length;i++){
            if(gramDyn[i].getFirst().getFirst().equals(temp2.getFirst()) && gramDyn[i].getFirst().getSecond().equals( temp2.getSecond())){
                return (gramDyn[i].getSecond());
            }
        }
      return 0;  
    }
    @Override
    public String toString(){
        Pair<Pair<T,T>,Integer> value = new Pair<>();
        String print ="";
        
         for(int i=0;i < gramDyn.length ; i++){
            for(int n=0;n< gramDyn.length-1; n++){
                if(gramDyn[n+1].getSecond() > gramDyn[n].getSecond()){
                    try {
                        value.setFirst((Pair<T, T>) gramDyn[n].getFirst().clone());
                        value.setSecond(gramDyn[n].getSecond());
                        gramDyn[n]=(Pair<Pair<T, T>, Integer>) gramDyn[n+1].clone();
                        gramDyn[n+1]=(Pair<Pair<T, T>, Integer>) value.clone();
                    } catch (CloneNotSupportedException ex) {
                        System.out.println(ex);
                    }

                }
            }
        }

        for(int i=0; i< gramDyn.length;i++){
           print += (gramDyn[i].getFirst().getFirst()+","+gramDyn[i].getFirst().getSecond()+"-"+gramDyn[i].getSecond()+"\n");
        }
        return(print);
    }
  
}
  
         
