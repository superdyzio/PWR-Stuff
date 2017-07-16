public interface BoardListener {
    // called before `move` is made on `board`
    void onMove(Board board, Move move);

    // called when new game button has been pressed
    void onNewGame(Board board);

}