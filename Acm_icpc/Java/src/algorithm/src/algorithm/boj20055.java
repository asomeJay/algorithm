import java.io.*;
import java.lang.*;
import java.util.*;

public class boj20055 {

    static int N, K, S, turn;
    static int[] conveyor;
    static ArrayList<Integer> robots = new ArrayList<>();

    static void rotate(){
        S = (S == 1 ? N : --S);
    }

    static void robotMove(){
        for(Integer i : robots){
            int nxt = (i + 1 > N ? 1 : i + 1);
            boolean overlap = robots.stream().anyMatch(n-> n == nxt);

            if(conveyor[nxt] != 0 && !overlap ){
                i = nxt;
                conveyor[i]--;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br =new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer( br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        conveyor = new int[N+1];

        st = new StringTokenizer(br.readLine());

        for(int i = 1; i <= N; i++) conveyor[i] = Integer.parseInt(st.nextToken());

        

    }
}
