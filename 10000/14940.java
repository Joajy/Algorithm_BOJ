import java.awt.Point;
import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n, m;
    static int[][] area, dist;
    static Point start;

    static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        area = new int[n + 1][m + 1];
        dist = new int[n + 1][m + 1];
        for (int i = 1; i <= n; ++i) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= m; ++j) {
                area[i][j] = Integer.parseInt(st.nextToken());
                dist[i][j] = -1;
                if(area[i][j] == 2) start = new Point(i, j);
                if(area[i][j] != 1) dist[i][j] = 0;
            }
        }
    }

    static void solution() {
        final int[] dx = {0, 1, 0, -1};
        final int[] dy = {1, 0, -1, 0};
        Deque<Point> q = new ArrayDeque<>();
        q.add(start);
        while (!q.isEmpty()) {
            Point cur = q.poll();
            for (int dir = 0; dir < 4; ++dir) {
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];
                if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
                if(area[nx][ny] != 1 || dist[nx][ny] > 0) continue;
                q.add(new Point(nx, ny));
                dist[nx][ny] = dist[cur.x][cur.y] + 1;
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                System.out.print(dist[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
