import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int n, m, answer;
	static char[][] area;
	static int[][] fire, path;
	static class Info{
		int x, y;
		Info(int x, int y){
			this.x = x;
			this.y = y;
		}
	}
	static Info init;
	static List<Info> fires;
	static final int[] dx = {0, 1, 0, -1};
	static final int[] dy = {1, 0, -1, 0};
	
    static void input() throws IOException {
		st = new StringTokenizer(br.readLine());
    	n = Integer.parseInt(st.nextToken());
    	m = Integer.parseInt(st.nextToken());
    	fires = new ArrayList<>();
    	area = new char[n][m];
    	fire = new int[n][m];
    	path = new int[n][m];
    	for(int i = 0;i < n; ++i) {
    		String tmp =br.readLine();
    		for(int j = 0;j < m; ++j) {
    			area[i][j] = tmp.charAt(j);
    			if(area[i][j] == 'J') init = new Info(i, j);
    			else if(area[i][j] == 'F') fires.add(new Info(i, j));
    		}
    	}
    	answer = (int)1e9;
    }
    
    static boolean range(int x, int y){
    	return x >= 0 && y >= 0 && x < n && y < m;
    }
    
    static void spread() {
    	Deque<Info> q = new ArrayDeque<>();
    	for(int i = 0;i < n; ++i) {
    		Arrays.fill(fire[i], (int)1e9);
    	}
    	for(Info info : fires) {
    		q.add(info);
    		fire[info.x][info.y] = 0; 
    	}
    	while(!q.isEmpty()) {
    		Info cur = q.poll();
    		for(int dir = 0;dir < 4; ++dir) {
    			int nx = cur.x + dx[dir];
    			int ny = cur.y + dy[dir];
    			if(!range(nx, ny) || area[nx][ny] == '#') continue;
    			if(fire[nx][ny] <= fire[cur.x][cur.y] + 1) continue;
    			fire[nx][ny] = fire[cur.x][cur.y] + 1; 
    			q.add(new Info(nx, ny));
    		}
    	}
    }
    
    static void escape() {
    	Deque<Info> q = new ArrayDeque<>();
    	for(int i = 0;i < n; ++i) {
    		Arrays.fill(path[i], (int)1e9);
    	}
    	q.add(init);
    	path[init.x][init.y] = 0; 
    	while(!q.isEmpty()) {
    		Info cur = q.poll();
    		for(int dir = 0;dir < 4; ++dir) {
    			int nx = cur.x + dx[dir];
    			int ny = cur.y + dy[dir];
    			if(!range(nx, ny)) {
    				answer = path[cur.x][cur.y] + 1;
    				return;
    			}
    			if(area[nx][ny] == '#') continue;
    			if(fire[nx][ny] <= path[cur.x][cur.y] + 1) continue;
    			if(path[nx][ny] <= path[cur.x][cur.y] + 1) continue;
    			path[nx][ny] = path[cur.x][cur.y] + 1; 
    			q.add(new Info(nx, ny));
    		}
    	}
    }
    
    static void solution() {
    	spread();
    	escape();
    	if(answer != (int)1e9) System.out.println(answer);
    	else System.out.println("IMPOSSIBLE");
    }
    
    public static void main(String[] args) throws IOException {
   		input();
   		solution();
    }
}
