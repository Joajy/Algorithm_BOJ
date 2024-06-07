import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;
    static int n, m;
    static class Edge{
    	int v, cost;
    	Edge(int v, int cost){
    		this.v = v;
    		this.cost = cost;
    	}
    }
    static List<Edge>[] edges;
    static int first, last;
    static int[] dist;

    static void input() throws IOException {
		n = Integer.parseInt(br.readLine());
		m = Integer.parseInt(br.readLine());
		edges = new ArrayList[n + 1];
		dist = new int[n + 1];
		for(int i = 1;i <= n; ++i) {
			edges[i] = new ArrayList<>();
			dist[i] = (int)1e9;
		}
		for(int i = 0;i < m; ++i) {
			st = new StringTokenizer(br.readLine());
			int start = Integer.parseInt(st.nextToken());
			int end = Integer.parseInt(st.nextToken());
			int cost = Integer.parseInt(st.nextToken());
			edges[start].add(new Edge(end, cost));
		}
		st = new StringTokenizer(br.readLine());
		first = Integer.parseInt(st.nextToken());
		last = Integer.parseInt(st.nextToken());
    }
    
    static void solution() {
    	PriorityQueue<Edge> q = new PriorityQueue<>(new Comparator<Edge>() {
			@Override
			public int compare(Edge o1, Edge o2) {
				return o1.cost - o2.cost;
			}
		});
    	q.add(new Edge(first, 0));
    	dist[first] = 0;
    	while(!q.isEmpty()) {
    		Edge edge = q.poll();
    		if(dist[edge.v] < edge.cost) continue;
    		for(Edge nxt : edges[edge.v]) {
    			if(dist[nxt.v] <= dist[edge.v] + nxt.cost) continue;
    			dist[nxt.v] = dist[edge.v] + nxt.cost;
    			q.add(new Edge(nxt.v, dist[nxt.v]));
    		}
    	}
    	System.out.println(dist[last]);
    }
    
    public static void main(String[] args) throws IOException {
   		input();
   		solution();
    }
}
