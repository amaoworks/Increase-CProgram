#include "clu.h"

//char brackets[NUM_OPS];
//int bb=0;

/*功能：表达式输入和转换
 *      接收输入并翻译为操作符和操作数存入表达式链
 *输入：表达式链的地址
 *输出：执行状态，正确返回1,错误返回0
 */
int input(Node *in){
	//input->string
	char ins[INPUT_MAX]={0};
	int insi = 0;
	char temp_in = 0;
	int len = 0;
	//检测开头的空格
	while(' '==(ins[0]=getchar()));
	//检测是不是直接输入了一个回车
	if(ins[0]!='\n')
	{
		do{
			temp_in=getchar();
			//只能忽略多余空格
			if(ins[insi]==' '&&temp_in==' ')
				continue;
			ins[++insi]=temp_in;
		}while(temp_in!='\n');
		ins[insi]=0;
	}

	insi=0;
	//输入回车直接输出0
	if(ins[0]=='\n')
		in->tp=Opd,in->opd=0.0,in++;
	else
		//压入表达式链
		while(ins[insi])
		{
			if(translate(ins+insi,in++,&len))
				insi+=len;
			else
				return 0;
		}
	//自动添加等号
	if((in-1)->opt!='=')
        in->opt='=',in->tp=Opt,in++;
	in->opt=-1,in->tp=Opt;
	return 1;
}
/*功能：翻译字符串为操作数或操作符
 *输入：字符串地址，翻译返回节点，操作数和操作符长度返回地址
 *输出：翻译结果状态
 */
int translate(char *p,Node *re,int *len)
{
	if(*p>='0'&&*p<='9')
	{
		re->tp=Opd;
		re->opd=translateopd(p,len);
		return 1;
	}
	else if(*p=='e'||*p=='p')
	{
		if(*p=='e')
		{
			re->tp=Opd;
			re->opd=M_E;
			*len=1;
			if(p[1]==' ')
				(*len)++;	//十分重要，此处必须加括号
			return 1;
		}
		else
		{
			if(p[1]=='i')
			{
				re->tp=Opd;
				re->opd=M_PI;
				*len=2;
				if(p[2]==' ')
					(*len)++;
				return 1;
			}
			else
				return 0;
		}
	}
	else
	{
		re->tp=Opt;
		re->opt=translateopt(p,len);
		if(re->opt)
			return 1;
		else
			return 0;
	}
}
/*功能：翻译操作数
 */
double translateopd(char *p,int *len)
{
	int flag=0;
	int pointnum=1;
	double temp=0;
	int i=0;
	do{
		if(!flag&&p[i]!='.')
			temp=temp*10+p[i++]-'0';
		else if(!flag&&p[i]=='.')
			flag=1,i++;
		else
			temp+=(p[i++]-'0')*pow(0.1,pointnum),pointnum++;
	}while((p[i]>='0'&&p[i]<='9')||p[i]=='.');
	if(p[i]==' ')
		i++;
	*len=i;
	return temp;
}
/*功能：翻译操作数
 *      如果运算符非法，则返回0，合法则返回非零标志
 */
int translateopt(char *p,int *len)
{
	char fu[NUM_OPT][LEN_OPT]={"+","-","*","/","^","(",")","sin","cos","tan","asin","acos","atan","ln","lg","="};
	int fu_int[NUM_OPT]={'+','-','*','/','^','(',')','s','c','t','s'+'a','c'+'a','t'+'a','n','g','='};
	int i=0;
	for(i=0;i<NUM_OPT;i++)
	{
		if(*len=cmp(p,fu[i]))
			break;
	}
	if(i==NUM_OPT)
		return 0;
	if(p[*len]==' ')
		(*len)++;
	return fu_int[i];
}
/*功能：字符串比较，返回字符长度
 *      不匹配返回0
 */
int cmp(const char *s,const char *d)
{
	char *dd=(char*)d;
	while(*d)
		if(*(d++)!=*(s++))
			return 0;
	return d-dd;
}
/*功能：计算函数
 *输入：表达式链地址，计算结果返回地址
 *输出：成功与否
 */
int calculate(Node *n,double *r)
{
	//双链栈
	double OPRD[NUM_OPS]={0};
	int OPRT[NUM_OPS]={0};
	int db=0;
	int tb=0;

	int top=0;
	double a=0.0,b=0.0;
	int o=0;
	int len=0;
	Node *nb=n;

	if(n->tp==Opt&&n->opt=='-')
		OPRD[db]=0.0,db++;	//Push(&OPRD,0.0); 
	while(1)
	{
		//判断前面有没有负号
		if(n->tp==Opd)
		{
			OPRD[db]=n->opd,db++,n++;	//Push(&OPRD,n->opd),n++;
		}
		else
		{
			//双目运算符
            if(prid(n->opt))
            {
                //if(!GetTop(OPRT,&top))
				if(tb)
					top=OPRT[tb-1];
                if(!tb)
                {
                    if(n->opt=='='||n->opt==')')
                    {
						if(n->opt==')')
						{
							bb--;	//if(!Pop(&brackets,&temp))
							if(bb<0)
							{
								printf("Bracket does not match!");
								return 0;
							}
						}
                        break;
                    }
                    else
						OPRT[tb]=n->opt,tb++,n++;	//Push(&OPRT,n->opt),n++;
                    continue;
                }
                if(prid(top)==0)
                {
                    //Pop(&OPRD,&a);
                    //Pop(&OPRT,&o);
					db--;
					a=OPRD[db];
					tb--;
					o=OPRT[tb];
                    if(sclt(o,&a))
                    {
						OPRD[db]=a,db++;	//Push(&OPRD,a);
                        continue;
                    }
                    else
                        return 0;
                }
                if(prid(top)>=prid(n->opt))
                {
                    //Pop(&OPRD,&b);
                    //Pop(&OPRD,&a);
                    //Pop(&OPRT,&o);
					db--;
					b=OPRD[db];
					db--;
					a=OPRD[db];
					tb--;
					o=OPRT[tb];
                    if(dclt(o,&a,b))
                    {
						OPRD[db]=a,db++;	//Push(&OPRD,a);
                    }
                    else
                        return 0;
                }
                else
                {
					OPRT[tb]=n->opt,tb++,n++;	//Push(&OPRT,n->opt),n++;
                }
            }
            else
            {
				//单目运算符和括号
                double x=0.0;
                if(n->opt=='(')
                {
					brackets[bb]='(',bb++;	//Push(&brackets,'(');
                    if(len=calculate(n+1,&x))
                    {
						OPRD[db]=x,db++;	//Push(&OPRD,x);
                        n+=len,n++;
						if(n->tp==Opt&&n->opt==-1)
						{
							printf("Bracket does not match!");
							return 0;
						}
                    }
                    else
                        return 0;
                }
                else
                {
					OPRT[tb]=n->opt,tb++;	//Push(&OPRT,n->opt);
                    n++;
                }
            }
        }
	}
	*r=OPRD[db-1];
	return n-nb+1;
}
/*功能：单目运算
 */
int sclt(int opr,double *opd)
{
    switch(opr)
    {
    case 's':
        *opd=sin(*opd);
        break;
    case 'c':
        *opd=cos(*opd);
        break;
    case 't':
        *opd=tan(*opd);
        break;
    case 'a'+'s':
        if(*opd<-1||*opd>1)
        {
            printf("Beyond asin()!");
            return 0;
        }
        else
            *opd=asin(*opd);
        break;
    case 'a'+'c':
        if(*opd<-1||*opd>1)
        {
            printf("Beyond acos()!");
            return 0;
        }
        else
            *opd=acos(*opd);
        break;
    case 'a'+'t':
        if(*opd>-3.141592654/2&&*opd<3.141592654/2)
            *opd=atan(*opd);
        else
        {
            printf("Beyond atan()!");
            return 0;
        }
        break;
    case 'n':
        if(*opd>0)
            *opd=log(*opd);
        else
        {
            printf("Beyond ln()!");
            return 0;
        }
        break;
    case 'g':
        if(*opd>0)
            *opd=log10(*opd);
        else
        {
            printf("Beyond lg()!");
            return 0;
        }
        break;
    }
    return 1;
}
/*功能：双目运算
 */
int dclt(int opr,double *opd1,double opd2)
{
    switch(opr)
    {
        case '+':
            *opd1 = *opd1+opd2;break;
        case '-':
            *opd1 = *opd1-opd2;break;
        case '*':
            *opd1 = (*opd1)*opd2;break;
        case '/':
            if(opd2>pow(0.1,8)||opd2<0-pow(0.1,8))
                *opd1 = (*opd1)/opd2;
            else
            {
                printf("Error 1/0 !");
                return 0;
            }
            break;
        case '^':
            *opd1 = pow(*opd1,opd2);break;
    }
    return 1;
}
/*功能：判断优先级
 */
int prid(int c)
{
    switch(c)
    {
        case '+':
        case '-':
		case '=':
		case ')':
        return 1;break;
        case '*':
        case '/':
        return 2;break;
        case '^':
        return 3;break;
        default :return 0;break;
    }
}
