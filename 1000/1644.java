import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;
	static int n, m, answer = 0;
	static int[] a;
	static long[] prefixSum;
	static List<Integer> numbers = new ArrayList<>();
	
	static void input() throws IOException {
		n = Integer.parseInt(br.readLine());
	}
	
	static void sieve() {
		a = new int[n + 1];
		for(int i = 2;i * i <= n; ++i) {
			for(int j = i << 1;j <= n; j += i) {
				a[j] = -1;
			}
		}
		for(int i = 2;i <= n; ++i) {
			if(a[i] != -1) numbers.add(i);
		}
		numbers.add(0);
	}
	
	static void solution() {
		sieve();
		int st = 0, en = 0, sum = 0;
		int len = numbers.size();
		while(st < len && en < len) {
			if(sum == n) {
				++answer;
				sum -= numbers.get(st++);
			}
			else if(sum > n) {
				sum -= numbers.get(st++);
			}
			else {
				sum += numbers.get(en++);
			}
		}
		System.out.println(answer);
	}
	
	public static void main(String[] args) throws Exception{
		input();
		solution();
	}
}
