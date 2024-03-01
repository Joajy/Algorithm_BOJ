import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	static int n, r, c;
	static final int[] dx = {0, 1, 0, -1};
	static final int[] dy = {1, 0, -1, 0};
	static int[][] dp;
	static int[] row, col;
	
	static void input() throws IOException{
		n = Integer.parseInt(br.readLine());
		row = new int[n + 1];
		col = new int[n + 1];
		dp = new int[n + 1][n + 1];
		for(int i = 1;i <= n; ++i) {
			st = new StringTokenizer(br.readLine());
			row[i] = Integer.parseInt(st.nextToken());
			col[i] = Integer.parseInt(st.nextToken());
		}
	}
	
	static void solution() throws IOException{
		for(int i = 1; i <= n; ++i) {
			Arrays.fill(dp[i], (int)1e9);
		}
		for(int i = 1;i <= n; ++i) {
			dp[i][i] = 0;
		}
		for(int len = 1;len <= n; ++len) {
			for(int st = 1; st <= n - len; ++st) {
				int en = st + len;
				for(int mid = st; mid < en; ++mid) {
					dp[st][en] = Math.min(dp[st][en], dp[st][mid] + dp[mid + 1][en] + row[st] * col[mid] * col[en]);
				}
			}
		}
		System.out.println(dp[1][n]);
	}
	
	public static void main(String[] args) throws IOException{
		input();
		solution();
	}
}
