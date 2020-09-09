import java.io.*;
import java.util.*;

class Pair {
    int r, c;

    Pair(int a, int b) {
        r = a;
        c = b;
    }
}

public class boj4991 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static char[][] map;
    static int R, C, NOWR = 0, NOWC = 0, totalTime, dirtyCount;
    static int[][] table;
    static ArrayList<Pair> dirtyPoint;
    static int[] dr = {-1, 0, 1, 0};
    static int[] dc = {0, 1, 0, -1};

    static int pI(String s) {
        return Integer.parseInt(s);
    }

    static boolean isRange(int r, int c) {
        return 0 <= r && r < R && c >= 0 && c < C;
    }

    static boolean initAndInput() throws IOException {
        st = new StringTokenizer(br.readLine());

        C = pI(st.nextToken());
        R = pI(st.nextToken());

        if (R == 0 && C == 0) return false;

        map = new char[R][C];

        dirtyPoint = new ArrayList<>();
        totalTime = Integer.MAX_VALUE;
        dirtyCount = 0;

        for (int i = 0; i < R; i++) {
            st = new StringTokenizer(br.readLine());
            String temp = st.nextToken();
            for (int j = 0; j < C; j++) {

                map[i][j] = temp.charAt(j);
                if (map[i][j] == 'o') {
                    NOWR = i;
                    NOWC = j;
                    map[i][j] = '.';
                }
                if (map[i][j] == '*') {
                    dirtyPoint.add(new Pair(i, j));
                    dirtyCount++;
                }
            }
        }

        table = new int[dirtyCount + 1][dirtyCount + 1];

        return true;
    }

    public static void main(String[] args) throws IOException {

        while (true) {
            if (!initAndInput()) {
                return;
            } else {
                dirtyPoint.add(dirtyPoint.get(0));
                dirtyPoint.set(0, new Pair(NOWR, NOWC));
                dirtyCount ++;

                for(int i = 0; i < dirtyPoint.size(); i++){
                    table[i][i] = 0;
                    for(int j = i + 1; j < dirtyPoint.size(); j++){
                        table[i][j] = table[j][i] = bfs(i, j);
                    }
                }

                ArrayList<Integer> list = new ArrayList<>();
                boolean[] isVisit = new boolean[dirtyCount];

                make(dirtyCount-1, list, isVisit);
            }
            if(totalTime < 0) totalTime = -1;
            bw.write(totalTime + "\n");
            bw.flush();
        }
    }

    static int bfs(int src, int dest) {
        boolean[][] Visited = new boolean[R + 1][C + 1];
        Queue<Pair> q = new LinkedList<>();
        Queue<Integer> time = new LinkedList<>();
        Pair start;
        if (src == -1) {
            start = new Pair(NOWR, NOWC);
        } else {
            start = dirtyPoint.get(src);
        }

        Pair destination = dirtyPoint.get(dest);
        q.add(start);
        time.add(0);
        Visited[start.r][start.c] = true;

        while (!q.isEmpty()) {
            int rr = q.peek().r;
            int cc = q.poll().c;
            int currentTime = time.poll();

            if (rr == destination.r && cc == destination.c) {
                return currentTime;
            }

            for (int i = 0; i < 4; i++) {
                int nr = rr + dr[i];
                int nc = cc + dc[i];
                if (isRange(nr, nc) && !Visited[nr][nc] && map[nr][nc] != 'x') {
                    Visited[nr][nc] = true;
                    q.add(new Pair(nr, nc));
                    time.add(currentTime + 1);
                }
            }
        }
        return Integer.MIN_VALUE;
    }

    static void make(int dirty, ArrayList<Integer> list, boolean[] isVisit) {
        // 순서 지정이 모두 끝났다.
        if (dirty == 0) {
            int nowSum = table[0][list.get(0)];
            for (int i = 0; i < list.size() - 1; i++) {
                nowSum += table[list.get(i)][list.get(i+1)];
            }
            totalTime = Math.min(totalTime, nowSum);
            return;
        }

        for (int i = 1; i < dirtyPoint.size(); i++) {
            if (!isVisit[i]) {
                ArrayList<Integer> currentList = new ArrayList<>(list);
                currentList.add(i);

                isVisit[i] = true;
                make(dirty - 1, currentList, isVisit);
                isVisit[i] = false;
            }
        }
    }
}
