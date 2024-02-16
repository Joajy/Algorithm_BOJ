import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int h, w, maxH = 0;
    static int[] a;

    static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        h = Integer.parseInt(st.nextToken());
        w = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        a = new int[w];
        for (int i = 0; i < w; ++i) {
            a[i] = Integer.parseInt(st.nextToken());
            if(maxH < a[i]) maxH = a[i];
        }
    }

    static void solution() {
        int answer = 0;
        for (int i = 0; i <= maxH; ++i) {
            int idx = 0;
            for (int j = 0; j < w; ++j) {
                if (a[j] >= i) {
                    idx = j;
                    break;
                }
            }
            for (int j = idx + 1; j < w; ++j) {
                if (a[j] >= i) {
                    answer +=j - idx - 1;
                    idx = j;
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
