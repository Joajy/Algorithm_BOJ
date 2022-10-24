import java.util.*;
import java.math.BigInteger;
import java.io.*;

public class Main{
    public static void main(String args[]){
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        BigInteger a[] = new BigInteger[10001];
        a[0] = new BigInteger("0");
        a[1] = new BigInteger("1");
        for(int i=2;i<=n;i++){
            a[i] = a[i - 1].add(a[i - 2]);
        }
        System.out.println(a[n]);
    }
}
