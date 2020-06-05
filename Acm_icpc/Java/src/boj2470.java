import java.util.*;
import java.math.*;

public class boj2470 {
    static int N;
    static Vector<Long> a;

    public static void main(String[] args) {
       Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        a = new Vector<>();

        for(int i = 0; i < N; i++){
            a.add(sc.nextLong());
        }
        solve();
    }

    static void solve(){
        Collections.sort(a, new SComapare());

        int s_index = 0 , a_index = N-1;
        long target_s = 0, target_a = 0, smallest = 9876543210L;
        while(a_index > s_index){
            long temp = (a.get(a_index) + a.get(s_index));

            if(Math.abs(temp) < smallest){
                smallest = Math.abs(temp);
                target_s = a.get(s_index);
                target_a = a.get(a_index);
            }
            if(temp < 0){
                s_index++;
            }
            else
                a_index--;
        }
        System.out.print(target_s); System.out.print(" ");
        System.out.print(target_a);
    }
}

class AlcaliCompare implements Comparator<Long> {
    public int compare(Long a, Long b){
        if(a.intValue() < b.intValue()){
           return 1;
        } else if(a.intValue() == b.intValue()){
            return 0;
        }
        else {
            return -1;
        }
    }
}

class SComapare implements  Comparator<Long> {
    public int compare(Long a, Long b){
        if(a.intValue() < b.intValue()){
            return -1;
        } else if(a.intValue() == b.intValue()){
            return 0;
        }
        else {
            return 1;
        }
    }
}

