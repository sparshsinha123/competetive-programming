import java.util.*;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;
 
public class taskd{
    
    public static void main(String[] args) {
        InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
            /* solve here */
            int n , q;
            n = nextInt();
            int[] ar = new int[n + 1];
            int[] pref = new int[n + 1];
            for(int i = 0; i < n; i++){
                ar[i] = nextInt();
                pref[i] = ar[i];
                if(i != 0) pref[i] += pref[i - 1];
            }
            q = in.next();
            for(int i = 0; i < q; i++){
                int l , r;
                l = nextInt();
                r = nextInt();
                int ans = pref[r];
                if(l != 0) ans -= pref[l - 1];
                ans %= 10;
                out.println(ans); 
            }
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
 
