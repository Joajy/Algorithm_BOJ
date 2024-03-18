import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n, k;
    static long l, r, answer = 0;
    static int[] line;

    static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        k = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());
        line = new int[k];
        l = 1;
        for (int i = 0; i < k; ++i) {
            line[i] = Integer.parseInt(br.readLine());
            if(line[i] > r) r = line[i];
        }
    }

    static int getMaxLength(long len) {
        int cnt = 0;
        for (int i = 0; i < k; ++i) {
            cnt += line[i] / len;
        }
        return cnt;
    }

    static void binarySearch() {
        while (l <= r) {
            long mid = (l + r) >> 1;
            int cnt = getMaxLength(mid);
            if (cnt < n) {
                r = mid - 1;
            }
            else{
                answer = mid;
                l = mid + 1;
            }
        }
    }

    static void solution() {
        Arrays.sort(line);
        binarySearch();
        System.out.println(answer);
    }

    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
