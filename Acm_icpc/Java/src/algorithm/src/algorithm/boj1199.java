import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class boj1199 {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int N, edges;
    static int[][] edge;
    static boolean flag = false;
    static ArrayList<Integer> route = new ArrayList<>();

    static int pI(String s) {
        return Integer.parseInt(s);
    }

    static void dfs(int curr) throws Exception {

        for (int i = 1; i <= N; i++) {
            if (edge[curr][i] != 0) {
                edge[curr][i]--;
                edge[i][curr]--;

                dfs(i);
            }
        }
        bw.write(curr + " ");
    }


    public static void main(String[] args) throws Exception {
        N = pI(new StringTokenizer(br.readLine()).nextToken());
        edge = new int[N + 1][N + 1];
        int start = 0;
        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            int thisEdge = 0;

            for (int j = 1; j <= N; j++) {
                edge[i][j] = pI(st.nextToken());
                thisEdge += edge[i][j];
            }

            if ((thisEdge & 1) == 1) {
                bw.write("-1\n");
                bw.flush();
                return;
            }
            if (start == 0 && thisEdge > 0)
                start = i;
        }

        dfs(start);

        bw.flush();
    }
}
