import java.io.*;
import java.util.*;

class first {

	public static int sequence(StringBuffer s, StringBuffer t) {  
	{  
		int n1 = s.length();  
		int n2 = t.length();  
		int dp[][] = new int [n1+1][n2+1];  
		char ch1,ch2 ; 
		
		for (int i = 0; i <= n1; i++) {  
			for (int j = 0; j <= n2; j++) {  
				dp[i][j] = 0;  
			}  
			}  
			
		// for each character of S  
		for (int i = 1; i <= n1; i++) {  

				// for each character in T  
			for (int j = 1; j <= n2; j++) {  
				  
				ch1 = s.charAt(i - 1); 
				ch2 = t.charAt(j - 1); 
				  
				// if character are same in both   
				// the string                  
				if (ch1 == ch2)   
					dp[i][j] = 1 + dp[i][j - 1] + dp[i - 1][j];              
				else 
					dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];              
			}  
			}  
			
			return dp[n1][n2];  
		}
	}

	public static void main (String[] args) throws java.lang.Exception
	{
		try {
            Scanner s = new Scanner(System.in);
            int t = s.nextInt();
            while (t-- > 0) {
                int n = s.nextInt();
                int[] a = new int[n];
                for (int i = 0; i < n; i++) {
                    a[i] = s.nextInt();
                }
                int m = s.nextInt();
                HashMap<Integer, Integer> map = new HashMap<>();
                for (int i = 0; i < m; i++) {
                    map.put(s.nextInt(), 0);
                }
                int i = 0;
                int count = 0;
                while (i < n) {
                    if (map.containsKey(a[i])) {
                        count++;
                    }
                    while (map.containsKey(a[i++])){
                        if(i>=n)
                            break;
                    }

                }
                System.out.println(count);
			}
			s.close();
        }catch (Exception e){}
	}
}

