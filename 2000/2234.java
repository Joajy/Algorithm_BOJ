import java.awt.Point;
import java.util.*;
import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static StringTokenizer st;
    static int n, m;
    static int[][] area, team;
    static final int[] dx = {0, 1, 0, -1};
    static final int[] dy = {1, 0, -1, 0};

    static class Room {
        int number;
        List<Point> points;
        List<Integer> adj;
        Room(int number) {
            this.number = number;
            points = new ArrayList<>();
            adj = new ArrayList<>();
        }
    }
    static List<Room> rooms;

    static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        m = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());
        area = new int[n + 1][m + 1];
        team = new int[n + 1][m + 1];
        for(int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j = 1; j <= m; j++) {
                area[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        rooms = new ArrayList<>();
    }

    static void search() {
        int number = 0;
        boolean[][] vis = new boolean[n + 1][m + 1];
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(vis[i][j]) continue;
                Room room = new Room(++number);
                vis[i][j] = true;
                Deque<Point> q = new ArrayDeque<>();
                q.add(new Point(i, j));
                while (!q.isEmpty()) {
                    Point cur = q.poll();
                    room.points.add(cur);
                    team[cur.x][cur.y] = number;
                    for (int dir = 0; dir < 4; ++dir) {
                        int nx = cur.x + dx[dir];
                        int ny = cur.y + dy[dir];
                        if(!range(nx, ny) || vis[nx][ny]) continue;
                        //처음 탐색에서는 벽이 있다면 뚫지 않을 것이다.
                        if((area[nx][ny] & (1 << dir)) > 0) continue;
                        vis[nx][ny] = true;
                        q.add(new Point(nx, ny));
                    }
                }
                rooms.add(room);
            }
        }
    }

    static void research() {
        boolean[][] vis = new boolean[n + 1][m + 1];
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(vis[i][j]) continue;
                vis[i][j] = true;
                Deque<Point> q = new ArrayDeque<>();
                q.add(new Point(i, j));
                while (!q.isEmpty()) {
                    Point cur = q.poll();
                    for (int dir = 0; dir < 4; ++dir) {
                        int nx = cur.x + dx[dir];
                        int ny = cur.y + dy[dir];
                        if(!range(nx, ny) || vis[nx][ny]) continue;
                        if(team[i][j] != team[nx][ny]) {
                            if(rooms.get(team[i][j] - 1).adj.contains(team[nx][ny] - 1)) continue;
                            rooms.get(team[i][j] - 1).adj.add(team[nx][ny] - 1);
                            rooms.get(team[nx][ny] - 1).adj.add(team[i][j] - 1);
                            continue;
                        }
                        vis[nx][ny] = true;
                        q.add(new Point(nx, ny));
                    }
                }
            }
        }
    }

    static void solution() {
        //방 갯수와 넓은 방 동시에 얻을 수 있음
        search();
        System.out.println(rooms.size());
        int answer = 0;
        for(Room room : rooms) {
            if(answer < room.points.size()) answer = room.points.size();
        }
        System.out.println(answer);
        //벽 제거하는 경우는, 인접하는 녀석들이 있을 때 성립. 즉 다시 탐색해줘야 한다.
        research();
        answer = 0;
        for(Room room : rooms) {
            for (Integer adjacent : room.adj) {
                int sum = room.points.size() + rooms.get(adjacent).points.size();
                if(sum > answer) answer = sum;
            }
        }
        System.out.println(answer);
    }

    static boolean range(int x, int y) {
        return x >= 1 && x <= n && y >= 1 && y <= m;
    }

    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
