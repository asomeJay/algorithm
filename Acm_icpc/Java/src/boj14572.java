import java.io.*;
import java.util.*;

class Node {
    long id;
    long d;
    ArrayList<Long> algorithm;

    Node(long id, long d) {
        this.id = id;
        this.d = d;
        algorithm = new ArrayList<Long>();
    }
    public void algoAdd(long i) {
        algorithm.add(i);
    }
}

public class boj14572 {
    static long N, K, D, MAX;
    static ArrayList<Node> student;
    static ArrayList<ArrayList<Long>> tree;
    static ArrayList<Long> int_tree;

    static BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter sw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) {
        try{
            StringTokenizer st = new StringTokenizer(sc.readLine());
            N = Integer.parseInt(st.nextToken());
            K = Integer.parseInt(st.nextToken());
            D = Integer.parseInt(st.nextToken());
            MAX = 0;
//System.out.println(N); System.out.println(K); System.out.println(D);
        long height = (long)Math.ceil(Math.log10(N) / Math.log10(2));
        student = new ArrayList<Node>();
        tree = new ArrayList<ArrayList<Long>>();
        int_tree = new ArrayList<Long>();

        for(int i = 0; i < 1<<(height+1); i++){
            tree.add(new ArrayList<Long>());
            int_tree.add(0L);
        }
        for(int i = 0; i < N; i++){
            st = new StringTokenizer(sc.readLine());

            long M = Integer.parseInt(st.nextToken());
            long d = Integer.parseInt(st.nextToken());
//            System.out.print(M); System.out.print(" "); System.out.println(d);
            student.add(new Node(i, d));

            st = new StringTokenizer(sc.readLine());
            for(int j = 0; j < M; j++) {
                long A = Integer.parseInt(st.nextToken());
                student.get(i).algoAdd(A);
            }
            Collections.sort(student.get(i).algorithm);
        }

        Collections.sort(student, new NodeDComparator());
        solve();

        System.out.println(MAX);

    } catch(Exception e){
            e.printStackTrace();
        }
    }
    public static void solve(){
       seg_init(1, 0,N-1);
       for(int i = 1; i < tree.size(); i++){
           int_tree.set(i, (long)tree.get(i).size());
       }

       long start = 0, end = 1, diff = 0;
       long diff_algo = student.get((int)start).algorithm.size();

        while(true){
            if(diff > D){

                diff_algo -= student.get((int)start).algorithm.size();

                start++;
                if(start == student.size())
                    break;
                diff = student.get((int)end).d - student.get((int)start).d;
            } else {
                long E = (diff_algo - seg_diff(1, 0, N-1, start, end-1)) *
                        (end - start) ;
                MAX = Math.max(MAX, E);

                diff += student.get((int)end).d;
                diff_algo += student.get((int)end).algorithm.size();

                end++;
                if(end == student.size())
                    break;
                diff = student.get((int)end).d - student.get((int)start).d;
            }

        }

    }
    public static long seg_diff(long node, long start, long end, long ts, long te) {
        if(end < ts || te < start){
            return 0;
        } else if(end >= ts && te >= start){
            return int_tree.get((int)node);
        } else {
            return seg_diff(node * 2, start, (start+end)/2, ts, te) +
            seg_diff(node * 2 + 1, (start+end)/ 2 + 1, end, ts, te);
        }
    }

    public static ArrayList<Long> seg_init(long node, long start, long end) {
        if(start == end){
            ArrayList<Long> temp = student.get((int)start).algorithm;
            tree.set((int)node, temp);
            return temp;

        } else {
            ArrayList<Long> temp;
            temp = same(seg_init(node * 2, start, (start+end)/2),
                    seg_init(node * 2 + 1, (start + end)/2+1, end));
            tree.set((int)node, temp);
            return temp;
        }
    }

   public static ArrayList<Long> same(ArrayList<Long> a, ArrayList<Long> b) {
        ArrayList<Long> temp = new ArrayList<Long>();
        long a_index = 0, b_index = 0;

        while(a_index != a.size() && b_index != b.size()){
            if(a.get((int)a_index) == b.get((int)b_index)){
                temp.add(a.get((int)a_index));
                a_index++; b_index++;
            }
            else {
                if(a.get((int)a_index) > b.get((int)b_index)){
                    b_index++;
                }
                else {
                     a_index++;
                }
            }
        }
        return temp;
   }
}

class NodeDComparator implements Comparator{

    public int compare(Object arg0, Object arg1){
        Node a = (Node)arg0;
        Node b = (Node)arg1;

        return a.d < b.d ? 1: a.d > b.d ? -1 : 0;
    }
}

