import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

class Pair {
    int r, c, cnt, time;

    Pair(int r, int c, int cnt, int time) {
        this.r = r;
        this.c = c;
        this.cnt = cnt;
        this.time = time;
    }
}

public class boj14442 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static int N, M, K;
    static int[] dr = {-1, 0, 1, 0}, dc = {0, 1, 0, -1};
    static boolean[][][] isVisit;
//    static String[] map;
    static char[][] map;
    static Queue<Pair> q = new ArrayDeque<Pair>();

    public static void main(String[] args) throws Exception {
        input();
        solve();
        bw.flush();
    }

    static int pI(String s) {
        return Integer.parseInt(s);
    }

    static void input() throws Exception {
        st = new StringTokenizer(br.readLine());
        N = pI(st.nextToken());
        M = pI(st.nextToken());
        K = pI(st.nextToken());

//        map = new String[N+1];
        map = new char[N+1][M+1];
        isVisit = new boolean[N + 1][M + 1][11];

        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            String temp = st.nextToken();
            for(int j = 0; j < temp.length(); j++){
                map[i][j+1] = temp.charAt(j);
            }
        }
    }

    static boolean isRange(int r, int c) {
        return r >= 1 && r <= N && c >= 1 && c <= M;
    }

    static void solve() throws Exception {
        isVisit[1][1][0] = true;
        q.add(new Pair(1, 1, 0, 1));

        while (!q.isEmpty()) {
            int rr = q.peek().r;
            int cc = q.peek().c;
            int cnt = q.peek().cnt;
            int time = q.peek().time;

            if(rr == N && cc== M ){
                bw.write(""+time);
                return;
            }

            q.poll();

            for (int i = 0; i < 4; i++) {
                int nr = rr + dr[i];
                int nc = cc + dc[i];

                if (isRange(nr, nc)) {
                    // 벽이 있을 때 뚫고 가거나 가지않는다.
                    if(map[nr][nc] == '1'){
                        if(cnt < K && !isVisit[nr][nc][cnt+1]){
                            isVisit[nr][nc][cnt+1] = true;

                            q.add(new Pair(nr, nc, cnt+1, time + 1));
                        }
                    }  else if(!isVisit[nr][nc][cnt]){

                        isVisit[nr][nc][cnt] = true;

                        q.add(new Pair(nr, nc, cnt, time + 1));
                    }
                }
            }
        }

        bw.write(-1+"");
    }
}
