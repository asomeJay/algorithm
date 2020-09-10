import java.io.*;
import java.util.*;

class Move implements Comparable<Move> {
    int r, c, k, dist;
    boolean day;

    Move(int a, int b, int cc, int d, boolean day) {
        r = a;
        c = b;
        k = cc;
        dist = d;
        this.day = day;
    }

    @Override
    public int compareTo(Move o) {
        return Integer.compare(this.dist, o.dist);
    }
}

public class boj16933 {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int N, M, K;
    static String[] map;
    static boolean[][][] Visit = new boolean[1001][1001][11];
    static int[] dr = {-1, 0, 1, 0};
    static int[] dc = {0, 1, 0, -1};

    static int pI(String s) {
        return Integer.parseInt(s);
    }

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        N = pI(st.nextToken());
        M = pI(st.nextToken());
        K = pI(st.nextToken());
        map = new String[N + 2];

        for (int i = 1; i <= N; i++) {
            map[i] = "-";
            map[i] += br.readLine();
        }

        bfs();

        bw.flush();

    }

    static boolean isRange(int r, int c) {
        return 1 <= r && r <= N && c >= 1 && c <= M;
    }

    static void bfs() throws IOException {
        PriorityQueue<Move> moveQueue = new PriorityQueue<>();
        moveQueue.add(new Move(1, 1, K, 1, true));
        Visit[1][1][K] = true;

        int root = Integer.MAX_VALUE;

        while (!moveQueue.isEmpty()) {
            int rr = moveQueue.peek().r;
            int cc = moveQueue.peek().c;
            int kk = moveQueue.peek().k;
            int dist = moveQueue.peek().dist;
            boolean day = moveQueue.poll().day;

            if (rr == N && cc == M) {
                bw.write(dist + "\n");
                return;
            }

            for (int i = 0; i < 4; i++) {
                int nr = rr + dr[i];
                int nc = cc + dc[i];

                if (isRange(nr, nc)) {
                    if (!Visit[nr][nc][kk] && map[nr].charAt(nc) == '0') {
                        Visit[nr][nc][kk] = true;
                        moveQueue.add(new Move(nr, nc, kk, dist + 1, !day));
                    }

                    if (map[nr].charAt(nc) == '1') {
                        if (kk > 0 && !Visit[nr][nc][kk - 1]) {
                            Visit[nr][nc][kk - 1] = true;

                            if (day)
                                moveQueue.add(new Move(nr, nc, kk - 1, dist + 1, false));
                            else
                                moveQueue.add(new Move(nr, nc, kk - 1, dist + 2, false));
                        }
                    }
                }
            }
        }
        bw.write(-1+"\n");
        return;
    }

//    static void dfs(int r, int c, int k, int dist, boolean day){
//        if(dist > root) return;
//        if(r == N && c == M){
//            root= Math.min(dist, root);
//            return;
//        }
//
//
//
//
//
//        boolean newDay = day;
////        for (int newDist = dist + 1; newDist  <= dist + 2; newDist++, newDay = !day) {
//
////        }
//    }
}
