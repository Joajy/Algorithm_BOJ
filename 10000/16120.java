import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String ppap;

    static void input() throws IOException {
        ppap = br.readLine();
    }

    static void solution() {
        Stack<Character> stack = new Stack<>();
        if(ppap.charAt(0) == 'A' || ppap.charAt(ppap.length() - 1) == 'A') {
            System.out.println("NP");
            return;
        }        
        if(ppap.length() <= 4) {
            if (ppap.equals("P") || ppap.equals("PPAP")) {
                System.out.println("PPAP");
                return;
            } else {
                System.out.println("NP");
                return;
            }
        }
        for (int i = 0; i < ppap.length() - 1; ++i) {
            if (ppap.charAt(i) == 'P') {
                stack.add('P');
            } else if(ppap.charAt(i + 1) == 'P' && stack.size() >= 2) {
                stack.pop();
                ++i;
            } else {
                System.out.println("NP");
                return;
            }
        }
        if(stack.size() == 1) System.out.print("PPAP");
        else System.out.print("NP");
    }

    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
