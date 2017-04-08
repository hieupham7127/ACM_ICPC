import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) throws Exception {
    
        BufferedReader stdin = 
            new BufferedReader(
                new InputStreamReader(System.in));

        String line = stdin.readLine();
        StringTokenizer st = new StringTokenizer(line);
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        
        BigInteger[][] arr = new BigInteger[k + 1][n + 1];
        for( int i = 0; i <= k; i++ )
            for( int j = 0; j <= n; j++ ) 
                arr[i][j] = new BigInteger("0");
                
        arr[0][0] = new BigInteger("1");
        
        for( int i = 1; i <= k; i++ )
            for( int j = 0; j <= n; j++ ) {
                arr[i][j] = arr[i][j].add(arr[i - 1][j]);
                if (j >= i)
                    arr[i][j] = arr[i][j].add(arr[i][j - i]);
            }
            
        System.out.print(arr[k][n].toString());
    }
}
