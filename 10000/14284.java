import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int n, m;
	static class Edge{
		int v, cost;
		Edge(int v, int cost){
			this.v = v;
			this.cost = cost;
		}
	}
	static List<Edge>[] edge;
	static int[] dist;
	static int s, t;
	
	
    static void input() throws IOException {
		st = new StringTokenizer(br.readLine());
    	n = Integer.parseInt(st.nextToken());
    	m = Integer.parseInt(st.nextToken());
    	edge = new ArrayList[n + 1];
    	dist = new int[n + 1];
    	for(int i = 1;i <= n; ++i) {
    		edge[i] = new ArrayList<>();
    	}
    	for(int i = 0;i < m; ++i) {
    		st = new StringTokenizer(br.readLine());
    		int a = Integer.parseInt(st.nextToken());
    		int b = Integer.parseInt(st.nextToken());
    		int c = Integer.parseInt(st.nextToken());
    		edge[a].add(new Edge(b, c));
    		edge[b].add(new Edge(a, c));
    	}
		st = new StringTokenizer(br.readLine());
		s = Integer.parseInt(st.nextToken());
		t = Integer.parseInt(st.nextToken());
    }
    
    static void solution() {
    	Arrays.fill(dist, (int)1e9);
    	dist[s] = 0;
    	Deque<Edge> q = new ArrayDeque<>();
    	q.add(new Edge(s, 0));
    	while(!q.isEmpty()) {
    		Edge cur = q.poll();
    		for(Edge nxt : edge[cur.v]) {
    			int nxtDist = dist[cur.v] + nxt.cost;
    			if(dist[nxt.v] <= nxtDist) continue;
    			dist[nxt.v] = nxtDist;
    			q.add(new Edge(nxt.v, nxtDist));
    		}
    	}
    	System.out.println(dist[t]);
    }
    
    public static void main(String[] args) throws IOException {
   		input();
   		solution();
    }
}
