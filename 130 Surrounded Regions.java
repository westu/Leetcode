public class Solution {
    /**
     * @param board a 2D board containing 'X' and 'O'
     * @return void
     */
    private class Coordinate {
        int x;
        int y;
        Coordinate(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public void surroundedRegions(char[][] board) {
        if (board.length == 0 || board[0].length == 0) {
            return;
        }
        boolean[][] isVisited = 
            new boolean[board.length][board[0].length];
        boolean[][] isRegion =
            new boolean[board.length][board[0].length];
        for (int i = 0; i < board.length; ++i) {
            for (int j = 0; j < board[0].length; ++j) {
                isVisited[i][j] = false;
                isRegion[i][j] = true;
            }
        }

        for (int i = 0; i < board[0].length; ++i) {
            if (board[0][i] == 'O' && !isVisited[0][i]) {
                bfs(board, isVisited, isRegion, 0, i);
            }
            if (board[board.length - 1][i] == 'O'
                && !isVisited[board.length - 1][i]) {
                bfs(board, isVisited, isRegion, board.length - 1, i);
            }
        }
        for (int i = 0; i < board.length; ++i) {
            if (board[i][0] == 'O' && !isVisited[i][0]) {
                bfs(board, isVisited, isRegion, i, 0);
            }
            if (board[i][board[0].length - 1] == 'O' && !isVisited[i][board[0].length - 1]) {
                bfs(board, isVisited, isRegion, i, board[0].length - 1);
            }
        }

        for (int i = 0; i < board.length; ++i) {
            for (int j = 0; j < board[0].length; ++j) {
                if (board[i][j] == 'O' && isRegion[i][j] == true) {
                    board[i][j] = 'X';
                }
            }
        }
    }

    private void bfs(char[][] board, boolean[][] isVisited, boolean[][] isRegion, int i, int j) {
        Queue<Coordinate> bfsQueue = new LinkedList<Coordinate>();
        bfsQueue.offer(new Coordinate(i, j));
        while (!bfsQueue.isEmpty()) {
            Coordinate point = bfsQueue.poll();
            isVisited[point.x][point.y] = true;
            isRegion[point.x][point.y] = false;
            expand(board, isVisited, bfsQueue, point.x - 1, point.y);
            expand(board, isVisited, bfsQueue, point.x + 1, point.y);
            expand(board, isVisited, bfsQueue, point.x, point.y - 1);
            expand(board, isVisited, bfsQueue, point.x, point.y + 1);
        }
    }

    private void expand(
        char[][] board,
        boolean[][] isVisited,
        Queue<Coordinate> bfsQueue,
        int x,
        int y) {
        if (0 <= x && x < board.length && 0 <= y && y < board[0].length) {
            if (!isVisited[x][y] && board[x][y] == 'O') {
                bfsQueue.offer(new Coordinate(x, y));
            }
        }
    }
}
