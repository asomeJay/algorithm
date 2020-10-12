import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

public class boj13334 {

    static class Pair implements Comparable<Pair> {
        int start, end;
        Pair(int a, int b){
            start = a; end = b;
        }


        @Override
        public int compareTo(Pair o) {
            return Integer.compare(this.start, o.start);
        }
    }

    static int N, length;
    static ArrayList<Pair> pairs = new ArrayList<>();

    public static void main(String[] args) {
        try{
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
            BufferedReader br =new BufferedReader(new InputStreamReader(System.in));
            StringTokenizer st = new StringTokenizer(br.readLine());

            N = Integer.parseInt(st.nextToken());
            for(int i = 0; i < N ; i++){
                st = new StringTokenizer(br.readLine());
                int a, b;
                a = Integer.parseInt(st.nextToken());
                b = Integer.parseInt(st.nextToken());
                if(a >b){
                    int temp = a;
                    a = b;
                    b = temp;
                }

                pairs.add(new Pair(a,b));
            }

            length = Integer.parseInt(new StringTokenizer(br.readLine()).nextToken());

            Collections.sort(pairs, new Comparator<Pair>() {
                @Override
                public int compare(Pair o1, Pair o2) {
                    return Integer.compare(o1.end, o2.end);
                }
            });

            PriorityQueue<Integer> pq = new PriorityQueue<>();

            int count = 0, maximum = 0;
            for (Pair pair : pairs) {
                while (!pq.isEmpty() && pq.peek() < pair.end - length) {
                    pq.poll();
                    count--;
                }

                if (pair.start >= pair.end - length) {
                    count++;
                    pq.add(pair.start);
                }

                maximum = Math.max(maximum, count);
            }

            bw.write(maximum + "\n");
            bw.flush();

        } catch(Exception e){
            e.printStackTrace();
        }
    }
}