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

        for(int i = 2; i <= N; i++){
            if(number[i])
                continue;
            number[i] = true;
            decimal.add(i);

            int k = i;
            for(int j = 1; j * k <= N; j++)
                number[k * j] = true;
        }

        for(int i = 0; i < decimal.size(); i++){
            System.out.print(decimal.get(i));
        }
    }
}
