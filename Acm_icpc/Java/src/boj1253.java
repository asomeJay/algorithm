import java.lang.reflect.Array;
import java.util.*;
import java.io.*;

public class boj1253 {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int[] arr;
    static int N, CNT;

    public static void main(String[] args) throws  Exception{
        input();
        solve();
        bw.write(CNT + "\n");
        bw.flush();
        bw.close();
    }

    static void input() throws Exception{

        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());

        arr = new int[N];
        for(int i = 0; i < N; i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }
    }

    static void solve() throws Exception{
        Arrays.sort(arr);

        for(int i = 0; i < N; i++){
            int left = 0, right = N-1;
            int target = arr[i];
            while(left < right){
                int summation = arr[left] + arr[right];
                if(summation < target){
                    left++;
                } else if(summation > target){
                    right--;
                } else{
                   if(i != left && i != right){
                       CNT++;
                       break;
                   }
                   if(left == i){
                      left++;
                   }
                   else {
                       right--;
                   }
                }
            }
        }
    }

}
