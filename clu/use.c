#include "clu.h"

int main(int argc, char **argv)
{
	int c=0;
	while(1)
	{
		Node nodes[NODE_MAX]={0};
		double r=0.0;
		//清空括号栈
		int bb = 0;	//InitStack(&brackets);
		printf("Enter: ");
		//输入
		if(!input(nodes))
		{
			printf("Input Error!");
			continue;
		}
		//计算
		if(calculate(nodes,&r))
		{
			if(bb)
			{
				printf("Bracket does not match!");
				continue;
			}
			if(floor(r)==r)
				printf("%d",(int)r);
			else
				printf("%.4f",r);
		}
		c=getchar();
		if(c=='q')	//退出
			break;
		else if(c=='c')	//清屏
			system("clear");
		if(c!='\n')
			getchar();
	}
	printf("Quit...\n");

	return 0;
}
