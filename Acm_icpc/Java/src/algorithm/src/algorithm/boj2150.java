import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.lang.reflect.Array;
import java.util.*;

public class boj2150 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static int V, E, c;
    static ArrayList<Integer>[] edge;
    static ArrayList<ArrayList<Integer>> SCC;
    static int[] identifier;
    static boolean[] finished;
    static Stack<Integer> s = new Stack<Integer>();

    public static void main(String[] args) throws Exception {
        input();
        solve();
        bw.flush();
    }

    static int pI(String s) {
        return Integer.parseInt(s);
    }

    static void input() throws Exception {
        st = new StringTokenizer(br.readLine());
        V = pI(st.nextToken());
        E = pI(st.nextToken());

        identifier = new int[V+1];
        finished = new boolean[V+1];
        SCC = new ArrayList<ArrayList<Integer>>();
        edge = new ArrayList[V+1];

        for(int i = 0; i <= V;i++){
            edge[i] = new ArrayList<Integer>();
        }

        for (int i = 0; i < E; i++) {
            int a, b;
            st = new StringTokenizer(br.readLine());

            a = pI(st.nextToken());
            b = pI(st.nextToken());
            edge[a].add(b);
        }
    }

    static int dfs(int x) throws Exception {
        identifier[x] = ++c;
        s.push(x);

        int parent = identifier[x];
        for(int i = 0; i < edge[x].size(); i++){
            int y = edge[x].get(i);
            // 방문한 적 없는 노드
            if(identifier[y] == 0) parent = Math.min(parent, dfs(y));
            // 방문한 적은 있지만, 아직 처리 중인 노드
            else if(!finished[y]) parent = Math.min(parent, identifier[y]);
        }

        // 자기 자신이 부모라면
        if(parent == identifier[x]){
            ArrayList<Integer> t_scc = new ArrayList<Integer>();
            while(true){
                int t = s.peek();
                s.pop();
                t_scc.add(t);
                finished[t] = true;
                if(t == x) break;
            }
            SCC.add(t_scc);
        }

        return parent;
    }

    static void solve() throws Exception {
        for(int i = 1;i <= V; i++){
            if(identifier[i] == 0)
                dfs(i);
        }

        for(int i = 0; i < SCC.size() ;i++){
            Collections.sort(SCC.get(i));
        }

        Collections.sort(SCC, new Comparator<ArrayList<Integer>>() {
            @Override
            public int compare(ArrayList<Integer> o1, ArrayList<Integer> o2) {
                return Integer.compare(o1.get(0), o2.get(0));
            }
        });

        bw.write(""+SCC.size()+"\n");
        for(int i = 0; i < SCC.size(); i++){
            for(int j = 0; j < SCC.get(i).size(); j++){
                bw.write(SCC.get(i).get(j) + " ");
            }
            bw.write(-1 + "\n");
        }
    }

}
