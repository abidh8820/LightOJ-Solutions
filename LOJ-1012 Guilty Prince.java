import java.util.*;

class pair {
    int x, y;
    pair(int a, int b) {
        this.x = a;
        this.y = b;
    }
}

public class Main {
    static int[] dx = {0, 0, 1, -1};
    static int[] dy = {1, -1, 0, 0};

    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);
        int t = input.nextInt();
        boolean[][] vis = new boolean[50][50];
        int cnt = 0;

        while (t-- > 0) {
            int m = input.nextInt(), n = input.nextInt();
            String[] grid = new String[n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    vis[i][j] = false;
                }
            }

            for (int i = 0; i < n; i++) grid[i] = input.next();

            pair source = new pair(0,0);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (grid[i].charAt(j) == '@'){ source = new pair(i, j); }
                }
            }
            LinkedList<pair> Q = new LinkedList<>();
            Q.add(source); vis[source.x][source.y] = true;

            while (Q.size() > 0) {
                pair u = Q.poll();
                for (int i = 0; i < 4; i++) {
                    int x = u.x + dx[i], y = dy[i] + u.y;
                    if(x<0 || x>=n || y<0 || y>=m) continue;
                    if (vis[x][y] || grid[x].charAt(y) != '.') continue;
                    vis[x][y] = true;  pair v = new pair(x, y);
                    Q.push(v);
                }
            }
            int ans = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (vis[i][j])  ans++;
                }
            }
            cnt ++ ;
            System.out.println("Case "+cnt+": "+(ans));
        }
    }
}

