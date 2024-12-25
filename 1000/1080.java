import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n, m, changed;
    static int[][] start, result;

    static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        start = new int[n][m];
        result = new int[n][m];
        for (int i = 0; i < n; ++i) {
            String s = br.readLine();
            for (int j = 0; j < m; ++j) {
                start[i][j] = s.charAt(j) - '0';
            }
        }
        for (int i = 0; i < n; ++i) {
            String s = br.readLine();
            for (int j = 0; j < m; ++j) {
                result[i][j] = s.charAt(j) - '0';
            }
        }
        changed = 0;
    }

    static boolean isSame() {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if(start[i][j] != result[i][j]) return false;
            }
        }
        return true;
    }

    static void change(int x, int y) {
        for (int i = x; i < x + 3; ++i) {
            for (int j = y; j < y + 3; ++j) {
                if(start[i][j] == 1) start[i][j] = 0;
                else start[i][j] = 1;
            }
        }
    }

    static void solution() {
        if(isSame()) {
            System.out.println(0);
            return;
        }
        for (int i = 0; i < n - 2; ++i) {
            for (int j = 0; j < m - 2; ++j) {
                if(start[i][j] == result[i][j]) continue;
                change(i, j);
                ++changed;
                if(isSame()) {
                    System.out.println(changed);
                    return;
                }
            }
        }
        System.out.println(-1);
    }

    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
