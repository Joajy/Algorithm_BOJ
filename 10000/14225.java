import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n;
    static int[] s;
    static boolean[] exists;
    static final int MAX = 2_000_000;

    static void input() throws IOException {
        n = Integer.parseInt(br.readLine());
        s = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; ++i) {
            s[i] = Integer.parseInt(st.nextToken());
        }
        exists = new boolean[MAX + 1];
    }

    static void solution() {
        Arrays.sort(s);
        exists[0] = true;
        for (int i = 0; i < n; ++i) {
            for (int start = MAX; start >= s[i]; --start) {
                if(!exists[start - s[i]]) continue;
                exists[start] = true;
            }
        }
        for (int i = 1; i <= MAX; ++i) {
            if(exists[i]) continue;
            System.out.println(i);
            return;
        }
    }

    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
