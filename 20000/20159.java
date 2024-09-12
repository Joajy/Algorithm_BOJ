import java.util.*;
import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n;
    static int[] even, odd, a;

    static void input()  throws IOException{
        n = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        even = new int[n];
        odd = new int[n];
        a = new int[n];
        for(int i = 0;i < n; ++i) {
            a[i] = Integer.parseInt(st.nextToken());
            if(i % 2 == 0){
                if(i == 0) even[i] = a[i];
                else even[i] += even[i - 2] + a[i];
            }
            else {
                if(i == 1) odd[i] = a[i];
                else odd[i] = odd[i - 2] + a[i];
            }
        }
    }

    static void solution() {
        int answer = Math.max(even[n - 2], odd[n - 1]);
        for (int i = 2; i < n; ++i) {
            if(i % 2 == 0) answer = Math.max(answer, even[i - 2] + odd[n - 1] - odd[i - 1]);
            else answer = Math.max(answer, even[i - 1] + odd[n - 3] - odd[i - 2]);
        }
        System.out.println(answer);
    }

    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
