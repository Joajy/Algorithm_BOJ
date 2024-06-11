import java.util.*;
import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static int n;
    static int[] a;
    static boolean[] vis;
    static Set<Integer> set = new TreeSet<>();

    static void input() throws IOException {
        n = Integer.parseInt(br.readLine());
        a = new int[n + 1];
        for (int i = 1; i <= n; ++i) {
            a[i] = Integer.parseInt(br.readLine());
        }
    }

    static void dfs(int start) {
        Deque<Integer> q = new ArrayDeque<>();
        q.add(start);
        vis[start] = true;
        List<Integer> list = new ArrayList<>();
        while (!q.isEmpty()) {
            int cur = q.poll();
            int nxt = a[cur];
            list.add(cur);
            //처음으로 돌아온다. 즉 위 아래가 가지는 집합이 동일
            if(nxt == start){
                set.addAll(list);
                return;
            }
            if(vis[nxt]) continue;
            vis[nxt] = true;
            q.add(nxt);
        }
    }

    static void solution() {
        for (int i = 1; i <= n; ++i) {
            vis = new boolean[n + 1];
            if(a[i] == i) {
                set.add(i);
                continue;
            }
            dfs(i);
        }
        sb.append(set.size()).append('\n');
        for (int i : set) {
            sb.append(i).append('\n');
        }
        sb.trimToSize();
        System.out.println(sb);
    }

    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
