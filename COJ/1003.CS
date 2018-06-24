/*
 * Creado por SharpDevelop.
 * Usuario: Reinier
 * Fecha: 11/12/2010
 * Hora: 09:39 p.m.
 * 
 * Para cambiar esta plantilla use Herramientas | Opciones | Codificación | Editar Encabezados Estándar
 */

using System;

namespace COJ
{

	public class Solution {
		
		const int MAX = 101;
		
		int NextInt {
			get {
				int kk = Console.Read();
				string current = string.Empty;
				
				while (kk != -1 && (char)kk != ' ' && (char)kk != '\n') {
					current = current + (char)kk;					
					kk = Console.Read();
				}

				return int.Parse(current);
			}
		}
		
		
		public void Solve() 
		{
			int T = NextInt;
						
			while ( T > 0 ) {
				int N = NextInt, M = NextInt, SOL = 0, ID = 0;
				int[] A = new int[MAX];
				
				for ( int i = 1; i <= M; i++ ) {
					for ( int j = 1; j <= N; j++ ) {
						A[j] += NextInt;
						if ( A[j] > SOL ) {
							SOL = A[j];
							ID = j;
						}
					}
				}

				T--;
				Console.WriteLine(ID.ToString());
			}
		}
	
	}
	
	public class COJ1003
	{
	
		public static void Main()
		{
			Solution S = new Solution();
			S.Solve();
		}
	
	}
	
}
