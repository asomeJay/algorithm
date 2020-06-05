import java.util.*;

public class boj1806 {
    static Vector<Integer> number;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N, target_S;
        N = sc.nextInt();
        target_S = sc.nextInt();

        number = new Vector<Integer>();

        for (int i = 0; i < N; i++) {
            number.add(sc.nextInt());
        }

        int start = 0, end = 1, sum = 0, shortest = 1000000000, cur_length = 1;
        sum = number.get(start);

        while(true) {
            if(sum >= target_S){
                if(shortest > cur_length){
                    shortest = cur_length;
                }
                if(start == number.size())
                    break;
                sum -= number.get(start);
                start++;
                cur_length--;

            }
            else {
                if(end == number.size())
                    break;
                sum += number.get(end);
                end++;
                cur_length++;
            }
        }
        if(shortest == 1000000000)
            shortest = 0;
        System.out.println(shortest);
    }
}
