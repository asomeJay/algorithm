import java.util.*;
import java.math.*;

public class Main {
    static boolean number[];
    static int N;
    static Vector<Integer> decimal;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();

        number = new boolean[N + 1];
        number[1] = true;

        decimal = new Vector<Integer>();
        for (int i = 2; i <= N; i++) {
            if (number[i])
                continue;
            number[i] = true;
            decimal.add(i);

            int k = i;
            for (int j = 1; j * k <= N; j++)
                number[k * j] = true;
        }
        /* 소수는 다 구했다 */
        int start = 0, end = 1, count = 0;
        int sum = 0;
        if(!decimal.isEmpty())
            sum = decimal.get(0);

        while (!decimal.isEmpty()) {
            if (sum == N) {
                count++;
                sum -= decimal.get(start);
                start++;
            } else if (sum > N) {
                sum -= decimal.get(start);
                start++;
            } else if (sum < N) {
                if(end == decimal.size())
                    break;
                sum += decimal.get(end);
                end++;
            } else {
                System.out.println("ERROR");
            }
        }
        System.out.println(count);
    }
}
