import java.util.*;
import java.io.*;

class Pair{
    Integer fir;
    Integer sec;

    public Pair(Integer key, Integer value){
        this.fir = key;
        this.sec = value;
    }
}

public class boj3190 {
    static int WALL = -1, SNAKE = -1;
    static int[] dr = {-1,0,1,0}, dc = {0,1,0,-1};

    static int APPLE = 2100000000;

    static int N, K, L;
    static int[][] board;
    static Snake snake;

    static BufferedReader br;
    static BufferedWriter bw;
    static StringTokenizer st;

    static class Snake{
        int dir;
        ArrayList<Pair> moveList = new ArrayList<>();
        HashMap<Integer, Character>inflectionPoint = new HashMap<Integer, Character>();

        Snake(){
            moveList.add(new Pair(1,1));
            this.dir = 1;
        }

        void setInflectionPoint(int second, char change){
            this.inflectionPoint.put(second, change);
        }

        char getInflectionPoint(int second){
            if(this.inflectionPoint.containsKey(second))
                return this.inflectionPoint.get(second);
            return '0';
        }
        void rotate(char dir) {
            if(dir == 'D'){
               if(this.dir == 3) {
                   this.dir = 0;
               } else {
                   this.dir++;
               }

            } else if(dir == 'L'){
                if(this.dir == 0){
                    this.dir = 3;
                } else {
                    this.dir--;
                }
            }
        }

        boolean is_crush(int r, int c){
           if(board[r][c] == WALL || board[r][c] == SNAKE){
               return true;
           }
            return false;
        }

        boolean move(int second){
            int nr = moveList.get(moveList.size()-1).fir + dr[this.dir];
            int nc = moveList.get(moveList.size()-1).sec + dc[this.dir];

            if(is_crush(nr, nc)) return false;

            moveList.add(new Pair(nr,nc));

            if(board[nr][nc] != APPLE){
                Pair temp = moveList.remove(0);
                board[temp.fir][temp.sec] = 0;
            }
            board[nr][nc] = SNAKE;
            if(this.getInflectionPoint(second) != '0'){
               this.rotate(this.getInflectionPoint(second));
            }

            return true;
        }
    }

    public static void main(String[] args) throws Exception {
        init();
        input();
        solve();
    }

    static void solve() throws IOException {
        int second = 1;
        while(snake.move(second++));

        bw.write(second-1 + "\n");
        bw.flush();
        bw.close();
    }

    static void init(){
        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        snake = new Snake();

    }

    static void input() throws  Exception{
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        K = Integer.parseInt(st.nextToken());

        board = new int[N+2][N+2];

        for(int i = 0; i <= N+1; i++){
            board[0][i] = board[N+1][i] = WALL;
            board[i][0] = board[i][N+1] = WALL;
        }
            board[1][1] = SNAKE;
        for(int i = 0; i < K; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            board[a][b] = APPLE;
        }

        st = new StringTokenizer(br.readLine());
        L = Integer.parseInt(st.nextToken());


        for(int i = 0; i <L; i++){
            st = new StringTokenizer(br.readLine());
            int key = Integer.parseInt(st.nextToken());
            char value = st.nextToken().charAt(0);
            snake.setInflectionPoint(key, value);
        }
    }

}
