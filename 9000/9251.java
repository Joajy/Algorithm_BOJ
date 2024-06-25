import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static String a, b;
	static int n, m;
	static int[][] dp;
	
    static void input() throws IOException {
    	a = br.readLine();
    	b = br.readLine();
    	n = a.length();
    	m = b.length();
    	dp = new int[n + 1][m + 1];
    }

    static void solution() {
    	for(int i = 1; i <= n; ++i) {
    		for(int j = 1;j <= m; ++j) {
    			if(a.charAt(i - 1) == b.charAt(j - 1)) {
    				dp[i][j] = dp[i - 1][j - 1] + 1;
    			} else {
    				dp[i][j] = Math.max(dp[i][j - 1], dp[i - 1][j]);
    			}
    		}
    	}
    	System.out.println(dp[n][m]);
    }    
    
    public static void main(String[] args) throws IOException {
   		input();
   		solution();
    }
}
