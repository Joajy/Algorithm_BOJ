import java.util.Scanner;

public class Main {

    public static int N, ans1 = 0, ans2 = 0, ans3 = 0;
    public static int[][] area = new int[2200][2200];
    public static Scanner sc = new Scanner(System.in);

    public static void input() {
        N = sc.nextInt();
        for (int i = 0; i < N; i++) {
            for (int j = 0;j < N; j++){
                area[i][j] = sc.nextInt();
            }
        }
    }

    public static boolean search(int x, int y, int n){
        int std = area[x][y];
        for(int i = x;i < x + n; ++i){
            for(int j = y;j < y + n; ++j){
                if(area[i][j] != std){
                    return false;
                }
            }
        }
        switch (std){
            case -1:
                ++ans1;
                break;
            case 0:
                ++ans2;
                break;
            case 1:
                ++ans3;
        }
        return true;
    }

    public static void dfs(int x, int y, int n) {
        boolean isSame = search(x, y, n);
        //만약 같을 경우에는 반환
        if(n == 0 || isSame) return;
        int div = n / 3;
        for (int i = x; i < x + n; i+=div) {
            for (int j = y;j < y + n; j+=div){
                dfs(i, j, div);
            }
        }
    }

    public static void main(String[] args) {
        input();
        dfs(0, 0, N);
        System.out.println(ans1);
        System.out.println(ans2);
        System.out.println(ans3);
    }
}
