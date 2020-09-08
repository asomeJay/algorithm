import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class boj1507 {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int N;
    static int[][] map, result;

    static int pI(String s){return Integer.parseInt(s);}

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        N = pI(st.nextToken());
        map = new int[N+1][N+1];
        result = new int[N+1][N+1];

        for(int i = 1; i <= N; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 1; j <= N; j++){
                map[i][j] = pI(st.nextToken());
            }
        }

        for(int i = 1; i <= N; i++){
            result[i] = map[i].clone();
        }

        solve();
        bw.flush();

    }

    static void solve() throws IOException {
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                // 행과 열이 같으면 계산 X
                if(i == j) continue;

                for(int k = 1; k <= N; k++){
                    if(i == k || k == j) continue;
                    if(map[i][j] == (map[i][k] + map[k][j])){
                        result[i][j] = 0;
                    }  else if(map[i][j] > map[i][k] + map[k][j]){
                        bw.write("-1\n");
                        return;
                    }
                }
            }
        }
        int sum = 0;
        for(int i = 1; i <= N; i++){
            sum += Arrays.stream(result[i]).sum();
        }
        bw.write(sum /2 + "\n");

    }
}
