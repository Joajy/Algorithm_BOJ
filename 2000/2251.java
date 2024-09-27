import java.util.*;
import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static class Info {
        int a, b, c;
        Info(int a, int b, int c) {
            this.a = a;
            this.b = b;
            this.c = c;
        }
    }
    static int[] start;
    static boolean[][][] vis;
    static Set<Integer> answer;

    static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());
        start = new int[]{a, b, c};
        vis = new boolean[201][201][201];
        answer = new HashSet<>();
    }

    static void solution() {
        Deque<int[]> q = new ArrayDeque<>();
        q.add(new int[]{0, 0, start[2]});
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            if(vis[cur[0]][cur[1]][cur[2]]) continue;
            vis[cur[0]][cur[1]][cur[2]] = true;
            if(cur[0] == 0) {
                answer.add(cur[2]);
            }
            if(cur[0] + cur[1] > start[0]) {
                q.add(new int[]{start[0], cur[0] + cur[1] - start[0], cur[2]});
            } else {
                q.add(new int[]{cur[0] + cur[1], 0, cur[2]});
            }
            if(cur[0] + cur[1] > start[1]) {
                q.add(new int[]{cur[0] + cur[1] - start[1], start[1], cur[2]});
            } else {
                q.add(new int[]{0, cur[0] + cur[1], cur[2]});
            }

            if(cur[0] + cur[2] > start[0]) {
                q.add(new int[]{start[0], cur[1], cur[0] + cur[2] - start[0]});
            } else {
                q.add(new int[]{cur[0] + cur[2], cur[1], 0});
            }
            if(cur[0] + cur[2] > start[2]) {
                q.add(new int[]{cur[0] + cur[2] - start[2], cur[1], start[2]});
            } else {
                q.add(new int[]{0, cur[1], cur[0] + cur[2]});
            }

            if(cur[1] + cur[2] > start[1]) {
                q.add(new int[]{cur[0], start[1], cur[1] + cur[2] - start[1]});
            } else {
                q.add(new int[]{cur[0], cur[1] + cur[2], 0});
            }
            if(cur[1] + cur[2] > start[2]) {
                q.add(new int[]{cur[0], cur[1] + cur[2] - start[2], start[2]});
            } else {
                q.add(new int[]{cur[0], 0, cur[1] + cur[2]});
            }
        }
        List<Integer> ans = new ArrayList<>(answer);
        Collections.sort(ans);
        for (int i : ans) {
            System.out.print(i + " ");
        }
    }


    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
