import java.io.*;
import java.util.*;

public class boj1219 {

    private static int N;
    private static int startCity;
    private static int arriveCity;
    private static int nTransport;

    private static long[] money = new long[111];
    private static long[] profit = new long[111];
    private static Pair[] transports;

    private static long pL(String s) {
        return Long.parseLong(s);
    }

    private static int pI(String s){
        return Integer.parseInt(s);
    }

    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        N = pI(st.nextToken());
        startCity = pI(st.nextToken());
        arriveCity = pI(st.nextToken());
        nTransport = pI(st.nextToken());

        transports = new Pair[nTransport];
        Arrays.fill(money, Long.MIN_VALUE);

        for (int i = 0; i < nTransport; i++) {
            st = new StringTokenizer(br.readLine());

            int start = pI(st.nextToken());
            int end = pI(st.nextToken());
            int price = pI(st.nextToken());
            transports[i] = new Pair(start, end, price);
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) profit[i] = pL(st.nextToken());

        money[startCity] = profit[startCity];

        // Bellman-Ford Application
        // Relaxation
        for(int i = 0; i <= N + 100; i++){
            for(int j = 0; j < nTransport; j++){
                int src = transports[j].src;
                int dst = transports[j].dest;
                int weight = transports[j].price;

                // src가 한번도 방문하지않은 곳이면 체크할 필요 없음. 아직 단절된 상태
                if(money[src] == Long.MIN_VALUE) continue;

                // src가 사이클이라면 dst도 무한히 커진다.
                else if(money[src] == Long.MAX_VALUE) money[dst] = Long.MAX_VALUE;

                // 현재까지 기록된, dst까지의 최고 비용보다
                // src에서 출발해서 dst의 profit을 가지고 해당하는 간선의 비용을 치르는 게
                // 더 이득인 경우 갱신한다.
                else if(money[dst] < money[src] + profit[dst] - weight){
                    money[dst] = money[src] + profit[dst] - weight;

                    // 모든 정점을 순회한 후에도 갱신할 수 있다면 사이클 발생
                    if(i >= N-1) money[dst] = Long.MAX_VALUE;
                }
            }
        }

        // 단절된 곳이면 못가므로 gg
        if(money[arriveCity] == Long.MIN_VALUE) bw.write("gg\n");
        // 양의 사이클이 만들어졌으므로 Gee
        else if(money[arriveCity] == Long.MAX_VALUE) bw.write("Gee\n");
        // 이상의 케이스가 아니라면 정상적으로 출력한다.
        else bw.write(money[arriveCity]+ "\n");

        bw.flush();
    }
}

class Pair {
    int src, dest, price;

    Pair(int s,int d, int p) {
        src = s;
        dest = d;
        price = p;
    }
}
