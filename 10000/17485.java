import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int n, m;
	static int[][] area;
	static int[][][] dp;
	static final int[] dx = {1, 1, 1};
	static final int[] dy = {-1, 0, 1};
	
    static void input() throws IOException {
    	st = new StringTokenizer(br.readLine());
    	n = Integer.parseInt(st.nextToken());
    	m = Integer.parseInt(st.nextToken());
    	area = new int[n][m];
    	dp = new int[n][m][3];
    	for(int i = 0;i < n; ++i) {
    		st = new StringTokenizer(br.readLine());
        	for(int j = 0;j < m; ++j) {
            	area[i][j] = Integer.parseInt(st.nextToken());
            	for(int k = 0;k < 3; ++k) {
            		dp[i][j][k] = (int)1e9;
            	}
    		}
    	}
    }
    
    static void solution() {
    	for(int i = 0;i < m; ++i) {
    		for(int j = 0;j < 3; ++j) {
        		dp[0][i][j] = area[0][i];
    		}
    	}
    	for(int i = 1;i < n; ++i) {
    		dp[i][0][1] = dp[i - 1][0][0] + area[i][0];
    		dp[i][0][0] = Math.min(dp[i - 1][1][1], dp[i - 1][1][2]) + area[i][0];
    		dp[i][m - 1][1] = dp[i - 1][m - 1][2] + area[i][m - 1];
    		dp[i][m - 1][2] = Math.min(dp[i - 1][m - 2][0], dp[i - 1][m - 2][1]) + area[i][m - 1];
        	for(int j = 1;j < m - 1; ++j) {
        		dp[i][j][0] = Math.min(dp[i - 1][j + 1][1], dp[i - 1][j + 1][2]) + area[i][j];
        		dp[i][j][1] = Math.min(dp[i - 1][j][0], dp[i - 1][j][2]) + area[i][j];
        		dp[i][j][2] = Math.min(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1]) + area[i][j];
    		}
    	}
    	int answer = (int)1e9;
    	for(int i = 0;i < m; ++i) {
    		for(int j = 0;j < 3; ++j) {
    			answer = Math.min(answer, dp[n - 1][i][j]);
    		}
    	}
    	System.out.println(answer);
    }
	
    public static void main(String[] args) throws IOException {
    	input();
    	solution();
    }
}
