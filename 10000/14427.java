import java.util.*;
import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static int n, m;
    static int[] a;
    static boolean[] vis;
    static class Info{
        int index, value;

        Info(int index, int value) {
            this.index = index;
            this.value = value;
        }
    }
    static PriorityQueue<Info> pq;

    public static void main(String[] args) throws IOException{
        pq = new PriorityQueue<>((o1, o2) -> {
            if(o1.value == o2.value) {
                return o1.index - o2.index;
            }
            return o1.value - o2.value;
        });
        n = Integer.parseInt(br.readLine());
        a = new int[n + 1];
        vis = new boolean[n + 1];
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; ++i) {
            a[i] = Integer.parseInt(st.nextToken());
            pq.add(new Info(i, a[i]));
        }
        m = Integer.parseInt(br.readLine());
        for (int i = 0; i < m; ++i) {
            st = new StringTokenizer(br.readLine());
            int q = Integer.parseInt(st.nextToken());
            if(q == 1) {
                int idx = Integer.parseInt(st.nextToken());
                int v = Integer.parseInt(st.nextToken());
                a[idx] = v;
                pq.add(new Info(idx, v));
            } else {
                while (!pq.isEmpty()) {
                    Info info = pq.poll();
                    if(a[info.index] == info.value) {
                        sb.append(info.index).append('\n');
                        pq.add(info);
                        break;
                    }
                }
            }
        }
        System.out.println(sb);
    }
}
