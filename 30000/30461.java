import java.util.*;
import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static StringTokenizer st;
    static int m, n, q, answer;
    static int[][] area, prefix;

    static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        q = Integer.parseInt(st.nextToken());
        area = new int[n + 1][m + 1];
        prefix = new int[n + 1][m + 1];
        for (int i = 1; i <= n; ++i) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= m; ++j) {
                area[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        answer = 0;
    }

    static void setPrefix() {
        for (int j = 1; j <= m; ++j) {
            for (int i = 1; i <= n; ++i) {
                prefix[i][j] += prefix[i - 1][j] + area[i][j];
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                prefix[i][j] += prefix[i - 1][j - 1];
            }
        }
    }

    static void solution() throws IOException {
        setPrefix();
        for (int i = 0; i < q; ++i) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            sb.append(prefix[a][b]).append('\n');
        }
        System.out.println(sb);
    }

    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
