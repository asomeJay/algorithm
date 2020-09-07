import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class Pair implements Comparable<Pair> {
    int src, weight;

    Pair(int a, int b) {
        src = a;
        weight = b;
    }

    @Override
    public int compareTo(Pair o) {
        return Integer.compare(this.weight, o.weight);
    }
}

class Two {
    int a, b;
    Two(int c, int d){
        a = c; b= d;
    }
}

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int N, M;
    static int[] dist = new int[1001], history = new int[1001];
    static List<Two> list = new ArrayList<>();

    static int[][] edge = new int[1001][1001];
    static PriorityQueue<Pair> pq = new PriorityQueue<>();

    static int pi(String s) {
        return Integer.parseInt(s);
    }

    public static void dfs() {
        dist[1] = 0;
        pq.add(new Pair(1, 0));

        while (!pq.isEmpty()) {
            int src = pq.peek().src;
            int weight = pq.poll().weight;

            for (int i = 1; i <= N; i++) {
                if (edge[src][i] != -1 && dist[i] > weight + edge[src][i]) {

                    history[i] = src;
                    pq.add(new Pair(i, weight + edge[src][i]));
                    dist[i] = weight + edge[src][i];
                }
            }
        }

        for (int i = 2; i <= N; i++) {
            // each history
            list.add(new Two(i, history[i]));
        }
    }

    public static void main(String[] args) throws Exception {
        st = new StringTokenizer(br.readLine());
        N = pi(st.nextToken()); M = pi(st.nextToken());

        Arrays.fill(dist, 210000000);
        for(int i = 1; i <= 1000; i++){
            Arrays.fill(edge[i], -1);
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int a, b, c;
            a = pi(st.nextToken());
            b = pi(st.nextToken());
            c = pi(st.nextToken());

            edge[a][b] = edge[b][a] = c;
        }

        dfs();
        bw.write(list.size() + "\n");
        for(Two t : list)
            bw.write(t.a + " " + t.b + "\n");
        bw.flush();
    }
}
