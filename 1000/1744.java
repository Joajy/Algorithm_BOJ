import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
    static int n;
    static PriorityQueue<Integer> pos, ngv;
    
    static void input() throws IOException {
    	n = Integer.parseInt(br.readLine());
    	//양수, 음수(0 포함)
    	pos = new PriorityQueue<>(Collections.reverseOrder());
    	ngv = new PriorityQueue<>();
    	for(int i = 0;i < n; ++i) {
    		int num = Integer.parseInt(br.readLine());
    		if(num > 0) pos.add(num);
    		else ngv.add(num);
    	}
    }
    
    
    static void solution() {
    	int answer = 0;
    	while(pos.size() >= 2) {
    		int a = pos.poll();
    		int b = pos.poll();
    		answer += Math.max(a + b,  a * b);
    	}
    	if(!pos.isEmpty()) {
    		answer += pos.poll();
    	}
    	while(ngv.size() >= 2) {
    		answer += ngv.poll() * ngv.poll();
    	}
    	if(!ngv.isEmpty()) {
    		answer += ngv.poll();
    	}
    	System.out.println(answer);
    }
    
    public static void main(String[] args) throws IOException {
    	input();
   		solution();
    }
}
