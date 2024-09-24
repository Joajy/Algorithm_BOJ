import java.util.*;
import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n, L;
    static class Ground {
        int start, end;
        Ground(int start, int end) {
            this.start = start;
            this.end = end;
        }
    }
    static Ground[] a;

    static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        L = Integer.parseInt(st.nextToken());
        a = new Ground[n];
        for (int i = 0; i < n; ++i) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            a[i] = new Ground(start, end);
        }
    }

    static void solution() {
        Arrays.sort(a, (o1, o2) -> {
            if (o1.start == o2.start) {
                return Integer.compare(o2.end, o1.end);
            }
            return Integer.compare(o1.start, o2.start);
        });
        int index = 0, answer = 0;
        for (int i = 0; i < n; ++i) {
            //현재 물웅덩이의 끝 지점보다 설치된 지점이 더 멀리 있으면 넘어간다.
            if(index > a[i].end) continue;
            //현재 물웅덩이 시작 지점보다 전에 있던 경우, 현재 시작점으로 index 값 끌어온다.
            if(index < a[i].start) {
                index = a[i].start;
            }
            //L만큼씩 나누고, 만약 나머지가 있으면 널빤지 한 개 더 추가한다.
            int count = a[i].end - index;
            count = count / L + (count % L == 0 ? 0 : 1);
            //answer에 count만큼 더하고, index는 count * L만큼 앞서나간다.
            answer += count;
            index += count * L;
        }
        System.out.println(answer);
    }

    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
