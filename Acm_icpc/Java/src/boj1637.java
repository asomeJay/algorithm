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

    static long ANS, CNT;
    static int N, SUM, MAXI, MINI=2147483647;
    static chocolate[] choco;

    public static void main(String[] args) throws Exception{
        input(); solve();
        if(SUM % 2 ==0)
            bw.write("NOTHING" + "\n");
        else
            bw.write(ANS + " " + CNT + "\n");

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

        Arrays.sort(choco, new Comparator<chocolate>() {
            @Override
            public int compare(chocolate o1, chocolate o2) {
                if (o1.A == o2.A) {
                    return Integer.compare(o1.B, o2.B);
                } else {
                    return Integer.compare(o1.A, o2.A);
                }
            }
        });
    }

    public static void solve() throws Exception{
        if(SUM % 2 == 0)
            return;
        int l = 0, r = MAXI;
        while(l < r){
            long cnt = 0;
            long mid = ((long)l + r ) /2;

            for(int i = 0; i < N; i++){
                if(choco[i].A > mid){
                    continue;
                }
                cnt += (Math.min(choco[i].C, mid) - choco[i].A) /  choco[i].B + 1;
            }
            if(cnt % 2 == 0){
                l = (int)mid + 1;
            } else {
                r = (int)mid;
            }
        }
        ANS = l;
        for(int i = 0; i < N; i++){
            if(choco[i].A > ANS || choco[i].C < ANS) continue;
            if(((ANS - choco[i].A) % choco[i].B) == 0)
                CNT++;
        }
    }
}

