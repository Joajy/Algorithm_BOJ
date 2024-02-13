import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n, k, answer = 0;
    static String[] s;
    static boolean[] vis;

    static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        s = new String[n];
        vis = new boolean[26];
        vis[0] = vis[2] = vis[8] = vis[13] = vis[19] = true;
        for(int i = 0;i < n; ++i){
            s[i] = br.readLine();
            s[i] = s[i].substring(4, s[i].length() - 4);
        }
    }

    static boolean analyzeWord(String word){
        for (int i = 0; i < word.length(); ++i) {
            if(vis[word.charAt(i) - 'a']) continue;
            return false;
        }
        return true;
    }

    static void rec(int cnt, int idx) {
        if(cnt == k){
            int tmp = 0;
            for (int i = 0; i < n; ++i) {
                if(analyzeWord(s[i])) ++tmp;
            }
            if(tmp > answer) answer = tmp;
            return;
        }
        for (int i = idx; i < 26; ++i) {
            if(vis[i]) continue;
            vis[i] = true;
            rec(cnt + 1, i);
            vis[i] = false;
        }
    }

    static void solution() {
        if(k < 5) {
            System.out.println(answer);
            return;
        }
        rec(5, 0);
        System.out.println(answer);
    }

    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
