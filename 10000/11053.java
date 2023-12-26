import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

import static java.lang.Integer.*;

public class Main {

    static int n;
    static int[] a = new int[1001];
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static Vector<Integer> v = new Vector<>();

    static int binarySearch(int val){
        int l = 0, r = v.size() - 1;
        int mid;
        while (l <= r){
            mid = (l + r) >> 1;
            if (v.elementAt(mid) < val) {
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return l;
    }

    static int LIS(){
        v.add(0);
        for(int i=0;i<n;++i){
            if (v.lastElement() < a[i]) {
                v.add(a[i]);
            }
            else{
                int idx = binarySearch(a[i]);
                v.set(idx, a[i]);
            }
        }
        return v.size() - 1;
    }

    public static void main(String[] args) throws Exception {
        init();
        System.out.println(LIS());
    }

    private static void init() throws Exception {
        n = parseInt(br.readLine());
        StringTokenizer numbers = new StringTokenizer(br.readLine());
        for(int i = 0;i < n; ++i){
            a[i] = parseInt(numbers.nextToken());
        }
    }
}
