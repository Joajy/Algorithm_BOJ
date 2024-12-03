import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int n;
    static int[][] area;

    static void input() throws IOException {
        n = Integer.parseInt(br.readLine());
        area = new int[10][n];
    }

    static void solution() {
        if(n == 1) {
            System.out.println(10);
            return;
        }
        for (int index = 0; index <= 9; ++index) {
            area[index][0] = index + 1;
        }
        for (int index = 1; index < n; ++index) {
            area[0][index] = 1;
            for (int adder = 1; adder <= 9; ++adder) {
                area[adder][index] += (area[adder - 1][index] + area[adder][index - 1]) % 10007;
            }
        }
        System.out.println(area[9][n - 1]);
    }

    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
