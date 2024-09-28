import java.awt.Point;
import java.util.*;
import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static String s;
    static int n;
    static List<Point> list;
    static Set<String> answer;
    static boolean[] vis;

    static void input() throws IOException {
        s = br.readLine();
        n = s.length();
        list = new ArrayList<>();
        answer = new TreeSet<>();
        vis = new boolean[n];
    }

    static void rec(int idx) {
        if (idx == list.size()) {
            String insert = "";
            for (int i = 0; i < n; ++i) {
                if(vis[i]) continue;
                insert += s.charAt(i);
            }
            answer.add(insert);
            return;
        }
        rec(idx + 1);
        vis[list.get(idx).x] = true;
        vis[list.get(idx).y] = true;
        rec(idx + 1);
        vis[list.get(idx).x] = false;
        vis[list.get(idx).y] = false;
    }

    static void solution() {
        //괄호 쌍 맞춰주기
        Deque<Integer> q = new ArrayDeque<>();
        for (int i = 0; i < n; ++i) {
            char c = s.charAt(i);
            if (q.isEmpty() || c == '(') {
                q.addLast(i);
            } else if (c == ')') {
                list.add(new Point(q.pollLast(), i));
            }
        }
        rec(0);
        for (String ans : answer) {
            if(ans.equals(s)) continue;
            System.out.println(ans);
        }
    }

    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
