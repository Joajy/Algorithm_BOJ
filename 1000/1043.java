import java.util.*;
import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n, m, cnt;
    static boolean[] know, tellTrue;
    static List<Integer>[] party;

    static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        know = new boolean[n + 1];
        tellTrue = new boolean[m + 1];
        party = new ArrayList[m + 1];
        cnt = 0;
        st = new StringTokenizer(br.readLine());
        int knowCnt = Integer.parseInt(st.nextToken());
        for (int i = 0; i < knowCnt; i++) {
            int number = Integer.parseInt(st.nextToken());
            know[number] = true;
            cnt++;
        }
        for(int i = 1; i <= m; i++) {
            party[i] = new ArrayList<>();
            st = new StringTokenizer(br.readLine());
            int cnt = Integer.parseInt(st.nextToken());
            for(int j = 0; j < cnt; ++j) {
                int number = Integer.parseInt(st.nextToken());
                party[i].add(number);
            }
        }
    }

    static void search() {
        for (int i = 1; i <= m; ++i) {
            //m개의 파티 동안 진실을 이미 말한 곳은 넘긴다.
            if(tellTrue[i]) continue;
            //i번째 파티에서 거짓말 할 수 있는지 확인한다.
            for(int human : party[i]) {
                if(!know[human]) continue;
                tellTrue[i] = true;
                //한 명이라도 알고 있다면 진실 말해야 됨
                for(int recentKnow : party[i]) {
                    if(!know[recentKnow]) ++cnt;
                    know[recentKnow] = true;
                }
            }
        }
    }

    static void solution() {
        int before = -1;
        while (before != cnt) {
            before = cnt;
            //우선 거짓을 고할 수 없는 파티를 구한다
            //거짓을 고할 수 없게 되는 추가 파티를 확인한다.
            search();
        }
        int answer = 0;
        for (int i = 1; i <= m; ++i) {
            if(!tellTrue[i]) ++answer;
        }
        System.out.println(answer);
    }
    
    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
