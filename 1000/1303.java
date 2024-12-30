import java.awt.Point;
import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n, m, sumB, sumW;
    static char[][] area;
    static boolean[][] vis;

    static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        m = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());
        area = new char[n][m];
        vis = new boolean[n][m];
        for (int i = 0; i < n; ++i) {
            String s = br.readLine();
            for (int j = 0; j < m; ++j) {
                area[i][j] = s.charAt(j);
            }
        }
        sumB = sumW = 0;
    }

    static void bfs(int x, int y) {
        final int[] dx = {0, 1, 0, -1};
        final int[] dy = {1, 0, -1, 0};
        Deque<Point> q = new ArrayDeque<>();
        q.add(new Point(x, y));
        vis[x][y] = true;
        int sum = 0;
        while (!q.isEmpty()) {
            Point cur = q.poll();
            ++sum;
            for (int dir = 0; dir < 4; ++dir) {
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(vis[nx][ny] || area[nx][ny] != area[x][y]) continue;
                vis[nx][ny] = true;
                q.add(new Point(nx, ny));
            }
        }
        if(area[x][y] == 'B') sumB += sum * sum;
        else sumW += sum * sum;
    }

    static void solution() {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if(vis[i][j]) continue;
                bfs(i, j);
            }
        }
        System.out.println(sumW + " " + sumB);
    }

    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
