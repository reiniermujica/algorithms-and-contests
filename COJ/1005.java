import java.io.BufferedInputStream;
import java.util.*;

class segment implements Comparable<segment>{
    public int start, end, score;
    
    public segment(int s, int e, int c)
    {
        start = s;
        end = e;
        score = c;
    }
    
    @Override
    public int compareTo(segment other) 
    {
        if (end < other.end) {
            return -1;
        }
        if (end > other.end) {
            return 1;
        }
        return 0;
    }
}

public class Main {
    
    final static int maxn = 10005;
    static int dp[] = new int[maxn];
    static segment V[] = null;
    static ArrayList<segment> S = null;
    static int N, T;
    static int i, j, k;
    static int x, y, c;
    
    public static int max(int a, int b)
    {
        return (a>b) ? a : b;
    }
    
    public static void main(String[] args) 
    {
        Scanner R = new Scanner(new BufferedInputStream(System.in));
        
        T = R.nextInt();
        
        while (T-- > 0)
        {
            N = R.nextInt();
            V = new segment[N];
            
            for (i = 0; i < N; i++)
            {
                x = R.nextInt();
                y = R.nextInt();
                c = R.nextInt();
                
                V[i] = new segment(x, x + y, c);
                dp[i] = 0;
            }
            dp[N] = 0;
       
            Arrays.sort(V);
            
            S = new ArrayList<>();
            
            S.add(V[0]);
            dp[1] = V[0].score;
            
            for (i = 2; i <= N; i++)
            {
          
                k = Collections.binarySearch(S, new segment(0, V[i-1].start, 0));
                
                if (k < 0)
                {
                   k = -k-1;
                   dp[i] = max(dp[i-1], dp[k] + V[i-1].score);
                }
                else
                {
                    k++;
                    dp[i] = max(dp[i-1], dp[k] + V[i-1].score);
                }
               
                S.add(V[i-1]);
            }
            
            System.out.println(dp[N]);            
        }
    }
}
