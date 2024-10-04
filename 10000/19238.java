import java.awt.Point;
import java.util.*;
import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static StringTokenizer st;
    static int n, m, fuel, minDist;
    static int[][] area;
    static class User {
        int srcX, srcY, dstX, dstY;
        boolean end;
        User(int srcX, int srcY, int dstX, int dstY) {
            this.srcX = srcX;
            this.srcY = srcY;
            this.dstX = dstX;
            this.dstY = dstY;
            end = false;
        }
    }
    static User[] users;
    static Point taxi;
    static final int[] dx = {-1, 0, 1, 0};
    static final int[] dy = {0, -1, 0, 1};

    static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        fuel = Integer.parseInt(st.nextToken());
        area = new int[n + 1][n + 1];
        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= n; j++) {
                area[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        st = new StringTokenizer(br.readLine());
        taxi = new Point(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        users = new User[m + 1];
        for(int i = 1; i <= m; ++i) {
            st = new StringTokenizer(br.readLine());
            int srcX = Integer.parseInt(st.nextToken());
            int srcY = Integer.parseInt(st.nextToken());
            int dstX = Integer.parseInt(st.nextToken());
            int dstY = Integer.parseInt(st.nextToken());
            users[i] = new User(srcX, srcY, dstX, dstY);
        }
    }

    static User findTarget() {
        User target = null;
        minDist = Integer.MAX_VALUE;
        List<User> targets = new ArrayList<>();
        for (int i = 1; i <= m; ++i) {
            //이미 내린 손님은 제외하고 타겟을 찾는다
            if(users[i].end) continue;
            int dist = getDist(users[i]);
            if(dist == -1) continue;
            if(dist <= minDist) {
                if(dist < minDist) targets.clear();
                targets.add(users[i]);
                minDist = dist;
            }
        }
        for (User user : targets) {
            if(target == null) target = user;
            else {
                if (target.srcX == user.srcX) {
                    if(target.srcY > user.srcY) {
                        target = user;
                    }
                } else if(target.srcX > user.srcX) {
                    target = user;
                }
            }
        }
        return target;
    }

    static boolean move(User user) {
        //택시 위치 유저의 목적지로 옮기고, 이동 거리 fuel과 대입해서 강제 종료 여부 확인
        if(fuel - minDist < 0) return false;
        Deque<Point> q = new ArrayDeque<>();
        q.add(new Point(user.srcX, user.srcY));
        int[][] vis = new int[n + 1][n + 1];
        for (int i = 1; i <= n; ++i) {
            Arrays.fill(vis[i], (int)1e9);
        }
        vis[user.srcX][user.srcY] = 0;
        while (!q.isEmpty()) {
            Point cur = q.poll();
            if(cur.x == user.dstX && cur.y == user.dstY) {
                user.end = true;
                taxi.x = cur.x; taxi.y = cur.y;
                fuel -= minDist + vis[cur.x][cur.y];
                if(fuel < 0) return false;
                fuel += vis[cur.x][cur.y] << 1;
                return true;
            }
            for (int dir = 0; dir < 4; ++dir) {
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];
                if(!range(nx, ny) || vis[nx][ny] <= vis[cur.x][cur.y] + 1) continue;
                if(area[nx][ny] == 1) continue;
                vis[nx][ny] = vis[cur.x][cur.y] + 1;
                q.add(new Point(nx, ny));
            }
        }
        return false;
    }

    static void solution() {
        for (int i = 1; i <= m; ++i) {
            //최적 타겟 찾기
            User target = findTarget();
            //만약 길에 가로막혔다면 -1 반환 후 종료
            //타겟까지 위치 이동
            //연료가 바닥났는지 확인 (fuel < 0) 후 조건대로 2배 채워준다
            if(target == null || !move(target)) {
                System.out.println(-1);
                return;
            }
        }
        System.out.println(fuel);
    }

    static int getDist(User user) {
        Deque<Point> q = new ArrayDeque<>();
        q.add(new Point(taxi.x, taxi.y));
        int[][] vis = new int[n + 1][n + 1];
        for (int i = 1; i <= n; ++i) {
            Arrays.fill(vis[i], (int)1e9);
        }
        vis[taxi.x][taxi.y] = 0;
        while (!q.isEmpty()) {
            Point cur = q.poll();
            if(cur.x == user.srcX && cur.y == user.srcY) {
                return vis[cur.x][cur.y];
            }
            for (int dir = 0; dir < 4; ++dir) {
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];
                if(!range(nx, ny) || vis[nx][ny] <= vis[cur.x][cur.y] + 1) continue;
                if(area[nx][ny] == 1) continue;
                vis[nx][ny] = vis[cur.x][cur.y] + 1;
                q.add(new Point(nx, ny));
            }
        }
        return -1;
    }

    static boolean range(int x, int y) {
        return x >= 1 && x <= n && y >= 1 && y <= n;
    }

    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
