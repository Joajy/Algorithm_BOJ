import java.util.*;
import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int len, n, l, r, answer;
    static int[] a;

    static void input() throws IOException {
        len = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        l = Integer.parseInt(st.nextToken());
        r = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(br.readLine());
        a = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = Integer.parseInt(br.readLine());
        }
        answer = (int)1e9;
    }

    static void rec(int index, int cnt, int left, int right) {
        if (index == n) {
            if(answer > cnt) answer = cnt;
            return;
        }
        //가만히 있어도 되는 경우
        if(a[index] == left || a[index] == right) rec(index + 1, cnt, left, right);
        //1. 가장 왼쪽에 있는 경우
        if(left > a[index]) rec(index + 1, cnt + (left - a[index]), a[index], right);
        //2. 중간에 있는 경우
        if(a[index] > left) rec(index + 1, cnt + (a[index] - left), a[index], right);
        if(right > a[index]) rec(index + 1, cnt + (right - a[index]), left, a[index]);
        //3. 가장 오른쪽에 있는 경우
        if(right < a[index]) rec(index + 1, cnt + (a[index] - right), left, a[index]);
    }

    static void solution() {
        rec(0, 0, l, r);
        System.out.println(answer);
    }

    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
