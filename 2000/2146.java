import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
	  static StringTokenizer st;
    static int n;
    static int[][] area;
    static boolean[][] vis;
    static final int[] dx = {0, 1, 0, -1};
    static final int[] dy = {1, 0, -1, 0};

    static void input() throws IOException {
		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		area = new int[n][n];
		vis = new boolean[n][n];
    	for(int i = 0;i < n; ++i) {
    		st = new StringTokenizer(br.readLine(), " ");
    		for(int j = 0;j < n; ++j) {
    			area[i][j] = Integer.parseInt(st.nextToken());
    		}
    	}
    }
    
    static boolean range(int x, int y) {
    	return x >= 0 && y >= 0 && x < n && y < n;
    }
    
    static void divideArea() {
    	int cnt = 0;
    	for(int i = 0;i < n; ++i) {
    		for(int j = 0;j < n; ++j) {
    			if(vis[i][j] || area[i][j] == 0) continue;
    			++cnt;
    			Deque<Integer> q = new ArrayDeque<>(); 
    			q.add(i * n + j);
    			vis[i][j] = true;
    			while(!q.isEmpty()) {
    				int cur = q.poll();
    				area[cur / n][cur % n] = cnt;
    				for(int dir = 0;dir < 4; ++dir) {
    					int nx = cur / n + dx[dir];
    					int ny = cur % n + dy[dir];
    					if(!range(nx, ny) || area[nx][ny] == 0) continue;
    					if(vis[nx][ny]) continue;
    					vis[nx][ny] = true;
    					q.add(nx * n + ny);
    				}
    			}
    		}
    	}
    }
    
    static void solution() {
    	divideArea();
    	int answer = (int)1e9;
    	for(int i = 0;i < n; ++i) {
    		for(int j = 0;j < n; ++j) {
    			if(area[i][j] == 0) continue;
    			vis = new boolean[n][n];
    			answer = Math.min(answer, bfs(i, j));
    		}
    	}
    	System.out.println(answer);
    }
    
    static int bfs(int i, int j) {
		Deque<Integer> q = new ArrayDeque<>(); 
		q.add(i * n + j);
		vis[i][j] = true;
		while(!q.isEmpty()) {
			int cur = q.poll();
			for(int dir = 0;dir < 4; ++dir) {
				int nx = cur / n + dx[dir];
				int ny = cur % n + dy[dir];
				if(!range(nx, ny) || vis[nx][ny]) continue;
				if(area[nx][ny] == area[i][j]) continue;
				if(area[nx][ny] > 0 && area[nx][ny] != area[i][j]) {
					return Math.abs(nx - i) + Math.abs(ny - j) - 1;
				}
				vis[nx][ny] = true;
				q.add(nx * n + ny);
			}
		}
    	return (int)1e9;
    }

    public static void main(String[] args) throws IOException {
   		input();
       	solution();
    }
}
