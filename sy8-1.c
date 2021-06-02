#include <stdio.h>
#define big 9998
#define max 40
void prim(int g[][max],int n)		
{
 int lc[max],ct[max];
 int i,j,k,min,sum=0;
 for(i=2;i<=n;i++){ 				
 	lc[i]=g[1][i]; 		
 	ct[i]=1; 					
 }
 lc[1]=0; 					
 for(i=2;i<=n;i++){ 					
	 min=big;
 	k=0;
 	for(j=2;j<=n;j++)					
 		if((lc[j]<min)&&(lc[j]!=0)){
     	 	min=lc[j];
 			k=j;
     	}
     sum+=min;
	 printf("(%d,%d)",ct[k],k);
 	 lc[k]=0;					 
 	 for(j=2;j<=n;j++) 			
     if(g[k][j]<lc[j]){ 
     	lc[j]=g[k][j];
        ct[j]=k;
     }
 	printf("\n");
 }
 printf("%d",sum);
} 
int adjg(int g[][max]) 		
{
 	int n,e,i,j,k,v1,v2,weight,x[max];
 	scanf("%d %d",&n,&e);
 	for(i=1;i<=n;i++)
 		scanf("%d",&x[n]);
 	for(i=1;i<=n;i++) 
 		for(j=1;j<=n;j++)
 			g[i][j]=big; 		
 		for(k=1;k<=e;k++){
 			scanf("%d %d %d",&v1,&v2,&weight);
 			g[v1][v2]=weight;
 			g[v2][v1]=weight;
   		}
 	return(n);
}
int main()
{
 	int g[max][max],n;
 	n=adjg(g);
 	prim(g,n);
 	return 0;
}


