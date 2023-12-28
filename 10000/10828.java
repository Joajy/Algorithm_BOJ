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
        for(int i=0;i<n;++i){
            StringTokenizer st = new StringTokenizer(br.readLine());
            String cmd = st.nextToken();
            int number = -1;
            if (st.hasMoreTokens()) {
                number = Integer.parseInt(st.nextToken());
            }
            order(cmd, number);
        }
        System.out.println(sb);
    }

    static void order(String cmd, int number) throws IOException {
        if (cmd.matches("push")) {
            s.add(number);
        } else if (cmd.matches("pop")) {
            if (s.isEmpty()) {
                sb.append(-1).append("\n");
            } else {
                sb.append(s.peek()).append("\n");
                s.pop();
            }
        } else if (cmd.matches("size")) {
            sb.append(s.size()).append("\n");
        } else if (cmd.matches("empty")) {
            if (s.isEmpty()) {
                sb.append(1).append("\n");
            } else {
                sb.append(0).append("\n");
            }
        } else if (cmd.matches("top")) {
            if (s.isEmpty()) {
                sb.append(-1).append("\n");
                return;
            }
            sb.append(s.peek()).append("\n");
        }
    }
}
