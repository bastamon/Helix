#include <stdio.h>
#define N 100    //���98x98
int a[N][N];
int main()
{
    int i,j,k,n,m=0;
    printf("�������,���98x98");
    scanf("%d",&n);
    for(i=0;i<=n+1;i++)//�������ܲ���������=0��ʾ������
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
        case 0:     //�ҷ�����
            if(a[i][j+1])   //����ҷ�û�п���λ��
               m=1;        //��Ϊ�·�����
            else
              a[i][++j]=++k;
            break;
        case 1:    //�·�����
            if(a[i+1][j])
               m=2;
            else
              a[++i][j]=++k;
            break;
        case 2:   //������
            if(a[i][j-1])
               m=3;
            else
               a[i][--j]=++k;
            break;
        case 3:      //�Ϸ�����
            if(a[i-1][j])
               m=0;
            else
             a[--i][j]=++k;
        }
        if(k==n*n)break;  //��������������
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("%5d",a[i][j]);
            printf("\n");
    }
	return 1;
}
