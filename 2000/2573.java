import java.awt.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n, m, cnt = 0, day = 0;
    static int[][] a;
    static final int[] dx = {0,1,0,-1};
    static final int[] dy = {1,0,-1,0};

    static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        a = new int[n][m];
        for(int i = 0;i < n; ++i){
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; ++j) {
                a[i][j] = Integer.parseInt(st.nextToken());
                if(a[i][j] > 0) ++cnt;
            }
        }
    }

    static void update(int[][] melt){
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if(a[i][j] == 0) continue;
                a[i][j] -= melt[i][j];
                if(a[i][j] <= 0) {
                    a[i][j] = 0;
                    --cnt;
                }
            }
        }
    }

    static int meltSide(int x, int y) {
        int side = 0;
        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(a[nx][ny] == 0) ++side;
        }
        return side;
    }

    static void melting(){
        int[][] melt = new int[n][m];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if(a[i][j] == 0) continue;
                melt[i][j] += meltSide(i, j);
            }
        }
        update(melt);
    }

    static int search(){
        int cnt = 0;
        boolean[][] vis = new boolean[n][m];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if(a[i][j] == 0 || vis[i][j]) continue;
                ++cnt;
                Queue<Point> q = new ArrayDeque<>();
                q.add(new Point(i, j));
                vis[i][j] = true;
                while (!q.isEmpty()) {
                    Point cur = q.poll();
                    for (int dir = 0; dir < 4; ++dir) {
                        int x = cur.x + dx[dir];
                        int y = cur.y + dy[dir];
                        if(x < 0 || y < 0 || x >= n || y >= m) continue;
                        if(vis[x][y] || a[x][y] == 0) continue;
                        vis[x][y] = true;
                        q.add(new Point(x, y));
                    }
                }
            }
        }
        return cnt;
    }

    static int solution() {
        while (true) {
            int div = search();
            if(div == 0) return 0;
            if(div >= 2) return day;
            melting();
            ++day;
        }
    }

    public static void main(String[] args) throws IOException {
        input();
        System.out.println(solution());
    }
}
