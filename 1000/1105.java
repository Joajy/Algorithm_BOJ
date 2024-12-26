import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static String L, R;

    static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        L = st.nextToken();
        R = st.nextToken();
    }

    static void solution() {
        if(L.length() != R.length()) {
            System.out.println(0);
            return;
        }
        int answer = 0;
        for (int i = 0; i < L.length(); ++i) {
            if (L.charAt(i) == '8' && R.charAt(i) == '8') {
                ++answer;
            } else if(L.charAt(i) == R.charAt(i)){
                continue;
            } else {
                break;
            }
        }
        System.out.println(answer);
    }

    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
