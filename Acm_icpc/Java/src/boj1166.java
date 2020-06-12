import java.util.*;
import java.io.*;

public class boj1166 {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int N;
    static double L, W, H,ANS;

    public static void main(String[] args) {

    }

    static void input() throws Exception{
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());

        L = Float.parseFloat(st.nextToken()) / N;
        W = Float.parseFloat(st.nextToken()) / N;
        H = Float.parseFloat(st.nextToken()) / N;
    }

    static void solve(){
        long l, r, m;
        l = 0; r = 1000000000;
        while(l<=r){
            m = (l + r) / 2;
            if(m <= L && m <= W && m <= H){
                ANS = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
    }
}
