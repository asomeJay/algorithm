import java.nio.Buffer;
import java.util.*;
import java.io.*;

public class boj1561 {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int N, M, ANS;
    static int[] minute_per_device;
    public static void main(String[] args) throws Exception{
        input(); solve();
        bw.write(ANS + "\n"); bw.flush(); bw.close();
    }

    static void input() throws Exception{
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        minute_per_device = new int[M];

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < M; i++){
            minute_per_device[i] = Integer.parseInt(st.nextToken());
        }
    }

    static void solve() throws  Exception{
        long l = 0, r = (long)2000000000 * 30;
        while(l <= r){
            long mid = (l + r ) / 2;
            long cnt = 0;
            for(int i = 0; i < M; i++){
                cnt += (mid / minute_per_device[i]);
            }
            if(cnt < N){
                l = mid + 1;
            }  else {
                r = mid - 1;
            }
        }
        long cnt = 0;
        for(int i = 0; i < M; i++){
            cnt += (l / minute_per_device[i]);
            if(cnt >= N){
                ANS = i;
                break;
            }
        }

    }
}
