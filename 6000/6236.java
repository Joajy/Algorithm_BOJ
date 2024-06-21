import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int n, m, answer, l, r;
	static int[] a;
	
    static void input() throws IOException {
		st = new StringTokenizer(br.readLine());
    	n = Integer.parseInt(st.nextToken());
    	m = Integer.parseInt(st.nextToken());
    	a = new int[n];
    	for(int i = 0;i < n; ++i) {
   			a[i] = Integer.parseInt(br.readLine());
   			l = Math.max(a[i], l);
    	}
   	}
    
    //연산 상 mid가 익숙하여 mid 변수를 사용했으나
    //mid == k임을 명시합니다.
    static void binarySearch() {
    	r = (int)1e9;
    	while(l <= r) {
    		int mid = (l + r) >> 1;
    		int count = parametricSearch(mid);	//인출 횟수
    		//m번보다 더 많이 인출하는 경우, 인출 금액을 높인다.
    		if(count > m) {
    			l = mid + 1;
    		} else {
    			answer = mid;
    			r = mid - 1;
    		}
    	}
    }
    
    //몇 번 인출하는지에 대해 리턴합니다.
    //여기가 parametric search
    static int parametricSearch(int k) {
    	//최초 1회 인출 후 시작
    	int count = 1, sum = k;
    	for(int i = 0;i < n; ++i) {
			//모자라게 되면 남은 금액은 통장에 집어넣고 다시 K원을 인출
    		if(sum < a[i]) {
    			++count;
    			sum = k;
    		}
			sum -= a[i];
		}
    	return count;
    }
	
	/*
	 * K를 크게 하면 한 번 출금해서 n일 동안 별도의 출금 없음
	 * 따라서 m 번의 출금을 요할 만한 최소 k를 찾는 것이 관건
	 * */
	//bs + parametric search
    static void solution() {
    	binarySearch();
    	System.out.println(answer);
    }
    
    public static void main(String[] args) throws IOException {
   		input();
   		solution();
    }
}
