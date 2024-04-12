import java.util.*;
import java.io.*;

public class Main{
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;
	static int n, k;
	static int wt, wp, bt, bp;
	static int[][] dp;
	
	static void input() throws IOException{
		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		dp = new int[n + 1][k + 1];
		st = new StringTokenizer(br.readLine());
		wt = Integer.parseInt(st.nextToken());
		wp = Integer.parseInt(st.nextToken());
		bt = Integer.parseInt(st.nextToken());
		bp = Integer.parseInt(st.nextToken());
		dp[0][wt] = wp;
		dp[0][bt] = Math.max(dp[0][bt], bp);
	}
	
	static void solution() throws IOException{
		for(int i = 1;i < n; ++i) {
			st = new StringTokenizer(br.readLine());
			wt = Integer.parseInt(st.nextToken());
			wp = Integer.parseInt(st.nextToken());
			bt = Integer.parseInt(st.nextToken());
			bp = Integer.parseInt(st.nextToken());
			for(int j = 0;j <= k; ++j) {
				if(dp[i - 1][j] == 0) continue;
				if(wt + j <= k) {
					dp[i][wt + j] = Math.max(dp[i][wt + j], dp[i - 1][j] + wp);
				}
				if(bt + j <= k) {
					dp[i][bt + j] = Math.max(dp[i][bt + j], dp[i - 1][j] + bp);
				}
			}
		}
		int answer = 0;
		for(int i = 0;i <= k; ++i) {
			answer = Math.max(answer, dp[n - 1][i]);
		}
		System.out.println(answer);
	}
	
	public static void main(String[] args) throws IOException {
		input();
		solution();
	}
}
