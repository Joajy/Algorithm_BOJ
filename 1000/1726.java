import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;
    static int n, m;
    static int[][] a;
    static boolean[][][] vis;
    static final int[] dx = {0, 1, 0, -1};
    static final int[] dy = {1, 0, -1, 0};
    static class Info{
    	int x, y, dir, cnt;
    	Info(int x, int y, int dir, int cnt){
    		this.x = x;
    		this.y = y;
    		this.dir = dir;
    		this.cnt = cnt;
    	}    	
    }
    static Info start, end;

    static void input() throws IOException {
		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
    	m = Integer.parseInt(st.nextToken());
		a = new int[n][m];
		vis = new boolean[n][m][4];
    	for(int i = 0;i < n; ++i) {
    		st = new StringTokenizer(br.readLine());
    		for(int j = 0;j < m; ++j) {
    			a[i][j] = Integer.parseInt(st.nextToken());
    		}
    	}
		st = new StringTokenizer(br.readLine());
		int x = Integer.parseInt(st.nextToken()) - 1;
		int y = Integer.parseInt(st.nextToken()) - 1;
		int d = settingInitDir(Integer.parseInt(st.nextToken()));
		start = new Info(x, y, d, 0);
		st = new StringTokenizer(br.readLine());
		x = Integer.parseInt(st.nextToken()) - 1;
		y = Integer.parseInt(st.nextToken()) - 1;
		d = settingInitDir(Integer.parseInt(st.nextToken()));
		end = new Info(x, y, d, 0);
    }
    
    static int settingInitDir(int dir) {
    	if(dir == 1) return 0;
    	else if(dir == 2) return 2;
    	else if(dir == 3) return 1;
    	else return 3;
    }
    
    static boolean range(int x, int y) {
    	return x >= 0 && y >= 0 && x < n && y < m;
    }
    
    static void solution(){
    	Deque<Info> q = new ArrayDeque<>();
    	q.add(start);
    	vis[start.x][start.y][start.dir] = true; 
    	while(!q.isEmpty()) {
    		Info cur = q.poll();
    		if(cur.x == end.x && cur.y == end.y && cur.dir == end.dir) {
    			System.out.println(cur.cnt);
    			return;
    		}
    		for(int cnt = 1; cnt <= 3; ++cnt) {
    			int nx = cur.x + dx[cur.dir] * cnt;
    			int ny = cur.y + dy[cur.dir] * cnt;
    			if(!range(nx, ny) || a[nx][ny] == 1) break;
    			if(vis[nx][ny][cur.dir]) continue;
    			vis[nx][ny][cur.dir] = true; 
    			q.add(new Info(nx, ny, cur.dir, cur.cnt + 1));
    		}
    		int left = (cur.dir + 3) % 4;
    		int right = (cur.dir + 1) % 4;
    		if(!vis[cur.x][cur.y][left]) {
    			vis[cur.x][cur.y][left] = true;
    			q.add(new Info(cur.x, cur.y, left, cur.cnt + 1));
    		}
    		if(!vis[cur.x][cur.y][right]) {
    			vis[cur.x][cur.y][right] = true;
    			q.add(new Info(cur.x, cur.y, right, cur.cnt + 1));
    		}
    	}
    }

    public static void main(String[] args) throws IOException {
   		input();
       	solution();
    }
}
