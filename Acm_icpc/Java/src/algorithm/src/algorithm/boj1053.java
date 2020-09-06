import java.io.*;

public class boj1053 {

    static StringBuffer s = new StringBuffer();
    // i: 시작 j: 끝, 즉 dp[i][j] = i ~ j 범위까지 펠린 드롬 만드는 최솟값
    static int[][] dp = new int[51][51];

    static void swap(int src, int dst) {
        char temp = s.charAt(src);
        s.setCharAt(src, s.charAt(dst));
        s.setCharAt(dst, temp);
    }

    public static void dps(int[][] dp, int ch, int ta) {
        // 문자 위치 바꾸기
        swap(ch, ta);

        // dp 배열 초기화하기
        for (int i = 0; i < s.length(); i++) {
            dp[i][i] = 0;
            if (i < s.length() - 1) {
                if (s.charAt(i) == s.charAt(i + 1)) dp[i][i + 1] = 0;
                else dp[i][i + 1] = 1;
            }
        }

        for (int i = 2; i < s.length(); i++) {
            for (int j = 0; j + i < s.length(); j++) {
                dp[j][j + i] = Math.min(dp[j + 1][j + i] + 1, dp[j][j + i - 1] + 1);
                if (s.charAt(j + i) == s.charAt(j)) dp[j][j + i] = Math.min(dp[j + 1][j + i - 1], dp[j][j + i]);
                else dp[j][j + i] = Math.min(dp[j + 1][j + i - 1] + 1, dp[j][j + i]);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int result = Integer.MAX_VALUE;

        s.append(br.readLine().trim());

        // 원래 문자열에서 팰린드롬 만드는 값 구하기
        dps(dp, 0,0);
        result = dp[0][s.length()-1];

        // 이제 바꾼 문자열에서 팰린드롬 만드는 값 구한다.
        for (int ch = 0; ch < s.length(); ch++) {
            for (int ta = ch + 1; ta < s.length(); ta++) {
                dps(dp, ch, ta);
                result = Math.min(result, dp[0][s.length() - 1] + 1);
                // 문자열 원상복구 시키기
                swap(ch, ta);
            }
        }
        bw.write(result + "\n");
        bw.flush();
    }
}
