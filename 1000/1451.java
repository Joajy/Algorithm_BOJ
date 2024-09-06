import java.awt.*;
import java.util.*;
import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n, m;
    static char[][] a;
    static long[][] prefix;
    static long answer = 0;

    static void input()  throws IOException{
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        a = new char[n + 1][m + 1];
        prefix = new long[n + 1][m + 1];
        for(int i = 1;i <= n; ++i) {
            String s = br.readLine();
            for(int j = 1;j <= m; ++j) {
                a[i][j] = s.charAt(j - 1);
                prefix[i][j] = a[i][j] - '0';
            }
        }
        for(int i = 1;i <= n; ++i) {
            for(int j = 1;j <= m; ++j) {
                prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] + (a[i][j] - '0') - prefix[i - 1][j - 1];
            }
        }
    }

    /*
        rotate한 경우 포함
        1. [] [] []
        2.  [] []
            [   ]
    */

    static void sequential() {
        for(int i = 1;i <= n; ++i) {
            for(int j = i + 1; j <= n; ++j) {
                long value = prefix[i][m] * (prefix[j][m] - prefix[i][m]) * (prefix[n][m] - prefix[j][m]);
                if(answer < value) answer = value;
            }
        }
        for(int i = 1;i <= m; ++i) {
            for(int j = i + 1; j <= m; ++j) {
                long value = prefix[n][i] * (prefix[n][j] - prefix[n][i]) * (prefix[n][m] - prefix[n][j]);
                if(answer < value) answer = value;
            }
        }
    }

    static void oneStand() {
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                long value = prefix[n][j] *
                        (prefix[i][m] - prefix[i][j]) *
                        (prefix[n][m] - prefix[i][m] - prefix[n][j] + prefix[i][j]);
                if(answer < value) answer = value;
            }
        }
        for(int i = n; i >= 1; --i) {
            for(int j = 1; j <= m; ++j) {
                long value = (prefix[n][m] - prefix[n][j]) *
                        prefix[i][j] *
                        (prefix[n][j] - prefix[i][j]);
                if(answer < value) answer = value;
            }
        }
    }

    static void twoStand() {
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                long value = prefix[i][m] *
                        (prefix[n][j] - prefix[i][j]) *
                        (prefix[n][m] - prefix[i][m] - prefix[n][j] + prefix[i][j]);
                if(answer < value) answer = value;
            }
        }
        for(int i = n; i >= 1; --i) {
            for(int j = 1; j <= m; ++j) {
                long value = (prefix[n][m] - prefix[i][m]) *
                        prefix[i][j] *
                        (prefix[i][m] - prefix[i][j]);
                if(answer < value) answer = value;
            }
        }
    }

    static void solution() {
        sequential();
        oneStand();
        twoStand();
        System.out.println(answer);
    }

    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
