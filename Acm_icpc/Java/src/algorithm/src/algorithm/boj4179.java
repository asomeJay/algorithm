import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class pair {
    int r, c;

    pair(int a, int b) {
        r = a;
        c = b;
    }
}

public class boj4179 {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static int R, C;
    static char[][] maze;
    static pair jh;
    static Queue<pair> fireQ = new LinkedList();
    static int[] dr = {-1, 0, 1, 0};
    static int[] dc = {0, 1, 0, -1};

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
        R = pI(st.nextToken());
        C = pI(st.nextToken());
        maze = new char[R + 1][C + 1];

        for (int i = 1; i <= R; i++) {
            st = new StringTokenizer(br.readLine());
            String t = st.nextToken();
            for (int j = 1; j <= C; j++) {
                maze[i][j] = t.charAt(j - 1);
                // 지훈이의 현재 위치를 저장한다.
                if (maze[i][j] == 'J')
                    jh = new pair(i, j);

                // 불을 저장한다.
                if (maze[i][j] == 'F') {
                    fireQ.add(new pair(i, j));
                }
            }
        }
    }

    static boolean is_range(int r, int c) {
        return r > 0 && r <= R && c > 0 && c <= C;
    }

    static void solve() throws Exception {
        boolean[][] isVisit = new boolean[R + 1][C + 1];
        Queue<pair> jhPos = new LinkedList<pair>();
        isVisit[jh.r][jh.c] = true;

        jhPos.add(new pair(jh.r, jh.c));

        int time = 0;
        outbreak:
        while(true) {
            int j_size = jhPos.size();
            int f_size = fireQ.size();
            time++;

            if(j_size == 0){
                bw.write("IMPOSSIBLE");
                break;
            }
            while(f_size-- != 0){
                pair curr = fireQ.poll();

                for (int i = 0; i < 4; i++) {
                    int nr = curr.r + dr[i];
                    int nc = curr.c + dc[i];

                    // 범위 안이고, 방문한 적 없고, 벽이면
                    if (is_range(nr, nc) && maze[nr][nc] != '#' && maze[nr][nc] != 'F') {
                        maze[nr][nc] = 'F';
                        fireQ.add(new pair(nr, nc));
                    }
                }
            }

            while (j_size-- != 0) {
                pair curr = jhPos.poll();

                for (int i = 0; i < 4; i++) {
                    int nr = curr.r + dr[i];
                    int nc = curr.c + dc[i];

                    if(is_range(nr, nc) == false){
                        bw.write(time+"");
                        break outbreak;
                    }
                    // 범위 안이고, 방문한 적 없고, 벽이면
                    if (isVisit[nr][nc] == false && maze[nr][nc] != '#' && maze[nr][nc] != 'F') {
                        isVisit[nr][nc] = true;
                        jhPos.add(new pair(nr, nc));
                    }
                }
            }

        }
    }

}
