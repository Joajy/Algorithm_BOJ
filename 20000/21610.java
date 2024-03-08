package a;

import java.awt.Point;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Solution {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	static int n, m;
	static int answer;
	static int[][] a;
	static boolean[][] vis;
	static Deque<Point> cloud = new ArrayDeque<>();
	static Deque<Point> isRained;
	static final int[] dx = {0, -1, -1, -1, 0, 1, 1, 1};
	static final int[] dy = {-1, -1, 0, 1, 1, 1, 0, -1};
	
	static void input() throws IOException{
		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		a = new int[n][n];
		vis = new boolean[n][n];
		for(int i = 0;i < n; ++i) {
			st = new StringTokenizer(br.readLine());
			for(int j = 0;j < n; ++j) {
				a[i][j] = Integer.parseInt(st.nextToken());
			}
		}
	}
	
	static boolean inRange(int x, int y) {
		if(x < 0 || y < 0 || x >= n || y >= n) return false;
		return true;
	}
	
	static void moveCloud(int dir, int s) {
		Deque<Point> tmp = new ArrayDeque<>();
		while(!cloud.isEmpty()) {
			Point cur = cloud.poll();
			cur.x = ((cur.x + (dx[dir] * s) % n) + n) % n;
			cur.y = ((cur.y + (dy[dir] * s) % n) + n) % n;
			tmp.add(cur);
		}
		cloud = tmp;
	}
	
	static void rainFromCloud() {
		isRained = new ArrayDeque<>();
		vis = new boolean[n][n];
		while(!cloud.isEmpty()) {
			Point cur = cloud.poll();
			++a[cur.x][cur.y];
			vis[cur.x][cur.y] = true;
			isRained.add(cur);
		}
	}
	
	static int[][] copy() {
		int[][] tmp = new int[n][n];
		for(int i = 0;i < n; ++i) {
			for(int j = 0;j < n; ++j) {
				tmp[i][j] = a[i][j];
			}
		}
		return tmp;
	}
	
	static void copyWaterBug() {
		int[][] copy = copy();
		while(!isRained.isEmpty()) {
			Point cur = isRained.poll();
			int cnt = 0;
			for(int dir = 1;dir < 8; dir+=2) {
				int nx = cur.x + dx[dir];
				int ny = cur.y + dy[dir];
				if(!inRange(nx ,ny)) continue;
				if(a[nx][ny] > 0) ++cnt;
			}
			copy[cur.x][cur.y] += cnt; 
		}
		for(int i = 0;i < n; ++i) {
			for(int j = 0;j < n; ++j) {
				a[i][j] = copy[i][j];
			}
		}
	}
	
	static void makeCloud() {
		cloud = new ArrayDeque<>();
		for(int i = 0;i < n; ++i) {
			for(int j = 0;j < n; ++j) {
				if(a[i][j] >= 2 && !vis[i][j]) {
					a[i][j] -= 2;
					cloud.add(new Point(i, j));
				}
			}
		}
	}
	
	static void move(int d, int s) {
		moveCloud(d, s);
		rainFromCloud();
		copyWaterBug();
		makeCloud();
	}
	
	static void getAnswer() {
		for(int i = 0;i < n;++i) {
			for(int j = 0;j < n; ++j) {
				answer += a[i][j];
			}
		}
	}
	
	static void init() {
		for(int i = n - 2; i < n; ++i) {
			for(int j = 0;j < 2; ++j) {
				cloud.add(new Point(i, j));
				vis[i][j] = true;
			}
		}
	}
	
	static void solution() throws IOException {
		init();
		for(int i = 0;i < m; ++i) {
			st = new StringTokenizer(br.readLine());
			int d = Integer.parseInt(st.nextToken()) - 1;
			int s = Integer.parseInt(st.nextToken());
			move(d, s);
		}
		getAnswer();
		System.out.println(answer);
	}
	
	public static void main(String[] args) throws IOException{
		input();
		solution();
	}
}
