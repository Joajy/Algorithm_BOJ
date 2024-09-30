import java.awt.Point;
import java.util.*;
import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n, m, t;
    static int[][] area, dist;
    static final int[] dx = {0, 1, 0, -1};
    static final int[] dy = {1, 0, -1, 0};
    static Point gram;

    static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        t = Integer.parseInt(st.nextToken());
        area = new int[n + 1][m + 1];
        dist = new int[n + 1][m + 1];
        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= m; j++) {
                area[i][j] = Integer.parseInt(st.nextToken());
                if(area[i][j] == 2) {
                    gram = new Point(i, j);
                }
            }
        }
    }

    static void findGram() {
        setting();
        Deque<Point> q = new ArrayDeque<>();
        q.add(new Point(1, 1));
        dist[1][1] = 0;
        while (!q.isEmpty()) {
            Point cur = q.poll();
            if(gram.x == cur.x && gram.y == cur.y) continue;
            for(int dir = 0; dir < 4; ++dir) {
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];
                if(!range(nx, ny) || dist[cur.x][cur.y] + 1 >= dist[nx][ny]) continue;
                if(area[nx][ny] == 1) continue;
                dist[nx][ny] = dist[cur.x][cur.y] + 1;
                q.add(new Point(nx, ny));
            }
        }
    }

    static void withGram() {
        setting();
        Deque<Point> q = new ArrayDeque<>();
        q.add(new Point(gram.x, gram.y));
        dist[gram.x][gram.y] = 0;
        while (!q.isEmpty()) {
            Point cur = q.poll();
            if(cur.x == n && cur.y == m) continue;
            for(int dir = 0; dir < 4; ++dir) {
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];
                if(!range(nx, ny) || dist[cur.x][cur.y] + 1 >= dist[nx][ny]) continue;
                dist[nx][ny] = dist[cur.x][cur.y] + 1;
                q.add(new Point(nx, ny));
            }
        }
    }

    static void solution() {
        findGram();
        int directDist = dist[n][m];
        int toGram = dist[gram.x][gram.y];
        withGram();
        toGram += dist[n][m];
        int answer = Math.min(directDist, toGram);
        if(answer > t) System.out.println("Fail");
        else System.out.println(answer);
    }

    static void setting() {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                dist[i][j] = (int)1e9;
            }
        }
    }

    static boolean range(int x, int y) {
        return x >= 1 && x <= n && y >= 1 && y <= m;
    }

    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
