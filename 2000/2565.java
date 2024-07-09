import java.io.*;
import java.util.*;

public class Main {
	
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int n;
	static int[][] area;
	static int[] dp;
	
    static void input() throws IOException {
    	n = Integer.parseInt(br.readLine());
    	area = new int[n][2];
    	dp = new int[n];
    	for(int i = 0;i < n; ++i) {
    		st = new StringTokenizer(br.readLine());
        	for(int j = 0;j < 2; ++j) {
            	area[i][j] = Integer.parseInt(st.nextToken());
    		}
    	}
    }
    
    static void solution() {
        Arrays.sort(area, new Comparator<int[]>() {
			@Override
			public int compare(int[] o1, int[] o2) {
				return Integer.compare(o1[0], o2[0]);
			}
		});
    	for(int i = 0;i < n; ++i) {
    		dp[i] = 1;
    		for(int j = 0;j < i; ++j) {
    			if(area[i][1] > area[j][1]) {
    				dp[i] = Math.max(dp[i], dp[j] + 1);
    			}
    		}
    	}
    	int answer = 0;
    	for(int i = 0;i < n; ++i) {
    		answer = Math.max(answer, dp[i]);
    	}
    	System.out.println(n - answer);
    }
	
    public static void main(String[] args) throws IOException {
    	input();
    	solution();
    }
}
