import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;
	static int n, m, k;
	static int a, b, c, d;
	static boolean[][][] brokenBridge;
	static long[][] dp;
	
    static void input() throws IOException {
		st = new StringTokenizer(br.readLine());
    	n = Integer.parseInt(st.nextToken());
    	m = Integer.parseInt(st.nextToken());
    	dp = new long[n + 1][m + 1];
    	brokenBridge = new boolean[n + 1][m + 1][2];
    	k = Integer.parseInt(br.readLine());
		for(int i = 0;i < k; ++i) {
			st = new StringTokenizer(br.readLine());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			c = Integer.parseInt(st.nextToken());
			d = Integer.parseInt(st.nextToken());
			setting();
		}
   	}
    
    static void setting() {
    	if(a == c) {
    		brokenBridge[a][Math.min(b,  d)][0] = true;
    	} else {
    		brokenBridge[Math.min(a,  c)][b][1] = true;
    	}
    }
    
    static void solution() {
    	for(int i = 1;i <= m; ++i) {
    		if(brokenBridge[0][i - 1][0]) break;
    		dp[0][i] = 1L;
    	}
    	for(int i = 1;i <= n; ++i) {
    		if(brokenBridge[i - 1][0][1]) break;
    		dp[i][0] = 1L;
    	}
    	for(int i = 1;i <= n; ++i) {
    		for(int j = 1;j <= m; ++j) {
    			if(!brokenBridge[i - 1][j][1]) dp[i][j] += dp[i - 1][j];
    			if(!brokenBridge[i][j - 1][0]) dp[i][j] += dp[i][j - 1];
    		}
    	}
    	System.out.println(dp[n][m]);
    }
    
    public static void main(String[] args) throws IOException {
   		input();
   		solution();
    }
}
