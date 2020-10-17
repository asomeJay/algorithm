import java.io.*;
import java.util.Arrays;
import java.util.Objects;
import java.util.StringTokenizer;

public class boj15653 {

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static class Marble {
        private int r, c;
        public boolean inHole;

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Marble marble = (Marble) o;
            return r == marble.r &&
                    c == marble.c;
        }

        @Override
        public int hashCode() {
            return Objects.hash(r, c);
        }

        @Override
        public String toString() {
            return "r = " + this.r + " c = " + this.c;
        }

        Marble(int a, int b) {
            r = a;
            c = b;
            this.inHole = false;
        }

        Marble(Marble a) {
            r = a.r;
            c = a.c;
            inHole = false;
        }

        public void tileLeft() {
            this.c--;
        }

        public void tileRight() {
            this.c++;
        }

        public void tileUp() {
            this.r--;
        }

        public void tileDown() {
            this.r++;
        }
    }

    static class Board {
        private int R, C;
        private int hole_r, hole_c;
        private Character[][] map;
        private Marble red, blue;

        private int[][][][] visited = new int[11][11][11][11];

        Board(int a, int b) {
            R = a;
            C = b;

            map = new Character[a][b];

            for (int i = 0; i < 11; i++) {
                for (int j = 0; j < 11; j++) {
                    for (int k = 0; k < 11; k++) {
                        for (int l = 0; l < 11; l++) {
                            visited[i][j][k][l] = Integer.MAX_VALUE;
                        }
                    }
                }
            }
        }

        public void setBoard() throws IOException {
            for (int i = 0; i < R; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                String s = st.nextToken();
                for (int j = 0; j < C; j++) {

                    map[i][j] = s.charAt(j);
                    if (map[i][j] == 'R') {
                        red = new Marble(i, j);
                    } else if (map[i][j] == 'B') {
                        blue = new Marble(i, j);
                    } else if (map[i][j] == 'O') {
                        hole_c = j;
                        hole_r = i;
                    }
                }
            }
        }

        public boolean noMove(Marble aM, Marble bM, Marble taM, Marble tbM){
            return aM.equals(taM) && bM.equals(tbM);
        }

        public boolean nextMove(Marble newm, Marble newb, Marble m, Marble b, int count){
            return !noMove(newm, newb, m, b) && (visited[newm.r][newm.c][newb.r][newb.c] > count);
        }

        public int relatedWithHole(Marble m ,Marble b){
            if (isHole(b)) {
                // blue to hole
                return -1 ;
            } else if (isHole(m)) {
                // red to hole but blue not in hole
                return 0;
            } else {
                return 1;
            }
        }

        public int tilting(Marble m, Marble b, int count) {

            int newCount = Integer.MAX_VALUE;
            // Up
            Marble newm = new Marble(m);
            Marble newb = new Marble(b);

            if (newm.r < newb.r) {
                tiltUp(newm, newb);
            } else {
                tiltUp(newb, newm);
            }

            if(newm.inHole && !newb.inHole) {
                return count;
            }

            if (!newb.inHole && nextMove(newm, newb, m, b, count)) {

                visited[newm.r][newm.c][newb.r][newb.c] = count;
                int result = tilting(newm, newb, count + 1);
                if (result != -1)
                    newCount = Math.min(newCount, result);
            }

            // Down
            newm = new Marble(m);
            newb = new Marble(b);

            if (newm.r > newb.r) {
                tiltDown(newm, newb);
            } else {
                tiltDown(newb, newm);
            }
            if(newm.inHole && !newb.inHole) {
                return count;
            }
            if (!newb.inHole && nextMove(newm, newb, m, b, count)) {

                visited[newm.r][newm.c][newb.r][newb.c] = count;
                int result = tilting(newm, newb, count + 1);
                if (result != -1)
                    newCount = Math.min(newCount, result);
            }
            // Left
            newm = new Marble(m);
            newb = new Marble(b);

            if (newm.c > newb.c) {
                tiltLeft(newb, newm);
            } else {
                tiltLeft(newm, newb);
            }
            if(newm.inHole && !newb.inHole) {
                return count;
            }
            if (!newb.inHole && nextMove(newm, newb, m, b, count)) {

                visited[newm.r][newm.c][newb.r][newb.c] = count;
                int result = tilting(newm, newb, count + 1);
                if (result != -1)
                    newCount = Math.min(newCount, result);
            }
            // Right
            newm = new Marble(m);
            newb = new Marble(b);

            if (newm.c > newb.c) {
                tiltRight(newm, newb);
            } else {
                tiltRight(newb, newm);
            }
            if(newm.inHole && !newb.inHole) {
                return count;
            }
            if (!newb.inHole && nextMove(newm, newb, m, b, count)) {

                visited[newm.r][newm.c][newb.r][newb.c] = count;
                int result = tilting(newm, newb, count + 1);
                if (result != -1)
                    newCount = Math.min(newCount, result);
            }

            return newCount;
        }

        public boolean isRange(Marble m) {
            return m.r >= 0 && m.r < R && m.c >= 0 && m.c < C && (map[m.r][m.c] != '#');
        }

        public boolean isHole(Marble m) {
            return m.r == hole_r && m.c == hole_c;
        }

        public boolean isCrash(Marble m, Marble b) {
            return ((m.r == b.r) && (m.c == b.c));
        }

        // m이 더 왼쪽에 있다.
        public void tiltLeft(Marble m, Marble b) {
            while (true) {
                m.tileLeft();
                if (!isRange(m)) {
                    m.tileRight();
                    break;
                }

                if (isHole(m)) {
                    m.r = m.c = -1;
                    m.inHole = true;
                    break;
                }
            }

            while (true) {
                b.tileLeft();
                if (!isRange(b) || isCrash(b, m)) {
                    b.tileRight();
                    break;
                }

                if (isHole(b)) {
                    b.r = b.c = -1;
                    b.inHole = true;
                    break;
                }
            }
        }

        public void tiltRight(Marble m, Marble b) {
            while (true) {
                m.tileRight();
                if (!isRange(m)) {
                    m.tileLeft();
                    break;
                }

                if (isHole(m)) {
                    m.r = m.c = -1;
                    m.inHole = true;
                    break;
                }
            }

            while (true) {
                b.tileRight();
                if (!isRange(b) || isCrash(b, m)) {
                    b.tileLeft();
                    break;
                }

                if (isHole(b)) {
                    b.r = b.c = -1;
                    b.inHole = true;
                    break;
                }
            }
        }

        public void tiltUp(Marble m, Marble b) {
            while (true) {
                m.tileUp();
                if (!isRange(m)) {
                    m.tileDown();
                    break;
                }

                if (isHole(m)) {
                    m.r = m.c = -1;
                    m.inHole = true;
                    break;
                }
            }

            while (true) {
                b.tileUp();
                if (!isRange(b) || isCrash(b, m)) {
                    b.tileDown();
                    break;
                }

                if (isHole(b)) {
                    b.r = b.c = -1;
                    b.inHole = true;
                    break;
                }
            }
        }

        public void tiltDown(Marble m, Marble b) {
            while (true) {
                m.tileDown();
                if (!isRange(m)) {
                    m.tileUp();
                    break;
                }

                if (isHole(m)) {
                    m.r = m.c = -1;
                    m.inHole = true;
                    break;
                }
            }

            while (true) {
                b.tileDown();
                if (!isRange(b) || isCrash(b, m)) {
                    b.tileUp();
                    break;
                }

                if (isHole(b)) {
                    b.r = b.c = -1;
                    b.inHole = true;
                    break;
                }
            }
        }
    }

    static int R, C;

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());

        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        Board board = new Board(R, C);

        // Input Setting
        board.setBoard();

        // Solve Problem
        int res = board.tilting(board.red, board.blue, 1);

        bw.write((res == Integer.MAX_VALUE ? -1 : res)                 + "\n");
        bw.flush();
    }
}
