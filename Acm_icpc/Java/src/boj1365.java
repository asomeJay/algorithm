import java.util.*;
import java.io.*;

public class boj1365 {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int N, ANS;
    static int[] powerPole;

    public static void main(String[] args) throws Exception{
        input();
        solve();

        bw.write(ANS+"\n"); bw.flush(); bw.close();

    }

    static void input() throws Exception{
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());

        powerPole = new int[N+1];

        st = new StringTokenizer(br.readLine());
        for(int i = 1; i <= N; i++){
            powerPole[i] = Integer.parseInt(st.nextToken());
        }
    }

    static void solve() throws Exception{
        int large = 0, small = 0;
        for(int i = 1; i <= N; i++){
            if(i < powerPole[i]){
                large++;
            } else if(i > powerPole[i]){
                small++;
            }
        }

        ANS = Math.min(large, small);
    }
}
