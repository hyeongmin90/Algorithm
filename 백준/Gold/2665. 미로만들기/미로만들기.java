import java.io.*;
import java.util.*;

class Pair{
    int a;
    int b;
    public Pair(int a, int b){
        this.a = a;
        this.b = b;
    }
}

public class Main {
    static char[][] arr = new char[51][51];
    static int[] dx = new int[]{1, 0, -1, 0};
    static int[] dy = new int[]{0, 1, 0, -1};
    static int[][] dist = new int[51][51];
    static int INF = 0x3f3f3f3f;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        for(int i = 0; i < n; i++){
            arr[i] = sc.next().toCharArray();
        }

        for(int i = 0; i < n; i++){
            Arrays.fill(dist[i], INF);
        }

        Deque<Pair> q = new ArrayDeque<>();
        q.offer(new Pair(0,0));
        dist[0][0] = 0;
        while(!q.isEmpty()){
            Pair p = q.poll();
            int x = p.a;
            int y = p.b;
            for(int dir = 0; dir < 4; dir++){
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                int r = arr[x][y] == '1' ? 0 : 1;
                if(dist[nx][ny] <= dist[x][y] + r) continue;
                dist[nx][ny] = dist[x][y] + r;
                if(arr[nx][ny] == '1'){
                    dist[nx][ny] = dist[x][y];
                    q.offerFirst(new Pair(nx, ny));
                }
                else {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.offerLast(new Pair(nx, ny));
                }
            }
        }
        System.out.println(dist[n - 1][n - 1]);
    }
}

