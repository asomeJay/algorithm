import java.util.*;
import java.io.*;

public class boj1450 {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static StringTokenizer st;

    static int N, C, ANS = 1;
    static int[] array_of_N;

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
        Arrays.sort(array_of_N);
    }

    public static void solve() throws Exception{
        int l = 0, r = 0, m= 0, i;
        for(i = 0; i < N && m <= C; i++){
            m += array_of_N[i];
        }
        i--;
        ANS = (int)Math.pow(2, i);
    }
}
