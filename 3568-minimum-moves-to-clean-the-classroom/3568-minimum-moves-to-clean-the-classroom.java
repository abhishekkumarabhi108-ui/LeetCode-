import java.util.*;

class Solution {
    public int minMoves(String[] classroom, int energy) {
        int m = classroom.length;
        int n = classroom[0].length();

        // Find starting position and litter positions
        int startR = 0;
        int startC = 0;

        List<int[]> litters = new ArrayList<>();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char ch = classroom[i].charAt(j);

                if (ch == 'S') {
                    startR = i;
                    startC = j;
                } else if (ch == 'L') {
                    litters.add(new int[]{i, j});
                }
            }
        }

        int totalLitter = litters.size();

        // No litter to collect
        if (totalLitter == 0) {
            return 0;
        }

        int fullMask = (1 << totalLitter) - 1;

        /*
         * litterAt[r][c] = bit corresponding to litter at this cell
         * -1 means there is no litter
         */
        int[][] litterAt = new int[m][n];

        for (int[] row : litterAt) {
            Arrays.fill(row, -1);
        }

        for (int i = 0; i < totalLitter; i++) {
            int r = litters.get(i)[0];
            int c = litters.get(i)[1];
            litterAt[r][c] = i;
        }

        /*
         * State:
         * row, col, remaining energy, collected mask
         */
        class State {
            int r;
            int c;
            int e;
            int mask;
            int moves;

            State(int r, int c, int e, int mask, int moves) {
                this.r = r;
                this.c = c;
                this.e = e;
                this.mask = mask;
                this.moves = moves;
            }
        }

        Queue<State> queue = new LinkedList<>();

        /*
         * visited[r][c][energy][mask]
         *
         * energy can be 0...energy
         */
        boolean[][][][] visited =
                new boolean[m][n][energy + 1][1 << totalLitter];

        queue.offer(new State(startR, startC, energy, 0, 0));
        visited[startR][startC][energy][0] = true;

        int[] dr = {-1, 1, 0, 0};
        int[] dc = {0, 0, -1, 1};

        while (!queue.isEmpty()) {

            State cur = queue.poll();

            // All litter collected
            if (cur.mask == fullMask) {
                return cur.moves;
            }

            // If energy is 0, cannot make another move
            if (cur.e == 0) {
                continue;
            }

            for (int d = 0; d < 4; d++) {

                int nr = cur.r + dr[d];
                int nc = cur.c + dc[d];

                // Outside grid
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                    continue;
                }

                // Obstacle
                if (classroom[nr].charAt(nc) == 'X') {
                    continue;
                }

                int newEnergy = cur.e - 1;

                // Reset area
                if (classroom[nr].charAt(nc) == 'R') {
                    newEnergy = energy;
                }

                // Collect litter
                int newMask = cur.mask;

                if (litterAt[nr][nc] != -1) {
                    int bit = litterAt[nr][nc];
                    newMask |= (1 << bit);
                }

                if (!visited[nr][nc][newEnergy][newMask]) {

                    visited[nr][nc][newEnergy][newMask] = true;

                    queue.offer(
                        new State(
                            nr,
                            nc,
                            newEnergy,
                            newMask,
                            cur.moves + 1
                        )
                    );
                }
            }
        }

        return -1;
    }
}