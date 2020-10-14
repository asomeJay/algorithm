import java.io.*;
import java.util.StringTokenizer;

public class boj15653 {

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static class Marble {
        private int r, c;

        @Override
        public String toString() {
            return "r = " + this.r + " c = " + this.c;
        }

        Marble(int a, int b) {
            r = a;
            c = b;
        }

        Marble(Marble a) {
            r = a.r;
            c = a.c;
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
        private boolean[][][][] visited = new boolean[11][11][11][11];

        Board(int a, int b) {
            R = a;
            C = b;

            map = new Character[a][b];
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

        public int tilting(Marble m, Marble b, int count) {
            if (isHole(b)) {
                // blue to hole
                return -1;
            } else if (isHole(m)) {
                // red to hole but blue not in hole
                return count;
            }

            System.out.println(m.toString() + " " + b.toString() + " count = " + count);

            int newCount = Integer.MAX_VALUE;
            // Up
            Marble newm = new Marble(m);
            Marble newb = new Marble(b);
            boolean flag = false;
            if (newm.r > newb.r) {
                flag |= tiltUp(newm, newb);
                flag |= tiltUp(newb, newm);
            } else {
                flag |= tiltUp(newb, newm);
                flag |= tiltUp(newm, newb);
            }

            if (flag && !visited[newm.r][newm.c][newb.r][newb.c]) {
                visited[newm.r][newm.c][newb.r][newb.c] = true;
                int result = tilting(newm, newb, count + 1);
                if(result != -1)
                    newCount = Math.min(newCount, result);
            }

            // Down
            newm = new Marble(m);
            newb = new Marble(b);
            flag = false;
            if (newm.r > newb.r) {
                flag |= tiltDown(newm, newb);
                flag |= tiltDown(newb, newm);
            } else {
                flag |= tiltDown(newb, newm);
                flag |= tiltDown(newm, newb);
            }
            if (flag && !visited[newm.r][newm.c][newb.r][newb.c]) {
                visited[newm.r][newm.c][newb.r][newb.c] = true;
                int result = tilting(newm, newb, count + 1);
                if(result != -1)
                    newCount = Math.min(newCount, result);
            }
            // Left
            newm = new Marble(m);
            newb = new Marble(b);
            flag = false;
            if (newm.c > newb.c) {
                flag |= tiltLeft(newb, newm);
                flag |= tiltLeft(newm, newb);
            } else {
                flag |= tiltLeft(newm, newb);
                flag |= tiltLeft(newb, newm);
            }

            if (flag && !visited[newm.r][newm.c][newb.r][newb.c]) {
                visited[newm.r][newm.c][newb.r][newb.c] = true;
                int result = tilting(newm, newb, count + 1);
                if(result != -1)
                    newCount = Math.min(newCount, result);
            }
            // Right
            newm = new Marble(m);
            newb = new Marble(b);
            flag = false;
            if (newm.c > newb.c) {
                flag |= tiltRight(newm, newb);
                flag |= tiltRight(newb, newm);
            } else {
                flag |= tiltRight(newb, newm);
                flag |= tiltRight(newm, newb);
            }
            if (flag&& !visited[newm.r][newm.c][newb.r][newb.c]) {
                visited[newm.r][newm.c][newb.r][newb.c] = true;
                int result = tilting(newm, newb, count + 1);
                if(result != -1)
                    newCount = Math.min(newCount, result);
            }

            return newCount;
        }

        public boolean canMove(Marble m) {
            return isRange(m) && !isHole(m);
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

        public boolean tiltLeft(Marble m, Marble b) {
            boolean flag = false;
            while (true) {
                m.tileLeft();
                if (!isRange(m) || isCrash(m, b)) {
                    m.tileRight();
                    break;
                }
                flag = true;
            }
            return flag;
        }

        public boolean tiltRight(Marble m, Marble b) {
            boolean flag = false;
            while (true) {
                m.tileRight();
                if (!isRange(m) || isCrash(m, b)) {
                    m.tileLeft();
                    break;
                }
                flag = true;
            }
            return flag;
        }

        public boolean tiltUp(Marble m, Marble b) {
            boolean flag = false;
            while (true) {
                m.tileUp();
                if (!isRange(m) || isCrash(m, b)) {
                    m.tileDown();
                    break;
                }
                flag = true;
            }
            return flag;
        }

        public boolean tiltDown(Marble m, Marble b) {
            boolean flag = false;
            while (true) {
                m.tileDown();
                if (!isRange(m) || isCrash(m, b)) {
                    m.tileUp();
                    break;
                }
                flag = true;
            }
            return flag;
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
        bw.write(board.tilting(board.red, board.blue, 0) + "\n");
        bw.flush();
    }
}
