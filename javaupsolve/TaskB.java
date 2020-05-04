import java.util.*;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;
 
public class TaskB{
    public static void main(String[] args) {
        InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        String str = in.next();
        int[] fro = new int[str.length()];
        int[] end = new int[str.length()];
        int nf = 0;
        int ne = 0;
        for(int i = 0; i < (int) str.length(); i++){
            if(str.charAt(i) == 'l'){
                // System.out.println("adding to end");
                end[ne++] = i + 1;
            } else{
                // System.out.println("adding to front");
                fro[nf++] = i + 1;
            }
        }
         for(int i = 0; i < nf; i++) out.println(fro[i]);
         for(int i = ne - 1; i >= 0; i--) out.println(end[i]);
          out.close();
        }
}


class InputReader {
    BufferedReader reader;
    StringTokenizer tokenizer;
 
    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
        tokenizer = null;
    }
 
    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }
 
}
 
