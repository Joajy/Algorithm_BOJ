import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    static int n, m, v;
    static int[][] list;
    static boolean[] vis;

    static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        v = Integer.parseInt(st.nextToken());
        list = new int[n + 1][n + 1];
        for(int i = 0;i < m; ++i){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            list[a][b] = list[b][a] = 1;
        }
    }

    static void bfs(){
        Queue<Integer> q = new ArrayDeque<>();
        vis = new boolean[n + 1];
        q.add(v);
        vis[v] = true;
        while (!q.isEmpty()) {
            int cur = q.poll();
            sb.append(cur).append(" ");
            for (int i = 1; i <= n; ++i) {
                if(list[cur][i] == 0 || vis[i]) continue;
                q.add(i);
                vis[i] = true;
            }
        }
    }

    static void dfs(int cur){
        vis[cur] = true;
        sb.append(cur).append(" ");
        for (int i = 1; i <= n; ++i) {
            if(list[cur][i] == 0 || vis[i]) continue;
            vis[i] = true;
            dfs(i);
        }
    }

    static void solution() {
        vis = new boolean[n + 1];
        dfs(v);
        sb.append("\n");
        bfs();
        System.out.println(sb);
    }

    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
