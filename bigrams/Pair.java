/**
 *
 * @author Gme Jemsy
 * @param <T>
 * @param <S>
 */
public class Pair<T,S> implements Cloneable{
    private T first; 
    private S second; 

     public Pair() {
       
    }
     
    public Pair(T first, S second) {
        this.first = first;
        this.second = second;
    }
    
    public Pair(Pair<T,S> obj) {
        this.first = obj.first;
        this.second = obj.second;
    }

    public void setFirst(T first) {
        this.first = first;
    }

    public void setSecond(S second) {
        this.second = second;
    }

    public T getFirst() {
        return first;
    }

    public S getSecond() {
        return second;
    }
    
    @Override
    public Object clone()throws CloneNotSupportedException{  
        return super.clone();  
    }  
}
