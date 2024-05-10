import java.awt.Point;
import java.util.*;
import java.io.*;
/*
  Title: 보물섬
  Tier: Gold 5
  Algorithm: BFS
  Constraint: 1 Second, 512MB
*/
public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n, m, maxDist;
    static int[] dx = {1, -1, 0, 0};
    static int[] dy = {0, 0, -1, 1};
    static int[][] vis;
    static char[][] area;

    static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        maxDist = 0;
        area = new char[n][m];
        for (int i = 0; i < n; ++i) {
            String tmp = br.readLine();
            for (int j = 0; j < m; ++j) {
                area[i][j] = tmp.charAt(j);
            }
        }
    }

    static boolean range(int x, int y) {
        return x >= 0 && y >= 0 && x < n && y < m;
    }

    static void bfs(int x, int y) {
        vis = new int[n][m];
        for(int i=0;i<n;++i){
            for (int j = 0; j < m; ++j) {
                vis[i][j] = (int)1e9;
            }
        }
        vis[x][y] = 0;
        Queue<Point> q = new ArrayDeque<>();
        q.add(new Point(x, y));
        while (!q.isEmpty()) {
            Point cur = q.poll();
            if (vis[cur.x][cur.y] > maxDist) {
                maxDist = vis[cur.x][cur.y];
            }
            for (int dir = 0; dir < 4; ++dir) {
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];
                if(!range(nx, ny) || area[nx][ny] == 'W') continue;
                if(vis[nx][ny] <= vis[cur.x][cur.y] + 1) continue;
                q.add(new Point(nx, ny));
                vis[nx][ny] = vis[cur.x][cur.y] + 1;
            }
        }
    }

    static void solution() {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if(area[i][j] == 'W') continue;
                bfs(i, j);
            }
        }
        System.out.println(maxDist);
    }

    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
