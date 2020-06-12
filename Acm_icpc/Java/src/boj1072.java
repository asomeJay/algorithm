import java.util.*;
import java.io.*;

public class boj1072 {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static long gameCnt, winCnt, percent,ANS;

    public static void main(String[] args) throws Exception {
        input();
        solve();
        bw.write(ANS + "\n");
        bw.flush();
        bw.close();
    }

    static void input() throws Exception {
        st = new StringTokenizer(br.readLine());
        gameCnt = Integer.parseInt(st.nextToken());
        winCnt = Integer.parseInt(st.nextToken());

        percent = winCnt * 100 / gameCnt;
        ANS = -1;
    }

    static void solve() throws Exception{
       long l, r, m;
       l = 0; r = gameCnt;

       while(l <= r ){
           m = (l + r) /2;
           long x = gameCnt + m;
           long y = (winCnt + m) * 100;
            if((y / x) != percent){
                r = m - 1;
                ANS = m;
            } else{
                l = m + 1;
            }
       }
    }
}
