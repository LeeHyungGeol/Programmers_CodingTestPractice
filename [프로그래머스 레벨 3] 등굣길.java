// dp 문제
// (백준 골드 4) 내리막길(1520번)
// (프로그래머스 레벨 3) 보행자 천국(2017 카카오 코드 예선)
// 위의 문제들과 똑같은 문제

import java.util.*;

class Solution등굣길 {
    final static int MOD = 1000000007;
    static int Dx[] = {1,0};
    static int Dy[] = {0,1};
    static int[][] Dp;
    static int[][] Graph;
    
    public int solution(int m, int n, int[][] puddles) {
        int answer = 0;
        Dp = new int[m][n];
        Graph = new int[m][n];
        
        for(int i = 0; i < m; i++) {
            Arrays.fill(Dp[i], -1);
        }
        
        for(int[] p : puddles) {
            Graph[p[0]-1][p[1]-1] = 1;
        }
        
        answer = dfs(0,0,n,m);
        
        return answer;
    }
    
    public int dfs(int x, int y, int n, int m) {
        if(x==m-1 && y==n-1) {
            return 1;
        }
        if(Dp[x][y] != -1) {
            return Dp[x][y];
        }
        
        Dp[x][y] = 0;
        
        for(int i = 0; i < 2; ++i) {
            int nx = x + Dx[i];
            int ny = y + Dy[i];
            
            if(0 <= nx && nx < m && 0 <= ny && ny < n) {
                if(Graph[nx][ny] == 0) {
                    Dp[x][y] += dfs(nx,ny,n,m) % MOD;
                }
            }
        }
        
        return Dp[x][y] % MOD;
    }
}