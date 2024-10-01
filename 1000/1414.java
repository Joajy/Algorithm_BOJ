import java.util.*;
import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static StringTokenizer st;
    static int n, answer;
    static int[][] lines;
    static class Info {
        int v, cost;
        Info(int v, int cost) {
            this.v = v;
            this.cost = cost;
        }
    }
    static List<Info>[] bridges;

    static void input() throws IOException {
        n = Integer.parseInt(br.readLine());
        lines = new int[n + 1][n + 1];
        bridges = new ArrayList[n + 1];
        for (int i = 1; i <= n; ++i) {
            bridges[i] = new ArrayList<>();
        }
        answer = 0;
        for (int i = 1; i <= n; ++i) {
            String s = br.readLine();
            for (int j = 1; j <= n; ++j) {
                lines[i][j] = converter(s.charAt(j - 1));
                if(lines[i][j] == 0) continue;
                answer += lines[i][j];
                if(i == j) continue;
                bridges[i].add(new Info(j, lines[i][j]));
                bridges[j].add(new Info(i, lines[i][j]));
            }
        }
    }

    static int prim(int start) {
        PriorityQueue<Info> q = new PriorityQueue<>((o1, o2) -> {
            return o1.cost - o2.cost;
        });
        q.add(new Info(start, 0));
        boolean[] vis = new boolean[n + 1];
        int value = 0;
        while (!q.isEmpty()) {
            Info cur = q.poll();
            if(vis[cur.v]) continue;
            vis[cur.v] = true;
            value += cur.cost;
            for (Info nxt : bridges[cur.v]) {
                if(vis[nxt.v]) continue;
                q.add(nxt);
            }
        }
        for (int i = 1; i <= n; ++i) {
            if(!vis[i]) {
                return -1;
            }
        }
        return value;
    }

    static void solution() {
        int del = (int)1e9;
        for (int i = 1; i <= n; ++i) {
            del = Math.min(del, prim(i));
        }
        if(del == -1) System.out.println(-1);
        else System.out.println(answer - del);
    }

    static int converter(char c) {
        if(c >= 'a' && c <= 'z') return c - 'a' + 1;
        else if(c >= 'A' && c <= 'Z') return c - 'A' + 27;
        return 0;
    }

    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
