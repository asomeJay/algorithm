import java.util.*;
import java.io.*;

class Pair{
    int left, right;
    Pair(int a, int b){
        this.left = a;
        this.right = b;
    }

    int compare(Pair a){
        if(this.left < a.left){
            return -1;
        } else if(this.left == a.left){
            return 0;
        } else {
            return 1;
        }
    }
}

public class boj2568 {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int n_of_electric, ANS;

    static int[] index_of_selected_line;
    static ArrayList<Pair> selected_line, electric_line;

    public static void main(String[] args) throws Exception{
        input(); solve();

        bw.write(ANS + "\n");

        int index_of_print_line = selected_line.size()-1;

        for(int i = n_of_electric - 1; i >= 0; i--){
            if(index_of_selected_line[i] == index_of_print_line){
                index_of_selected_line[i] = -1;
                index_of_print_line--;
            }
        }

        for(int i = 0; i < n_of_electric;i++){
            if(index_of_selected_line[i] != -1){
                bw.write(electric_line.get(i).left + "\n");
            }
        }
        bw.flush(); bw.close();
    }

    public static void input() throws Exception{
        st = new StringTokenizer(br.readLine());
        n_of_electric = Integer.parseInt(st.nextToken());
        index_of_selected_line = new int[n_of_electric + 1];

        electric_line = new ArrayList<Pair>();
        selected_line = new ArrayList<Pair>();

        for(int i = 0; i < n_of_electric; i++){
            st = new StringTokenizer(br.readLine());

            int a, b;
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());

            electric_line.add(new Pair(a,b));
        }
        electric_line.sort(new Comparator<Pair>() {
            @Override
            public int compare(Pair o1, Pair o2) {
                return o1.compare(o2);
            }
        });
    }

    public static void solve() throws Exception{
        for(int i = 0; i < n_of_electric; i++){
            int index_of_current_position = lowerBound(electric_line.get(i).right);
            index_of_selected_line[i] = index_of_current_position;

            if(index_of_current_position >= selected_line.size()){
                selected_line.add(electric_line.get(i));
            }
            else {
                selected_line.set(index_of_current_position, electric_line.get(i));
            }
        }
        ANS = n_of_electric - selected_line.size();
    }

    static int lowerBound(int target){
        int s = 0, e = selected_line.size();
        while(s < e){
            int mid = (s + e ) /2;
            if(selected_line.get(mid).right< target){
                s = mid + 1;
            }
            else {
                e = mid;
            }
        }
        return s;
    }
}
