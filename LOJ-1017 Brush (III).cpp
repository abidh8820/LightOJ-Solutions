import java.util.*;

public class a {
    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);

        int t = input.nextInt(), c = 0;
        int N = 105;

        while (t-- > 0) {
            int n = input.nextInt(), w = input.nextInt(), k = input.nextInt();
            int[][] dp = new int[N][N];
            int[] p = new int[n];

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    dp[i][j] = 0;
                }
            }


            for (int i = 0; i < n; i++) {
                p[i] = input.nextInt();
                p[i] = input.nextInt();
            }

            Arrays.sort(p);

            int ans = 0;
            for (int i = 1; i <= k; i++) {
                for (int j = 1; j <= n; j++) {
                    dp[i][j] = dp[i][j - 1];
                    int prv = j, cnt = 0;
                    for (int l = j; l >= 1; l--) {
                        if (Math.abs(p[j-1] - p[l-1]) <= w) {
                            prv = l;   cnt++;
                        }
                    }
                    if (prv > 0 && i > 0)
                        dp[i][j] = Math.max(dp[i][j], dp[i - 1][prv - 1] + cnt);
                    ans = Math.max(ans,dp[i][j]);
                }
            }
            System.out.println("Case "+(++c)+": "+ans);
        }
    }
}
