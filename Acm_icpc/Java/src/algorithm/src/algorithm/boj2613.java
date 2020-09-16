import java.io.*;
import java.util.StringTokenizer;

public class boj2613 {

    static int N, M, upperBound, lowerBound;
    static int[] nArr;

    static int pI(String s) {
        return Integer.parseInt(s);
    }

    static int isPossible(int mid) {
        int start = 0, cnt = 1;
        for (int i = 1; i <= N; i++) {
            start += nArr[i];
            if (start > mid) {
                start = nArr[i];
                cnt++;
            }
        }

        return cnt;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = pI(st.nextToken());
        M = pI(st.nextToken());
        nArr = new int[N + 1];

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            nArr[i] = pI(st.nextToken());
            upperBound += nArr[i];
            lowerBound = Math.max(lowerBound, nArr[i]);
        }

        // 이분탐색을 통해 최적해를 찾는다.

        int mid = 0;
        while (lowerBound <= upperBound) {
            mid = (lowerBound + upperBound) / 2;
            int cnt = isPossible(mid);
            if (cnt > M) {
                lowerBound = mid + 1;
            } else {
                upperBound = mid - 1;
            }
        }

        bw.write(lowerBound + "\n");
        int cnt = 0, sum = 0, i;
        for (i = 1; i <= N; i++) {
            sum += nArr[i];
            if (sum > lowerBound) {
                M--;
                cnt = (cnt == 0 ? 1 : cnt);
                bw.write(cnt + " ");
                sum = nArr[i];
                cnt = 0;
            }
            cnt++;

            // 1개씩 배치할 만한 구슬은 남겨둬야한다.
            if (M == N - i + 1) {
                break;
            }
        }
        for (; i <= N; i++) {
            bw.write(cnt + " ");
            cnt = 1;
        }
        bw.flush();
    }
}
