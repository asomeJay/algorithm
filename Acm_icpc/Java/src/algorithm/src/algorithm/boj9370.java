import java.awt.image.AreaAveragingScaleFilter;
import java.io.*;
import java.util.*;

class Pair implements Comparable<Pair> {
    int node, weight;

    Pair(int a, int b) {
        node = a;
        weight = b;
    }

    @Override
    public int compareTo(Pair o) {
        return Integer.compare(this.weight, o.weight);
    }
}

public class boj9370 {

    static int n, m, t, s, g, h;
    static List<Pair>[] edge;
    static List<Integer> objectCandidate;
    static int[] distSrc, history, distNose, distH;
    static PriorityQueue<Pair> pq = new PriorityQueue<>();
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int pi(String s) {
        return Integer.parseInt(s);
    }

    static void dijkstra(int src, int[] dist) throws IOException {
        pq.clear();
        dist[src] = 0;
        pq.add(new Pair(src, 0));

        while (!pq.isEmpty()) {
            int curr = pq.peek().node;
            int weight = pq.poll().weight;

            for (Pair p : edge[curr]) {
                if (dist[p.node] > weight + p.weight) {
                    dist[p.node] = weight + p.weight;
                    pq.add(new Pair(p.node, weight + p.weight));
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int test;
        test = pi(st.nextToken());

        while (test-- != 0) {
            st = new StringTokenizer(br.readLine());
            n = pi(st.nextToken());
            m = pi(st.nextToken());
            t = pi(st.nextToken());
            st = new StringTokenizer(br.readLine());
            s = pi(st.nextToken());
            g = pi(st.nextToken());
            h = pi(st.nextToken());

            edge = new ArrayList[n + 1];
            for (int i = 0; i <= n; i++) edge[i] = new ArrayList<>();

            distSrc = new int[n + 1];
            distNose = new int[n+1];
            objectCandidate = new ArrayList<>();

            Arrays.fill(distSrc, Integer.MAX_VALUE);
            Arrays.fill(distNose, Integer.MAX_VALUE);

            for (int i = 0; i < m; i++) {
                st = new StringTokenizer(br.readLine());
                int a, b, c;
                a = pi(st.nextToken());
                b = pi(st.nextToken());
                c = pi(st.nextToken());
                edge[a].add(new Pair(b, c));
                edge[b].add(new Pair(a, c));
            }

            for (int i = 0; i < t; i++) {
                st = new StringTokenizer(br.readLine());
                objectCandidate.add(pi(st.nextToken()));
            }

            List<Integer> list = new ArrayList<>();

            dijkstra(s, distSrc);
            if(distSrc[g] < distSrc[h]){
                dijkstra(h, distNose);
                for(int target : objectCandidate){
                    if(distSrc[target] == distSrc[h] + distNose[target]){
                        list.add(target);
                    }
                }
            }  else{
                dijkstra(g, distNose);
                for(int target: objectCandidate){
                    if(distSrc[target] == distSrc[g] + distNose[target]){
                        list.add(target);
                    }
                }
            }
            list.sort(new Comparator<Integer>() {
                @Override
                public int compare(Integer o1, Integer o2) {
                    return Integer.compare(o1,o2);
                }
            });
            for(int answer : list){
                bw.write(answer + " ");
            }bw.write("\n");
            bw.flush();
        }
    }
}
