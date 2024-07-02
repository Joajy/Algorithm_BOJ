import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static String s;
	static int n;
	static int[] dp;
	
	
    static void input() throws IOException {
    	s = br.readLine();
    	n = s.length();
    	dp = new int[n + 1];
    }
    
    static void solution() {
   		if(s.charAt(0) == '0') {
   			System.out.println(0);
   			return;
   		}
    	dp[0] = dp[1] = 1;
    	for(int i = 2;i <= n; ++i) {
    		int num = Integer.parseInt(s.substring(i - 2, i));
    		if(num % 10 == 0) {
    			if(num == 10 || num == 20) {
    				dp[i] = dp[i - 2] % (int)1e6;
    			} else break;
    		} else if(num >= 10 && num <= 26) {
    			dp[i] = (dp[i - 1] + dp[i - 2]) % (int)1e6;
    		} else {
    			dp[i] = dp[i - 1] % (int)1e6;
    		}
    	}
    	System.out.println(dp[n] % (int)1e6);
    }
    
    public static void main(String[] args) throws IOException {
   		input();
   		solution();
    }
}
