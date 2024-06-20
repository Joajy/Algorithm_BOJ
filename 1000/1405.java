import java.io.*;
import java.util.*;

public class Main {

  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int n;
	static double answer;
	static double[] percent;
	static boolean[][] vis;
	static final int[] dx = {0, 0, 1, -1};
	static final int[] dy = {1, -1, 0, 0};
	
    static void input() throws IOException {
    	answer = 0;
    	percent = new double[4];
    	vis = new boolean[31][31];
		st = new StringTokenizer(br.readLine());
    	n = Integer.parseInt(st.nextToken());
    	for(int i = 0;i < 4; ++i) {
   			percent[i] = Double.parseDouble(st.nextToken()) / 100;
    	}
   	}
    
    static void dfs(int x, int y, int cnt, double p) {
    	if(cnt == n) {
    		answer += p;
    		return;
    	}
    	for(int dir = 0;dir < 4; ++dir) {
    		if(percent[dir] == 0) continue;
    		int nx = x + dx[dir];
    		int ny = y + dy[dir];
    		if(vis[nx][ny]) continue;
    		vis[nx][ny] = true;
    		dfs(nx, ny, cnt + 1, p * percent[dir]);
    		vis[nx][ny] = false;
    	}
    }
    
    static void solution() {
    	vis[15][15] = true;
    	dfs(15, 15, 0, 1.0);
    	System.out.println(answer);
    }
    
    public static void main(String[] args) throws IOException {
   		input();
   		solution();
    }
}
