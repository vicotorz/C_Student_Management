#include<stdio.h>                                           //��������                                           
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
#define M 80                                               //80Ϊ������
#define N 60                                               //60Ϊ������
char kfname[30]="D:\\project\\*\\***.txt";                 //�������ļ�·��
struct student                                             //ѧ���ṹ�壨���ﶨ����ѧ�ţ��������Ա𣬷������ܷ�����
{ 

	char number[9];
    char name[30];
    char sex;
    float score[3];
    float sum;
    struct student *next;
};
void output3(FILE*);
void output1(FILE *);                                     //output1��������(���ֶ�������ⶼ���ô˺�����
void output2(FILE *,int,int);                             //output2��������(���ڷֶ����)
void paixu(FILE *,FILE *,int j,int k);                    //paixuΪΪ��������ĺ���
void fenduan(FILE *,FILE *,int j,int k);                  //fenduanΪΪ���ݷֶεĺ���
void yandb(FILE* ,FILE *,int i,int j,int k);              //yandbΪ���㲻������
void main ()                                              //������
{
	char s='y',fname[10][30],kkfname[30];
	char*x[6]={"ѧ��","����","���ĳɼ�","��ѧ�ɼ�","Ӣ��ɼ�","�ܳɼ�"},*y[2]={"����","����"},*v[3]={"���ĳɼ�","��ѧ�ɼ�","Ӣ��ɼ�"},*w[2]={"����","������"};
	int z,j,k,e,i,n=0,q,u=1,c,aa=1,bb=1,cc=1,dd=1,ee=1,ff=1,gg=1,hh=1;                  //z����༶
	FILE*p[10],*p0,*p2,*fp;                                                             //p[10]Ϊԭʼ�ɼ���ָ��

	printf("��ӭʹ�óɼ��������\n�ó����Ȩ����  ����ؾ�\n");
	getchar();
    printf("\n���ڿ�ʼ����ԭʼ�ɼ���\n");
	while(s=='y')                                     //sΪ����while��������fname,kkfnameΪ���ļ���������
	{
		n++;
		printf("�������%d�����ԭʼ�ɼ��������ļ����ļ���:",n);
		scanf("%s",fname[n]);
		while(u==1)
		{u=0;
		  if((p[n]=fopen(fname[n],"rb"))==NULL)
		  {
			  printf("���ļ��򲻿�\n�������뻹����ֹ����(1����������2����ֹ) :  ");
		      scanf("%d",&c);
			  if(c==2) 
				  exit(0);
			  else 
			  {
				  printf("�������%d�����ԭʼ�ɼ��������ļ����ļ���: ",n);
				  scanf("%s",fname[n]);u=1;
			  }
		  }
		}
		u=1;
		printf("�Ƿ����(y->��  n->��) :");
		scanf("\n%c",&s);
	
	}
	printf("��������ʼ����ԭʼ�ɼ���:\n");
    for(z=1;z<=3;z++)                                                           //z����༶                                                    
		for(j=1;j<=6;j++)                                               //j����*x[6]ָ����������
			for(k=0;k<=1;k++)                                       //k����������
			{
				kfname[13]=2+48;                                //������������for����֮ǰ�����char kfname[30]="D:\\project\\*\\***.txt";�ġ�*�����и�ֵ
				kfname[11]=z+48;
				kfname[14]=j+48;
				kfname[15]=k+48;
				if((p0=fopen(kfname,"wb"))==NULL)               //���ｫ���ݡ�ֻд�����ļ���
				{
					printf("can not\n");
				    exit(0);
				}
				if((fp=fopen(fname[z],"rb"))==NULL)             //���ļ�
				{
				      printf("NOT\n");
					 exit(0);
				}
			   paixu(fp,p0,j,k);                                     //����������
			   fclose(p0);
			   fclose(fp);
			   getchar();
			   printf("��%d���ఴ%s�����%s�ɼ��������ɲ�������%s�ļ���\n",z,x[j-1],y[k],kfname);
			}
    for(z=1;z<=3;z++)                                                                 //z����༶
		 for(i=3;i<=4;i++)                                                    //i 3�������㣬4�������㣬������Ҫ����yandb����
			 for(k=1;k<=3;k++)                                            //k���������� 
				 for(j=0;j<=1;j++)                                    //j����*x[6]ָ����������                              
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
					   
					if((fp=fopen(fname[z],"rb"))==NULL)           //�ļ���ֻд��
					{
						printf("NOT\n");
					    exit(0);
					}
		           yandb(fp,p0,i,j,k);
				   fclose(p0);
				   fclose(fp);
				   getchar();
				   printf("��%d���ఴ%s�����%s��%s�ɼ��������ɲ�������%s�ļ�����\n",z,v[k-1],y[j],w[i-3],kfname);
				 }
	   for(z=1;z<=3;z++)                                                           //ͬ��z����༶,j����*x[6]ָ����,k�����Ŀ���������ڷֶκ���
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
				      printf("��%d���ఴ%s�����%s�ķֶγɼ��������ɲ�������%s�ļ�����\n",z,v[k-1],y[j],kfname);
			  }
	s='y';
    while(s=='y')
	{
        printf("��ѡ����ʷ�ʽ:1,���ļ��� 2,��������\n");
		scanf("%d",&e);
		if(e==1)                                                  //��1.�ļ�����ʽ����
		{
		    printf("�������ļ���:");
		    scanf("%s",kkfname);
		    while(bb==1)
			{   bb=0;
			    if((p2=fopen(kkfname,"rb"))==NULL)
				{
					bb=1;
			        printf("���ļ��򲻿�\n");
			        printf("�������뻹����ֹ����(1, ��������2����ֹ����):   ");
			        scanf("%d",&aa);
			        if(aa==2)
						exit(0);
					else
					{
						printf("�������ļ���:");
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
        if(e==2)                                                      //��2.�������𲽷�ʽ����
		{
			
			printf("��ѡ��༶(��1~%d��ѡ):",n);
			scanf("\n%c",&kfname[11]);q=kfname[11]-48;      //��kfname[11]��ֵ
			while(cc==1)
			{
				cc=0;
				if(q<1||q>n)
				{
					printf("��������  ��������\n");
                    printf("��ѡ��༶(��1~%d��ѡ):",n);
			        scanf("\n%c",&kfname[11]);q=kfname[11]-48;
				    cc=1;
				}
			}
			cc=1;
            printf("��ѡ��ɼ�������(1,ԭʼ�ɼ��� 2,�����ɼ��� 3,����ɼ��� 4,������ɼ��� 5,�ֶγɼ���):");
			scanf("\n%c",&kfname[13]);i=kfname[13]-48;
			while(dd==1)
			 {
				dd=0;
	            if(i<1||i>6)
				{
                  printf("��������  ��������\n");
	              printf("��ѡ��ɼ�������(1,ԭʼ�ɼ��� 2,�����ɼ��� 3,����ɼ��� 4,������ɼ��� 5,�ֶγɼ���):");
			      scanf("\n%c",&kfname[13]);i=kfname[13]-48;
			      dd=1;
				}
			 }
            dd=1;
  if(i==1)
	output1(p[q]);                                                   //p[q]Ϊԭʼ�ɼ����ļ�ָ������
  if(i==2)
	{
		printf("��ѡ������(1,ѧ�� 2������3�����ĳɼ�4����ѧ�ɼ�5��Ӣ��ɼ�6���ܳɼ�):");
		scanf("\n%c",&kfname[14]);j=kfname[14]-48;               //j=kfname[14]-48������������
        while(ee==1) 
		{
	          ee=0;
	          if(j<1||j>6)
			  {  printf("��������  ��������\n");
	             printf("��ѡ������(1,ѧ�� 2������3�����ĳɼ�4����ѧ�ɼ�5��Ӣ��ɼ�6���ܳɼ�):");
	             scanf("\n%c",&kfname[14]);j=kfname[14]-48;
			     ee=1;
			  }
		}
        ee=1;
        printf("��ѡ������(1->�� 2��>��):");
	    scanf("\n%c",&kfname[15]);k=kfname[15]-48;
			while(ff==1)
			{
				ff=0;
				if(k!=0&&k!=1)
				{
					printf("��������  ��������\n");
				    printf("��ѡ������(1->�� 2��>��):");
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
	printf("��ѡ������(1->�� 2��>��):");
    scanf("\n%c",&kfname[14]);j=kfname[14]-48; 
	while(ff==1)
	{
		ff=0;
		if(j!=0&&j!=1)
		{
			printf("��������  ����������\n");
		    printf("��ѡ������(1->�� 2��>��):");
			scanf("\n%c",&kfname[14]);j=kfname[14]-48;
			ff=1;
		}
	}
	ff=1;
    printf("��ѡ������:(1,����2����ѧ3��Ӣ��):");
	scanf("\n%c",&kfname[15]);k=kfname[15]-48;
	while(ff==1)
	{
		ff=0;
		if(k<1||k>3)
		{   printf("��������  ��������\n");
			printf("��ѡ������:(1,����2����ѧ3��Ӣ��):");
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
	printf("��ѡ������(1->�� 2��>��):");
	scanf("\n%c",&kfname[14]);j=kfname[14]-48;
	while(ff==1)
	{
		ff=0;
		if(j!=0&&j!=1)
		{
			printf("��������  ��������\n");
			printf("��ѡ������(1->�� 2��>��):");
			scanf("\n%c",&kfname[14]);j=kfname[14]-48;
			ff=1;
		}
	}
	ff=1;
	printf("��ѡ������:(1,����2����ѧ3��Ӣ��):");
	scanf("\n%c",&kfname[15]);k=kfname[15]-48;
	while(ff==1)
	{
		ff=0;
		if(k<1||k>3)
		{
			printf("��������  ��������\n");
			printf("��ѡ������:(1,��һ��2���ڶ���3��������):");
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
printf("�Ƿ����(y->��  n->��): ");
scanf("\n%c",&s);
}
if(s!='y')
printf("\n��ӭ�´�ʹ��\n�ټ�\n");
getchar();                                              //����������
}

void paixu(FILE *p1,FILE *p2,int j,int k)              //����������  p1Ϊ����ָ�� p2Ϊд��ָ��
{
	char a[10][30],temp[30];
	int m,n,i,w=1;
	float b[10],te;
	struct student tempp,cf[10];                  //cfΪʮ���˳ɼ�����Ϣ
	fread(cf,sizeof(struct student),10,p1);       //����struct student�е����ݣ�������cf������
	if(j==1||j==2)                                //����
	{
		for(i=0;i<10;i++)
		{       if(j==1)
				strcpy(a[i],cf[i].number);
				if(j==2)
				strcpy(a[i],cf[i].name);
		}
		for(i=0;i<10;i++)                     //ѡ��
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
	if(j!=1&&j!=2)                               //ð������
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

void yandb(FILE*p1,FILE*p2,int i,int j,int k)                     //yandb�������� ���㲻������

{
	struct student cf[10],df[11],temp;
	float b[10],e[10],temppp;                                 //b[10]��������e[10]Ϊ��b����ѡ�����ݴ��ȥ
    int m,n,w=-1,d, r,g=0;
    fread(cf,sizeof(struct student),10,p1);
    for(d=0;d<10;d++)
	{
		if(k==1) b[d]=(cf[d].score)[0];                   //k�����Ŀ
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



void output3(FILE*fp)                                                //output3��������
{
	struct student*head,*p1,*p2;
	int n=0;
	head=NULL;
	p1=p2=(struct student*)malloc(sizeof(struct student));
	fread(p1,sizeof(struct student),1,fp);
	if(p1->number[0]!='5')
		printf("\n***************û��****************\n");
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
		printf("\n��Ӧ�ĳɼ������£�\n");
		printf("  ѧ��               ����         �Ա�    ����  ��ѧ  Ӣ��  �ܳɼ�\n");
		printf("*******************************************************************************\n");
		while(p2!=NULL)
		{
			printf("%-20s%-15s %c    %-7.1f%-7.1f%-7.1f%-7.1f\n",p2->number,p2->name,p2->sex,p2->score[0],p2->score[1],p2->score[2],p2->sum);
            p2=p2->next;
		}
		printf("********************************************************************************\n\n");
}

 
void output1(FILE*p)                                                     //output1��������
{
	int i=0;
    struct student cf[10];fread(&cf[0],sizeof(struct student),1,p);
	if((cf[0].number)[0]!=5+48)
		printf("\n************û����Ӧ�ĳɼ���**********\n");
    else
	{
		printf("\n��Ӧ�ĳɼ������£�\n");
	    printf("  ѧ��            ����        �Ա�         ����  ��ѧ  Ӣ��  �ܳɼ�\n");
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
 


void output2(FILE*p,int j,int k)                                      //output2��������
{
	int m,i;
	struct student cf[10];
	float b[10];
	printf("\n��Ӧ�ɼ����£�\n");
	printf(" �ɼ���           ѧ��            ����  �Ա�    ����  ��ѧ Ӣ�� �ܳɼ�\n");
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
			printf("%d--%d��\n",m*10,(m+1)*10);
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
			printf("%d--%d��\n",m*10,(m+1)*10);
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




void fenduan(FILE*p1,FILE*p2,int j,int k)                              //�ֶκ�������
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
  for(i=0;i<10;i++)                                                    //�������
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