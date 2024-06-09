import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;
    static int n, k;
    static String num;

    static void input() throws IOException {
		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		num = br.readLine();
    }
    
    static void solution() {
    	Stack<Character> s = new Stack<>();
		s.add(num.charAt(0));
		int len = n - k;
    	for(int i = 1;i < num.length(); ++i) {
    		char cur = num.charAt(i);
    		while(true) {
    			if(k == 0 || s.isEmpty()) break;
    			if(s.peek() < cur) {
    				--k;
    				s.pop();
    			} else break;
    		}
    		s.add(num.charAt(i));
    	}
    	while(!s.isEmpty()) {
    		sb.append(s.pop());
    	}
    	System.out.println(sb.reverse().substring(0, len));
    }
    
    public static void main(String[] args) throws IOException {
   		input();
   		solution();
    }
}
