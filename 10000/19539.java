import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n;
    static int[] trees;

    static void input() throws IOException {
        n = Integer.parseInt(br.readLine());
        trees = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; ++i) {
            trees[i] = Integer.parseInt(st.nextToken());
        }
    }

    static void solution() {
        int one = 0, two = 0;
        for (int tree : trees) {
            two += tree >> 1;
            one += tree % 2;
        }
        //2를 최대한 모았음에도, 1보다 적다면 당연히 불가하다.
        if(one > two) System.out.println("NO");
        //2의 갯수 - x == 2 * x + 1의 갯수
        //위의 공식이 성립해야만 동일 조건을 만족시킬 수 있다.
        else if((two - one) % 3 != 0) System.out.println("NO");
        else System.out.println("YES");
    }

    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
