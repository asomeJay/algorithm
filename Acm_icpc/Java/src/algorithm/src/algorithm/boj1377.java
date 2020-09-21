import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class boj1377 {
    static class element implements Comparable<element>{
        int number, value;
        element(int a, int b){
            number = a;
            value = b;
        }


        @Override
        public int compareTo(element o) {
            return Integer.compare(this.value, o.value);
        }
    }

    static ArrayList<element> elementArrayList= new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int n = Integer.parseInt(new StringTokenizer(br.readLine()).nextToken());
        for(int i = 1; i <= n; i++){
            st =new StringTokenizer(br.readLine());

            int a = Integer.parseInt(st.nextToken());

            elementArrayList.add(new element(i, a));
        }
        Collections.sort(elementArrayList);
        int max = 0;
        for(int i = 1;i<=elementArrayList.size();i++){
            max = Integer.max(max, elementArrayList.get(i-1).number - i + 1);
        }
        bw.write(max + "\n");
        bw.flush();
    }

}
