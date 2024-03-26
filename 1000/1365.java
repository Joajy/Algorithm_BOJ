import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    static int n;
    static int[] a;

    static void input() throws IOException {
        n = Integer.parseInt(br.readLine());
        a = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; ++i) {
            a[i] = Integer.parseInt(st.nextToken());
        }
    }

    static void solution() {
        Vector<Integer> list = new Vector<>();
        list.add(0);
        for (int i = 0; i < n; ++i) {
            int last = list.lastElement();
            if(a[i] > last){
                list.add(a[i]);
            }
            else{
                int idx = Collections.binarySearch(list, a[i]);
                if(idx < 0) idx = -idx - 1;
                list.set(idx, a[i]);
            }
        }
        System.out.println(n - (list.size() - 1));
    }

    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
