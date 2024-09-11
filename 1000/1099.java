import java.util.*;
import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static String str;
    static String[] words;
    static int[] dp;
    static int n, answer;

    static void input()  throws IOException{
        str = br.readLine();
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        words = new String[n];
        dp = new int[str.length() + 1];
        for(int i = 0; i < n; i++){
            words[i] = br.readLine();
        }
        for(int i = 0; i <= str.length(); i++){
            dp[i] = (int)1e9;
        }
        dp[0] = 0;
        answer = (int)1e9;
    }

    static int match(int idx, String word) {
        int count = 0;
        int[] cnt = new int[26];
        for(int i = 0; i < word.length(); i++){
            if(str.charAt(idx + i) != word.charAt(i)){
                ++count;
                ++cnt[word.charAt(i) - 'a'];
                --cnt[str.charAt(idx + i) - 'a'];
            }
        }
        for(int i : cnt) {
            if(i != 0) return -1;
        }
        return count;
    }

    static void solution() {
        Arrays.sort(words, (o1, o2) -> {
            return Integer.compare(o1.length(), o2.length());
        });
        for(int i = 0; i < str.length(); i++){
            for(int j = 0; j < words.length; j++){
                int len = words[j].length();
                if(i + len > str.length()) break;
                int matchCount = match(i, words[j]);
                if(matchCount == -1) continue;
                dp[i + len] = Math.min(dp[i + len], dp[i] + matchCount);
            }
        }
        if(dp[str.length()] == (int)1e9) dp[str.length()] = -1;
        System.out.println(dp[str.length()]);
    }

    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
