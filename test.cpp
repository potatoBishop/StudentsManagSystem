#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
//================================================结构体区 
 typedef struct stu{
	//基础 
	char id[20];
	char name[10];
	
	//成绩
	float c; 
	float math; 
	float eng;
	float sum; 
	
	struct stu *next;
	
	void printI(){
		printf("%s %s %.2f %.2f %.2f %.2f\n",id,name,c,math,eng,sum);
	}
} link; 

//=================================================函数声明区 
void new_link();

int dengLu();		//登陆界面  
void guanLi();    //管理菜单界面  
	void search_Stu();   //  1.学生信息查询 
		void search_by_id(); 
		void search_by_name();
		void search_by_c();
		void search_by_math(int num);
		void search_by_eng(int num);
		void search_by_sum(int num);
		
void add_Stu();     //   2.添加学生 
void sort_Stu();     //  3.排序查询学生 
	void sort_by_c();
	void sort_by_math();
	void sort_by_eng();
	void sort_by_sum();
		
void del_Stu();		//   4.删除学生信息 
//void out_sys();   //     5.退出程序 
	 
	 
//杂辅助函数	 
void basic();    //输出标题 
void openError();   //检查文件是否打开成功 



link *head,*tail,*ps;
//=================================================main
int main()
{
	new_link();//载入文件    

	basic();
	int pan = 1;
	int flag=dengLu();
	 
	if(flag==1){
		
		while(pan){
			//界面打印 
			system("cls");
			basic();
			guanLi();
			
			//判断用户的操作意愿 
			int flag_g=0;    scanf("%d",&flag_g);
			system("cls");
			basic();
			if(flag_g==1){
			//	search_Stu();
				
			}else if(flag_g==2){
				add_Stu();
					
			}else if(flag_g==3){
				//sort_Stu();
				
			}else if(flag_g==4){
				//del_Stu();
					
			}else if(flag_g==5){
				pan=0;
				              //退出程序	
			}	
				
		}   
	}
	
	
	return 0;
}

//==================================================函数实现区
void new_link(){
	head= (link*)malloc(sizeof(link));//头节点  初始化 
	strcpy(head->name,"admin");
	strcpy(head->id,"123");
	head->c=0;
	head->eng=0;
	head->math=0;
	head->sum=0;
	
	link *temp=head;
	int i=0;
	//生成链表
	FILE *g=fopen("成绩.txt","r");
	while(!feof(g)){
		link* a= (link*)malloc(sizeof(link));
		fscanf(g,"%s %s %f %f %f %f",&a->id, &a->name, &a->c, &a->math, &a->eng, &a->sum);
		a->next=NULL;
		//建立连接
		temp->next= a;
		temp= temp->next; 
		
	}
	tail= temp; 
	fclose(g);
}
 
void search_Stu(int num){
	puts("		请选择查询方式：");	
	puts("		1.按学号");	
	puts("		2.按姓名");	
	puts("		3.按c语言成绩");	
	puts("		4.按数学成绩");	
	puts("		5.按英语成绩");	
	puts("		6.按总成绩");
	puts("		7.返回主菜单");
	
	while(1){
		
		int flag_s;    scanf("%d",&flag_s);
		if(flag_s==1){
			//search_by_id();
			
		}else if(flag_s==2){
			//search_by_name();
			
		}else if(flag_s==3){
			
		}else if(flag_s==4){
			
		}else if(flag_s==5){
			
		}else if(flag_s==6){
			
		}else if(flag_s==7){
		}	
	}
}
void search_by_id(int num){
	printf("		请输入学号：");
	char str[20];    scanf("%s",&str);
	
	for(int i=0;i<num;i++){
		
	}
	puts("\n\n		查询完毕！");
}

void basic(){
	printf("		---------------学生信息管理系统---------------\n\n"); 
} 

void add_Stu(){
	puts("		请分别输入学生的 学号 姓名 c语言成绩 数学成绩 英语成绩：");
	printf("                  ");
	stu *pp=(link*)malloc(sizeof(link));
	//输入新学生 
	scanf("%s %s %f %f %f",&pp->id, &pp->name, &pp->c, &pp->math, &pp->eng);
	pp->sum = pp->c + pp->math + pp->eng;
	pp->next= NULL;
	pp->printI();
	//尾节点转移 
	tail->next=pp;
	tail=pp;
	//覆写文件 
	FILE *fp=fopen("成绩.txt","w");
	ps= head;
	while(ps!=NULL){
		fprintf(fp,"%s %s %f %f %f %f\n",ps->id, ps->name, ps->c, ps->math, ps->eng, ps->sum);
		ps=ps->next;
	}

	fclose(fp);
	
	
	
	puts("创建成功！"); 
	Sleep(2000);
} 

void error_cheek(FILE *p){     //文件是否打开 
	if(p==NULL){
		system("cls");
		basic();
		puts("open file fail!可能是未创建账号！");
		exit(0);
	}
}

void guanLi()
{
	puts("		1.学生信息查询");
	puts("		2.添加学生");
	puts("		3.排序查询学生");
	puts("		4.删除学生信息");
	puts("		5.退出程序");
	puts("		--------------------------------------------");
	printf("		请根据需要输入所需的服务代号:");	
	
	
	
}


int dengLu(){

	return 1;
	

} 


