import java.nio.Buffer;
import java.util.*;
import java.io.*;

public class boj1561 {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int N, M;
    static long ANS;
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
        if(N <= M){
            ANS = N;
            return;
        }

        long l = 0, r = (long)2000000000 * 30, stand = 0;
        while(l < r){
            long mid = (l + r ) / 2;
            long cnt = 0;

            for(int i = 0; i < M; i++){
                cnt += (mid / minute_per_device[i] + 1);
            }

            if(cnt < N){
                l = mid + 1;
            }  else {
                r = mid;
            }
        }
        long cnt = 0;
        int i = 0;
        r--;


        for(i = 0; i < M; i++){
            cnt += (r / minute_per_device[i] + 1);
        }
        i = 0; r++;
        while(true){
            if(r % minute_per_device[i] == 0)
                cnt++;
            if(cnt >= N && (r % minute_per_device[i] == 0)){
                break;
            }
            i++;
        }
        ANS = i+1;
    }
}
