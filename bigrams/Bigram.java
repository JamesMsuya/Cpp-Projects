
import java.io.IOException;

/**
 *
 * @author James Msuya
 * @param <T>
 */
        
public interface Bigram<T>{
   
    void readFile(String filename)throws Exception;

    int numGrams();

    int numOfGrams(T fisrt,T second);

};
