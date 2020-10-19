import java.io.*;
import java.lang.*;
import java.util.*;

public class boj20055 {

    static int N, K, S = 1, turn;
    static int[] conveyor;
    static ArrayList<Integer> robots = new ArrayList<>();

    static int rotate() {

        int last = conveyor[2 * N];

        System.arraycopy(conveyor, 1, conveyor, 2, 2 * N - 1);
        conveyor[1] = last;

        int exit = -1, zero = 0;
        for (int i = 0; i < robots.size(); i++) {
            int next = (robots.get(i) == 2 * N ? 1 : robots.get(i) + 1);
            robots.set(i, next);

            if (next == N)
                exit = i;
        }

        if (exit != -1)
            robots.remove(exit);

        return zero;
    }

    static int robotMove() {
        int exit = -1, zero = 0;
        for (int i = 0; i < robots.size(); i++) {
            int next = (robots.get(i) == 2 * N ? 1 : robots.get(i) + 1);
            if (conveyor[next] > 0 && robots.stream().noneMatch(n -> n == next)) {
                robots.set(i, next);
                conveyor[next]--;
                if (conveyor[next] == 0)
                    zero++;
            }

            if (next == N)
                exit = i;
        }

        if (exit != -1)
            robots.remove(exit);

        return zero;
    }

    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        conveyor = new int[2 * N + 1];

        st = new StringTokenizer(br.readLine());

        for (int i = 1; i <= 2 * N; i++) conveyor[i] = Integer.parseInt(st.nextToken());

        int zeroCount = 0;
        while (zeroCount < K) {

            turn++;
            zeroCount += rotate();
            zeroCount += robotMove();

            boolean isFirst = robots.stream().anyMatch(n -> n == 1);
            if (!isFirst && conveyor[1] > 0) {
                robots.add(1);
                conveyor[1]--;
                if(conveyor[1] == 0){
                    zeroCount++;
                }
            }
        }

        bw.write(turn + "\n");
        bw.flush();
    }
}
