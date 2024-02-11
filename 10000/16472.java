import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String a;
    static int n, len;
    static int[] alp;

    static void input() throws IOException {
        n = Integer.parseInt(br.readLine());
        a = br.readLine();
        len = a.length();
        alp = new int[26];
    }

    static void solution() {
        int cnt = 0, delIdx = 0, answer = 0;
        for (int i = 0; i < len; ++i) {
            int index = a.charAt(i) - 'a';
            if (alp[index]++ == 0) {
                ++cnt;
            }
            while (n < cnt && delIdx < i) {
                if (--alp[a.charAt(delIdx++) - 'a'] == 0){
                    --cnt;
                }
            }
            answer = Math.max(answer, i - delIdx + 1);
        }
        System.out.println(answer);
    }

    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
