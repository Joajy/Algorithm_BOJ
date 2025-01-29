import java.awt.Point;
import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static StringTokenizer st;
    static int n, m, k;
    static int[][] area;
    static boolean[][] vis;
    static final int[] dx = {0, 1, 0, -1};
    static final int[] dy = {1, 0, -1, 0};

    static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        area = new int[n][m];
        for (int i = 0; i < k; ++i) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            area[x][y] = 1;
        }
        vis = new boolean[n][m];
    }

    static void solution() {
        int answer = 0;
        for(int i = 0;i<n;++i) {
            for (int j = 0; j < m; ++j) {
                if(area[i][j] == 0 || vis[i][j]) continue;
                ++answer;
                vis[i][j] = true;
                Deque<Point> q = new ArrayDeque<>();
                q.add(new Point(i, j));
                while (!q.isEmpty()) {
                    Point cur = q.poll();
                    for (int dir = 0; dir < 4; ++dir) {
                        int nx = cur.x + dx[dir];
                        int ny = cur.y + dy[dir];
                        if(nx < 0 | nx >= n || ny < 0 || ny >= m) continue;
                        if(vis[nx][ny] || area[nx][ny] == 0) continue;
                        q.add(new Point(nx, ny));
                        vis[nx][ny] = true;
                    }
                }
            }
        }
        sb.append(answer).append('\n');
    }

    public static void main(String[] args) throws IOException {
        int t = Integer.parseInt(br.readLine());
        for (int i = 0; i < t; ++i) {
            input();
            solution();
        }
        System.out.println(sb);
    }
}
