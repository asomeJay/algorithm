import java.io.*;
import java.util.*;

class node {
    int pos, cnt;
    node (int a, int b) {
        this.pos = a;
        this.cnt = b;
    }
}

public class boj13549 {
   static BufferedReader br;
   static BufferedWriter bw;
    static PriorityQueue<node> pq;
   static int N, K, ANS;
   static boolean[] chk;

    public static void main(String[] args) throws Exception {
        init();
        input();
       Comparator<node> timeStampComparator = new Comparator<node>() {
            @Override
            public int compare(node o1, node o2) {
                return  Integer.compare(o1.cnt, o2.cnt);
            }
        };
        pq = new PriorityQueue<>(timeStampComparator);
//        pq.add(new node(1,1));
//        pq.add(new node(2,2));
//
//        while(!pq.isEmpty()){
//            node a = pq.remove();
//           bw.write(a.pos + "" + a.cnt);
//        }
       solve();

       bw.write(ANS + "\n");
       bw.flush();
       bw.close();
    }

    static public void init() throws Exception {
        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));
        chk = new boolean[100010];
    }

    static public void input() throws Exception{
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

    }

    static void solve(){
        pq.add(new node(N, 0));

        while(!pq.isEmpty()){
            node temp = pq.remove();
            int cur_pos = temp.pos;
            int cur_cnt = temp.cnt;
            chk[cur_pos] = true;
//            System.out.println("cur_pos " + cur_pos + " cur_cnt " + cur_cnt);
            if(cur_pos == K){
                ANS = cur_cnt;
                return;
            }
            if(cur_pos != 0 && !chk[cur_pos - 1]){
//                chk[cur_pos-1] = true;
                pq.add(new node(cur_pos-1, cur_cnt+1));
            } if(cur_pos <= 100000 && !chk[cur_pos + 1]){
//                chk[cur_pos+1] = true;
                pq.add(new node(cur_pos+1, cur_cnt+1));
            } if(cur_pos <= 50000 && !chk[cur_pos * 2]){
//                chk[cur_pos * 2] = true;
                pq.add(new node(cur_pos * 2, cur_cnt));
            }
        }
    }
}
