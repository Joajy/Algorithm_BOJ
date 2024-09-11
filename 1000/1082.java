import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;
	static int n, m;
	static int[] a;
	static String[] dp;
	
    static void input() throws IOException {
    	n = Integer.parseInt(br.readLine());
    	a = new int[n + 1];
    	st = new StringTokenizer(br.readLine());
    	for(int i = 0;i < n; ++i) {
    		a[i] = Integer.parseInt(st.nextToken());
    	}
    	m = Integer.parseInt(br.readLine());
    	dp = new String[m + 1];
    	for(int i = 0;i <= m; ++i) {
    		dp[i] = "";
    	}
    }
    
    static void solution() {
    	for(int i = n - 1; i >= 0; --i) {
    		for(int j = m - a[i]; j >= 0; --j) {
    			if(compare(dp[j], dp[j + 1])) {
    				dp[j] = dp[j + 1];
    			}
    			if(dp[j + a[i]].isEmpty() && i == 0) continue;
    			if(compare(dp[j], dp[j + a[i]] + i)) {
    				dp[j] = dp[j + a[i]] + i;
    			}
    		}
    	}
    	if(dp[0] == "") dp[0] = "0";
    	System.out.println(dp[0]);
    }
    
    static boolean compare(String a, String b) {
    	if(a.length() == b.length()) {
    		for(int i = 0; i < a.length(); ++i) {
    			if(a.charAt(i) < b.charAt(i)) return true;
    		}
    		return false;
    	}
    	return a.length() < b.length();
    }
	
    public static void main(String[] args) throws IOException {
    	input();
    	solution();
    }
}
