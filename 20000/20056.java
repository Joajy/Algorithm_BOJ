import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n, m, k;
    static final int[] dx = {-1, -1, 0, 1, 1, 1, 0, -1};
    static final int[] dy = {0, 1, 1, 1, 0, -1, -1, -1};

    static class FireBall{
        int x, y, m, d, s;
        public FireBall(int x, int y, int m, int d, int s) {
            this.x = x;
            this.y = y;
            this.m = m;
            this.d = d;
            this.s = s;
        }
    }
    static List<FireBall>[][] a;
    static Deque<FireBall> fb = new ArrayDeque<>();

    static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        a = new ArrayList[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                a[i][j] = new ArrayList<>();
            }
        }
        int x, y, mm, d, s;
        for (int i = 0; i < m; ++i) {
            st = new StringTokenizer(br.readLine());
            x = Integer.parseInt(st.nextToken()) - 1;
            y = Integer.parseInt(st.nextToken()) - 1;
            mm = Integer.parseInt(st.nextToken());
            s = Integer.parseInt(st.nextToken());
            d = Integer.parseInt(st.nextToken());
            fb.add(new FireBall(x, y, mm, d, s));
        }
    }

    static void moveFireBall(){
        while (!fb.isEmpty()) {
            FireBall ball = fb.poll();
            ball.x = ((ball.x + (dx[ball.d] * ball.s) + n) % n + n) % n;
            ball.y = ((ball.y + (dy[ball.d] * ball.s) + n) % n + n) % n;
            a[ball.x][ball.y].add(ball);
        }
    }

    static void divideFireBalls(int x, int y) {
        int sumM = 0, sumS = 0;
        boolean odd = false, even = false;
        for (FireBall cur : a[x][y]) {
            sumM += cur.m;
            sumS += cur.s;
            if(cur.d % 2 == 0) even = true;
            else odd = true;
        }
        sumM /= 5;
        sumS /= a[x][y].size();
        if(sumM == 0) return;
        int dir = 0;
        if (odd && even) ++dir;
        for (; dir < 8; dir += 2) {
            fb.add(new FireBall(x, y, sumM, dir, sumS));
        }
    }

    static void process() {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if(a[i][j].isEmpty()) continue;
                if(a[i][j].size() == 1) fb.add(a[i][j].get(0));
                else divideFireBalls(i, j);
                a[i][j].clear();
            }
        }
    }

    static void solution(){
        for (int i = 0; i < k; ++i) {
            moveFireBall();
            process();
        }
        int answer = 0;
        while (!fb.isEmpty()) {
            FireBall cur = fb.poll();
            answer += cur.m;
        }
        System.out.println(answer);
    }

    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
