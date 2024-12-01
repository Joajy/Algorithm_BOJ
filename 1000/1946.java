import java.awt.Point;
import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static StringTokenizer st;
    static int n;
    static Point[] grade;

    static void input() throws IOException {
        n = Integer.parseInt(br.readLine());
        grade = new Point[n];
        for (int index = 0; index < n; ++index) {
            st = new StringTokenizer(br.readLine());
            int paper = Integer.parseInt(st.nextToken());
            int interview = Integer.parseInt(st.nextToken());
            grade[index] = new Point(paper, interview);
        }
    }

    static void solution() {
        //서류심사 기준 정렬
        Arrays.sort(grade, new Comparator<Point>() {
            @Override
            public int compare(Point o1, Point o2) {
                return Integer.compare(o1.x, o2.x);
            }
        });
        //직전 대상자의 면접 성적보다 순위 낮으면 생략
        int pass = 1, interviewGrade = grade[0].y;
        for (int index = 1; index < n; ++index) {
            if(interviewGrade < grade[index].y) continue;
            interviewGrade = grade[index].y;
            ++pass;
        }
        sb.append(pass).append('\n');
    }

    public static void main(String[] args) throws IOException {
        int testCase = Integer.parseInt(br.readLine());
        for (int current = 1; current <= testCase; ++current) {
            input();
            solution();
        }
        System.out.println(sb);
    }
}
