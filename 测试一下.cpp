#include<stdio.h>                                           //函数定义                                           
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
#define M 80                                               //80为优秀线
#define N 60                                               //60为及格线
char kfname[30]="D:\\project\\*\\***.txt";                 //定义了文件路径
struct student                                             //学生结构体（这里定义了学号，姓名，性别，分数，总分数）
{ 

	char number[9];
    char name[30];
    char sex;
    float score[3];
    float sum;
    struct student *next;
};
void output3(FILE*);
void output1(FILE *);                                     //output1函数定义(除分段输出以外都可用此函数）
void output2(FILE *,int,int);                             //output2函数定义(用于分段输出)
void paixu(FILE *,FILE *,int j,int k);                    //paixu为为数据排序的函数
void fenduan(FILE *,FILE *,int j,int k);                  //fenduan为为数据分段的函数
void yandb(FILE* ,FILE *,int i,int j,int k);              //yandb为优秀不及格函数
void main ()                                              //主函数
{
	char s='y',fname[10][30],kkfname[30];
	char*x[6]={"学号","姓名","语文成绩","数学成绩","英语成绩","总成绩"},*y[2]={"降序","升序"},*v[3]={"语文成绩","数学成绩","英语成绩"},*w[2]={"优秀","不及格"};
	int z,j,k,e,i,n=0,q,u=1,c,aa=1,bb=1,cc=1,dd=1,ee=1,ff=1,gg=1,hh=1;                  //z代表班级
	FILE*p[10],*p0,*p2,*fp;                                                             //p[10]为原始成绩单指针

	printf("欢迎使用成绩管理程序\n该程序版权所有  翻版必究\n");
	getchar();
    printf("\n现在开始加载原始成绩单\n");
	while(s=='y')                                     //s为进入while的条件，fname,kkfname为存文件名的数组
	{
		n++;
		printf("请输入第%d个班的原始成绩单所在文件的文件名:",n);
		scanf("%s",fname[n]);
		while(u==1)
		{u=0;
		  if((p[n]=fopen(fname[n],"rb"))==NULL)
		  {
			  printf("该文件打不开\n重新输入还是终止程序(1，重新输入2，终止) :  ");
		      scanf("%d",&c);
			  if(c==2) 
				  exit(0);
			  else 
			  {
				  printf("请输入第%d个班的原始成绩单所在文件的文件名: ",n);
				  scanf("%s",fname[n]);u=1;
			  }
		  }
		}
		u=1;
		printf("是否继续(y->是  n->否) :");
		scanf("\n%c",&s);
	
	}
	printf("接下来开始处理原始成绩单:\n");
    for(z=1;z<=3;z++)                                                           //z代表班级                                                    
		for(j=1;j<=6;j++)                                               //j代表*x[6]指的六个变量
			for(k=0;k<=1;k++)                                       //k代表升降序
			{
				kfname[13]=2+48;                                //这里利用三重for语句对之前定义的char kfname[30]="D:\\project\\*\\***.txt";的“*”进行赋值
				kfname[11]=z+48;
				kfname[14]=j+48;
				kfname[15]=k+48;
				if((p0=fopen(kfname,"wb"))==NULL)               //这里将内容“只写”入文件中
				{
					printf("can not\n");
				    exit(0);
				}
				if((fp=fopen(fname[z],"rb"))==NULL)             //打开文件
				{
				      printf("NOT\n");
					 exit(0);
				}
			   paixu(fp,p0,j,k);                                     //运行排序函数
			   fclose(p0);
			   fclose(fp);
			   getchar();
			   printf("第%d个班按%s排序的%s成绩单已生成并保存在%s文件中\n",z,x[j-1],y[k],kfname);
			}
    for(z=1;z<=3;z++)                                                                 //z代表班级
		 for(i=3;i<=4;i++)                                                    //i 3代表优秀，4代表不优秀，这里主要用与yandb函数
			 for(k=1;k<=3;k++)                                            //k代表升降序 
				 for(j=0;j<=1;j++)                                    //j代表*x[6]指的六个变量                              
				 {
					kfname[13]=i+48;
				    kfname[11]=z+48;
				    kfname[14]=j+48;
				    kfname[15]=k+48;
                    if((p0=fopen(kfname,"wb"))==NULL)
					{
						printf("can not\n");
					     exit(0);
					}
					   
					if((fp=fopen(fname[z],"rb"))==NULL)           //文件“只写”
					{
						printf("NOT\n");
					    exit(0);
					}
		           yandb(fp,p0,i,j,k);
				   fclose(p0);
				   fclose(fp);
				   getchar();
				   printf("第%d个班按%s处理的%s的%s成绩单已生成并保存在%s文件夹中\n",z,v[k-1],y[j],w[i-3],kfname);
				 }
	   for(z=1;z<=3;z++)                                                           //同上z代表班级,j代表*x[6]指升降,k代表科目，这里用于分段函数
			for(k=1;k<=3;k++)
              for(j=0;j<=1;j++)
				{
					
					   kfname[13]=5+48;
				       kfname[11]=z+48;
				       kfname[14]=j+48;
				       kfname[15]=k+48;
					   if((p0=fopen(kfname,"wb"))==NULL)
					   {
						   printf("can not\n");
				           exit(0);
					   }
					   if((fp=fopen(fname[z],"rb"))==NULL)
					   {
						   printf("NOT\n");
					       exit(0);
					   }
			          fenduan(fp,p0,j,k);
				      fclose(p0);
				      fclose(fp);
				      getchar();
				      printf("第%d个班按%s处理的%s的分段成绩单已生成并保存在%s文件夹中\n",z,v[k-1],y[j],kfname);
			  }
	s='y';
    while(s=='y')
	{
        printf("请选择访问方式:1,按文件名 2,按类型逐步\n");
		scanf("%d",&e);
		if(e==1)                                                  //按1.文件名方式访问
		{
		    printf("请输入文件名:");
		    scanf("%s",kkfname);
		    while(bb==1)
			{   bb=0;
			    if((p2=fopen(kkfname,"rb"))==NULL)
				{
					bb=1;
			        printf("该文件打不开\n");
			        printf("重新输入还是终止程序(1, 重新输入2，终止程序):   ");
			        scanf("%d",&aa);
			        if(aa==2)
						exit(0);
					else
					{
						printf("请输入文件名:");
		                scanf("%s",kkfname);
					}
				}
			}
		    bb=1;
		    if(kkfname[13]==(5+48))
			   output2(p2,kkfname[14]-48,kkfname[15]-48);
		    if(kkfname[13]==(3+48)||kkfname[13]==(4+48))
			    output3(p2);
		    if((kkfname[13]!=(48+5))&&(kkfname[13]!=(3+48))&&(kkfname[13]!=(4+48)))
			   output1(p2);
		    fclose(p2);
		}
        if(e==2)                                                      //按2.按类型逐步方式访问
		{
			
			printf("请选择班级(从1~%d中选):",n);
			scanf("\n%c",&kfname[11]);q=kfname[11]-48;      //对kfname[11]赋值
			while(cc==1)
			{
				cc=0;
				if(q<1||q>n)
				{
					printf("输入有误  重新输入\n");
                    printf("请选择班级(从1~%d中选):",n);
			        scanf("\n%c",&kfname[11]);q=kfname[11]-48;
				    cc=1;
				}
			}
			cc=1;
            printf("请选择成绩单类型(1,原始成绩单 2,排序后成绩单 3,优秀成绩单 4,不及格成绩单 5,分段成绩单):");
			scanf("\n%c",&kfname[13]);i=kfname[13]-48;
			while(dd==1)
			 {
				dd=0;
	            if(i<1||i>6)
				{
                  printf("输入有误  重新输入\n");
	              printf("请选择成绩单类型(1,原始成绩单 2,排序后成绩单 3,优秀成绩单 4,不及格成绩单 5,分段成绩单):");
			      scanf("\n%c",&kfname[13]);i=kfname[13]-48;
			      dd=1;
				}
			 }
            dd=1;
  if(i==1)
	output1(p[q]);                                                   //p[q]为原始成绩单文件指针数组
  if(i==2)
	{
		printf("请选择依据(1,学号 2，姓名3，语文成绩4，数学成绩5，英语成绩6，总成绩):");
		scanf("\n%c",&kfname[14]);j=kfname[14]-48;               //j=kfname[14]-48代表排序依据
        while(ee==1) 
		{
	          ee=0;
	          if(j<1||j>6)
			  {  printf("输入有误  重新输入\n");
	             printf("请选择依据(1,学号 2，姓名3，语文成绩4，数学成绩5，英语成绩6，总成绩):");
	             scanf("\n%c",&kfname[14]);j=kfname[14]-48;
			     ee=1;
			  }
		}
        ee=1;
        printf("请选择升或降(1->升 2－>降):");
	    scanf("\n%c",&kfname[15]);k=kfname[15]-48;
			while(ff==1)
			{
				ff=0;
				if(k!=0&&k!=1)
				{
					printf("输入有误  重新输入\n");
				    printf("请选择升或降(1->升 2－>降):");
			        scanf("\n%c",&kfname[15]);k=kfname[15]-48;
			        ff=1;
				}
			}
		ff=1;
		if((p0=fopen(kfname,"rb"))==NULL)
		{
			printf("can not\n");
			exit(0);
		}
		output1(p0);
		fclose(p0);
	}
if(i==3||i==4)
{
	printf("请选择升或降(1->升 2－>降):");
    scanf("\n%c",&kfname[14]);j=kfname[14]-48; 
	while(ff==1)
	{
		ff=0;
		if(j!=0&&j!=1)
		{
			printf("输入有误  请重新输入\n");
		    printf("请选择升或降(1->升 2－>降):");
			scanf("\n%c",&kfname[14]);j=kfname[14]-48;
			ff=1;
		}
	}
	ff=1;
    printf("请选择依据:(1,语文2，数学3，英语):");
	scanf("\n%c",&kfname[15]);k=kfname[15]-48;
	while(ff==1)
	{
		ff=0;
		if(k<1||k>3)
		{   printf("输入有误  重新输入\n");
			printf("请选择依据:(1,语文2，数学3，英语):");
			scanf("\n%c",&kfname[15]);k=kfname[15]-48;
			ff=1;
		}
	}
	ff=1;
	if((p0=fopen(kfname,"rb"))==NULL)
	{
		printf("can not\n");
		exit(0);
	}
	output3(p0);
	fclose(p0);
}
if(i==5)
{
	printf("请选择升或降(1->升 2－>降):");
	scanf("\n%c",&kfname[14]);j=kfname[14]-48;
	while(ff==1)
	{
		ff=0;
		if(j!=0&&j!=1)
		{
			printf("输入有误  重新输入\n");
			printf("请选择升或降(1->升 2－>降):");
			scanf("\n%c",&kfname[14]);j=kfname[14]-48;
			ff=1;
		}
	}
	ff=1;
	printf("请选择依据:(1,语文2，数学3，英语):");
	scanf("\n%c",&kfname[15]);k=kfname[15]-48;
	while(ff==1)
	{
		ff=0;
		if(k<1||k>3)
		{
			printf("输入有误  重新输入\n");
			printf("请选择依据:(1,第一科2，第二科3，第三科):");
			scanf("\n%c",&kfname[15]);k=kfname[15]-48;
			ff=1;
		}
	}
	ff=1;
	if((p0=fopen(kfname,"rb"))==NULL)
	{
		printf("can not\n");
		exit(0);
	}
	output2(p0,j,k);
	fclose(p0);
}
}
printf("是否继续(y->是  n->否): ");
scanf("\n%c",&s);
}
if(s!='y')
printf("\n欢迎下次使用\n再见\n");
getchar();                                              //主函数结束
}

void paixu(FILE *p1,FILE *p2,int j,int k)              //排序函数内容  p1为读入指针 p2为写入指针
{
	char a[10][30],temp[30];
	int m,n,i,w=1;
	float b[10],te;
	struct student tempp,cf[10];                  //cf为十个人成绩的信息
	fread(cf,sizeof(struct student),10,p1);       //读入struct student中的内容，并存在cf数组中
	if(j==1||j==2)                                //排序
	{
		for(i=0;i<10;i++)
		{       if(j==1)
				strcpy(a[i],cf[i].number);
				if(j==2)
				strcpy(a[i],cf[i].name);
		}
		for(i=0;i<10;i++)                     //选择法
		{      
			m=i;
			for(n=i+1;n<10;n++)
				{
				    if(k==1&&strcmp(a[m],a[n])>0)
					 m=n;
					 if(k==0&&strcmp(a[m],a[n])<0)
						m=n;
				}
			if(m!=i)
				{
					tempp=cf[i];
					cf[i]=cf[m];
					cf[m]=tempp;
					strcpy(temp,a[m]);
					strcpy(a[m],a[i]);
					strcpy(a[i],temp);
				}
			        
		}
	}
	if(j!=1&&j!=2)                               //冒泡排序
	{
	
	      for(i=0;i<10;i++)

		  { if(j==3) b[i]=(cf[i].score)[0];
			if(j==4) b[i]=(cf[i].score)[1];
			if(j==5) b[i]=(cf[i].score)[2];
			if(j==6) b[i]=cf[i].sum;
		  }
		while(w==1)
		{
			w=0;
					for(i=0;i<9;i++)
					{
						if(k==1&&(b[8-i]>b[9-i]))
						 {
							tempp=cf[9-i];
						    w=1;
						    cf[9-i]=cf[8-i];
						    cf[8-i]=tempp;
						    te=b[8-i];
						    b[8-i]=b[9-i];
						    b[9-i]=te;
						}
						
					 if(k==0&&(b[8-i]<b[9-i]))
					{
							tempp=cf[9-i];
						   w=1;
						   cf[9-i]=cf[8-i];
						   cf[8-i]=tempp;
                           te=b[8-i];
						   b[8-i]=b[9-i];
						   b[9-i]=te;
					 }
					}
		}
	}
	for(i=0;i<10;i++)
		fwrite(&cf[i],sizeof(struct student),1,p2);
}

void yandb(FILE*p1,FILE*p2,int i,int j,int k)                     //yandb函数定义 优秀不及格函数

{
	struct student cf[10],df[11],temp;
	float b[10],e[10],temppp;                                 //b[10]用于排序，e[10]为从b中挑选出数据存进去
    int m,n,w=-1,d, r,g=0;
    fread(cf,sizeof(struct student),10,p1);
    for(d=0;d<10;d++)
	{
		if(k==1) b[d]=(cf[d].score)[0];                   //k代表科目
		if(k==2) b[d]=(cf[d].score)[1];
		if(k==3) b[d]=(cf[d].score)[2];
	}

    for(d=0;d<10;d++)
	{
		if(i==3&&b[d]>=M)
		{
			w++;
            e[w]=b[d];df[w]=cf[d];
		}
        if(i==4&&b[d]<N)
        {
			w++;
            e[w]=b[d];df[w]=cf[d];}
		}
		for(d=0;d<=w;d++)
		{
			m=d;
			for(n=d+1;n<=w;n++)
			{
				if(j==1&&e[m]>e[n])
					m=n;
				if(j==0&&e[m]<e[n])
					m=n;
			}
			if(m!=d)
			{
				temp=df[d];
			    df[d]=df[m];
			    df[m]=temp;
			    temppp=e[d];
               e[d]=e[m];
               e[m]=temppp;
			}
		}
		for(r=0;r<=w;r++)
			fwrite(&df[r],sizeof(struct student),1,p2);
}



void output3(FILE*fp)                                                //output3函数定义
{
	struct student*head,*p1,*p2;
	int n=0;
	head=NULL;
	p1=p2=(struct student*)malloc(sizeof(struct student));
	fread(p1,sizeof(struct student),1,fp);
	if(p1->number[0]!='5')
		printf("\n***************没有****************\n");
	else
		while(p1->number[0]=='5')
		{
			n=n+1;
			if(n==1)
				head=p1;
			else
			{
				p2=p1;
				p1=(struct student*)malloc(sizeof(struct student));
				fread(p1,sizeof(struct student),1,fp);
				p2->next=p1;
			}
		}
		p2->next=NULL;
		p2=head;
		printf("\n相应的成绩单如下：\n");
		printf("  学号               姓名         性别    语文  数学  英语  总成绩\n");
		printf("*******************************************************************************\n");
		while(p2!=NULL)
		{
			printf("%-20s%-15s %c    %-7.1f%-7.1f%-7.1f%-7.1f\n",p2->number,p2->name,p2->sex,p2->score[0],p2->score[1],p2->score[2],p2->sum);
            p2=p2->next;
		}
		printf("********************************************************************************\n\n");
}

 
void output1(FILE*p)                                                     //output1函数定义
{
	int i=0;
    struct student cf[10];fread(&cf[0],sizeof(struct student),1,p);
	if((cf[0].number)[0]!=5+48)
		printf("\n************没有相应的成绩单**********\n");
    else
	{
		printf("\n相应的成绩单如下：\n");
	    printf("  学号            姓名        性别         语文  数学  英语  总成绩\n");
        printf("********************************************************************************\n");
		while((cf[i].number)[0]==5+48)
		{
			printf("%-16s%-15s %c          %-7.1f%-7.1f%-7.1f%-7.1f",cf[i].number,cf[i].name,cf[i].sex,(cf[i].score)[0],(cf[i].score)[1],(cf[i].score)[2],cf[i].sum);
	        printf("\n");
		    i++;
            fread(&cf[i],sizeof(struct student),1,p);
	
		}
	}
	printf("*******************************************************************************\n\n");

}
 


void output2(FILE*p,int j,int k)                                      //output2函数定义
{
	int m,i;
	struct student cf[10];
	float b[10];
	printf("\n相应成绩如下：\n");
	printf(" 成绩段           学号            姓名  性别    语文  数学 英语 总成绩\n");
	printf("*********************************************************************\n");
	fread(cf,sizeof(struct student),10,p);
	for(i=0;i<10;i++)
	{
		if(k==1) b[i]=cf[i].score[0];
		if(k==2) b[i]=cf[i].score[1];
		if(k==3) b[i]=cf[i].score[2];
	}
	if(j==1)
	{
		for(m=0;m<10;m++)
		{
			printf("%d--%d分\n",m*10,(m+1)*10);
			for(i=0;i<10;i++)
				if(b[i]>=(m*10)&&b[i]<((m+1)*10))
				{
					printf("%20s%20s %c %7.1f%7.1f%7.1f%7.1f",cf[i].number,cf[i].name,cf[i].sex,cf[i].score[0],cf[i].score[1],cf[i].score[2],cf[i].sum);
	                 printf("\n");
				}
				printf("_______________________________________________________________________\n");
		}
	}
	if(j==0)
	{
		for(m=9;m>=0;m--)
		{
			printf("%d--%d分\n",m*10,(m+1)*10);
			for(i=0;i<10;i++)
				if(b[i]>=(m*10)&&b[i]<((m+1)*10))
				{
					printf("%20s%20s%4.1f%4.1f%4.1f%4.1f",cf[i].number,cf[i].name,cf[i].score[0],cf[i].score[1],cf[i].score[2],cf[i].sum);
	                 printf("\n");
				}
				printf("__________________________________________________________________________\n");
		}
	}
	printf("*********************************************************************\n");
}




void fenduan(FILE*p1,FILE*p2,int j,int k)                              //分段函数定义
{ struct student cf[10],temp;
  float b[10],tempp;
  int i,m,n;
  for(i=0;i<10;i++)
  {
	  fread(&cf[i],sizeof(struct student),1,p1);
	  if(k==1) b[i]=cf[i].score[0];
	  if(k==2) b[i]=cf[i].score[1];
	  if(k==3) b[i]=cf[i].score[2];
  }
  for(i=0;i<10;i++)                                                    //排序过程
  {  
	  m=i;
	  for(n=i+1;n<10;n++)
	  {
		  if(j==1&&b[m]>b[n])
			  m=n;
		  if(j==0&&b[m]<b[n])
			  m=n;
	  }
	  if(m!=i)
	  {
		  tempp=b[i];
	      b[i]=b[m];
	      b[m]=tempp;
	      temp=cf[i];
	      cf[i]=cf[m];
	      cf[m]=temp;
	  }
  }
  fwrite(cf,sizeof(struct student),10,p2);
}