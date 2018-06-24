/*
 Reinier César Mujica
 1 - 12 - 2009
*/

import java.io.*;
import java.util.StringTokenizer;

public class DOMINO {
	
	public static void main( String args[] ) throws IOException {
		int N, sol = 0, res = 0, sum;
		
		BufferedReader fe = new BufferedReader(new FileReader("DOMINO.in"));
		PrintWriter fs = new PrintWriter(new FileWriter("DOMINO.out"));
		StringTokenizer st = new StringTokenizer(fe.readLine());
		
		N = Integer.parseInt(st.nextToken());
		sum = ( (N * (N+1)) / 2 );
		for ( int i = 0; i <= N; i++ ) {
			sol += ((N - i + 1) * i); // top
			for ( int j = i; j <= N; j++ )
				sol += j;
		}
	
		fs.println(sol);
		
		fe.close();
		fs.close();
	}

}
