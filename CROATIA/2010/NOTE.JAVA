/*
 Reinier César Mujica
 1 - 12 - 2009
 I still retired for a time, but I come back
 now in Java and believe me C++ is a shit
*/

import java.io.*;
import java.util.StringTokenizer;

public class NOTE {
	
	public static void main( String args[] ) throws IOException {
		
		boolean min_max = true, max_min = true;
		int last, current;
		
		BufferedReader fe = new BufferedReader(new FileReader("NOTE.in"));
		BufferedWriter fs = new BufferedWriter(new FileWriter("NOTE.out"));
		StringTokenizer st = new StringTokenizer(fe.readLine());
		
		last = Integer.parseInt(st.nextToken());
		for ( int i = 1; i < 8; i++ ) {
			current = Integer.parseInt(st.nextToken());;
			if (last > current) min_max = false;
			if (current > last) max_min = false;
			last = current;
		}
		
		if ( !min_max && !max_min )
			fs.write("mixed\n");
		if ( min_max )
			fs.write("ascending\n");
		if ( max_min )
			fs.write("descending\n");
		
		fe.close();
		fs.close();
	}
}
