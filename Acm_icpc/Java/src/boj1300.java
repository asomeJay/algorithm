import java.util.*;
import java.io.*;

public class boj1300 {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int[][] A;
    static int[] B;
    static int N, K,CNT;

    public static void main(String[] args) throws Exception{
        input();
        solve();
        bw.write(CNT+"\n");
        bw.flush(); bw.close();
    }

    public static void input() throws Exception{
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        K = Integer.parseInt(st.nextToken());

        //A = new int[N+1][N+1];
        //B = new int[(int)Math.pow(N+1,2)];
    }

    public static void solve() throws Exception {
        int left = 1, right = K;
        while(left <= right){
            int mid = (left + right) / 2;
            int lower_than_mid = lowerThanX(mid);
            if(lower_than_mid >= K){
                CNT = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
    }

    public static int lowerThanX(int x){
        int cnt = 0;
        for(int i = 1; i <= N; i++){
            cnt += Math.min(x / i, N);
        }
        return cnt;
    }

}
