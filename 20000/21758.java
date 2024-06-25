import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int[] a, prefix;
	static int n, min1, min2;
	
    static void input() throws IOException {
    	n = Integer.parseInt(br.readLine());
    	st = new StringTokenizer(br.readLine());
    	min1 = min2 = Integer.MAX_VALUE;
    	a = new int[n];
    	prefix = new int[n];
    	for(int i = 0;i < n; ++i) {
    		a[i] = Integer.parseInt(st.nextToken());
    		prefix[i] = a[i];
    	}
    	for(int i = 1;i < n; ++i) {
    		prefix[i] += prefix[i - 1];
    	}
    }

    static void solution() {
    	int answer = 0;
    	for(int i = 1;i < n - 1; ++i) {
    		answer = Math.max(answer, (prefix[n - 1] - a[0] - a[i]) + (prefix[n - 1] - prefix[i]));
    		answer = Math.max(answer, (prefix[n - 1] - a[n - 1] - a[i]) + (prefix[i] - a[i]));
    		answer = Math.max(answer, (prefix[i] - a[0]) + (prefix[n - 1] - prefix[i] + a[i] - a[n - 1]));
       	}
    	System.out.println(answer);
    }
    
    public static void main(String[] args) throws IOException {
   		input();
   		solution();
    }
}
