class Solution {
    List<String> ans = new ArrayList<>();

    class Node {
        char ch;
        String isterminal;
        HashMap<Character, Node> child;

        public Node(char ch) {
            this.ch = ch;
            child = new HashMap<>();
        }
    }

    Node root;

    public Solution() {
            root = new Node('*');
        }

    public void insert(String word) {
        Node curr = root;
        for (int i = 0; i < word.length(); i++) {
            char ch = word.charAt(i);
            if (curr.child.containsKey(ch)) { // common prefix
                curr = curr.child.get(ch);
            } else {
                Node nn = new Node(ch);
                curr.child.put(ch, nn);
                curr = nn;
            }
        }
        curr.isterminal = word;
    }

    public void search(char[][] maze, int i, int j, Node node) {
        if (i < 0 || j < 0 || i >= maze.length || j >= maze[0].length || !node.child.containsKey(maze[i][j]))
            return;
        char ch = maze[i][j];
        node = node.child.get(ch);
        if (node.isterminal != null) {
            ans.add(node.isterminal);
            node.isterminal = null;
        }
        maze[i][j] = '*';
        search(maze, i + 1, j, node);
        search(maze, i, j + 1, node);
        search(maze, i - 1, j, node);
        search(maze, i, j - 1, node);
        maze[i][j] = ch;
    }

    public List<String> findWords(char[][] board, String[] words) {
        for (String word : words) {
            insert(word);
        }

        int m = board.length;
        int n = board[0].length;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char ch = board[i][j];
                if (root.child.containsKey(ch)) {
                    search(board, i, j, root);
                }
            }
        }

        return ans;
    }
}