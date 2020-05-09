#include<stdio.h>
#include<stdlib.h>
#include<limits.h>



int Map[300][300];

typedef struct road
{
	int st_pt;
	int weight;
	int end_pt;
}Road;

int MinWeight(int a[],int visited[],int numRoads)
{
	int minni=-1;
	int min=INT_MAX;
	for(int i=0;i<numRoads;i++)
	{
		if(a[i]<min&&visited[i]==0)
		{	
			min=a[i];
			minni=i;
		}
	}
	return minni;
}
int padyatra(int distance[],int parent[],int visited[],int st_pt,int end_pt,int numRoads,int weight)
{
	int s;
	int dist=0;
	distance[st_pt]=0;
	parent[st_pt]=-1;
	int count=0;
	Map[st_pt][end_pt]=0;
	Map[end_pt][st_pt]=0;
	for(int i=0;i<numRoads;i++)
	{
		distance[i]=INT_MAX;
		parent[i]=-1;
		visited[i]=0;
	}
	
	while(count<numRoads)
	{
		s=MinWeight(distance,visited,numRoads);
		if(s==-1)
		{
		    distance[s]=0;
		    break;
		}
		for(int i=0;i<numRoads;i++)
		{
			if(Map[s][i]!=0)
			{
				if(distance[s]+Map[s][i]<distance[i])
				{
					distance[i]=distance[s]+Map[s][i];
					parent[i]=s;
				}
			}
		}
		visited[s]=1;
		if(s==end_pt)
		{
			break;
		}
		count ++;
	}
	Map[st_pt][end_pt]=weight;
	Map[end_pt][st_pt]=weight;
	return distance[s];
}
int main()
{
	int numRoads;
	int min;
	int ans=INT_MAX;
	printf("Enter the total number of roads..: \n");
	scanf("%d",&numRoads);
	for(int i=0;i<300;i++)
	{
		for(int j=0;j<300;j++)
		{
			Map[i][j]=0;
		}
	}
	Road a[numRoads];
	for(int i=0;i<numRoads;i++)
	{
		printf("Enter the starting point, end point and weight of %dth road : \n", (i+1));
		scanf("%d",&a[i].st_pt);
		scanf("%d",&a[i].end_pt);
		scanf("%d",&a[i].weight);
		Map[a[i].st_pt-1][a[i].end_pt-1]=a[i].weight;
		Map[a[i].end_pt-1][a[i].st_pt-1]=a[i].weight;
	}
	int distance[numRoads];
	int parent[numRoads];
	int visited[numRoads];
	for(int i=0;i<numRoads;i++)
	{
		int minimum=a[i].weight;
		min=padyatra(distance,parent,visited,a[i].end_pt-1,a[i].st_pt-1,numRoads,a[i].weight);
		minimum=minimum+min;
		if(minimum<ans)
		{
			ans=minimum;
		}
	}
	printf("\nMaximum possible cycle coverage path cost is %d\n",(ans+9));
}

