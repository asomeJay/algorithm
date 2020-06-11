import java.util.*;
import java.io.*;

public class boj1114 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter  bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static int L, K ,C, ANS, ANS_INDEX;
    static int[] pos;

    public static void main(String[] args) throws Exception {
        input();
        solve();
        bw.write(ANS + " " + ANS_INDEX + "\n");
        bw.flush();
        bw.close();
    }

    static void input() throws Exception {
        st = new StringTokenizer(br.readLine());
        L = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        pos = new int[10001];
        st = new StringTokenizer(br.readLine());

        for(int i = 0; i < K; i++){
            pos[i] = Integer.parseInt(st.nextToken());
        }
    }

    static void solve(){
        int start, end, dist;
        start = 0; end = pos[0]; dist = end-start;
        for(int i = 1; i < K; i++){
           dist = end - start;
           if(end + dist <= pos[i])
               continue;
           start = end; end = pos[i];
        }

        ANS = dist;
        ANS_INDEX = end;
    }
}
