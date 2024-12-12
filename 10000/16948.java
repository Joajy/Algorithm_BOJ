import java.awt.Point;
import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n, r1, r2, c1, c2;
    static int[][] area;

    static void input() throws IOException {
        n = Integer.parseInt(br.readLine());
        area = new int[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                area[i][j] = (int)1e9;
            }
        }
        st = new StringTokenizer(br.readLine());
        r1 = Integer.parseInt(st.nextToken());
        c1 = Integer.parseInt(st.nextToken());
        r2 = Integer.parseInt(st.nextToken());
        c2 = Integer.parseInt(st.nextToken());
        area[r1][c1] = 0;
    }

    static void solution() {
        final int[] dx = {-2, -2, 0, 0, 2, 2};
        final int[] dy = {-1, 1, -2, 2, -1, 1};
        Deque<Point> q = new ArrayDeque<>();
        q.add(new Point(r1, c1));
        while (!q.isEmpty()) {
            Point cur = q.poll();
            for (int dir = 0; dir < 6; ++dir) {
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if(area[cur.x][cur.y] + 1 >= area[nx][ny]) continue;
                area[nx][ny] = area[cur.x][cur.y] + 1;
                q.add(new Point(nx, ny));
            }
        }
        if(area[r2][c2] == (int)1e9) area[r2][c2] = -1;
        System.out.println(area[r2][c2]);
    }

    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
