import java.util.*;
import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    static int n, m, answer = 0;
    static List<Integer> up, down;

    static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        up = new ArrayList<>();
        down = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            int num = Integer.parseInt(st.nextToken());
            if (num < 0) down.add(-num);
            else up.add(num);
        }
        Collections.sort(up, Collections.reverseOrder());
        Collections.sort(down, Collections.reverseOrder());
    }

    static void solution() {
        int left = Integer.MIN_VALUE, right = Integer.MIN_VALUE;
        if(!down.isEmpty()) left = Math.abs(down.get(0));
        if(!up.isEmpty()) right = Math.abs(up.get(0));
        if (left > right) {
            calculate(up, down);
        } else {
            calculate(down, up);
        }
        System.out.println(answer);
    }

    static void calculate(List<Integer> first, List<Integer> next) {
        for (int i = 0; i < first.size(); ++i) {
            if(i % m != 0) continue;
            answer += first.get(i) << 1;
        }
        for (int i = 0; i < next.size(); ++i) {
            if(i % m != 0) continue;
            if(i == 0) answer += next.get(i);
            else answer += next.get(i) << 1;
        }
    }

    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
