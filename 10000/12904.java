import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
	static String a, b;
    
    static void input() throws IOException {
    	a = br.readLine();
    	b = br.readLine();
    }
    
    static int change() {
    	Deque<String> q = new ArrayDeque<>();
    	q.add(b);
    	while(!q.isEmpty()) {
    		String cur = q.poll();
    		if(cur.isEmpty()) continue;
    		if(cur.equals(a)) return 1;
    		char word = cur.charAt(cur.length() - 1);
    		if(word == 'A') {
    			q.add(cur.substring(0, cur.length() - 1));
    		}
    		if(word == 'B') {
    			sb = new StringBuilder(cur.substring(0, cur.length() - 1)).reverse();
    			q.add(sb.toString());
    		}
    	}
    	return 0;
    }
    
    static void solution() {
    	System.out.println(change());
    }
    
    public static void main(String[] args) throws IOException {
   		input();
   		solution();
    }
}
