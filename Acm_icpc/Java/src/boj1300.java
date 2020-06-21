import java.util.*;
import java.io.*;

public class boj1300 {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int[][] A;
    static int[] B;
    static int N, K;

    public static void main(String[] args) {

    }

    public static void input() throws Exception{
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        K = Integer.parseInt(st.nextToken());

        A = new int[N+1][N+1];
        B = new int[(int)Math.pow(N+1,2)];
    }

    public static void solve() throws Exception {

    }
}
