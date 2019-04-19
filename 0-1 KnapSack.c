#include<stdio.h>
 
int max(int a, int b) { return (a > b)? a : b; }
 
int knapSack(int W, int weight[], int value[], int n)
{
   int i, w;
   int K[n+1][W+1];
 
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (weight[i-1] <= w)
                 K[i][w] = max(value[i-1] + K[i-1][w-weight[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }
 
   return K[n][W];
}
 
int main()
{
    int i, n, value[20], weight[20], W;
    
    printf("Enter total number of items:");
    scanf("%d", &n);
    
    printf("Enter the value and weight of these items:\n");
    for(i = 0;i < n; ++i){
    	scanf("%d%d", &value[i], &weight[i]);
    }
 
    printf("Enter size of knapsack:");
    scanf("%d", &W);
    
    printf("%d", knapSack(W, weight, value, n));
    return 0;
}