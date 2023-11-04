import java.util.*;

public class Main {

    private static int n, m, st, en;
    private static int[] dp = new int[41];

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int answer = 1;
        n = scanner.nextInt();
        m = scanner.nextInt();
        st = 0;
        makeDP();
        for(int i = 0;i < m; ++i){
            en = scanner.nextInt();
            answer *= dp[en - st - 1];
            st = en;
        }
        answer *= dp[n - en];
        System.out.println(answer);
    }

    private static void makeDP() {
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; ++i) {
            dp[i] = dp[i-1]+dp[i-2];
        }
    }
}
