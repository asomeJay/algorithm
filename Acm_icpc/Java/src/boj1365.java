import java.util.*;
import java.io.*;

public class boj1365 {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int N, ANS;
    static int[] powerPole;
    static ArrayList<Integer> vector;

    public static void main(String[] args) throws Exception{
        input();
        solve();

        bw.write(ANS+"\n"); bw.flush(); bw.close();

    }

    static void input() throws Exception{
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());

        powerPole = new int[N+1];
        vector = new ArrayList<Integer>();
        st = new StringTokenizer(br.readLine());

        for(int i = 1; i <= N; i++){
            powerPole[i] = Integer.parseInt(st.nextToken());
        }
    }

    static void solve() throws Exception{
        vector.add(-1);
        for(int i = 1; i <= N;i++){
            int index = lowerBound(vector.size()-1, powerPole[i]);
            if(index >= vector.size()){
                vector.add(powerPole[i]);
            } else {
                vector.set(index, powerPole[i]);
            }
        }

        ANS = N - vector.size() + 1;
    }

    static int lowerBound(int r,int target){
        int left = 0, right =r+1, mid = 0;
        while(left < right){
            mid = (left + right)/2;
            if(vector.get(mid) >= target){
                right = mid;
            } else if (vector.get(mid) < target){
                left = mid+1;
            }
        }
        return right;
    }
}
