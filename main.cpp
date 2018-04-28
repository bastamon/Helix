#include <stdio.h>
#define N 100    //最大98x98
int a[N][N];
int main()
{
    int i,j,k,n,m=0;
    printf("输入介数,最大98x98");
    scanf("%d",&n);
    for(i=0;i<=n+1;i++)//方阵四周不能填数，=0表示可填数
    {
        a[i][0]=-1;
        a[i][n+1]=-1;
        a[0][i]=-1;
        a[n+1][i]=-1;
    }
    k=1;
    a[1][1]=1;
    i=1;j=1;
    while(1)
    {   switch(m)
        {
        case 0:     //右方填数
            if(a[i][j+1])   //如果右方没有可填位置
               m=1;        //改为下方填数
            else
              a[i][++j]=++k;
            break;
        case 1:    //下方填数
            if(a[i+1][j])
               m=2;
            else
              a[++i][j]=++k;
            break;
        case 2:   //左方填数
            if(a[i][j-1])
               m=3;
            else
               a[i][--j]=++k;
            break;
        case 3:      //上方填数
            if(a[i-1][j])
               m=0;
            else
             a[--i][j]=++k;
        }
        if(k==n*n)break;  //如果输填完则结束
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("%5d",a[i][j]);
            printf("\n");
    }
	return 1;
}
