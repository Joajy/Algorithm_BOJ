import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int n, k;
	static final int MOD = (int)1e9;
	static int[][] dp;
	
    static void input() throws IOException {
    	st = new StringTokenizer(br.readLine());
    	n = Integer.parseInt(st.nextToken());
    	k = Integer.parseInt(st.nextToken());
    	dp = new int[n + 1][k + 1];
   	}
    
    static void solution() {
    	for(int i = 1;i <= n; ++i) {
    		dp[i][1] = 1;
    	}
    	for(int i = 1;i <= k; ++i) {
    		dp[1][i] = i;
    	}
    	for(int i = 2;i <= n; ++i) {
    		for(int j = 2; j <= k; ++j) {
    			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
    		}
    	}
    	System.out.println(dp[n][k]);
    }
    
    public static void main(String[] args) throws IOException {
   		input();
   		solution();
    }
}
