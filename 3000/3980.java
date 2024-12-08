import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static StringTokenizer st;
    static int answer;
    static int[][] area;
    static boolean[] vis;

    static void input() throws IOException {
        area = new int[11][11];
        vis = new boolean[11];
        for (int i = 0; i < 11; ++i) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 11; ++j) {
                area[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        answer = 0;
    }

    static void backTracking(int index, int sum) {
        if(index == 11) {
            answer = Math.max(answer, sum);
            return;
        }
        for (int i = 0; i < 11; ++i) {
            if(vis[i] || area[index][i] == 0) continue;
            vis[i] = true;
            backTracking(index + 1, sum + area[index][i]);
            vis[i] = false;
        }
    }

    static void solution() {
        backTracking(0, 0);
        sb.append(answer).append('\n');
    }

    public static void main(String[] args) throws IOException {
        int t = Integer.parseInt(br.readLine());
        for(int testCase = 1; testCase <= t; ++testCase) {
            input();
            solution();
        }
        System.out.println(sb);
    }
}
