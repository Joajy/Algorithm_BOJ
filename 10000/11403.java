import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n;
    static int[][] area;

    static void input() throws IOException {
        n = Integer.parseInt(br.readLine());
        area = new int[n + 1][n + 1];
        for (int i = 1; i <= n; ++i) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= n; ++j) {
                area[i][j] = Integer.parseInt(st.nextToken());
            }
        }
    }

    static void solution() {
        for (int k = 1; k <= n; ++k) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    if(area[i][k] == 1 && area[k][j] == 1) area[i][j] = 1;
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                System.out.print(area[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
