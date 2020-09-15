import java.io.*;
import java.nio.Buffer;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class boj2143 {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int pI(String s) {
        return Integer.parseInt(s);
    }

    static void makeArr(ArrayList<Integer> destArr, int index, int[] srcArr, int sum) {
        if (index == srcArr.length) {
            return;
        }
        destArr.add(sum + srcArr[index]);
        makeArr(destArr, index + 1, srcArr, sum + srcArr[index]);
    }

    public static void main(String[] args) throws IOException {
        long t = Long.parseLong(new StringTokenizer(br.readLine()).nextToken());
        int n, m;

        n = pI(new StringTokenizer(br.readLine()).nextToken());
        int[] nArr = new int[n];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            nArr[i] = pI(st.nextToken());
        }

        m = pI(new StringTokenizer(br.readLine()).nextToken());
        int[] mArr = new int[m];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < m; i++) mArr[i] = pI(st.nextToken());

        ArrayList<Integer> nTargetArr = new ArrayList<>();
        ArrayList<Integer> mTargetArr = new ArrayList<>();

        for (int i = 0; i < nArr.length; i++) makeArr(nTargetArr, i, nArr, 0);
        for (int i = 0; i < mArr.length; i++) makeArr(mTargetArr, i, mArr, 0);

        Collections.sort(nTargetArr);
        Collections.sort(mTargetArr);

        int l = 0, r = mTargetArr.size() - 1;
        long count = 0;
        while (l < nTargetArr.size() && r >= 0) {
            long temp = nTargetArr.get(l) + mTargetArr.get(r);
            if (temp == t) {
                long ll = nTargetArr.get(l);
                long rr = mTargetArr.get(r);
                l++;
                r--;
                long lCount = 1, rCount = 1;

                while (l < nTargetArr.size() && ll == nTargetArr.get(l)) {
                    l++;
                    lCount++;
                }
                while (r >= 0 && rr == mTargetArr.get(r)) {
                    r--;
                    rCount++;
                }

                count += (lCount * rCount);

            } else if (temp < t) {
                l++;
            } else {
                r--;
            }
        }
        bw.write(count + "\n");
        bw.flush();
    }
}
