import java.util.*;
import java.io.*;

public class boj1477 {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int n_of_rest, more_rest, l_of_highway, ANS;
    static int[] rest, p_of_rest;

    public static void main(String[] args) throws Exception {
        input();
        solve();
        bw.write(ANS + "\n"); bw.flush(); bw.close();
    }

    static void input() throws Exception{
       st = new StringTokenizer(br.readLine());
       n_of_rest = Integer.parseInt(st.nextToken());
       more_rest = Integer.parseInt(st.nextToken());
       l_of_highway = Integer.parseInt(st.nextToken());

       st = new StringTokenizer(br.readLine());
       rest = new int[n_of_rest + 2];
       p_of_rest = new int[n_of_rest + 2];

       p_of_rest[0] = 0;
       for(int i = 1; i <= n_of_rest; i++){
           p_of_rest[i] = Integer.parseInt(st.nextToken());
       } p_of_rest[n_of_rest+1] = l_of_highway;

        Arrays.sort(p_of_rest);

        for(int i = 0; i <= n_of_rest; i++){
            rest[i] = p_of_rest[i+1] - p_of_rest[i] - 1;
        }
    }

    static void solve() throws Exception{
        int l = 0, r = l_of_highway, mid=0;

        while(l <= r){
            int cnt = 0;
            mid = (l+r) / 2;
            for(int i = 0; i <= n_of_rest; i++){
                cnt += rest[i]/ mid;
            }

            if(cnt > more_rest){
                l = mid + 1;
            }  else {
                r = mid - 1;
            }
        }
        ANS = l;
    }
}
