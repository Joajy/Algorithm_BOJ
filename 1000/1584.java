import java.awt.Point;
import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n, m, x1, x2, y1, y2;
    static int[][] area, dp;
    static final int FINISH = 500;

    static void input() throws IOException {
        area = new int[FINISH + 1][FINISH + 1];
        dp = new int[FINISH + 1][FINISH + 1];
        for (int i = 0; i <= 500; ++i) {
            Arrays.fill(dp[i], (int) 1e9);
        }
        dp[0][0] = 0;
        n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; ++i) {
            st = new StringTokenizer(br.readLine());
            x1 = Integer.parseInt(st.nextToken());
            y1 = Integer.parseInt(st.nextToken());
            x2 = Integer.parseInt(st.nextToken());
            y2 = Integer.parseInt(st.nextToken());
            setHarmArea(x1, y1, x2, y2, 1);
        }
        m = Integer.parseInt(br.readLine());
        for (int i = 0; i < m; ++i) {
            st = new StringTokenizer(br.readLine());
            x1 = Integer.parseInt(st.nextToken());
            y1 = Integer.parseInt(st.nextToken());
            x2 = Integer.parseInt(st.nextToken());
            y2 = Integer.parseInt(st.nextToken());
            setHarmArea(x1, y1, x2, y2, 2);
        }
        area[0][0] = 0;
    }

    /*
    * 위험 구역일 경우 value = 1
    * 죽음 구역일 경우 value = 2
    * 위험 이후 죽음 구역을 체크하므로 중요도 파악에서는 문제되지 않는다.
    */
    static void setHarmArea(int x1, int y1, int x2, int y2, int value) {
        if(x1 > x2) {
            int tmp = x1;
            x1 = x2;
            x2 = tmp;
        }
        if(y1 > y2) {
            int tmp = y1;
            y1 = y2;
            y2 = tmp;
        }
        for (int x = x1; x <= x2; ++x) {
            for (int y = y1; y <= y2; ++y) {
                area[x][y] = value;
            }
        }
    }

    static void solution() {
        final int[] dx = {0, 1, 0, -1};
        final int[] dy = {1, 0, -1, 0};
        Deque<Point> q = new ArrayDeque<>();
        q.add(new Point(0, 0));
        while (!q.isEmpty()) {
            Point cur = q.poll();
            for (int dir = 0; dir < 4; ++dir) {
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];
                if(nx < 0 || nx > FINISH || ny < 0 || ny > FINISH) continue;
                if(area[nx][ny] == 2 || dp[cur.x][cur.y] + area[nx][ny] >= dp[nx][ny]) continue;
                dp[nx][ny] = dp[cur.x][cur.y] + area[nx][ny];
                q.add(new Point(nx, ny));
            }
        }
        if(dp[FINISH][FINISH] == (int)1e9) dp[FINISH][FINISH] = -1;
        System.out.println(dp[FINISH][FINISH]);
    }

    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
