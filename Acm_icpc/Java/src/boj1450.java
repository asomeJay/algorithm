import java.util.*;
import java.io.*;

public class boj1450 {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static StringTokenizer st;

    static int N, C, ANS = 1;
    static int[] array_of_N, half, rest_half;

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

        half = new int[1 << (N / 2)];
        rest_half = new int[1 << (N - N/2)];

        for(int i = 0; i < (1 << (N/2)); i++){
            for(int j = 0; j < N/2; j++){
                System.out.print((i  & j) + " ");
                if((i & j) == 1){
                    half[i] += array_of_N[j];
                }
            }
        }

        for(int i = 0; i < (1 << (N-N/2)); i++ ){
            for(int j = N/2; j < N; j++){
                System.out.print((i & (j - N/2)) + " " );
                if((i & (j - N/2)) == 1){
                    rest_half[i] += array_of_N[j];
                }
            }
        }
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
