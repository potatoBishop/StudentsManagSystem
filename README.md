# 学生信息管理系统 大一 期末作业

大一上学期的期末大作业，漏洞百出
纯C语言实现

默认白名单账号：admin
          密码：123
记得按回车确认


主要功能：
  教师白名单登录、
  添加学生、
  删除学生、
  按照学生的不同条件进行查找、
  文件操作
  
 
主要函数一览
int dengLu();		//登陆界面  
void guanLi();    //管理菜单界面  
	void search_Stu();   //  1.学生信息查询 
		void search_by_id();  //学号查询
		void search_by_name();  //姓名查询
		void search_by_c();     //以下均为按不同成绩查询
		void search_by_math();
		void search_by_eng();
		void search_by_sum();
		
void add_Stu();     //   2.添加学生 
void sort_Stu();     //  3.排序查询学生 
	void sort_by_c();        //通过不同条件查询学生排名
	void sort_by_math();
	void sort_by_eng();
	void sort_by_sum();
		
void del_Stu();		//   4.删除学生信息 
//void out_sys();   //     5.退出程序 
	 
	 
//杂辅助函数	 
void basic();    //输出标题 
void openError();   //检查文件是否打开成功 
 
 ![image](https://user-images.githubusercontent.com/89138111/234158172-5fc50eb5-7aff-4767-8385-af2f2f306de6.png)
 ![image](https://user-images.githubusercontent.com/89138111/234158232-02817df3-23ec-4c51-9600-3640d7997f45.png)
![image](https://user-images.githubusercontent.com/89138111/234158250-f3b57cce-8bc3-456f-b2ea-2bdc5b00f4ec.png)
![image](https://user-images.githubusercontent.com/89138111/234158275-a070a2cc-8433-4e80-ad16-2980042882fd.png)
![image](https://user-images.githubusercontent.com/89138111/234158503-448a66eb-da3c-4789-912d-5c57f47704c4.png)
![image](https://user-images.githubusercontent.com/89138111/234160692-20a540c6-d97c-4ec4-8f65-6132c1a3388e.png)

注意！：文件操作时，中文输入时好时坏，请尽量使用英文
 
