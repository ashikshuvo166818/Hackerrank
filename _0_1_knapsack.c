//
// Created by ashik on 9/22/2023.
//
//https://www.hackerrank.com/contests/srin-aadc03/challenges/classic-01-knapsack/problem
#include<stdio.h>
int knapsack(int weight[],int profit[],int netWeight,int item)
{
    int table[item+1][netWeight+1];
    for (int i = 0; i <=item; ++i) {
        for (int j = 0; j <=netWeight; ++j) {
            if(i==0 || j==0)
            {
                table[i][j]=0;
            }
            else if(j<weight[i-1])
            {
                table[i][j]=table[i-1][j];
            }
            else
            {
                table[i][j]=profit[i-1]+table[i-1][j-weight[i-1]];
                if(table[i][j]<table[i-1][j])
                {
                    table[i][j]=table[i-1][j];
                }
            }
        }
    }
    return table[item][netWeight];
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++) {
        int netWeight,item;
        scanf("%d %d",&netWeight,&item);
        int weight[item],profit[item];
        for (int j = 0; j <item; j++) {
            scanf("%d %d",&weight[j],&profit[j]);
        }
        int k=0;
        k=knapsack(weight,profit,netWeight,item);
        printf("%d",k);
    }
}