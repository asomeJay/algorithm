import java.lang.reflect.Array;
import java.util.*;
import java.io.*;

public class boj1253 {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static HashSet<Integer> hashSet = new HashSet<Integer>();

    static int[] arr;
    static ArrayList<Integer> number;
    static int N, CNT;

    public static void main(String[] args) throws  Exception{
        input();
        solve();
        bw.write(hashSet.size() + "\n");
        bw.flush();
        bw.close();
    }

    static void input() throws Exception{
       number = new ArrayList<Integer>();

        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        arr = new int[N];
        for(int i = 0; i < N; i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }
    }

    static void solve() throws Exception{
        for(int i = 0; i < N; i++){
            for(int j = i+1; j < N; j++){
                if(arr[i] == 0 || arr[j] == 0)
                    continue;
                number.add(arr[i] + arr[j]);
            }
        }

        HashSet<Integer> intermediate = new HashSet<Integer>(number);
        ArrayList<Integer> afterNumber = new ArrayList<Integer>(intermediate);

        Arrays.sort(arr);
        afterNumber.sort(new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o1.compareTo(o2);
            }
        });

        int left = 0, right = 0;
        while(left != arr.length && right != afterNumber.size()){
           if(arr[left]> afterNumber.get(right)){
                right++;
           }  else if(arr[left] < afterNumber.get(right)){
                left++;
           } else {
               left++; right++;
               while(left != arr.length && arr[left] == arr[left-1])
                   left++;
               while(right != afterNumber.size() && afterNumber.get(right).equals(afterNumber.get(right-1)))
                   right++;

               hashSet.add(arr[left-1]);
           }
        }
    }
}
