import java.awt.Point;
import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n, k, s, x, y;
    static int[][] area, spreadTime;
    static List<Point>[] startingPoint;

    static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        area = new int[n][n];
        spreadTime = new int[n][n];
        startingPoint = new ArrayList[k + 1];
        for (int i = 1; i <= k; ++i) {
            startingPoint[i] = new ArrayList<>();
        }
        for (int i = 0; i < n; ++i) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; ++j) {
                area[i][j] = Integer.parseInt(st.nextToken());
                spreadTime[i][j] =(int)1e9;
                //바이러스 존재하는 영역은 시간 0부터 시작하고, 시작점을 가져오기 위해 덱에 저장
                if(area[i][j] > 0) {
                    startingPoint[area[i][j]].add(new Point(i, j));
                    spreadTime[i][j] = 0;
                }
            }
        }
        st = new StringTokenizer(br.readLine());
        s = Integer.parseInt(st.nextToken());
        x = Integer.parseInt(st.nextToken());
        y = Integer.parseInt(st.nextToken());
    }

    static void dfs(List<Point> start) {
        if(start.isEmpty()) return;
        final int[] dx = {0, 1, 0, -1};
        final int[] dy = {1, 0, -1, 0};
        Deque<Point> spread = new ArrayDeque<>(start);
        while (!spread.isEmpty()) {
            Point cur = spread.poll();
            if(spreadTime[cur.x][cur.y] == s) continue;
            for (int dir = 0; dir < 4; ++dir) {
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];
                if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if(area[nx][ny] > 0 && spreadTime[cur.x][cur.y] + 1 >= spreadTime[nx][ny]) continue;
                spreadTime[nx][ny] = spreadTime[cur.x][cur.y] + 1;
                area[nx][ny] = area[start.get(0).x][start.get(0).y];
                spread.add(new Point(nx, ny));
            }
        }
    }

    static void solution() {
        for(int virus = 1; virus <= k; ++virus) {
            dfs(startingPoint[virus]);
        }
        System.out.println(area[x - 1][y - 1]);
    }

    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
