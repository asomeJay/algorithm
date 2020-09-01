import java.io.*;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class Race implements Comparable<Race> {
    int pNum, deadline, ramenNum;

    Race(int a, int b, int c) {
        pNum = a;
        deadline = b;
        ramenNum = c;
    }

    @Override
    public int compareTo(Race o) {
        return Integer.compare(this.deadline, o.deadline);
    }
}

public class boj1781 {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static int N;
    static Race[] problems;

    public static void main(String[] args) throws Exception{
        input();
        solve();
        bw.flush();
    }

    static int pI(String s) { return Integer.parseInt(s);}

    static void input() throws Exception {
        st = new StringTokenizer(br.readLine());
        N = pI(st.nextToken());
        problems = new Race[N];

        for(int i = 0; i < N; i++){
            st = new StringTokenizer(br.readLine());
            problems[i] = new Race(i+1, pI(st.nextToken()), pI(st.nextToken()));
        }
    }

    static void solve() throws IOException {
        // 데드라인 기준으로 정렬한다.
        Arrays.sort(problems);

        PriorityQueue<Integer> pq = new PriorityQueue<Integer>();

        for(int i = 0; i < N;i++){
        // 현재 데드라인보다 많은 수의 과제를 수행할 수 없다.

            // 작은 것부터 위로오게 한다.
            pq.add(problems[i].ramenNum);
            while(pq.size() > problems[i].deadline)
                pq.poll();
        }

        int ans = 0;
        while(!pq.isEmpty())
            ans += pq.poll();

        bw.write(""+ans);
    }
}
