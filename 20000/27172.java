import java.util.*;
import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static StringTokenizer st;
    static int n;
    static int[] a, sieve;
    static boolean[] vis;
    static final int MAX = 1000000;

    static void input() throws IOException {
        n = Integer.parseInt(br.readLine());
        a = new int[n];
        sieve = new int[MAX + 1];
        vis = new boolean[MAX + 1];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; ++i) {
            a[i] = Integer.parseInt(st.nextToken());
            vis[a[i]] = true;
        }
    }
    
    static void sieve(int x){
        for (int i = (x << 1); i <= MAX; i += x) {
            if(!vis[i]) continue;
            --sieve[i];
            ++sieve[x];
        }
    }

    static void solution() {
        for (int i = 0; i < n; ++i) {
            sieve(a[i]);
        }
        for (int i = 0; i < n; ++i) {
            sb.append(sieve[a[i]]).append(' ');
        }
        sb.trimToSize();
        System.out.println(sb);
    }

    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
