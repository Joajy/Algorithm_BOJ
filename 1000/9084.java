import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static StringTokenizer st;
    static int n, m;
    static int[] coins;
    static int[] dp;

    static void input() throws IOException {
        n = Integer.parseInt(br.readLine());
        coins = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; ++i) {
            coins[i] = Integer.parseInt(st.nextToken());
        }
        m = Integer.parseInt(br.readLine());
        dp = new int[m + 1];
    }

    static void solution() {
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if(j > coins[i]) {
                    dp[j] += dp[j - coins[i]];
                } else if(j == coins[i]) {
                    ++dp[j];
                }
            }
        }
        sb.append(dp[m]).append('\n');
    }

    public static void main(String[] args) throws IOException {
        int t = Integer.parseInt(br.readLine());
        for(int i = 1; i <= t; ++i) {
            input();
            solution();
        }
        System.out.println(sb);
    }
}
