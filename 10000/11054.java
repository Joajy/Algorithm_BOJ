import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n;
    static int[] a, dp, rdp;

    static void input() throws IOException {
        n = Integer.parseInt(br.readLine());
        a = new int[n];
        dp = new int[n];
        rdp = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; ++i) {
            a[i] = Integer.parseInt(st.nextToken());
            dp[i] = rdp[i] = 1;
        }
    }

    static void solution(){
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if(a[i] < a[j] && dp[j] < dp[i] + 1) dp[j] = dp[i] + 1;
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i - 1; j >= 0; --j) {
                if(a[i] < a[j] && rdp[j] < rdp[i] + 1) rdp[j] = rdp[i] + 1;
            }
        }
        int answer = 0;
        for (int i = 0; i < n; ++i) {
            answer = Math.max(answer, dp[i] + rdp[i] - 1);
        }
        System.out.println(answer);
    }

    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
