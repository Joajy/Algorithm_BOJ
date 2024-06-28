import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int n, k;
	static int[][] a;
	
    static void input() throws IOException {
    	n = Integer.parseInt(br.readLine());
    	a = new int[n][2];
    	for(int i = 0;i < n; ++i) {
    		st = new StringTokenizer(br.readLine());
    		a[i][0] = Integer.parseInt(st.nextToken());
    		a[i][1] = Integer.parseInt(st.nextToken());
    	}
    }

    static void solution() {
    	Arrays.sort(a, new Comparator<int[]>() {
			@Override
			public int compare(int[] o1, int[] o2) {
				if(o1[0] == o2[0]) return Integer.compare(o1[1], o2[1]);
				return Integer.compare(o1[0], o2[0]);
			}
    	});
    	int answer = 0;
    	int start = a[0][0], end = a[0][1];
    	for(int i = 1;i < n; ++i) {
    		if(a[i][0] <= end) end = Math.max(end, a[i][1]);
    		else {
    			answer += end - start;
    			start = a[i][0];
    			end = a[i][1];
    		}
    	}
    	answer += end - start;
    	System.out.println(answer);
    }
    
    public static void main(String[] args) throws IOException {
   		input();
   		solution();
    }
}
