import java.io.*;
import java.util.*;

class Pair {
    int r, c;

    Pair(int a, int b) {
        r = a;
        c = b;
    }

    Pair() {
        ;
    }
}

public class boj18809 {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static int N, M, G, R, flower;
    static int[] dr = {-1, 0, 1, 0}, dc = {0, 1, 0, -1};
    static int[][] map, times;
    static final int lake = 0, dead = 1, can = 2;
    static final int redMedium = 3, greenMedium = 4, flowerMedium = 5;

    // 배양액을 뿌릴 수 있는 곳
    static List<Pair> cultureMdeium = new ArrayList<>();

    // 빨간색 배양액 뿌린 곳
    static List<Pair> red = new ArrayList<>();

    // 초록색 배양액 뿌린곳
    static List<Pair> green = new ArrayList<>();

    // 배양액을 이미 뿌린 곳
    static boolean[] isUsed;

    static int pI(String s) {
        return Integer.parseInt(s);
    }

    static boolean isRange(int r, int c) {
        return r >= 0 && r < N && c >= 0 && c < M;
    }

    static boolean canPlant(int r, int c, int color, int[][] pot) {
        if (!isRange(r, c)) return false;

        return pot[r][c] != lake && pot[r][c] != color && pot[r][c] != flowerMedium;
    }

    static int plantFlower(int currSize, Queue<Pair> q, int[][] flowerPot, int srcMedium, int dstMedium, int time) {
        int curFlower = 0;

        while (currSize != 0) {
            currSize--;
            int rr = q.peek().r;
            int cc = q.poll().c;

            if (flowerPot[rr][cc] == flowerMedium || flowerPot[rr][cc] == dstMedium)
                continue;

            for (int i = 0; i < 4; i++) {
                int nr = rr + dr[i];
                int nc = cc + dc[i];

                // 여기에 src 배양액을 심을 수 있다.
                if (canPlant(nr, nc, srcMedium, flowerPot)) {

                    if (flowerPot[nr][nc] == dstMedium) {
                        if (times[nr][nc] == time) {
                            curFlower++;
                            flowerPot[nr][nc] = flowerMedium;
                        }
                    } else {
                        times[nr][nc] = time;
                        flowerPot[nr][nc] = srcMedium;
                        q.add(new Pair(nr, nc));
                    }
                }
            }
        }
        return curFlower;
    }

    static void blossom(int[][] flowerPot) {
        Queue<Pair> gQueue = new LinkedList<>(green);
        Queue<Pair> rQueue = new LinkedList<>(red);

        for (int[] arr : times) {
            Arrays.fill(arr, -1);
        }

        for (Pair g : gQueue) {
            flowerPot[g.r][g.c] = greenMedium;
            times[g.r][g.c] = 0;
        }
        for (Pair r : rQueue) {
            flowerPot[r.r][r.c] = redMedium;
            times[r.r][r.c] = 0;
        }

        int curFlower = 0, time = 0;

        while (!gQueue.isEmpty() || !rQueue.isEmpty()) {
            time++;
            int greenSize = gQueue.size();
            int redSize = rQueue.size();

            curFlower += plantFlower(greenSize, gQueue, flowerPot, greenMedium, redMedium, time);
            curFlower += plantFlower(redSize, rQueue, flowerPot, redMedium, greenMedium, time);
        }

        flower = Math.max(flower, curFlower);
    }

    // 어디에 어떤 배양액을 뿌릴 지 정한다.
    static void select(int r, int g, int index) {
        // 남은게 더 적어
        if (r + g > cultureMdeium.size() - index)
            return;
        // 다 골랐습니다.
        if (r == 0 && g == 0) {

            int[][] flowerPot = new int[N][M];
            for (int i = 0; i < N; i++)
                flowerPot[i] = map[i].clone();
            blossom(flowerPot);
            return;
        }
        if (index == cultureMdeium.size())
            return;

        select(r, g, index + 1);

        if (r != 0) {
            red.add(cultureMdeium.get(index));
            select(r - 1, g, index + 1);
            red.remove(cultureMdeium.get(index));
        }
        if (g != 0) {
            green.add(cultureMdeium.get(index));
            select(r, g - 1, index + 1);
            green.remove(cultureMdeium.get(index));
        }
    }

    public static void main(String[] args) throws Exception {
        st = new StringTokenizer(br.readLine());
        N = pI(st.nextToken());
        M = pI(st.nextToken());
        G = pI(st.nextToken());
        R = pI(st.nextToken());

        map = new int[N][M];
        times = new int[N][M];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());

            for (int j = 0; j < M; j++) {
                map[i][j] = pI(st.nextToken());
                if (map[i][j] == can) {
                    cultureMdeium.add(new Pair(i, j));
                }
            }
        }

        isUsed = new boolean[cultureMdeium.size() + 1];
        Arrays.fill(isUsed, false);

        select(R, G, 0);
        bw.write(flower + "\n");
        bw.flush();
    }
}
