import java.io.*;
import java.util.StringTokenizer;

public class boj1670 {

    static long[] dp = new long[10010];

    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N;
        N = Integer.parseInt(st.nextToken());
        dps(N);
        bw.write(dp[N] + "\n");
        bw.flush();
    }

    static void dps(int N) {
        dp[0] = 1;
        dp[2] = 1;
        for(int i = 4; i <= N; i += 2){
            long temporalSum = 0;
            for(int j = i-2; j >= 0; j -=2){
                temporalSum += ((dp[j] * dp[i - 2 -j]) % 987654321);
                temporalSum %= 987654321;
            }
            dp[i] = temporalSum;

        }
    }
}