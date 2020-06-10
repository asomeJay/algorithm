import java.util.*;
import java.io.*;

class Person{
    String parent;
    int value;

    Person(String name){
        this.parent = name;
        this.value = 1;
    }
}

class Relation{
    HashMap<String, Person> relation;

    Relation(){
        this.relation = new HashMap<String, Person>();
    }

    void clear(){
        relation.clear();
    }
    void addPerson(String s) {
        if(relation.containsKey(s))
            return;

        relation.put(s, new Person(s));
    }

    int unionParent(String a, String b){
        String aPar = findParent(a);
        String bPar = findParent(b);

        if(aPar.compareToIgnoreCase(bPar) == 0){
            return relation.get(aPar).value;
        }

        Person aPer = relation.get(aPar);
        Person bPer = relation.get(bPar);

        if(aPer.value > bPer.value){
            aPer.value += bPer.value;
            bPer.parent = aPar;

            return aPer.value;
        } else {
            bPer.value += aPer.value;
            aPer.parent = bPar;

            return bPer.value;
        }
    }

    String findParent(String a){
        if(relation.get(a).parent == a){
            return a;
        } else {
            String temp = relation.get(a).parent;
            return relation.get(a).parent = findParent(temp);
        }
    }
}

public class boj4195 {
    static StringTokenizer st;
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static int testCase, friend;
    static String friend1, friend2;
    static Relation relation = new Relation();

    public static void main(String[] args) throws Exception {
        st = new StringTokenizer(br.readLine());
        testCase = Integer.parseInt(st.nextToken());

        for(int i = 0; i < testCase; i++){
            input();
            bw.flush();
            relation.clear();
        }
        br.close();
        bw.close();
    }

    static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        friend = Integer.parseInt(st.nextToken());

        for(int i = 0; i < friend; i++){
            st = new StringTokenizer(br.readLine());
            friend1 = st.nextToken();
            friend2 = st.nextToken();

            relation.addPerson(friend1);
            relation.addPerson(friend2);

            bw.write(relation.unionParent(friend1, friend2) + "\n");
        }
    }
}
