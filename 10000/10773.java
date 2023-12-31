import java.io.*;
import java.util.*;

import static java.lang.Integer.*;

public class Main {

    static int n;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static Stack<Integer> s = new Stack<>();

    public static void main(String[] args) throws Exception {
        n = Integer.parseInt(br.readLine());
        for(int i = 0;i < n; ++i){
            int number = Integer.parseInt(br.readLine());
            if (number == 0) {
                s.pop();
                continue;
            }
            s.add(number);
        }
        int answer = 0;
        while (!s.isEmpty()) {
            answer += s.peek();
            s.pop();
        }
        System.out.println(answer);
    }
}
