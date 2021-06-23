#include<stdio.h>
#include<stdlib.h>
float x[10];
float total_profit;
int knapsack(int capacity,float w[],float price[],int n)
{
    int i;
    total_profit=0;
    for(i=0;i<n;i++)
    {
      x[i]=0;
    }
    for(i=0;i<n;i++)
    {

      if(w[i]>capacity)
      {
              break;
      }

      else
      {
        x[i]=1;
        total_profit=total_profit+price[i];
        capacity=capacity-w[i];
      }

    }
    if (i < n)
      x[i] = capacity / w[i];

   total_profit = total_profit + (x[i] * price[i]);

    return total_profit;
}

int Greedy_by_price(int capacity,float w[],float price[],int n)
{
    int i;

     printf("\nPlease enter the price of the items in descending order:");
    for(i=0;i<n;i++)
    {
       scanf("%f",&price[i]);
    }
    printf("\nPlease enter the weight of the items:");
    for(i=0;i<n;i++)
    {
      scanf("%f",&w[i]);
    }
   knapsack(capacity,w,price,n);

}

int Greedy_by_weight(int capacity,float w[],float price[],int n)
{
    int i;

     printf("\nPlease enter weight of the items in ascending order :");

    for(i=0;i<n;i++)
    {
       scanf("%f",&w[i]);
    }
    printf("\nPlease enter the corresponding price of the items:");
    for(i=0;i<n;i++)
    {
      scanf("%f",&price[i]);
    }
    knapsack(capacity,w,price,n);

}

int Greedy_by_ratio(int capacity,float w[],float price[],float ratio[],int n)
{
    int i,j,x;

    printf("\nEnter the weight of the items : ");
    for(i=0;i<n;i++)
    {
      scanf("%f",&w[i]);
    }
	printf("\nEnter the price of the items  : ");
    for(i=0;i<n;i++)
    {
       scanf("%f",&price[i]);
    }
    for(i=0;i<n;i++)
    {
       ratio[i]=price[i]/w[i];

    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
           if(ratio[i] < ratio[j])
           {
               x=ratio[i];
               ratio[i]=ratio[j];
               ratio[j]=x;

               x=w[i];
               w[i]=w[j];
               w[j]=x;

               x=price[i];
               price[i]=price[j];
               price[j]=x;
            }
        }
    }
    knapsack(capacity,w,price,n);

}

void main()
{
     int capacity,n,i,j,choice;
     float price[20],w[20],ratio[20];
    printf("\n\tEnter number of items:");
    scanf("%d",&n);
    printf("\n\tEnter knapsack capacity:");
    scanf("%d",&capacity);
   do
    {
       printf("\n\tKnapsack Greedyness Strategy");
       printf("\n \t  1.Greedy by price\n \t  2.Greedy by weight\n \t  3.Greedy by ratio\n \t  0.exit\n");
       printf("\n\tEnter your choice:");
       scanf("%d",&choice);
       switch(choice)
       {
            case 1:Greedy_by_price(capacity,w,price,n);
                   printf("The visible solution is:");
                   for(i=0;i<n;i++)
                   {
                       printf("\t%f",x[i]);
                   }
                   printf(" \nThe profit is :%f",total_profit);
                   break;
                   
            case 2:Greedy_by_weight(capacity,w,price,n);
                   printf("The visible solution is:");
                   for(i=0;i<n;i++)
                   {
                       printf("\t%f",x[i]);
                   }
                   //break;
                   printf("\nThe profit is :%f",total_profit);
                   break;
                   
            case 3:Greedy_by_ratio(capacity,w,price,ratio,n);
                   printf("\nThe optimal solution is:");
                   for(i=0;i<n;i++)
                   {
                       printf("\t%f",x[i]);
                   }
                   printf("\nThe Maximum profit is :%f\n",total_profit);
                   break;
                   
            case 0:exit(0);
                   break;
                   
            default: printf("Wrong choice!!\n\n");
       }
    }
   while(1);
}
