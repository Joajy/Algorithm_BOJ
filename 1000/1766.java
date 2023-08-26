import java.util.*;

public class Main {
    public static void main(String[] args) {
        int deg[] = new int[32001];
        Scanner s = new Scanner(System.in);
        Vector<Integer> a[] = new Vector[32001];
      
        for(int i=0;i<32001;++i){
            a[i] = new Vector<>();
        }
      
        int N,M;
        N = s.nextInt();
        M = s.nextInt();
        for(int i=0;i<M;++i){
            int x,y;
            x = s.nextInt();
            y = s.nextInt();
            a[x].add(y);
            ++deg[y];
        }

        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for(int i=1;i<=N;++i){
            if(deg[i] == 0) pq.add(i);
        }
        while(!pq.isEmpty()){
            Integer cur = pq.poll();
            System.out.print(cur + " ");
            for(int nxt : a[cur]){
                if(--deg[nxt] == 0) pq.add(nxt);
            }
        }
    }
}
