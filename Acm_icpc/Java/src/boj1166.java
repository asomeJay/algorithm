import java.util.*;
import java.io.*;

public class boj1166 {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int N;
    static long L, W, H;
    static double ANS;

    public static void main(String[] args) throws Exception {
        input();
        solve();
        bw.write(Double.parseDouble(String.format("%.9f", ANS)) + "\n"); bw.flush(); bw.close();
    }

    static void input() throws Exception{
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        L = Integer.parseInt(st.nextToken());
        W = Integer.parseInt(st.nextToken());
        H = Integer.parseInt(st.nextToken());

       /* L = Float.parseFloat(st.nextToken()) / N;
        W = Float.parseFloat(st.nextToken()) / N;
        H = Float.parseFloat(st.nextToken()) / N;*/
    }

    static void solve(){
        double l, r, m;
        l = 0; r = 1e15;
        for(int i = 0; i <= 10000; i++){
            m = (l + r) / 2;
            double tot = (long)(L / m) * (long)(W / m) * (long)(H/m);
            if(tot >= N){
                l = m ;
                ANS = m;
            } else {
               r = m;
            }
        }
    }
}
