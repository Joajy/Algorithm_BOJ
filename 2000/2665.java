import java.io.*;
import java.util.*;
import java.awt.Point;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;
	static int n;
	static int[][] area, dp;
	static final int[] dx = {0, 1, 0, -1};
	static final int[] dy = {1, 0, -1, 0};
	
    static void input() throws IOException {
    	n = Integer.parseInt(br.readLine());
    	area = new int[n][n];
    	dp = new int[n][n];
    	for(int i = 0;i < n; ++i) {
    		String s = br.readLine();
    		for(int j = 0; j < n; ++j) {
    			area[i][j] = s.charAt(j) - '0';
    			dp[i][j] = (int)1e9;
    		}
    	}
    }
    
    static void bfs() {
    	Deque<Point> q = new ArrayDeque<>();
    	q.add(new Point(0, 0));
    	dp[0][0] = 0;
    	while(!q.isEmpty()) {
    		Point cur = q.poll();
    		for(int dir = 0; dir < 4; ++dir) {
    			int nx = cur.x + dx[dir];
    			int ny = cur.y + dy[dir];
    			if(!range(nx, ny)) continue;
    			//흰 방일때와 검은 방일때에 대해 분할해서 판단
    			if(area[nx][ny] == 1) {
    				if(dp[cur.x][cur.y] >= dp[nx][ny]) continue;
    				dp[nx][ny] = dp[cur.x][cur.y];
    				q.add(new Point(nx, ny));
    			} else {
    				if(dp[cur.x][cur.y] + 1 >= dp[nx][ny]) continue;
    				dp[nx][ny] = dp[cur.x][cur.y] + 1;
    				q.add(new Point(nx, ny));
    			}
    		}
    	}
    }
    
    static void solution() {
    	bfs();
    	System.out.println(dp[n - 1][n - 1]);
    }
    
    static boolean range(int x, int y) {
    	return x >= 0 && x < n && y >= 0 && y < n;
    }
    
    public static void main(String[] args) throws IOException {
    	input();
    	solution();
    }
}
