import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n;
    static int[] dp;
    static int[][] councils;

    static void input() throws IOException {
        n = Integer.parseInt(br.readLine());
        councils = new int[n + 2][2];
        dp = new int[n + 2];
        for (int i = 1; i <= n; ++i) {
            st = new StringTokenizer(br.readLine());
            councils[i][0] = Integer.parseInt(st.nextToken());
            councils[i][1] = Integer.parseInt(st.nextToken());
        }
    }

    static void solution() {
        int answer = 0;
        for (int i = 1; i <= n + 1; ++i) {
            answer = Math.max(answer, dp[i]);
            if(councils[i][0] + i > n + 1) continue;
            dp[i + councils[i][0]] = Math.max(dp[i + councils[i][0]], answer + councils[i][1]);
        }
        System.out.println(answer);
    }

    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
