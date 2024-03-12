import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static int n;
    static final int[] dx = {0, 1, 0, -1};
    static final int[] dy = {1, 0, -1, 0};
    static String sequence = "";

    static void input() throws IOException {
        for (int i = 0; i < 3; ++i) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 3; ++j) {
                sequence += st.nextToken();
            }
        }
    }

    static void solution(){
        Deque<String> q = new ArrayDeque<>();
        //9자리 배열 만들려면 메모리 초과. 32MB이므로 해시맵 채택
        //각 상태(배치) 별로 최소 위치 가져간다.
        HashMap<String, Integer> vis = new HashMap<>();
        q.add(sequence);
        vis.put(sequence, 0);
        while (!q.isEmpty()) {
            String cur = q.poll();
            if(cur.equals("123456780")){
                System.out.println(vis.get(cur));
                return;
            }
            int zero = cur.indexOf("0");
            for (int dir = 0; dir < 4; ++dir) {
                int nx = zero / 3 + dx[dir];
                int ny = zero % 3 + dy[dir];
                if(nx < 0 || ny < 0 || nx >= 3 || ny >= 3) continue;
                String nxt = swap(cur, zero, nx * 3 + ny);
                if(vis.containsKey(nxt)) continue;
                q.add(nxt);
                vis.put(nxt, vis.get(cur) + 1);
            }
        }
        System.out.println(-1);
    }

    static String swap(String origin, int x, int y) {
        char tmp = origin.charAt(y);
        String ret = origin.replace(tmp, '9');
        ret = ret.replace('0', tmp);
        ret = ret.replace('9', '0');
        return ret;
    }

    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
