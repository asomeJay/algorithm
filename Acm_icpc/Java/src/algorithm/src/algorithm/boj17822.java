import java.io.*;
import java.util.*;

class Pair {
    int x, d, k;

    Pair(int a, int b, int c) {
        x = a;
        d = b;
        k = c;
    }
}

public class boj17822 {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static long N, M, T, answer = 0;
    static long[][] circle;
    static Pair[] circular;

    public static void main(String[] args) throws IOException {

        input();
        solve();
        bw.write("" + answer);
        bw.flush();
    }

    static long pL(String s) {
        return Long.parseLong(s);
    }

    static int pI(String s) {
        return Integer.parseInt(s);
    }

    static void input() throws IOException {
        st = new StringTokenizer(br.readLine(), " ");
        N = pL(st.nextToken());
        M = pL(st.nextToken());
        T = pL(st.nextToken());

        circle = new long[(int) N + 1][(int) M];
        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            for (int j = 0; j < M; j++) {
                circle[i][j] = pL(st.nextToken());
            }
        }

        circular = new Pair[(int) T];
        for (int i = 0; i < T; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            int a, b, c;
            a = pI(st.nextToken());
            b = pI(st.nextToken());
            c = pI(st.nextToken());

            circular[i] = new Pair(a, b, c);
        }
    }

    static void rotate(int t) {
        // circular[t] Operation

        // k는 회전 횟수
        for (int multi = 1; multi * circular[t].x <= N; multi++) {
            int currCircle = circular[t].x * multi;

            for (int cnt = 0; cnt < circular[t].k; cnt++) {
                // 시계방향
                if (circular[t].d == 0) {
                    long temp = circle[currCircle][(int) M - 1];
                    for (int i = (int) M - 1; i > 0; i--)
                        circle[currCircle][i] = circle[currCircle][i - 1];

                    circle[currCircle][0] = temp;
                }
                // 반 시계 방향
                else {
                    long temp = circle[currCircle][0];
                    for (int i = 0; i < M - 1; i++)
                        circle[currCircle][i] = circle[currCircle][i + 1];

                    circle[currCircle][(int) M - 1] = temp;
                }
            }
        }
    }

    static long[][] deepCopy(long [][]src ){
        long[][] result = new long[(int)N + 1][(int)M];
        for(int i = 1; i <= N; i++){
            System.arraycopy(src[i], 0, result[i], 0, src[i].length);
        }
        return result;
    }

    static void solve() throws IOException {

        for (int t = 0; t < T; t++) {
            // Rotate
            boolean flag = true;

            rotate(t);
            long[][] temp = deepCopy(circle);

//            System.out.println("rotate ");
//            for (int i = 1; i <= N; i++) {
//                for (int j = 0; j < M; j++) {
//                    System.out.print(temp[i][j] + " ");
//                }
//                System.out.println();
//            }
//            System.out.println();
            long summation = 0;

            for (int i = 1; i <= N; i++) {
                for (int j = 1; j < M; j++) {
                    // 인접했는데 같은 숫자는 다 지운다.
                    if(circle[i][0] != 0 && circle[i][0] == circle[i][(int)M-1]){
                        flag = false;
                        temp[i][0] = temp[i][(int)M-1] = 0;
                    }
                    if (circle[i][j] != 0 && circle[i][j] == circle[i][j - 1]) {
                        flag = false;
                        temp[i][j] = temp[i][j-1] = 0;
                    }
                }
            }

            for (int i = 0; i < M; i++) {
                for (int j = 1; j <= N; j++) {
                    if (circle[j][i] != 0 && (circle[j][i] == circle[j - 1][i])) {
                        flag = false;
                        temp[j][i] = temp[j - 1][i] = 0;
                    }
                }
            }

            // 인접한 수가 없으므로 평균에 더해줘야함
            if(flag == true){
                int cnt = 0;
                for(int i = 1; i <= N; i++){
                    for(int j = 0; j < M; j++){
                        if(temp[i][j] != 0) cnt++;
                        summation += temp[i][j];
                    }
                }
                // 평균을 구했다.
                double avg = (double)summation / cnt;
                for(int i = 1; i <= N; i++){
                    for(int j = 0; j < M; j++){
                        if(temp[i][j] != 0){
                            if(temp[i][j] > avg){
                                temp[i][j] --;
                            } else if(temp[i][j] < avg){
                              temp[i][j] ++;
                            }
                        }
                    }
                }
            }
            circle = deepCopy(temp);

//            System.out.println("rotate End ");
//            for (int i = 1; i <= N; i++) {
//                for (int j = 0; j < M; j++) {
//                    System.out.print(circle[i][j] + " ");
//                }
//                System.out.println();
//            }
//            System.out.println();
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < M; j++) {
                answer += circle[i][j];
            }
        }
    }

}
