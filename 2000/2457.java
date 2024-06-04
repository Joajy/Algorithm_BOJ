import java.util.*;
import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n;
    static class Info{
        int start, end;
        Info(int start, int end){
            this.start = start;
            this.end = end;
        }
    }
    static ArrayList<Info> flowers;

    static void input() throws IOException {
        n = Integer.parseInt(br.readLine());
        flowers = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            st = new StringTokenizer(br.readLine());
            int sM = Integer.parseInt(st.nextToken());
            int sD = Integer.parseInt(st.nextToken());
            int eM = Integer.parseInt(st.nextToken());
            int eD = Integer.parseInt(st.nextToken());
            flowers.add(new Info(sM * 100 +  sD, eM * 100 + eD));
        }
    }

    static void solution() {
        flowers.sort((o1, o2) -> {
            if (o1.start == o2.start) return Integer.compare(o1.end, o2.end);
            return Integer.compare(o1.start, o2.start);
        });
        int start = 301, end = 1201, answer = 0;
        int endPoint = 0, lastDay = 0;
        while(start < end){
            int change = 0;
            for (int i = lastDay; i < n; ++i) {
                if(flowers.get(i).start > start) break;
                if(endPoint >= flowers.get(i).end) continue;
                endPoint = flowers.get(i).end;
                lastDay = i + 1;
                change = 1;
            }
            if(change == 0) break;
            start = endPoint;
            ++answer;
        }
        if(endPoint < end) System.out.println(0);
        else System.out.println(answer);
    }

    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
