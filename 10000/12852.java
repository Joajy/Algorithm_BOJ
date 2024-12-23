import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    static int n;
    static int[] dp, trace;

    static void input() throws IOException {
        n = Integer.parseInt(br.readLine());
        dp = new int[n + 1];
        trace = new int[n + 1];
        Arrays.fill(dp, (int) 1e9);
        dp[0] = dp[1] = 0;
    }

    static void solution() {
        //step 1
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + 1;
            trace[i] = i - 1;
            if(i % 2 == 0) {
                if(dp[i] > dp[i >> 1] + 1) {
                    dp[i] = dp[i >> 1] + 1;
                    trace[i] = i >> 1;
                }
            }
            if(i % 3 == 0) {
                if(dp[i] > dp[i / 3] + 1) {
                    dp[i] = dp[i / 3] + 1;
                    trace[i] = i / 3;
                }
            }
        }
        System.out.println(dp[n]);
        //step 2
        while(n > 0) {
            sb.append(n).append(' ');
            n = trace[n];
        }
        System.out.println(sb);
    }

    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
