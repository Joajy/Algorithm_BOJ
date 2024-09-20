import java.awt.Point;
import java.util.*;
import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    static int n, m;
    static char[][] a;
    static class Info {
        int x1, y1, x2, y2;
        int count;
        Info() {
            x1 = y1 = x2 = y2 = -1;
            count = 0;
        }

        Info(int x1, int y1, int x2, int y2, int count) {
            this.x1 = x1;
            this.y1 = y1;
            this.x2 = x2;
            this.y2 = y2;
            this.count = count;
        }
    }
    static Point[] coins;
    static final int[] dx = {0, 1, 0, -1};
    static final int[] dy = {1, 0, -1, 0};

    static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        coins = new Point[2];
        a = new char[n + 1][m + 1];
        for (int i = 1; i <= n; ++i) {
            String s = br.readLine();
            for (int j = 1; j <= m; ++j) {
                a[i][j] = s.charAt(j - 1);
                if (a[i][j] == 'o') {
                    if (coins[0] == null) {
                        coins[0] = new Point(i, j);
                    } else {
                        coins[1] = new Point(i, j);
                    }
                }
            }
        }
    }

    static void solution() {
        Deque<Info> q = new ArrayDeque<>();
        boolean[][][][] vis = new boolean[n + 1][m + 1][n + 1][m + 1];
        q.add(new Info(coins[0].x, coins[0].y, coins[1].x, coins[1].y, 0));
        vis[coins[0].x][coins[0].y][coins[1].x][coins[1].y] = true;
        while (!q.isEmpty()) {
            Info cur = q.poll();
            if(cur.count == 10) {
                break;
            }
            for (int dir = 0; dir < 4; ++dir) {
                int nx1 = cur.x1 + dx[dir];
                int nx2 = cur.x2 + dx[dir];
                int ny1 = cur.y1 + dy[dir];
                int ny2 = cur.y2 + dy[dir];
                boolean one = range(nx1, ny1), two = range(nx2, ny2);
                //1. 둘 다 범위 내
                if (one && two) {
                    if(vis[nx1][ny1][nx2][ny2]) continue;
                    //1-1. 둘 다 벽에 부딪칠 경우
                    if(a[nx1][ny1] == '#' && a[nx2][ny2] == '#') {
                        continue;
                    }
                    //1-2. 둘 중 하나만 벽에 부딪칠 경우
                    else if (a[nx1][ny1] == '#') {
                        vis[cur.x1][cur.y1][nx2][ny2] = true;
                        q.add(new Info(cur.x1, cur.y1, nx2, ny2, cur.count + 1));
                    }
                    else if (a[nx2][ny2] == '#') {
                        vis[nx1][ny1][cur.x2][cur.y2] = true;
                        q.add(new Info(nx1, ny1, cur.x2, cur.y2, cur.count + 1));
                    }
                    //1.3 둘 다 안전한 경우
                    else {
                        vis[nx1][ny1][nx2][ny2] = true;
                        q.add(new Info(nx1, ny1, nx2, ny2, cur.count + 1));
                    }

                }
                //2. 둘 중 하나만 떨어지는 경우 -> 정답 라인업
                else if(one ^ two) {
                    System.out.println(cur.count + 1);
                    return;
                }
                //3. 둘 다 떨어지는 경우는 신경 안 써도 됨
            }
        }
        System.out.println(-1);
    }

    static boolean range(int x, int y) {
        return x >= 1 && x <= n && y >= 1 && y <= m;
    }

    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
