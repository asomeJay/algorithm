import java.util.*;
import java.io.*;

public class boj1208 {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int N, S, ANS, plusIndex, minusIndex;
    static Integer[] plus, minus, arr;

    public static void main(String[] args) throws Exception{
        input();
        solve();
        bw.write(ANS + "\n"); bw.flush(); bw.close();
    }

    static void input() throws Exception{
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        S = Integer.parseInt(st.nextToken());

        arr = new Integer[N];

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++){
            int temp = Integer.parseInt(st.nextToken());
            arr[i] = temp;
        }
        for(Integer i: arr){
            System.out.println(i);
        }
        int half = N / 2;
        minus = new Integer[1 << (N-half)];
        plus = new Integer[1 << half];

        for(int i = 0; i < 1 << (N-half); i++){
            for(int j = 0; j < N-half; j++){
                System.out.println((i & (1 << j)) + " " + j + " " +(1 << j));
                if((i & (1 << j)) == (1 << j)){
                    minus[i] += arr[j];
                }
            }
        }

        for(int i = 0; i < 1 << half; i++){
            for(int j = 0; j < half; j++){
                if((i & (1 << j)) == (1<<j)){
                    plus[i] += arr[j + (N-half)];
                }
            }
        }
        for(Integer i: plus){
            System.out.println(i);
        }
        Arrays.sort(minus,
                new Comparator<Integer>() {
                    @Override
                    public int compare(Integer o1, Integer o2) {
                        return o1.compareTo(o2);
                    }
                });

        Arrays.sort(plus);
    }

    static void solve() throws Exception{
       for(Integer i: minus){
           bw.write(i + "\n");
       } for(Integer i : plus){
           bw.write(i + "\n");
        }
   }
}
