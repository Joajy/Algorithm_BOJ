import java.util.*;
import java.io.*;

public class Main {

	static StringBuilder sb = new StringBuilder();
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int n, m, answer = 0;
	static int[][] a;
	static boolean[][] vis;
	static int[] dx = {0,1,0,-1};
	static int[] dy = {1,0,-1,0};
	
	static void rec(int x, int y, int cnt, int sum) {
		if(cnt == 4) {
			answer = Math.max(answer, sum);
			return;
		}
		for(int i = 0;i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if(vis[nx][ny]) continue;
			if(cnt == 2) {
				vis[nx][ny] = true;
				rec(x, y, cnt + 1, sum + a[nx][ny]);
				vis[nx][ny] = false;
			}
			vis[nx][ny] = true;
			rec(nx, ny, cnt + 1, sum + a[nx][ny]);
			vis[nx][ny] = false;
		}
	}

	static void solution() throws IOException {
		for(int i = 0;i < n; ++i) {
			for(int j = 0;j < m; ++j) {
				if(vis[i][j]) continue;
				vis[i][j] = true;
				rec(i, j, 0, 0);
				vis[i][j] = false;
			}
		}
		System.out.println(answer);
	}
	
	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		a = new int[n][m];
		vis = new boolean[n][m];
		for(int i = 0;i < n; ++i) {
			st = new StringTokenizer(br.readLine());
			for(int j = 0;j < m; ++j) {
				a[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		solution();
	}
}
