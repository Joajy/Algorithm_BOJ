import java.awt.Point;
import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static StringTokenizer st;
    static int n, m, k;
    static int[][] area;

    static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        area = new int[n][m];
        for (int i = 0; i < k; ++i) {
            st = new StringTokenizer(br.readLine());
            int x1 = Integer.parseInt(st.nextToken());
            int y1 = Integer.parseInt(st.nextToken());
            int x2 = Integer.parseInt(st.nextToken());
            int y2 = Integer.parseInt(st.nextToken());
            for (int x = x1; x < x2; ++x) {
                for (int y = y1; y < y2; ++y) {
                    area[y][x] = 1;
                }
            }
        }
    }

    static void solution() {
        final int[] dx = {0, 1, 0, -1};
        final int[] dy = {1, 0, -1, 0};
        Deque<Point> q = new ArrayDeque<>();
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if(area[i][j] > 0) continue;
                area[i][j] = 1;
                int answer = 0;
                q.add(new Point(i, j));
                while (!q.isEmpty()) {
                    Point cur = q.poll();
                    ++answer;
                    for (int dir = 0; dir < 4; ++dir) {
                        int nx = cur.x + dx[dir];
                        int ny = cur.y + dy[dir];
                        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                        if(area[nx][ny] > 0) continue;
                        area[nx][ny] = 1;
                        q.add(new Point(nx, ny));
                    }
                }
                list.add(answer);
            }
        }
        System.out.println(list.size());
        Collections.sort(list);
        for (int size : list) {
            System.out.print(size + " ");
        }
    }

    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
