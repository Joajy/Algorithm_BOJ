import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
	  static StringTokenizer st;
    static int n;
    static int[] h;

    static void input() throws IOException {
		n = Integer.parseInt(br.readLine());
		h = new int[n];
    	for(int i = 0;i < n; ++i) {
        	h[i] = Integer.parseInt(br.readLine());
    	}
    }
    
    static void solution(){
    	Deque<Integer> s = new ArrayDeque<>();
    	s.add((int)2e9);
    	int answer = 0;
    	for(int i = 0;i < n; ++i) {
   			while(s.peekFirst() <= h[i]) {
   				s.pollFirst();
   			}
    		answer += s.size() - 1;
    		s.addFirst(h[i]);
    	}
    	System.out.println(answer);
    }

    public static void main(String[] args) throws IOException {
   		input();
       	solution();
    }
}
