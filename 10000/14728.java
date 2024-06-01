import java.util.*;
import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n, t;
    static int[][] dp, a;

    static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        t = Integer.parseInt(st.nextToken());
        dp = new int[n + 1][t + 1];
        a = new int[n + 1][2];
        for (int i = 1; i <= n; ++i) {
            st = new StringTokenizer(br.readLine());
            a[i][0] = Integer.parseInt(st.nextToken());
            a[i][1] = Integer.parseInt(st.nextToken());
        }
    }

    static void solution() {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= t; ++j) {
                if(a[i][0] <= j) {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - a[i][0]] + a[i][1]);
                } else{
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        System.out.println(dp[n][t]);
    }

    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
