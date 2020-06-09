import java.util.*;
import java.io.*;

class Person{
    int parent, value;
    String name;

    Person(int number, int value, String name){
        this.parent = number;
        this.name = name;
        this.value = value;
    }
}

class Relation{
    ArrayList<Person> relation;

    Relation(){
        relation = new ArrayList<Person>();
    }

    void addFriend(String a, String b){
       relation.
    }

    int unionParent(int a, int b){
        int aParent = findParent(a);
        int bParent = findParent(b);

        if(aParent == bParent) return relation.get(aParent).value;

        Person aPerson = relation.get(aParent);
        Person bPerson = relation.get(bParent);

        if(aPerson.value > bPerson.value){
            aPerson.value += bPerson.value;
            bPerson.parent = aParent;

            return aPerson.value;
        } else {
            bPerson.value += aPerson.value;
            aPerson.parent = bParent;

            return bPerson.value;
        }
    }

    int findParent(int a){
        if(relation.get(a).parent == a){
            return a;
        } else {
            int temp = relation.get(a).parent;
            return relation.get(a).parent = relation.get(temp).parent;
        }
    }
}

public class boj4195 {
    static StringTokenizer st;
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static int testCase, friend;
    static String friend1, friend2;

    public static void main(String[] args) throws Exception {
        st = new StringTokenizer(br.readLine());
        testCase = Integer.parseInt(st.nextToken());

        for(int i = 0; i < testCase; i++){
            input();
            solve();
        }
    }

    static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        friend = Integer.parseInt(st.nextToken());

        for(int i = 0; i < friend; i++){
            st = new StringTokenizer(br.readLine());
            friend1 = st.nextToken();
            friend2 = st.nextToken();

        }
    }

    static void solve() throws Exception {

    }

}
