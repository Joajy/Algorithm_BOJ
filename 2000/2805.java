import java.util.*;
import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n, m;
    static long answer = 0;
    static int[] tree;

    static void solution() {
        Arrays.sort(tree);
        long l = 0, r = (long)1e9;
        while (l <= r) {
            long mid = (l + r) >> 1;
            if (getAnswer(mid)) {
                l = mid + 1;
            } else{
                r = mid - 1;
            }
        }
        System.out.println(answer);
    }

    static boolean getAnswer(long mid) {
        long sum = 0;
        for (int i = 0; i < n; ++i) {
            if(tree[i] < mid) continue;
            sum += (tree[i] - mid);
        }
        if(sum >= m){
            answer = Math.max(answer, mid);
            return true;
        }
        return false;
    }

    static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        tree = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; ++i) {
            tree[i] = Integer.parseInt(st.nextToken());
        }
    }

    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
