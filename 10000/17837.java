import java.awt.*;
import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    static int n, k, answer;
    static boolean gameEnd = false;
    static Deque<Integer>[][] a;
    static int[][] horses, color;
    static final int[] dx = {0, 0, 0, -1, 1};
    static final int[] dy = {0, 1, -1, 0, 0};

    static void input() throws IOException{
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        a = new Deque[n + 1][n + 1];
        color = new int[n + 1][n + 1];
        for(int i = 1;i <= n; ++i) {
            st = new StringTokenizer(br.readLine());
            for(int j = 1;j <= n; ++j) {
                a[i][j] = new ArrayDeque<>();
                color[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        horses = new int[k + 1][3];    //x, y, dir
        for(int i = 1;i <= k; ++i) {
            st = new StringTokenizer(br.readLine());
            horses[i][0] = Integer.parseInt(st.nextToken());
            horses[i][1] = Integer.parseInt(st.nextToken());
            horses[i][2] = Integer.parseInt(st.nextToken());
            a[horses[i][0]][horses[i][1]].add(i);
        }
    }

    static void white(Point cur, int start, int curDir) {
        int nx = cur.x + dx[curDir];
        int ny = cur.y + dy[curDir];
        Deque<Integer> q = new ArrayDeque<>();
        while(!a[cur.x][cur.y].isEmpty()) {
            int num = a[cur.x][cur.y].pollFirst();
            horses[num][0] = nx;
            horses[num][1] = ny;
            q.addFirst(num);
            if(num == start) break;
        }
        while(!q.isEmpty()) {
            int horse = q.pollFirst();
            a[nx][ny].addFirst(horse);
        }
        if(a[nx][ny].size() >= 4) gameEnd = true;
    }

    static void red(Point cur, int start, int curDir) {
        int nx = cur.x + dx[curDir];
        int ny = cur.y + dy[curDir];
        Deque<Integer> q = new ArrayDeque<>();
        while(!a[cur.x][cur.y].isEmpty()) {
            int num = a[cur.x][cur.y].pollFirst();
            horses[num][0] = nx;
            horses[num][1] = ny;
            q.addFirst(num);
            if(num == start) break;
        }
        while(!q.isEmpty()) {
            int horse = q.pollLast();
            a[nx][ny].addFirst(horse);
        }
        if(a[nx][ny].size() >= 4) gameEnd = true;
    }

    static int changeDir(int dir) {
        if(dir == 1) dir = 2;
        else if(dir == 2) dir = 1;
        else if(dir == 3) dir = 4;
        else dir = 3;
        return dir;
    }

    static void move(int start) {
        Point cur = new Point(horses[start][0], horses[start][1]);
        int curDir = horses[start][2];
        int nx = cur.x + dx[curDir];
        int ny = cur.y + dy[curDir];
        //1. 체스판을 벗어나는 경우 && 2. 파란색인 경우
        if(outRange(nx, ny) || color[nx][ny] == 2) {
            horses[start][2] = curDir = changeDir(curDir);
            nx = cur.x + dx[curDir];
            ny = cur.y + dy[curDir];
            if(outRange(nx, ny) || color[nx][ny] == 2) return;
            if(color[nx][ny] == 0) white(cur, start, curDir);
            else red(cur, start, curDir);
        }
        //3. 흰색인 경우
        else if(color[nx][ny] == 0) white(cur, start, curDir);
        //4. 빨간색인 경우
        else red(cur, start, curDir);
    }

    static boolean outRange(int x, int y) {
        if(x < 1 || y < 1 || x > n || y > n) return true;
        return false;
    }

    static void solution() throws IOException {
        for(int turn = 1; turn <= 1000; ++turn) {
            for(int i = 1;i <= k; ++i) {
                move(i);
                if(gameEnd) {
                    System.out.println(turn);
                    return;
                }
            }
        }
        System.out.println(-1);
    }

    public static void main(String[] args) throws IOException{
        input();
        solution();
    }
}
