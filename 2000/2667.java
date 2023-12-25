import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Vector;

public class Main {

    private static int n, answer = 0;
    private static int dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};
    private static Vector<Integer> v = new Vector<>();
    private static int[][] area = new int[26][26];
    private static boolean[][] vis = new boolean[26][26];
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static class Point {
        int x, y;
        Point(int x, int y){
            this.x = x;
            this.y = y;
        }
    }

    private static void bfs(int x, int y){
        Queue<Point> q = new LinkedList<>();
        q.add(new Point(x, y));
        vis[x][y] = true;
        int cnt = 0;
        while (!q.isEmpty()) {
            Point cur = q.poll();
            ++cnt;
            for(int dir = 0; dir < 4;++dir){
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];
                if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if(area[nx][ny] == 0 || vis[nx][ny]) continue;
                vis[nx][ny] = true;
                q.add(new Point(nx, ny));
            }
        }
        v.add(cnt);
        ++answer;
    }

    public static void main(String[] args) throws Exception {
        init();
        for(int i=0;i<n;++i){
            for(int j =0;j<n;++j){
                if(area[i][j] == 0 || vis[i][j]) continue;
                bfs(i, j);
            }
        }
        System.out.println(answer);
        Collections.sort(v);
        for(int i : v){
            System.out.println(i);
        }
    }

    private static void init() throws Exception {
        String s;
        n = Integer.parseInt(br.readLine());
        for(int i = 0;i < n;++i){
            s = br.readLine();
            for(int j = 0;j < n;++j){
                area[i][j] = s.charAt(j) - '0';
            }
        }
    }
}
