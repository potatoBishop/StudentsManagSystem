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
		printf("%-10s %-10s %-7.2f %-7.2f %-7.2f %-7.2f\n",id,name,c,math,eng,sum);
	}
} link; 

int num=0;
//=================================================函数声明区 
void new_link();

int dengLu();		//登陆界面  
void guanLi();    //管理菜单界面  
	void search_Stu();   //  1.学生信息查询 
		void search_by_id(); 
		void search_by_name();
		void search_by_c();
		void search_by_math();
		void search_by_eng();
		void search_by_sum();
		
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
				search_Stu();
				
			}else if(flag_g==2){
				add_Stu();
					
			}else if(flag_g==3){
				sort_Stu();
				
			}else if(flag_g==4){
				del_Stu();
					
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
	FILE *g=fopen("成绩.txt","r");
	head= (link*)malloc(sizeof(link));//头节点  初始化 

	fscanf(g,"%d",&num);
	int u=num;
	fscanf(g,"%s %s %f %f %f %f",&head->id, &head->name, &head->c, &head->math, &head->eng, &head->sum);
	head->next=NULL;
		
	link *temp=head;
	//生成链表
	u--;
	while(u){
		link* a= (link*)malloc(sizeof(link));
		fscanf(g,"%s %s %f %f %f %f",&a->id, &a->name, &a->c, &a->math, &a->eng, &a->sum);
		a->next=NULL;
		//建立连接
		temp->next= a;
		temp= temp->next; 
		u--;
	}
	tail= temp; 
	fclose(g);

} 
void swap_node(stu *p1, stu *p2){
	stu p3;
	p3.c=p2->c;
	p3.sum=p2->sum;
	p3.math=p2->math;
	p3.eng=p2->eng;
	strcpy(p3.id,p2->id);
	strcpy(p3.name,p2->name);
	//p3.next=p2->next;
	
	p2->c=p1->c;
	p2->sum=p1->sum;
	p2->math=p1->math;
	p2->eng=p1->eng;
	strcpy(p2->id,p1->id);
	strcpy(p2->name,p1->name);
//	p2->next=p1->next;
	
	p1->c=p3.c;
	p1->sum=p3.sum;
	p1->math=p3.math;
	p1->eng=p3.eng;
	strcpy(p1->id,p3.id);
	strcpy(p1->name,p3.name);
//	p1->next=p3.next;
	
}
void del_node(stu *p1){
	stu *pre=head;
	ps=head->next;

	for(int i=0;i<num-1;i++){
		if(ps->id==p1->id){
			pre->next=ps->next;
			delete ps;
			break;
		}
		
		pre=ps;
		ps=ps->next;
	}
}

void del_Stu(){
		int flag=0;
		puts("		请输入删除所需学号：");	
		printf("		学号：");	
//		puts("		2.返回主菜单");	
//		printf("		:");
		char hao[20];    scanf("%s",&hao);
		ps=head;   
		
		for(int i=0;i<num;i++){
			if(!strcmp(ps->id,hao)){
				flag=1;
				printf("删除学生：\n");
				ps->printI();
				del_node(ps);
				break;
			}
			
			
			ps=ps->next;
		}
		
		
		system("cls");
		basic();
		if(flag==1){
			
			//覆写文件 
			FILE *fp=fopen("成绩.txt","w");
			ps= head;
			num--;
			fprintf(fp,"%d\n",num);
			while(ps!=NULL){
				fprintf(fp,"%s %s %f %f %f %f\n",ps->id, ps->name, ps->c, ps->math, ps->eng, ps->sum);
				ps=ps->next;
			}
			fclose(fp);
			puts("\n\n		删除完毕！按任意键后退出");
		}else{
			puts("未查询到该学生！");
		}
		
		char lll;
		getchar();
		scanf("%c",&lll);
	
}	


void sort_Stu(){
	while(1){
		puts("		请选择排序查询方式：");	
		puts("		1.按c语言成绩");	
		puts("		2.按高数成绩");	
		puts("		3.按英语成绩");	
		puts("		4.按总成绩");	
		puts("		5.返回主菜单");	
		
		printf("		:");
		int flag_s;    scanf("%d",&flag_s);
		if(flag_s==1){
			sort_by_c();
		}else if(flag_s==2){
			sort_by_math();	
		}else if(flag_s==3){
			sort_by_eng();
		}else if(flag_s==4){
			sort_by_sum();
		}else if(flag_s==5){
			break;
		}
		system("cls");
		basic();
	}
}
void sort_by_c(){
	system("cls");
	basic();
	printf("		学号	    姓名     c语言    高数   英语    总成绩\n");
	ps=head;
	for(int i=0;i<num;i++){
		stu *ps2=head;
		for(int j=0;j<num;j++){
			if(ps->c< ps2->c){
				swap_node(ps,ps2);
			}
			ps2=ps2->next;
		}
		ps=ps->next;
	}
	ps=head;
	for(int i=0;i<num;i++){
		printf("		");
		ps->printI();
		ps=ps->next;
	}
	puts("\n\n		查询完毕！按任意键后退出");
	char lll;
	getchar();
	scanf("%c",&lll);
}
void sort_by_math(){
	system("cls");
	basic();
	printf("		学号	    姓名     c语言    高数   英语    总成绩\n");
	ps=head;
	for(int i=0;i<num;i++){
		stu *ps2=head;
		for(int j=0;j<num;j++){
			if(ps->math< ps2->math){
				swap_node(ps,ps2);
			}
			ps2=ps2->next;
		}
		ps=ps->next;
	}
	ps=head;
	for(int i=0;i<num;i++){
		printf("		");
		ps->printI();
		ps=ps->next;
	}
	puts("\n\n		查询完毕！按任意键后退出");
	char lll;
	getchar();
	scanf("%c",&lll);
}
void sort_by_eng(){
	system("cls");
	basic();
	printf("		学号	    姓名     c语言    高数   英语    总成绩\n");
	ps=head;
	for(int i=0;i<num;i++){
		stu *ps2=head;
		for(int j=0;j<num;j++){
			if(ps->eng< ps2->eng){
				swap_node(ps,ps2);
			}
			ps2=ps2->next;
		}
		ps=ps->next;
	}
	ps=head;
	for(int i=0;i<num;i++){
		printf("		");
		ps->printI();
		ps=ps->next;
	}
	puts("\n\n		查询完毕！按任意键后退出");
	char lll;
	getchar();
	scanf("%c",&lll);
}
void sort_by_sum(){
	system("cls");
	basic();
	printf("		学号	    姓名     c语言    高数   英语    总成绩\n");
	ps=head;
	for(int i=0;i<num;i++){
		stu *ps2=head;
		for(int j=0;j<num;j++){
			if(ps->sum< ps2->sum){
				swap_node(ps,ps2);
			}
			ps2=ps2->next;
		}
		ps=ps->next;
	}
	ps=head;
	for(int i=0;i<num;i++){
		printf("		");
		ps->printI();
		ps=ps->next;
	}
	puts("\n\n		查询完毕！按任意键后退出");
	char lll;
	getchar();
	scanf("%c",&lll);
}


void search_Stu(){
	
	while(1){
		puts("		请选择查询方式：");	
		puts("		1.按学号");	
		puts("		2.按姓名");	
		puts("		3.按c语言成绩");	
		puts("		4.按数学成绩");	
		puts("		5.按英语成绩");	
		puts("		6.按总成绩");
		puts("		7.返回主菜单");
		printf("		:");
		int flag_s;    scanf("%d",&flag_s);
		if(flag_s==1){
			search_by_id();
			
		}else if(flag_s==2){
			search_by_name();	
		}else if(flag_s==3){
			search_by_c();
		}else if(flag_s==4){
			search_by_math();
		}else if(flag_s==5){
			search_by_eng();
		}else if(flag_s==6){
			search_by_sum();
		}else if(flag_s==7){
			break;
		}
		system("cls");
		basic();
	}
}
void search_by_sum(){
	system("cls");
	basic();
	printf("		请输入总成绩：");
	float score_sum;    scanf("%f",&score_sum);
	ps=head;
	printf("		学号	    姓名     c语言    高数   英语    总成绩\n");
	for(int i=0;i<num;i++){
		if(ps->eng==score_sum){
			printf("		");
			ps->printI();
		}
		ps=ps->next;
	}
	puts("\n\n		查询完毕！按任意键后退出");
	char lll;
	getchar();
	scanf("%c",&lll);
}
void search_by_eng(){
	system("cls");
	basic();
	printf("		请输入英语成绩：");
	float score_eng;    scanf("%f",&score_eng);
	ps=head;
	printf("		学号	    姓名     c语言    高数   英语    总成绩\n");
	for(int i=0;i<num;i++){
		if(ps->eng==score_eng){
			printf("		");
			ps->printI();
		}
		ps=ps->next;
	}
	puts("\n\n		查询完毕！按任意键后退出");
	char lll;
	getchar();
	scanf("%c",&lll);
}
void search_by_math(){
	system("cls");
	basic();
	printf("		请输入高数成绩：");
	float score_math;    scanf("%f",&score_math);
	ps=head;
	printf("		学号	    姓名     c语言    高数   英语    总成绩\n");
	for(int i=0;i<num;i++){
		if(ps->math==score_math){
			printf("		");
			ps->printI();
		}
		ps=ps->next;
	}
	puts("\n\n		查询完毕！按任意键后退出");
	char lll;
	getchar();
	scanf("%c",&lll);
}
void search_by_c(){
	system("cls");
	basic();
	printf("		请输入c语言成绩：");
	float score_c;    scanf("%f",&score_c);
	ps=head;
	printf("		学号	    姓名     c语言    高数   英语    总成绩\n");
	for(int i=0;i<num;i++){
		if(ps->c==score_c){
			printf("		");
			ps->printI();
		}
		ps=ps->next;
	}
	puts("\n\n		查询完毕！按任意键后退出");
	char lll;
	getchar();
	scanf("%c",&lll);
}
void search_by_name(){
	system("cls");
	basic();
	printf("		请输入姓名：");
	char str[20];    scanf("%s",&str);
	ps=head;
	printf("		学号	    姓名     c语言    高数   英语    总成绩\n");
	for(int i=0;i<num;i++){
		if(!strcmp(ps->name,str)){
			printf("		");
			ps->printI();
		}
		ps=ps->next;
	}
	puts("\n\n		查询完毕！按任意键后退出");
	char lll;
	getchar();
	scanf("%c",&lll);
}
void search_by_id(){
	system("cls");
	basic();
	printf("		请输入学号：");
	char str[20];    scanf("%s",&str);
	ps=head;
	printf("		学号	    姓名     c语言    高数   英语    总成绩\n");
	for(int i=0;i<num;i++){
		if(!strcmp(ps->id,str)){
			printf("		");
			ps->printI();
		}
		ps=ps->next;
	}
	puts("\n\n		查询完毕！按任意键后退出");
	char lll;
	getchar();
	scanf("%c",&lll);
}


void basic(){
	printf("		---------------学生信息管理系统---------------\n\n"); 
} 


void add_Stu(){
	puts("		请分别输入学生的 学号 姓名 c语言成绩 数学成绩 英语成绩：");
	printf("                  ");
	stu *pp=(link*)malloc(sizeof(link));
	num++;
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
	fprintf(fp,"%d\n",num);
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


void guanLi(){
	puts("		1.学生信息查询");
	puts("		2.添加学生");
	puts("		3.排序查询学生");
	puts("		4.删除学生信息");
	puts("		5.退出程序");
	puts("		--------------------------------------------");
	printf("		请根据需要输入所需的服务代号:");	
	
	
	
}


int dengLu(){

	int f_time=0;
	
	while(f_time<3){
		puts("		欢迎来到学生信息管理系统\n");
		puts("		请输入您的白名单账号与密码\n");
		if(f_time!=0)puts("		账户密码错误！请重试！\n\n");
		 
		printf("		账号：");
		char p_id[20];		scanf("%s",&p_id);
		
		printf("\n\n		密码：");
		char p_secret[20];		scanf("%s",&p_secret);
	
		FILE *p;	p=fopen("白名单.txt","r");
		error_cheek(p);
		 
		char p_id2[20],p_secret2[20];
		while(!feof(p)){	
			fscanf(p,"%s %s", &p_id2, &p_secret2);
			if((!strcmp(p_id2,p_id))&&(!strcmp(p_secret,p_secret2))){
				system("cls");
				basic();
				puts("		登陆成功,loading...\n");
				Sleep(1000);
				system("cls");
				basic();
				return 1; 
			}
		}
		f_time++;
		system("cls");
		basic();
		fclose(p);
	
	}
	
	system("cls");
	basic();
	puts("		登陆失败超过三次，即将退出程序！");
	return 0;
	

} 


