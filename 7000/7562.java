import java.awt.Point;
import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static StringTokenizer st;
    static int l;
    static int[][] dp;
    static Point start, end;

    static void input() throws IOException {
        l = Integer.parseInt(br.readLine());
        dp = new int[l][l];
        for (int row = 0; row < l; ++row) {
            Arrays.fill(dp[row], (int)1e9);
        }
        st = new StringTokenizer(br.readLine());
        start = new Point(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        st = new StringTokenizer(br.readLine());
        end = new Point(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
    }

    static void solution() {
        final int[] dx = {-2, -1, 1, 2, 2, 1, -1, -2};
        final int[] dy = {1, 2, 2, 1, -1, -2, -2, -1};
        Deque<Point> q = new ArrayDeque<>();
        q.add(start);
        dp[start.x][start.y] = 0;
        while (!q.isEmpty()) {
            Point current = q.poll();
            if(current.x == end.x && current.y == end.y) break;
            for (int dir = 0; dir < 8; ++dir) {
                int nx = current.x + dx[dir];
                int ny = current.y + dy[dir];
                if(nx >= l || nx < 0 || ny >= l || ny < 0) continue;
                if(dp[nx][ny] <= dp[current.x][current.y] + 1) continue;
                dp[nx][ny] = dp[current.x][current.y] + 1;
                q.add(new Point(nx, ny));
            }
        }
        sb.append(dp[end.x][end.y]).append('\n');
    }

    public static void main(String[] args) throws IOException {
        int testCase = Integer.parseInt(br.readLine());
        for (int current = 1; current <= testCase; ++current) {
            input();
            solution();
        }
        System.out.println(sb);
    }
}
