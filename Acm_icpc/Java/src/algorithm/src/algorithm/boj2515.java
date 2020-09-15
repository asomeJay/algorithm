import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class boj2515 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    // dp[i] = 1부터 i 까지 최댓값
    static long[] dp = new long[300001];
    static long[] dd = new long[300001];
    static long nPaint, s;
    static ArrayList<Paint> arrPaint = new ArrayList<>();

    static class Paint implements Comparable<Paint> {
        int height, price;

        Paint(int a, int b) {
            height = a;
            price = b;
        }

        @Override
        public int compareTo(Paint o) {
            if (this.height == o.height)
                return -Integer.compare(this.price, o.price);

            return Integer.compare(this.height, o.height);
        }
    }

    public static long pL(String s) {
        return Long.parseLong(s);
    }

    public static int pI(String s) {
        return Integer.parseInt(s);
    }

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        nPaint = pL(st.nextToken()); s = pL(st.nextToken());

        arrPaint.add(new Paint(0, 0));

        for (int i = 0; i < nPaint; i++) {
            st = new StringTokenizer(br.readLine());
            int a = pI(st.nextToken()), b = pI(st.nextToken());
            arrPaint.add(new Paint(a, b));
        }

        Collections.sort(arrPaint);

        // i 보다 앞에 세울 수 있는 그림 중 키가 제일 큰 그림
        for (int i = 1; i <= nPaint; i++) {
            if (arrPaint.get(i).height < s) continue;

            for (dd[i] = dd[i - 1]; dd[i] < i; dd[i]++) {
                if (arrPaint.get(i).height - arrPaint.get((int) dd[i]).height < s)
                    break;
            }
            dd[i]--;
        }

        // i를 세우거나 세우지 않거나 두 가지 경우의 수
        for (int i = 1; i <= nPaint; i++) {
            dp[i] = arrPaint.get(i).price + dp[(int)dd[i]];
            dp[i] = Math.max(dp[i], dp[i-1]);
        }

        bw.write(dp[(int)nPaint] + "\n");
        bw.flush();
    }
}
