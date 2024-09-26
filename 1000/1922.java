import java.util.*;
import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static StringTokenizer st;
    static int n, m;

    static class Info {
        int v, cost;
        public Info(int v, int cost) {
            this.v = v;
            this.cost = cost;
        }
    }
    static List<Info>[] connection;
    static boolean[] vis;

    static void input() throws IOException {
        n = Integer.parseInt(br.readLine());
        m = Integer.parseInt(br.readLine());
        connection = new ArrayList[n + 1];
        vis = new boolean[n + 1];
        for (int i = 1; i <= n; ++i) {
            connection[i] = new ArrayList<>();
        }
        for (int i = 0; i < m; ++i) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            connection[a].add(new Info(b, c));
            connection[b].add(new Info(a, c));
        }
    }

    static void solution() {
        PriorityQueue<Info> pq = new PriorityQueue<>((o1, o2) -> {
            return Integer.compare(o1.cost, o2.cost);
        });
        pq.add(new Info(1, 0));
        int answer = 0;
        while(!pq.isEmpty()) {
            Info cur = pq.poll();
            if(vis[cur.v]) continue;
            vis[cur.v] = true;
            answer += cur.cost;
            for(Info next : connection[cur.v]) {
                if(vis[next.v]) continue;
                pq.add(next);
            }
        }
        System.out.println(answer);
    }

    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
