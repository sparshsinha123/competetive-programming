import java.util.*;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;
 
public class TaskC{
    public static void main(String[] args) {
        InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
            /* solve here */
            String str = in.next();
            ArrayList<Integer> fro = new ArrayList<Integer>();
            ArrayList<Integer> end = new ArrayList<Integer>();
            for(int i = 0; i < (int) str.length(); i++){
                if(str.charAt(i) == 'l'){
                    end.add(i + 1);
                } else{
                    fro.add(i + 1);
                }
            }
            Collections.reverse(end);
            for(Integer ii : fro) out.println(ii);
            for(Integer jj : end) out.println(jj);
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
 
