import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    static int n, k;
    static int[] ball;
    static boolean[][] dp;

    static void input() throws IOException{
        n = Integer.parseInt(br.readLine());
        ball = new int[n + 1];
        dp = new boolean[n + 1][40001];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; ++i) {
            ball[i] = Integer.parseInt(st.nextToken());
        }
    }

    static void dfs(int cnt, int sum) {
        if(cnt == n + 1 || dp[cnt][sum]) return;
        dp[cnt][sum] = true;
        dfs(cnt + 1, sum);
        dfs(cnt + 1, sum + ball[cnt]);
        dfs(cnt + 1, Math.abs(sum - ball[cnt]));

    }

    static void solution() throws IOException {
        dfs(0, 0);
        k = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= k; ++i) {
            int w = Integer.parseInt(st.nextToken());
            if(dp[n][w]) sb.append("Y ");
            else sb.append("N ");
        }
        System.out.println(sb);
    }

    public static void main(String[] args) throws IOException{
        input();
        solution();
    }
}
