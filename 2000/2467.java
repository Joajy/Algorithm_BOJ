import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int n;
	static int[] a;
	
    static void input() throws IOException {
    	n = Integer.parseInt(br.readLine());
    	a = new int[n];
		st = new StringTokenizer(br.readLine());
    	for(int i = 0;i < n; ++i) {
    		a[i] = Integer.parseInt(st.nextToken());
    	}
    }
    
    static void solution() {
    	Arrays.sort(a);
    	int max = (int)2e9;
    	int answer1 = 0, answer2 = 0;
    	for(int i = 0; i < n; ++i) {
        	int l = i + 1, r = n - 1;
    		while(l <= r) {
    			int mid = (l + r) >> 1;
    			int sum = a[i] + a[mid];
    			if(Math.abs(sum) < max) {
    				answer1 = a[i];
    				answer2 = a[mid];
    				max = Math.abs(sum);
    			}
    			if(sum < 0) {
    				l = mid + 1;
    			} else {
    				r = mid - 1;
    			}
    		}
    	}
    	System.out.println(answer1 + " " + answer2);
    }
    
    public static void main(String[] args) throws IOException {
   		input();
   		solution();
    }
}
