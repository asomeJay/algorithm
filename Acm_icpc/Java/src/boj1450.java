import java.lang.reflect.Array;
import java.util.*;
import java.io.*;

public class boj1450 {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static StringTokenizer st;

    static int N, C, ANS;

    static int[] array_of_N;
    static ArrayList<Integer> half, rest_half;

    public static void main(String[] args)  throws Exception{
        input();
        solve();
        bw.write(ANS + "\n");
        bw.flush();
        bw.close();
    }

    static void input() throws Exception{
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        array_of_N = new int[N];

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++){
            array_of_N[i] = Integer.parseInt(st.nextToken());
        }

        half = new ArrayList<Integer>();
        rest_half = new ArrayList<Integer>();
    }

    public static void solve() throws Exception{
        dfs(0, (N/2)-1, 0, 0);
        dfs(N/2, N-1, 0, 1);
        int cnt = 0;
        for(int i = 0; i < half.size(); i++){
            for(int j = 0; j < rest_half.size(); j++){
               if(half.get(i) + rest_half.get(j) <= C)
                   ANS++;
            }
        }
   }

   static void dfs(int s, int e, int sum, int list){
        if(sum > C) return;
        if(s > e) {
            if(list == 0){
               half.add(sum);
            } else {
                rest_half.add(sum);
            }
            return;
        }
        dfs(s + 1, e, sum, list);
        dfs(s + 1, e, sum + array_of_N[s], list);
   }
}
