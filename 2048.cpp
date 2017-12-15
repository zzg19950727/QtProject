#include "head.h"

int game[4][4];
int xy[6];
int score,q, p;

int num(int n)
{
    /*if( n <= 0 )
        return 0;
    return (int)(log(n)/log(2));*/
    switch( n )
    {
    case 0:
        return 0;
    case 2:
        return 1;
    case 4:
        return 2;
    case 8:
        return 3;
    case 16:
        return 4;
    case 32:
        return 5;
    case 64:
        return 6;
    case 128:
        return 7;
    case 256:
        return 8;
    case 512:
        return 9;
    case 1024:
        return 10;
    case 2048:
        return 11;
    default:
        return 0;
    }
}

int bili(int g,int *x,int (*a)[4])
{
    int i,j,p;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(a[i][j]==128)
                g=8;
            else if(a[i][j]>=256)
                g=16;
            /*else if(a[i][j]==512)
                g=32;
            else if(a[i][j]==1024)
                g=64;*/
        }
    }
    if(g==4)
    {
        p=rand()%(x[0]+x[1]);
        if(p<x[0])
            p=1;
        else
            p=2;
    }
    else if(g==8)
    {
        p=rand()%(x[0]+x[1]+x[2]);
        if(p<x[0])
            p=1;
        else if(p<x[0]+x[1])
            p=2;
        else
            p=4;
    }
    else if(g==16)
    {
        p=rand()%(x[0]+x[1]+x[2]+x[3]);
        if(p<x[0])
            p=1;
        else if(p<x[0]+x[1])
            p=2;
        else if(p<x[0]+x[1]+x[2])
            p=4;
        else
            p=8;
    }
    else if(g==32)
    {
        p=rand()%(x[0]+x[1]+x[2]+x[3]+x[4]);
        if(p<x[0])
            p=1;
        else if(p<x[0]+x[1])
            p=2;
        else if(p<x[0]+x[1]+x[2])
            p=4;
        else if(p<x[0]+x[1]+x[2]+x[3])
            p=8;
        else
            p=16;
    }
    else if(g==64)
    {
        p=rand()%(x[0]+x[1]+x[2]+x[3]+x[4]+x[5]);
        if(p<x[0])
            p=1;
        else if(p<x[0]+x[1])
            p=2;
        else if(p<x[0]+x[1]+x[2])
            p=4;
        else if(p<x[0]+x[1]+x[2]+x[3])
            p=8;
        else if(p<x[0]+x[1]+x[2]+x[3]+x[4])
            p=16;
        else
            p=32;
    }
    return p;
}

void difficult_game()
{
    int g,b,c,m,n;
	g=4;p=1;
    xy[0]=40;
    xy[1]=20;
    xy[2]=10;
    xy[3]=3;
    xy[4]=2;
    xy[5]=1;
	srand(time(NULL));
	for(m=0;m<4;m++)
		for(n=0;n<4;n++)
			game[m][n]=0;
	c=rand()%4;
	b=rand()%4;
	while(game[c][b]!=0)
	{
		c=rand()%4;
		b=rand()%4;
	}
	game[c][b]=2*p;
    p=bili(g,xy,game);
	return;
}

int UP(int (*a)[4])
{
	int i,j,k,m,n,f=0;
		for(i=0;i<4;i++)//判断用户是否能进行向上操作
		{
			for(j=0;j<3;j++)
			{
				if(a[j][i]==0&&a[j+1][i]!=0||a[j][i]==a[j+1][i]&&a[j][i]!=0)
				{
					f=f+1;
					goto step1;
				}
			}
		}
		for(n=0;n<4;n++)//判断游戏是否结束
		{
	 	   for(m=0;m<4;m++)
		   {
	          if(a[n][m]==0)
			  {
				  q=q+1;
				  return 0;
			  }
		   }
		}
		if(q==0)
		{
			for(n=0;n<3;n++)//判断游戏是否结束
			{
	 	        for(m=0;m<3;m++)
				{
	                if(a[n][m]==a[n][m+1]||a[n][m]==a[n+1][m]||
						a[n][m+1]==a[n+1][m+1]||a[n+1][m]==a[n+1][m+1])
					{
						q=q+1;
						return 0;
					}
				}
			}
		}
		if(q==0)
			return 0;
step1:
		for(i=0;i<4;i++)//用户向上操作后的运算
		{
			for(j=0;j<4;j++)
			{
				 if(a[j][i]==0)
				 {
					for(k=j+1;k<4;k++)
					{
						if(k==1)
						{
							if(a[k][i]!=0&&a[k][i]!=a[k+1][i]&&a[k+1][i]!=0)
							{
								a[j][i]=a[k][i];
								a[k][i]=a[k+1][i];
								a[k+1][i]=0;
								break;
							}
						    else if(a[k][i]!=0&&a[k][i]==a[k+1][i])
							{
								a[j][i]=a[k][i]+a[k+1][i];
								a[k][i]=0;
								a[k+1][i]=0;
								break;
							}
							else if(a[k][i]!=0&&a[k][i]==a[k+2][i]&&a[k+1][i]==0)
							{
								a[j][i]=a[k][i]+a[k+2][i];
								a[k][i]=0;
								a[k+2][i]=0;
								break;
							}
							else if(a[k][i]!=0&&a[k+1][i]==0&&a[k+2][i]==0)
							{
								a[j][i]=a[k][i];
								a[k][i]=0;
								break;
							}
							else if(a[k][i]!=0&&a[k][i]!=a[k+2][i]&&a[k+1][i]==0)
							{
								a[j][i]=a[k][i];
								a[k][i]=a[k+2][i];
								a[k+2][i]=0;
							}
						}
						else if(k==2)
						{
						    if(a[k][i]!=0&&a[k][i]!=a[k+1][i])
							{
								a[j][i]=a[k][i];
								a[k][i]=a[k+1][i];
								a[k+1][i]=0;
								break;
							}
						    else if(a[k][i]!=0&&a[k][i]==a[k+1][i])
							{
								a[j][i]=a[k][i]+a[k+1][i];
								a[k][i]=0;
								a[k+1][i]=0;
								break;
							}
						}
						else
						{
						    if(a[k][i]!=0)
							{
								a[j][i]=a[k][i];
								a[k][i]=0;
							}
						}
					}
				 }
				 else
				 {
					 for(k=j+1;k<4;k++)
					 {
						 if(a[k][i]!=0&&a[k][i]!=a[j][i])
						 break;
						 else if(a[k][i]==a[j][i])
						 {
							 a[j][i]=a[j][i]+a[k][i];
							 a[k][i]=0;
							 break;
						 }
					 }
				 }
			}
		}
		return 1;
}


int DOWN(int (*a)[4])
{
	int i,j,k,m,n,f=0;
	for(i=0;i<4;i++)//判断用户是否能进行向下操作
		{
			for(j=3;j>0;j--)
			{
				if(a[j][i]==0&&a[j-1][i]!=0||a[j][i]==a[j-1][i]&&a[j][i]!=0)
				{
					f=f+1;
					goto step2;
				}
			}
		}
		for(n=0;n<4;n++)//判断游戏是否结束
		{
	 	   for(m=0;m<4;m++)
		   {
	          if(a[n][m]==0)
			  {
				  q=q+1;
				  return 0;
			  }
		   }
		}
		if(q==0)
		{
			for(n=0;n<3;n++)//判断游戏是否结束
			{
	 	        for(m=0;m<3;m++)
				{
	                if(a[n][m]==a[n][m+1]||a[n][m]==a[n+1][m]||
						a[n][m+1]==a[n+1][m+1]||a[n+1][m]==a[n+1][m+1])
					{
						q=q+1;
						return 0;
					}
				}
			}
		}
		if(q==0)
			return 0;
step2:
		for(i=0;i<4;i++)//用户向下操作后的运算
		{
			for(j=3;j>=0;j--)
			{
				 if(a[j][i]==0)
				 {
					for(k=j-1;k>=0;k--)
					{
						if(k==2)
						{
							if(a[k][i]!=0&&a[k][i]!=a[k-1][i]&&a[k-1][i]!=0)
							{
								a[j][i]=a[k][i];
								a[k][i]=a[k-1][i];
								a[k-1][i]=0;
								break;
							}
						    else if(a[k][i]!=0&&a[k][i]==a[k-1][i])
							{
								a[j][i]=a[k][i]+a[k-1][i];
								a[k][i]=0;
								a[k-1][i]=0;
								break;
							}
							else if(a[k][i]!=0&&a[k][i]==a[k-2][i]&&a[k-1][i]==0)
							{
								a[j][i]=a[k][i]+a[k-2][i];
								a[k][i]=0;
								a[k-2][i]=0;
								break;
							}
							else if(a[k][i]!=0&&a[k-1][i]==0&&a[k-2][i]==0)
							{
								a[j][i]=a[k][i];
								a[k][i]=0;
								break;
							}
							else if(a[k][i]!=0&&a[k][i]!=a[k-2][i]&&a[k-1][i]==0)
							{
								a[j][i]=a[k][i];
								a[k][i]=a[k-2][i];
								a[k-2][i]=0;
							}
						}
						else if(k==1)
						{
						    if(a[k][i]!=0&&a[k][i]!=a[k-1][i])
							{
								a[j][i]=a[k][i];
								a[k][i]=a[k-1][i];
								a[k-1][i]=0;
								break;
							}
						    else if(a[k][i]!=0&&a[k][i]==a[k-1][i])
							{
								a[j][i]=a[k][i]+a[k-1][i];
								a[k][i]=0;
								a[k-1][i]=0;
								break;
							}
						}
						else
						{
						    if(a[k][i]!=0)
							{
								a[j][i]=a[k][i];
								a[k][i]=0;
							}
						}
					}
				 }
				 else
				 {
					 for(k=j-1;k>=0;k--)
					 {
						 if(a[k][i]!=0&&a[k][i]!=a[j][i])
						 break;
						 else if(a[k][i]==a[j][i])
						 {
							 a[j][i]=a[j][i]+a[k][i];
							 a[k][i]=0;
							 break;
						 }
					 }
				 }
			}

		}
		return 1;
}


int LEFT(int (*a)[4])
{
	int i,j,k,m,n,f=0;
	for(i=0;i<4;i++)//判断用户是否能进行向左操作
		{
			for(j=0;j<3;j++)
			{
				if(a[i][j]==0&&a[i][j+1]!=0 ||a[i][j]==a[i][j+1]&&a[i][j]!=0)
				{
					f=f+1;
					goto step3;
				}
			}
		}
		for(n=0;n<4;n++)//判断游戏是否结束
		{
	 	   for(m=0;m<4;m++)
		   {
	          if(a[n][m]==0)
			  {
				  q=q+1;
				  return 0;
			  }
		   }
		}
		if(q==0)
		{
			for(n=0;n<3;n++)//判断游戏是否结束
			{
	 	        for(m=0;m<3;m++)
				{
	                if(a[n][m]==a[n][m+1]||a[n][m]==a[n+1][m]||
						a[n][m+1]==a[n+1][m+1]||a[n+1][m]==a[n+1][m+1])
					{
						q=q+1;
						return 0;
					}
				}
			}
		}
		if(q==0)
			return 0;
step3:
		for(i=0;i<4;i++)//用户向左操作后的运算
		{
			for(j=0;j<4;j++)
			{
				 if(a[i][j]==0)
				 {
					for(k=j+1;k<4;k++)
					{
						if(k==1)
						{
							if(a[i][k]!=0&&a[i][k]!=a[i][k+1]&&a[i][k+1]!=0)
							{
								a[i][j]=a[i][k];
								a[i][k]=a[i][k+1];
								a[i][k+1]=0;
								break;
							}
						    else if(a[i][k]!=0&&a[i][k]==a[i][k+1])
							{
								a[i][j]=a[i][k]+a[i][k+1];
								a[i][k]=0;
								a[i][k+1]=0;
								break;
							}
							else if(a[i][k]!=0&&a[i][k]==a[i][k+2]&&a[i][k+1]==0)
							{
								a[i][j]=a[i][k]+a[i][k+2];
								a[i][k]=0;
								a[i][k+2]=0;
								break;
							}
							else if(a[i][k]!=0&&a[i][k+1]==0&&a[i][k+2]==0)
							{
								a[i][j]=a[i][k];
								a[i][k]=0;
								break;
							}
							else if(a[i][k]!=0&&a[i][k]!=a[i][k+2]&&a[i][k+1]==0)
							{
								a[i][j]=a[i][k];
								a[i][k]=a[i][k+2];
								a[i][k+2]=0;
							}
						}
						else if(k==2)
						{
						    if(a[i][k]!=0&&a[i][k]!=a[i][k+1])
							{
								a[i][j]=a[i][k];
								a[i][k]=a[i][k+1];
								a[i][k+1]=0;
								break;
							}
						    else if(a[i][k]!=0&&a[i][k]==a[i][k+1])
							{
								a[i][j]=a[i][k]+a[i][k+1];
								a[i][k]=0;
								a[i][k+1]=0;
								break;
							}
						}
						else
						{
						    if(a[i][k]!=0)
							{
								a[i][j]=a[i][k];
								a[i][k]=0;
							}
						}
					}
				 }
				 else
				 {
					 for(k=j+1;k<4;k++)
					 {
						 if(a[i][k]!=0&&a[i][k]!=a[i][j])
						 break;
						 else if(a[i][k]==a[i][j])
						 {
							 a[i][j]=a[i][j]+a[i][k];
							 a[i][k]=0;
							 break;
						 }
					 }
				 }
			}
		}
		return 1;
}


int RIGHT(int (*a)[4])
{
	int i,j,k,m,n,f=0;
	for(i=0;i<4;i++)//判断用户是否能进行向右操作
		{
			for(j=3;j>0;j--)
			{
				if(a[i][j]==0&&a[i][j-1]!=0||a[i][j]==a[i][j-1]&&a[i][j]!=0)
				{
					f=f+1;
					goto step4;
				}
			}
		}

		for(n=0;n<4;n++)//判断游戏是否结束
		{
	 	   for(m=0;m<4;m++)
		   {
	          if(a[n][m]==0)
			  {
				  q=q+1;
				  return 0;
			  }
		   }
		}
		if(q==0)
		{
			for(n=0;n<3;n++)//判断游戏是否结束
			{
	 	        for(m=0;m<3;m++)
				{
	                if(a[n][m]==a[n][m+1]||a[n][m]==a[n+1][m]||
						a[n][m+1]==a[n+1][m+1]||a[n+1][m]==a[n+1][m+1])
					{
						q=q+1;
						return 0;
					}
				}
			}
		}
		if(q==0)
			return 0;

step4:
		for(i=0;i<4;i++)//用户向右操作后的运算
		{
			for(j=3;j>=0;j--)
			{
				 if(a[i][j]==0)
				 {
					for(k=j-1;k>=0;k--)
					{
						if(k==2)
						{
							if(a[i][k]!=0&&a[i][k]!=a[i][k-1]&&a[i][k-1]!=0)
							{
								a[i][j]=a[i][k];
								a[i][k]=a[i][k-1];
								a[i][k-1]=0;
								break;
							}
						    else if(a[i][k]!=0&&a[i][k]==a[i][k-1])
							{
								a[i][j]=a[i][k]+a[i][k-1];
								a[i][k]=0;
								a[i][k-1]=0;
								break;
							}
							else if(a[i][k]!=0&&a[i][k]==a[i][k-2]&&a[i][k-1]==0)
							{
								a[i][j]=a[i][k]+a[i][k-2];
								a[i][k]=0;
								a[i][k-2]=0;
								break;
							}
							else if(a[i][k]!=0&&a[i][k-1]==0&&a[i][k-2]==0)
							{
								a[i][j]=a[i][k];
								a[i][k]=0;
								break;
							}
							else if(a[i][k]!=0&&a[i][k]!=a[i][k-2]&&a[i][k-1]==0)
							{
								a[i][j]=a[i][k];
								a[i][k]=a[i][k-2];
								a[i][k-2]=0;
							}
						}
						else if(k==1)
						{
						    if(a[i][k]!=0&&a[i][k]!=a[i][k-1])
							{
								a[i][j]=a[i][k];
								a[i][k]=a[i][k-1];
								a[i][k-1]=0;
								break;
							}
						    else if(a[i][k]!=0&&a[i][k]==a[i][k-1])
							{
								a[i][j]=a[i][k]+a[i][k-1];
								a[i][k]=0;
								a[i][k-1]=0;
								break;
							}
						}
						else
						{
						    if(a[i][k]!=0)
							{
								a[i][j]=a[i][k];
								a[i][k]=0;
							}
						}
					}
				 }
				 else
				 {
					 for(k=j-1;k>=0;k--)
					 {
						 if(a[i][k]!=0&&a[i][k]!=a[i][j])
						 break;
						 else if(a[i][k]==a[i][j])
						 {
							 a[i][j]=a[i][j]+a[i][k];
							 a[i][k]=0;
							 break;
						 }
					 }
				 }
			}
		}
		return 1;	//运算结束
}

