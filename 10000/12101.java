import java.io.*;
import java.util.*;
//08-22 10:30
public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n, k;
    static String answer;

    static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
    }

    static void calculate(int sum, String formula) {
        if(sum == n) {
            if(--k == 0) {
                answer = formula.substring(0, formula.length() - 1);
            }
            return;
        }
        if(sum > n) return;
        for (int i = 1; i <= 3; ++i) {
            calculate(sum + i, formula + i + "+");
        }
    }

    static void solution() {
        calculate(0, "");
        if(k > 0) answer = "-1";
        System.out.println(answer);
    }

    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
