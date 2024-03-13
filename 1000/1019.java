import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

//인정한다. 이거는 내 힘만으론 못 풀었을 것이므로 참고한 자료를 첨부한다.
//https://www.slideshare.net/Baekjoon/baekjoon-online-judge-1019

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static long a, b, pow;
    static long[] num;

    static void input() throws IOException {
        b = Long.parseLong(br.readLine());
        num = new long[10];
        a = pow = 1;
    }

    static void calculate(long val, long cnt) {
        while (val > 0) {
            num[(int) (val % 10)] += cnt;
            val /= 10;
        }
    }

    static void makeFirstToZero(){
        while(a % 10 != 0 && a <= b){
            calculate(a, pow);
            ++a;
        }
    }

    static void makeLastToNine(){
        while(b % 10 != 9 && a <= b){
            calculate(b, pow);
            --b;
        }
    }

    static void moveNextPosition() {
        a /= 10;
        b /= 10;
        pow *= 10;
    }

    static void solution() {
        //1부터 n까지에 대한 탐색
        //작은 값은 덧셈을 통해 일의 자리를 0으로, 큰 값은 뺄셈을 통해 일의 자리를 9로 만들어준다
        //그래야 일의 자리 기준 0~9를 성립시킬 수 있으니 원하는 값 찾기에 유용함
        while (a <= b) {
            //큰 값 9만들기
            makeLastToNine();

             if(a > b) break;

             //작은 값 0 만들기
            makeFirstToZero();

            long cnt = b / 10 - a / 10 + 1;
            for (int i = 0; i < 10; ++i) {
                num[i] += cnt * pow;
            }
            moveNextPosition();
        }

        for (int i = 0; i < 10; ++i) {
            sb.append(num[i]).append(" ");
        }
        System.out.println(sb);
    }

    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
