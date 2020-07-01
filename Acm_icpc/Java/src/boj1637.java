import java.util.*;
import java.io.*;

class chocolate{
    int A, B, C;
    chocolate(int a, int b, int c){
        A = a;
        B = b;
        C = c;
    }
}

public class boj1637 {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static long ANS;
    static int N, SUM, MAXI, MINI=2147483647;
    static chocolate[] choco;

    public static void main(String[] args) throws Exception{
        input(); solve();
        if(SUM % 2 ==0)
            bw.write("NOTHING" + "\n");
        else
            bw.write(ANS + "\n");

        bw.flush(); bw.close();
    }

    static void input() throws Exception{
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        choco = new chocolate[N];

        for(int i = 0; i < N; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            SUM += Math.ceil((c - a + 1) / (float)b);
            MAXI = Math.max(MAXI, c);
            MINI = Math.min(MINI, a);
           choco[i] = new chocolate(a,b,c);
        }
    }

    static void solve() throws Exception{
        if(SUM % 2 == 0)
            return;
        long l = 0, r = 2147483647;

        while(l < r){
            System.out.println(l + " " + r);
           long mid = ((long)l + r ) / 2;
           int cnt = 0;

           for(int i = 0; i < N; i++){
                if(choco[i].A > mid || choco[i].C < mid) continue;
                if((mid - choco[i].A) % choco[i].B == 0){
                    cnt++;
                }
           }

           if(mid > MAXI || cnt % 2 == 1) {
                r = mid ;
           }  else {
               l = mid + 1;
           }
           System.out.println("cnt : " + cnt );
        }
        ANS = l;
    }
}

