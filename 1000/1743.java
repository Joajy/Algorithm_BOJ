import java.awt.Point;
import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n, m, k, answer;
    static int[][] area;
    static boolean[][] vis;

    static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        area = new int[n + 1][m + 1];
        vis = new boolean[n + 1][m + 1];
        for (int i = 0; i < k; ++i) {
            st = new StringTokenizer(br.readLine());
            int r = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            area[r][c] = 1;
        }
        answer = 0;
    }

    static void solution() {
        final int[] dx = {0, 1, 0, -1};
        final int[] dy = {1, 0, -1, 0};
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if(vis[i][j] || area[i][j] != 1) continue;
                Deque<Point> q = new ArrayDeque<>();
                q.add(new Point(i, j));
                vis[i][j] = true;
                int size = 0;
                while (!q.isEmpty()) {
                    Point cur = q.poll();
                    ++size;
                    for (int dir = 0; dir < 4; ++dir) {
                        int nx = cur.x + dx[dir];
                        int ny = cur.y + dy[dir];
                        if(nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
                        if(vis[nx][ny] || area[nx][ny] != 1) continue;
                        q.add(new Point(nx, ny));
                        vis[nx][ny] = true;
                    }
                }
                if(size > answer) answer = size;
            }
        }
        System.out.println(answer);
    }

    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
