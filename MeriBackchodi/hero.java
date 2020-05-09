import java.util.*; 
  
class hero { 

    static int vert = 9; 
    
    void dijkstra(int graph[][], int src, int end) 
    { 
        int dist[] = new int[vert]; 
        Boolean visited[] = new Boolean[vert]; 
   
        for (int i = 0; i < vert; i++) { 
            dist[i] = Integer.MAX_VALUE; 
            visited[i] = false; 
        } 
        dist[src] = 0; 
  
        for (int count = 0; count < vert; count++) { 

            int u = closestPath(dist, visited); 
            visited[u] = true; 
  
 
            for (int v = 0; v < vert; v++) 

                if (!visited[v] && graph[u][v] != 0 &&  
                   dist[u] != Integer.MAX_VALUE && dist[u] + graph[u][v] < dist[v]) 
                    dist[v] = dist[u] + graph[u][v]; 
        } 
        System.out.print("Minimum steps to reach ");
        System.out.println(dist[end] == Integer.MAX_VALUE ? 0 : dist[end]); 
    } 

    int closestPath(int dist[], Boolean visited[]) 
    { 
        int min = Integer.MAX_VALUE, min_index = -1; 
  
        for (int v = 0; v < vert; v++) 
            if (visited[v] == false && dist[v] <= min) { 
                min = dist[v]; 
                min_index = v; 
            } 
  
        return min_index; 
    } 
  
    public static void main(String[] args) 
    { 
        Scanner s1 = new Scanner(System.in);
        System.out.println("Enter the number of floors and close floors..:");
		int numFloor = s1.nextInt();
		int numJumps = s1.nextInt();

		vert = numFloor;		
		int pathway[][] = new int[numFloor][numFloor];
				
		for (int i = 0; i < numJumps; i++) {
            System.out.println("Enter the " + (i+1) +" closeby floors..:");
			int a = s1.nextInt()-1;
			int b = s1.nextInt()-1;
			
			pathway[a][b] = 1;
			pathway[b][a] = 1;
		}

        hero t = new hero(); 
        System.out.println("Enter the start and destination floors..:");
		int start = s1.nextInt()-1;
        int end = s1.nextInt()-1;
        
		s1.close();
        t.dijkstra(pathway, start, end); 

    } 
}