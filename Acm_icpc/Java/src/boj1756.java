import java.util.*;
import java.io.*;

public class boj1756 {
    static BufferedWriter bw;
    static BufferedReader br;
    static StringTokenizer st;

    static int D, N;
    static int []oven, pizza;

    public static void main(String[] args) throws Exception {
        bw = new BufferedWriter(new OutputStreamWriter(System.out));
        br = new BufferedReader(new InputStreamReader(System.in));

        st = new StringTokenizer(br.readLine());
        D = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());

        oven = new int[300001];
        pizza = new int[300001];

        st = new StringTokenizer(br.readLine());
        oven[0] = 2100000000;
        for(int i = 1; i <= D; i++){
            oven[i] = Math.min(Integer.parseInt(st.nextToken()), oven[i-1]);
        }

        st = new StringTokenizer(br.readLine());

        for(int i = 1; i <= N;i++){
            pizza[i] = Integer.parseInt(st.nextToken());
        }

        int index = 1, i;
        for(i = D; i >0; i--){
            if(pizza[index] > oven[i]) continue;
            index++;
            if(index > N){
                bw.write(i + "\n");
                break;
            }
        }
        if(i == 0){
            bw.write(0 + "\n");
        }
        bw.flush();
        bw.close();
    }
}
