import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

public class boj17071 {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static int N, K;
    static Queue<Integer> q = new LinkedList<>();
    static int[][] visited = new int[500000 + 1][2];

    public static void main(String[] args) throws Exception {
        input();
        solve();
        bw.flush();
    }

    static void input() throws Exception {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        for (int i = 0; i <= 500000; i++) {
            visited[i][0] = visited[i][1] = -1;
        }
    }

    static void solve() throws Exception {
        q.add(N);
        visited[N][0 % 2] = 0;
        int time = 0;
        while (!q.isEmpty()) {
            int q_size = q.size();
            time++;

            while (q_size-- != 0) {

                int curr = q.poll();

                if (curr - 1 >= 0 && visited[curr - 1][time % 2] == -1) {
                    visited[curr - 1][time % 2] = time;
                    q.add(curr - 1);
                }
                if (curr + 1 <= 500000 && visited[curr + 1][time % 2] == -1) {
                    visited[curr + 1][time % 2] = time;
                    q.add(curr + 1);
                }
                if (curr * 2 <= 500000 && visited[curr * 2][time % 2] == -1) {
                    visited[curr * 2][time % 2] = time;
                    q.add(curr * 2);
                }
            }
        }

        int mini = 2100000000;
        for (int i = 0; K + i <= 500000; i++) {
            K += i;

            if (visited[K][i % 2] == i) {
                mini = i;
                break;
            } else if (i > visited[K][i % 2] && (i - visited[K][i % 2]) % 2 == 0) {
                mini = i;
                break;
            } else if (i % 2 == 0) {
                // 만약 짝수라면

                // 나보다 1 작은 칸, 1 큰 칸과 1초 차이나면 성공.
                if (K > 0 && i > visited[K - 1][1] && (i - visited[K - 1][1]) % 2 == 1) {
                    mini = i + 1;
                    break;
                }  else if(K + 1 <= 500000 && i > visited[K+1][1] && (i - visited[K+1][1])%2 == 1) {
                    mini = i + 1;
                    break;
                }

            } else if (i % 2 == 1) {
                // 만약 홀수라면

                // 나보다 1 작은 칸, 1 큰 칸과 1초 차이나면 성공.
                if (K > 0 && i > visited[K - 1][0] && (i - visited[K - 1][0]) % 2 == 1) {
                    mini = i + 1;
                    break;
                }  else if(K + 1 <= 500000 && i > visited[K+1][0] && (i - visited[K+1][0])%2 == 1) {
                    mini = i + 1;
                    break;
                }
            }
        }

        if (mini == 2100000000) {
            mini = -1;

        bw.write("" + mini);
    }
}
