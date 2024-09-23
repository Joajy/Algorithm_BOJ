import java.util.*;
import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n, m;
    static long answer;
    static long[][] dp;

    static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        dp = new long[n + 1][2001];
        answer = 0;
    }

    static void solution() {
        Arrays.fill(dp[0], 1);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                for (int k = j * 2; k <= m; ++k) {
                    dp[i][k] += dp[i - 1][j];
                }
            }
        }
        for (int i = 1; i <= m; ++i) {
            answer += dp[n - 1][i];
        }
    }

    public static void main(String[] args) throws IOException {
        int t = Integer.parseInt(br.readLine());
        while(t-- > 0) {
            input();
            solution();
            System.out.println(answer);
        }
    }
}
