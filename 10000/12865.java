import java.awt.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    static int n, k, answer = 0;
    static int[][] dp;
    static Point[] item;

    static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        item = new Point[n + 1];
        for (int i = 1; i <= n; ++i) {
            st = new StringTokenizer(br.readLine());
            int w = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            item[i] = new Point(w, v);
        }
        dp = new int[n + 1][k + 1];
    }

    //
    static void solution() {
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= k; ++j) {
                if(j >= item[i].x){
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - item[i].x] + item[i].y);
                }
                else{
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        System.out.println(dp[n][k]);
    }

    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
