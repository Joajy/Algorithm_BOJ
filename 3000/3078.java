import java.util.*;
import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    static int n, k;

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        long answer = 0;
        int[] len = new int[21];

        Deque<String> q = new ArrayDeque<>();
        String friend = br.readLine();
        q.add(friend);
        ++len[friend.length()];
        for (int i = 1; i < n; ++i) {
            friend = br.readLine();
            //k만큼 차 있을 경우 하나 빼고, 새로운 걸 담을 수 있도록 조성
            if (q.size() == k + 1) {
                --len[q.pollFirst().length()];
            }
            q.add(friend);
            ++len[friend.length()];
            answer += len[friend.length()] - 1;
        }
        System.out.println(answer);
    }
}
