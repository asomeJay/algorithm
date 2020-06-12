import java.util.*;
import java.io.*;

public class boj1114 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter  bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static int L, K ,C, ANS, ANS_INDEX;
    static int[] pos;

    public static void main(String[] args) throws Exception {
        input();
        solve();
        bw.write(ANS + " " + ANS_INDEX + "\n");
        bw.flush();
        bw.close();
    }

    static void input() throws Exception {
        ANS = ANS_INDEX = 0;
        st = new StringTokenizer(br.readLine());
        L = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        pos = new int[K+2];

        st = new StringTokenizer(br.readLine());
        pos[0] = 0;

        for(int i = 1; i <= K; i++){
            pos[i] = Integer.parseInt(st.nextToken());
        }
        pos[K+1] = L;

        Arrays.sort(pos); // sort 함수를 잘 쓰자...
    }

    static void solve(){
        int left, right, middle,i, start, cutting, flag;
        left = 1; right = L;

        while(left <= right){
           middle = (left + right) / 2;
           cutting = C;
           flag = 0;
           //System.out.println(" " + left + " " + middle + " " + right+"\n");

           start = pos[K+1];
           for(i = K; i >= 0; i--){
                if(pos[i] + middle >= start) continue;
                if(pos[i+1] - pos[i] > middle) {
                    flag = 1;
                    break;
                }
                if(left == right)
                    ANS = Math.max(ANS, start-pos[i+1]);

                start = pos[i+1];
                cutting--;
           }
           if(left == right){
               ANS = Math.max(ANS, start);
               if(cutting == 0){
                   ANS_INDEX = start;
               } else {
                   ANS_INDEX = pos[1];
               }

               return;
           }

           if(cutting < 0 || flag == 1){
               left = middle + 1;
           } else {
               right = middle;
           }
        }
    }
}
