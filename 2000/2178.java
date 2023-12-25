import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    private static int n, m;
    private static int dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};
    private static int[][] area = new int[101][101];
    private static boolean[][] vis = new boolean[101][101];

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static class Point {
        int x, y, cnt;
        Point(int x, int y, int cnt){
            this.x = x;
            this.y = y;
            this.cnt = cnt;
        }
    }

    public static void main(String[] args) throws Exception {
        init();
        Queue<Point> q = new LinkedList<>();
        q.add(new Point(1, 1, 0));
        vis[1][1] = true;
        while (!q.isEmpty()) {
            Point cur = q.poll();
            if(cur.x == n && cur.y == m){
                System.out.println(cur.cnt + 1);
                return;
            }
            for(int dir = 0; dir < 4;++dir){
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];
                if(nx < 1 || ny < 1 || nx > n || ny > m) continue;
                if(area[nx][ny] == 0) continue;
                if(vis[nx][ny]) continue;
                vis[nx][ny] = true;
                q.add(new Point(nx, ny, cur.cnt + 1));
            }
        }
    }

    private static void init() throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        String s;
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        for(int i = 1;i <= n;++i){
            s = br.readLine();
            for(int j = 1;j <= m;++j){
                area[i][j] = s.charAt(j - 1) - '0';
            }
        }
    }
}
