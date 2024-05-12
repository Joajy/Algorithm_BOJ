import java.awt.Point;
import java.util.*;
import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n, m, answer;
    static int[][] area, dp;
    static final int[] dx = {0, 1, 0, -1};
    static final int[] dy = {1, 0, -1, 0};

    static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        m = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());
        area = new int[n][m];
        dp = new int[n][m];
        for (int i = 0; i < n; ++i) {
            String tmp = br.readLine();
            for (int j = 0; j < m; ++j) {
                area[i][j] = tmp.charAt(j) - '0';
                dp[i][j] = (int)1e9;
            }
        }
    }

    static void bfs() {
        dp[0][0] = 0;
        Queue<Point> q = new ArrayDeque<>();
        q.add(new Point(0, 0));
        while (!q.isEmpty()) {
            Point cur = q.poll();
            for (int dir = 0; dir < 4; ++dir) {
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];
                if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if(area[nx][ny] == 1){
                    if(dp[nx][ny] <= dp[cur.x][cur.y] + 1) continue;
                    dp[nx][ny] = dp[cur.x][cur.y] + 1;
                } else {
                    if(dp[nx][ny] <= dp[cur.x][cur.y]) continue;
                    dp[nx][ny] = dp[cur.x][cur.y];
                }
                q.add(new Point(nx, ny));
            }
        }
    }

    static void solution() {
        bfs();
        System.out.println(dp[n - 1][m - 1]);
    }

    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
