import java.util.*;
import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n, m;
    static int[][] area, dp;

    static void input()  throws IOException{
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        area = new int[n + 1][m + 1];
        dp = new int[n + 1][m + 1];
        for (int i = 1; i <= n; i++) {
            String s = br.readLine();
            for (int j = 1; j <= m; j++) {
                area[i][j] = s.charAt(j - 1) - '0';
                if(area[i][j] == 1) dp[i][j] = 1;
            }
        }
    }

    static void solution() {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(area[i][j] == 0) continue;
                dp[i][j] = Math.min(dp[i - 1][j], Math.min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
            }
        }
        int answer = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(answer < dp[i][j]) answer = dp[i][j];
            }
        }
        System.out.println(answer * answer);
    }

    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
