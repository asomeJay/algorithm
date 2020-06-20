import java.lang.reflect.Array;
import java.util.*;
import java.io.*;

class Pair{
    Integer a, b, add;
    Pair(int a, int b, int d){
        this.a = a;
        this.b = b;
        this.add = d;
    }
}

public class boj1253 {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int[] arr;
    static boolean[] is_visit;
    static ArrayList<Pair> number;
    static int N, CNT;

    public static void main(String[] args) throws  Exception{
        input();
        solve();
        bw.write(CNT + "\n");
        bw.flush();
        bw.close();
    }

    static void input() throws Exception{
       number = new ArrayList<Pair>();

        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());

        is_visit = new boolean[N];
        arr = new int[N];
        for(int i = 0; i < N; i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }
    }

    static void solve() throws Exception{
        for(int i = 0; i < N; i++){
            for(int j = i+1; j < N; j++){
                number.add(new Pair(i,j,arr[i] + arr[j]));
            }
        }

        Arrays.sort(arr);
        number.sort(new Comparator<Pair>() {
            @Override
            public int compare(Pair o1, Pair o2) {
                return o1.add.compareTo(o2.add);
            }
        });

        int left = 0, right = 0;

        while(left != arr.length && right != number.size()){
           if(arr[left]> number.get(right).add){
                right++;
           }  else if(arr[left] < number.get(right).add){
                left++;
           } else {
               int temp = right;
               while(temp < number.size() && number.get(temp).add.equals(arr[left])){
                   if(( number.get(temp).a.equals(left))|| number.get(temp).b.equals(left)){
                       temp++;
                       continue;
                   }
                   CNT++;
                   break;
               }
               left++;
           }
        }
    }
}
