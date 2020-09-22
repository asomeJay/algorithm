import java.io.*;
import java.util.*;
import java.util.concurrent.LinkedBlockingDeque;

public class boj14867 {

    static class Pair {
        int n ,m;
        Pair(int a, int b){
            n = a; m = b;
        }

        @Override
        public String toString() {
            return String.valueOf(m) + "/" + String.valueOf(n);
        }
    }
    static int a,b,c,d;
    static int currentA, currentB, minimum = -1;
    static Map<String, Integer> pair = new HashMap<>();

    static int pI(String s){return Integer.parseInt(s);}

    static void pour(boolean flag ){
        // true == A to B
        if(flag){
            int restB = b - currentB;
            if(restB < currentA){
                currentB = b;
                currentA -= restB;
            }  else {
                currentB += currentA;
                currentA = 0;
            }
        }  else {
            int restA = a - currentA;
            if(restA < currentB){
                currentA = a;
                currentB -= restA;
            }  else {
                currentA += currentB;
                currentB = 0;
            }
        }
    }

    static void empty(boolean flag){
        // true == A
        if(flag){
            currentA = 0;
        }  else {
            currentB = 0;
        }
    }
    static void full(boolean flag){
        // true == A
        if(flag){
            currentA = a;
        }  else {
            currentB = b;
        }
    }

    static void afterOperation(Set<String> stringHashSet, Queue<Pair> q, int originA, int originB){
        if(!stringHashSet.contains(new Pair(currentA, currentB).toString())) {
            stringHashSet.add(new Pair(currentA, currentB).toString());
            q.add(new Pair(currentA, currentB));
        }
        currentA = originA;
        currentB = originB;
    }
    static void match(int cnt){

        Queue<Pair> q = new LinkedBlockingDeque<>();
        q.add(new Pair(currentA, currentB));

        Set<String> stringSet = new HashSet<>();
        stringSet.add(new Pair(currentA, currentB).toString());

        while(!q.isEmpty()){
            int qSize = q.size();
            minimum++;

            while(qSize-- != 0){
                currentA = q.peek().n;
                currentB = q.poll().m;

                if(currentA == c && currentB == d){
                    return;
                }

                int originA = currentA, originB = currentB;

                full(true);
                afterOperation(stringSet, q, originA, originB);

                full(false);
                afterOperation(stringSet, q, originA, originB);

                empty(true);
                afterOperation(stringSet, q, originA, originB);

                empty(false);
                afterOperation(stringSet, q, originA, originB);

                pour(true);
                afterOperation(stringSet, q, originA, originB);

                pour(false);
                afterOperation(stringSet, q, originA, originB);
            }
        }
        minimum = -1;
        return;
    }

    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br =new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        a = pI(st.nextToken());
        b = pI(st.nextToken());
        c = pI(st.nextToken());
        d = pI(st.nextToken());

        currentB = 0;
        currentA = 0;

        match(0);
        if(minimum == Integer.MAX_VALUE)
            minimum = -1;
        bw.write(minimum + "\n");
        bw.flush();
    }
}
