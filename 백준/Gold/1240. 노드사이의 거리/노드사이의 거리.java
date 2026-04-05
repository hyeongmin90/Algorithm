import java.io.*;
import java.util.*;

class Pair {
    int a, b;
    public Pair(int a, int b){
        this.a = a;
        this.b = b;
    }
}

public class Main {
    static ArrayList<ArrayList<Pair>> edges = new ArrayList<>();

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        for(int i = 0; i < n + 1; i++){
            edges.add(new ArrayList<>());
        }
        for(int i = 0; i < n - 1; i++){
            int u = sc.nextInt();
            int v = sc.nextInt();
            int d = sc.nextInt();
            edges.get(u).add(new Pair(v, d));
            edges.get(v).add(new Pair(u, d));
        }
        for(int i = 0; i < m; i++){
            int u = sc.nextInt();
            int v = sc.nextInt();
            System.out.println(func(u, v));
        }
    }

    static int func(int s, int e){
        Deque<Pair> q = new ArrayDeque<>();
        boolean[] vis = new boolean[1001];
        q.offer(new Pair(s, 0));
        vis[s] = true;
        while(!q.isEmpty()){
            var cur = q.poll();
            if(cur.a == e){
                return cur.b;
            }
            for(Pair x : edges.get(cur.a)){
                int nxt = x.a, d = x.b;
                if(vis[nxt]) continue;
                vis[nxt] = true;
                q.offer(new Pair(nxt, cur.b + d));
            }
        }
        return -1;
    }
}

