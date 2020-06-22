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
        int target = 1, sum = 1;
        while(sum < K){
           target++;
           sum += factor(target);
        }
        CNT = target;

    }

    public static int factor(int n){
        int cnt = 0, defactor=0;
        while(defactor <= n){
            defactor++;
            if(n / defactor <= N && defactor <= N && n % defactor == 0){
                cnt++;
            }
        }
        return cnt;
    }

}
