import java.nio.Buffer;
import java.util.*;
import java.io.*;

public class boj1561 {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int N, M;
    static int[] minute_per_device;
    public static void main(String[] args) throws Exception{

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

    }
}
