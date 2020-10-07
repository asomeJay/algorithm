import java.io.*;
import java.util.*;

class Pair {
    int r, c;

    Pair(int a, int b) {
        r = a;
        c = b;
    }

    @Override
    public boolean equals(Object obj) {
        Pair p = (Pair) obj;
        return this.r == p.r && this.c == p.c;
    }
}

class Log {
    Direction status;
    Pair l, mid, r;

    Log(Log log) {
        this.status = log.status;
        this.l = new Pair(log.l.r, log.l.c);
        this.mid = new Pair(log.mid.r, log.mid.c);
        this.r = new Pair(log.r.r, log.r.c);
    }

    Log() {
        ;
    }

    @Override
    public boolean equals(Object obj) {
        Log logs = (Log) obj;
        return this.l.equals(logs.l) && this.mid.equals(logs.mid) && this.r.equals(logs.r);
    }

    @Override
    public String toString() {
        return "l : " + l.r + " " + l.c + " mid : " + mid.r + " " + mid.c + " r : "
                + r.r + " " + r.c;
    }

    public void setStatus(Direction status) {
        this.status = status;
    }

    public boolean isRange(int r, int c, int N) {
        return 1 <= r && r <= N && 1 <= c && c <= N;
    }

    public boolean U(Character[][] map, int N) {
        int highestRow = Math.min(l.r - 1, Math.min(mid.r - 1, r.r - 1));
        if (isRange(highestRow, 1, N)) {
            if (map[l.r - 1][l.c] != '1' && map[mid.r - 1][mid.c] != '1' && map[r.r - 1][r.c] != '1') {
                l.r--;
                mid.r--;
                r.r--;
                return true;
            }
        }
        return false;
    }

    public boolean D(Character[][] map, int N) {
        int lowestRow = Math.max(l.r + 1, Math.max(mid.r + 1, r.r + 1));
        if (isRange(lowestRow, 1, N)) {
            if (map[l.r + 1][l.c] != '1' && map[mid.r + 1][mid.c] != '1' && map[r.r + 1][r.c] != '1') {
                l.r++;
                mid.r++;
                r.r++;
                return true;
            }
        }
        return false;
    }

    public boolean L(Character[][] map, int N) {
        int leftestCol = Math.min(l.c - 1, Math.min(mid.c - 1, r.c - 1));
        if (isRange(1, leftestCol, N)) {
            if (map[l.r][l.c - 1] != '1' && map[mid.r][mid.c - 1] != '1' && map[r.r][r.c - 1] != '1') {
                l.c--;
                mid.c--;
                r.c--;
                return true;
            }
        }
        return false;
    }

    public boolean R(Character[][] map, int N) {
        int rightestCol = Math.max(l.c + 1, Math.max(mid.c + 1, r.c + 1));
        if (isRange(1, rightestCol, N)) {
            if (map[l.r][l.c + 1] != '1' && map[mid.r][mid.c + 1] != '1' && map[r.r][r.c + 1] != '1') {
                l.c++;
                mid.c++;
                r.c++;
                return true;
            }
        }
        return false;
    }

    /* 그 통나무를 둘러싸고 있는 3*3 정사각형의 구역에 단 한 그루의 나무도 없어야만 한다.*/
    public boolean T(Character[][] map, int N) {
        if (this.status.equals(Direction.R)) {
            for (int i = l.c; i <= r.c; i++) {
                for (int j = l.r - 1; j <= r.r + 1; j++) {
                    if (!isRange(j, i, N) || map[j][i] == '1')
                        return false;
                }
            }

            l.r--;
            l.c++;
            r.r++;
            r.c--;
            setStatus(Direction.C);
        } else if (this.status.equals(Direction.C)) {
            for (int i = l.r; i <= r.r; i++) {
                for (int j = l.c - 1; j <= r.c + 1; j++) {
                    if (!isRange(i, j, N) || map[i][j] == '1') {
                        return false;
                    }
                }
            }
            l.r++;
            l.c--;
            r.r--;
            r.c++;
            setStatus(Direction.R);
        } else {
            System.out.println("T ERROR");
            return false;
        }

        return true;
    }
}

enum Direction {
    R,
    C
}

public class Main {

    static int N, ret = Integer.MAX_VALUE;
    static Character[][] map = new Character[51][51];
    static Log targetLog = new Log(), originalLog = new Log();
    static boolean[][][] visited = new boolean[51][51][2];

    static int pI(String s) {
        return Integer.parseInt(s);
    }

    public static int bt(Log log) {

        Queue<Log> q = new LinkedList<>();
        q.add(log);
        visited[log.mid.r][log.mid.c][log.status.ordinal()] = true;

        int cnt = -1;
        while (!q.isEmpty()) {
            int q_size = q.size();
            cnt++;

            while (q_size-- != 0) {
                Log qLog = q.poll();
                if (targetLog.equals(qLog)) {
                    return cnt;
                }

                Log newLog = new Log(qLog);
                if (newLog.U(map, N) && !visited[newLog.mid.r][newLog.mid.c][newLog.status.ordinal()]) {
                    visited[newLog.mid.r][newLog.mid.c][newLog.status.ordinal()] = true;
                    q.add(newLog);
                }

                newLog = new Log(qLog);
                if (newLog.D(map, N) && !visited[newLog.mid.r][newLog.mid.c][newLog.status.ordinal()]) {
                    visited[newLog.mid.r][newLog.mid.c][newLog.status.ordinal()] = true;
                    q.add(newLog);
                }

                newLog = new Log(qLog);
                if (newLog.L(map, N) && !visited[newLog.mid.r][newLog.mid.c][newLog.status.ordinal()]) {
                    visited[newLog.mid.r][newLog.mid.c][newLog.status.ordinal()] = true;
                    q.add(newLog);
                }
                newLog = new Log(qLog);
                if (newLog.R(map, N) && !visited[newLog.mid.r][newLog.mid.c][newLog.status.ordinal()]) {
                    visited[newLog.mid.r][newLog.mid.c][newLog.status.ordinal()] = true;
                    q.add(newLog);
                }

                newLog = new Log(qLog);
                if (newLog.T(map, N) && !visited[newLog.mid.r][newLog.mid.c][newLog.status.ordinal()]) {
                    visited[newLog.mid.r][newLog.mid.c][newLog.status.ordinal()] = true;
                    q.add(newLog);
                }
            }
        }
        return 0;
    }

    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = pI(st.nextToken());
        int EtargetIndex = 0, BtargetIndex = 0;
        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            String s = st.nextToken();
            for (int j = 1; j <= N; j++) {
                map[i][j] = s.charAt(j - 1);

                if (map[i][j] == 'E') {
                    if (EtargetIndex == 0) {
                        targetLog.l = new Pair(i, j);
                    } else if (EtargetIndex == 1) {
                        targetLog.mid = new Pair(i, j);
                    } else if (EtargetIndex == 2) {
                        targetLog.r = new Pair(i, j);
                    }
                    EtargetIndex++;
                }

                if (map[i][j] == 'B') {
                    if (BtargetIndex == 0) {
                        originalLog.l = new Pair(i, j);
                    } else if (BtargetIndex == 1) {
                        originalLog.mid = new Pair(i, j);
                    } else if (BtargetIndex == 2) {
                        originalLog.r = new Pair(i, j);
                    }
                    BtargetIndex++;
                }
            }
        }

        if (originalLog.l.r != originalLog.r.r) {
            originalLog.setStatus(Direction.C);
            visited[originalLog.mid.r][originalLog.mid.c][Direction.C.ordinal()] = true;
        } else {
            originalLog.setStatus(Direction.R);
            visited[originalLog.mid.r][originalLog.mid.c][Direction.R.ordinal()] = true;
        }

        ret = bt(originalLog);
        if (ret == Integer.MAX_VALUE) ret = 0;
        bw.write(ret + "\n");
        bw.flush();
    }
}