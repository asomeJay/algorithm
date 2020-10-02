import java.io.*;
import java.util.*;

public class boj9661 {

    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        long res = Long.parseLong(st.nextToken()) % 5;
        // Win Lose Win Win Lose
        if(res == 1 || res == 3 || res == 4){
            bw.write("SK\n");
        } else {
            bw.write("CY\n");
        }
        bw.flush();
    }
}
