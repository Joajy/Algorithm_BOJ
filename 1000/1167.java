import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static int n, answer = 0, node = 1;
    static boolean[] vis;

    static class Edge {
        int v, cost;

        Edge(int v, int cost) {
            this.v = v;
            this.cost = cost;
        }
    }
    static List<Edge>[] edge;

    static void input() throws IOException {
        n = Integer.parseInt(br.readLine());
        edge = new ArrayList[n + 1];
        vis = new boolean[n + 1];
        for (int i = 1; i <= n; ++i) {
            edge[i] = new ArrayList<>();
        }
        for (int i = 1; i <= n; ++i) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int idx = Integer.parseInt(st.nextToken());
            while(true){
                int nxt = Integer.parseInt(st.nextToken());
                if(nxt == -1) break;
                int cost = Integer.parseInt(st.nextToken());
                edge[idx].add(new Edge(nxt, cost));
            }
        }
    }

    static void dfs(int start, int sum){
        if (answer < sum) {
            node = start;
            answer = sum;
        }
        vis[start] = true;
        for (Edge nxt : edge[start]) {
            if(vis[nxt.v]) continue;
            dfs(nxt.v, sum + nxt.cost);
        }
    }

    static void solution(){
        vis = new boolean[n + 1];
        dfs(1, 0);

        vis = new boolean[n + 1];
        dfs(node, 0);

        System.out.println(answer);
    }

    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
