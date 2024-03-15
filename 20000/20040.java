import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n, m;
    static int[] par;

    static void input() throws IOException{
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        par = new int[n];
        for (int i = 0; i < n; ++i) {
            par[i] = i;
        }
    }

    static int find(int cur) {
        if(par[cur] == cur) return cur;
        return par[cur] = find(par[cur]);
    }

    static boolean union(int a, int b) {
        a = find(a);
        b = find(b);
        if(a == b) return false;
        par[a] = b;
        return true;
    }

    static void solution() throws IOException {
        for(int i = 1;i <= m; ++i) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            if(!union(a, b)){
                System.out.println(i);
                return;
            }
        }
        System.out.println(0);
    }

    public static void main(String[] args) throws IOException{
        input();
        solution();
    }
}
