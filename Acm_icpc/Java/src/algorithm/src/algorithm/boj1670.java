import java.io.*;
import java.util.StringTokenizer;

public class boj1670 {

    static int N;

    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br =new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st= new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());

        bw.write(bt(-1) + "\n") ;
        bw.flush();
    }

    static int bt(int index){
        if(index == (2/N)){
            return 1;
        }

        if(index > (2/N)) return 0;
        int ret = 0;
        ret += bt(index + 1) % 987654321;
        ret += bt(index + 2) % 987654321;

        return ret % 987654321;
    }
}