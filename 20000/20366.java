//solution 1

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    static int n;
    static int[] h;

    static void input() throws IOException {
        n = Integer.parseInt(br.readLine());
        h = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; ++i) {
            h[i] = Integer.parseInt(st.nextToken());
        }
    }

    static void solution(){
        Arrays.sort(h);
        int answer = 2147483647;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int s = 0;
                int e = n - 1;
                int lSum = h[i] + h[j];
                while (s < e) {
                    if(s == i || s == j){
                        ++s;
                        continue;
                    } else if (e == i || e == j) {
                        --e;
                        continue;
                    }
                    int rSum = h[s] + h[e];
                    int diff = Math.abs(rSum - lSum);
                    answer = Math.min(answer, diff);
                    if (lSum == rSum) {
                        System.out.println(0);
                        return;
                    } else if (lSum < rSum) {
                        --e;
                    } else{
                        ++s;
                    }
                }
            }
        }
        System.out.println(answer);
    }

    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}


//solution 2
import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    static int n;
    static int[] h;

    static class Snowman {
        int a, b;
        int sum;
        Snowman(int a, int b){
            this.a = a;
            this.b = b;
            sum = h[a] + h[b];
        }
    }

    static void input() throws IOException {
        n = Integer.parseInt(br.readLine());
        h = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; ++i) {
            h[i] = Integer.parseInt(st.nextToken());
        }
    }

    static boolean isDuplicated(Snowman s1, Snowman s2) {
        return s1.a == s2.a || s1.a == s2.b || s1.b == s2.a || s1.b == s2.b;
    }

    static void solution(){
        int answer = 2147483647;
        List<Snowman> list = new ArrayList<>();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                Snowman snowman = new Snowman(i, j);
                list.add(snowman);
            }
        }
        Collections.sort(list, new Comparator<Snowman>() {
            @Override
            public int compare(Snowman o1, Snowman o2) {
                return Integer.compare(o1.sum, o2.sum);
            }
        });
        for (int i = 0; i < list.size() - 1; ++i) {
            Snowman s1 = list.get(i);
            Snowman s2 = list.get(i + 1);
            int diff = s2.sum - s1.sum;
            if(diff >= answer) continue;
            if(isDuplicated(s1, s2)) continue;
            answer = diff;
        }
        System.out.println(answer);
    }

    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
