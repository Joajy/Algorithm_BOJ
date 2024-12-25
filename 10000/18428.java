import java.awt.Point;
import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n;
    static boolean canEscape;
    static char[][] area;
    static Deque<Point> teachers;
    static final int[] dx = {0, 1, 0, -1};
    static final int[] dy = {1, 0, -1, 0};

    static void input() throws IOException {
        n = Integer.parseInt(br.readLine());
        area = new char[n][n];
        teachers = new ArrayDeque<>();
        for (int i = 0; i < n; ++i) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; ++j) {
                area[i][j] = st.nextToken().charAt(0);
                if(area[i][j] == 'T') teachers.add(new Point(i, j));
            }
        }
        canEscape = false;
    }

    static void bfs() {
        //선생님들 위치 전부 모아서 담는다.
        Deque<Point> q = new ArrayDeque<>(teachers);
        while (!q.isEmpty()) {
            Point cur = q.poll();
            if(area[cur.x][cur.y] == 'S') {
                return;
            }
            for (int dir = 0; dir < 4; ++dir) {
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];
                while(!(nx < 0 || nx >= n || ny < 0 || ny >= n)) {
                    if(area[nx][ny] == 'S') return;
                    if(area[nx][ny] == 'O') break;
                    nx += dx[dir];
                    ny += dy[dir];
                }
            }
        }
        canEscape = true;
    }

    static void dfs(int wall) {
        if(wall == 3) {
            bfs();
            return;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if(area[i][j] != 'X') continue;
                area[i][j] = 'O';
                dfs(wall + 1);
                area[i][j] = 'X';
            }
        }
    }

    static void solution() {
        dfs(0);
        if(canEscape) System.out.println("YES");
        else System.out.println("NO");
    }

    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
