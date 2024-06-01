import java.util.*;
import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static StringTokenizer st;
    static int n, m;
    static int[][] dp, a;

    static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        dp = new int[n + 1][n + 1];
        a = new int[n + 1][n + 1];
        for (int i = 1; i <= n; ++i) {
            Arrays.fill(dp[i], (int)1e9);
        }
        for (int i = 1; i < n; ++i) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            int dist = Integer.parseInt(st.nextToken());
            dp[start][end] = Math.min(dp[start][end], dist);
            dp[end][start] = Math.min(dp[end][start], dist);
        }
    }

    static void solution() throws IOException {
        for (int k = 1; k <= n; ++k) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    dp[i][j] = Math.min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            sb.append(dp[start][end]).append('\n');
        }
    }

    public static void main(String[] args) throws IOException {
        input();
        solution();
        System.out.println(sb);
    }
}
