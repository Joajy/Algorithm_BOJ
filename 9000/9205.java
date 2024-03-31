import java.awt.Point;
import java.io.*;
import java.util.*;

public class Main {
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	static int n, answer;
	static Point[] conv;
	static Point src, dst;
	
	static void input() throws IOException{
		n = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());
		src = new Point(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
		conv = new Point[n];
		for(int i = 0;i < n; ++i) {
			st = new StringTokenizer(br.readLine());
			conv[i] = new Point(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
		}
		st = new StringTokenizer(br.readLine());
		dst = new Point(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
	}
	
	static int getDistance(Point a, Point b) {
		return Math.abs(a.x - b.x) + Math.abs(a.y - b.y);
	}
	
	static boolean solution() {
		Deque<Point> q = new ArrayDeque<>();
		q.add(src);
		boolean[] vis = new boolean[n];
		while(!q.isEmpty()) {
			Point cur = q.poll();
			int dist = getDistance(cur, dst);
			if(dist <= 1000) return true;
			for(int i = 0;i < n; ++i) {
				if(vis[i]) continue;
				dist = getDistance(cur, conv[i]);
				if(dist > 1000) continue;
				vis[i] = true;
				q.add(conv[i]);
			}
		}
		return false;
	}
	
	public static void main(String[] args) throws IOException{
		int t = Integer.parseInt(br.readLine());
		for(int i = 1;i <= t; ++i) {
			input();
			if(solution()) sb.append("happy\n");
			else sb.append("sad\n");
		}
		System.out.println(sb);
	}
}
