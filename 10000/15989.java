import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
	static int n;
	static int[][] dp;    
    
    static void solution() {
    	dp = new int[10001][4];
    	for(int i = 1;i <= 3; ++i) {
    		for(int j = 1;j <= i; ++j) {
    			dp[i][j] = 1;
    		}
    	}
    	for(int i = 4; i <= 10000; ++i) {
    		dp[i][1] = dp[i - 1][1];
    		dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
    		dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
    	}
    }
    
    public static void main(String[] args) throws IOException {
		solution();
    	int t = Integer.parseInt(br.readLine());
    	for(int i = 1;i <= t; ++i) {
    		int num = Integer.parseInt(br.readLine());
    		sb.append(dp[num][1] + dp[num][2] + dp[num][3]).append('\n');
    	}
    	System.out.println(sb);
    }
}
