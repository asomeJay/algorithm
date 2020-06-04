import java.util.*;
import java.math.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x1, y1, r1, x2, y2, r2, tcase;
        tcase = sc.nextInt();
        for(int i = 0; i < tcase; i++){
            x1 = sc.nextInt();
            y1 = sc.nextInt();
            r1 = sc.nextInt();
            x2 = sc.nextInt();
            y2 = sc.nextInt();
            r2 = sc.nextInt();

            double d = dist(x1, y1, x2,y2);
            int r_max = Math.max(r1, r2);
            int r_min = Math.min(r1, r2);
            if(d == 0 && r1-r2 == 0){
                System.out.println(-1);
            }
            else if(d < r_max){ //  중심이 다른 원 안에 있다.
                if(r_max - d > r_min) {
                        // 서로 하나도 안만남
                    System.out.println(0);
                }
                else if(r_max - d == r_min){
                    // 한점에서 만남
                    System.out.println(1);
                }
                else {
                    // 두 점에서 만남
                    System.out.println(2);
                }
            }
            else { // 밖에 있음
                if(d > r1 +r2){ // 밖에있다
                    // 안만남
                    System.out.println(0);
                }
                else if(d == r1 +r2){
                    // 한 점에서 만남
                    System.out.println(1);
                }
                else {
                    // 두 점에서 만남남
                    System.out.println(2);
                }
            }

        }

    }

    public static double dist(int x1, int y1, int x2, int y2){
        return Math.sqrt(Math.pow(x2-x1, 2) + Math.pow(y2-y1, 2));
    }
}
