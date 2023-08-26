import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Integer dp[] = new Integer[1001];
        dp[1] = 1;
        dp[2] = 3;
        int n;
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        for(int i=3;i<=n;++i){
            dp[i] = (dp[i-1] + (dp[i-2]<<1)) % 10007;
        }
        System.out.println(dp[n]);
    }
}
