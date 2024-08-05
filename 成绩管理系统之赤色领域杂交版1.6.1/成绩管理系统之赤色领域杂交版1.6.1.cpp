#include <bits/stdc++.h>//c++他不香吗？
#include <windows.h>
#include <conio.h>
using namespace std;
#define MAX 300//取决于学生人数
#define N 10
int vip = 0;
time_t t = time(nullptr); // 获取1970年到现在的毫秒数
struct tm* now = localtime(&t); // 把毫秒转换为日期时间的结构体
// 以下依次把年月日的数据加入到字符串中
typedef struct Student {
	char no[20];		//学号
	char name[21];		//姓名
	int cour[6];		//6门功课成绩
	int sum = 0;		//总分
	int classno;        //班级
	int school_rank;	//校排名
	int class_rank;		//班排名
	bool out2 = false;  //第二次考试是否缺考
	int schange;        //分数变化
	int rchange;       //排名变化
} stu;
typedef struct {
	stu data[MAX];
	int length;//录入总人数
} Slist;
//科目的概念
typedef struct op {
	int average;//该课校平均分
	int smax;//校最高分
	int smin;//校最低分
	int cmax[N];//班最高分
	int cmin[N];//班最低分
	int classaverage[N];//该课的班级平均分
	int bujige_count = 0; //校不及格人数
	int banjibujige[N] = {0}; //班级不及格人数
} subj0; //这个科目的属性
struct sja {
	subj0 sub[N];
};//all subjects
//密码管理系统
typedef struct log {
	char username[MAX][MAX];//用户名
	char password[MAX][MAX];
	int num;
} user;
//日志文件
FILE *logfile;
//
FILE *f0;
//---------------------------------------函数部分-------------------------------------------------------------------
void menu1() {
	system("cls");
	cout << endl << endl << endl;
	cout << "\n\t\t";
	cout << "\t\t\t\t    へ　　　　　／|\n";
	cout << "\t\t\t\t　　/＼7　　　 ∠＿/\n";
	cout << "\t\t\t\t　 /　│　　 ／　／\n";
	cout << "\t\t\t\t　│　Z ＿,＜　／　　 /`ヽ\n";
	cout << "\t皮卡皮卡\t\t　│　　　　　ヽ　　 /　　〉\n";
	cout << "\t\t\t\t Y　　　　　`　 /　　/\n";
	cout << "\t感谢您对本系统的支持\t　?●　?　●　　??〈　　/\n";
	cout << "\t\t\t\t  ()   へ　　　　|　＼〈\n";
	cout << "\t\t\t\t　>? ?_　 ィ　 │ ／／\n";
	cout << "\t\t\t\t　 / へ　　 /　?＜| ＼＼\n";
	cout << "\t\t\t\t　 ヽ_?　　(_／　 │／／\n";
	cout << "\t\t\t\t　　7　　　　　　　|／\n";
	cout << "\t\t\t\t　　＞―r￣￣`?―＿\n";
	cout << "\n\t                                                 \n";
	cout << "\t***************************************************\n";
	cout << "\t*                学生成绩管理系统                 *\n";
	cout << "\t***************************************************\n";
	cout << "\t*               1.查看成绩（所有记录）            *\n";
	cout << "\t*               2.查看统计汇总                    *\n";
	cout << "\t*               3.成绩查询（支持模糊查询）        *\n";
	cout << "\t*               4.修改学生成绩                    *\n";
	cout << "\t*               5.学生成绩补录                    *\n";
	cout << "\t*               6.删除学生成绩                    *\n";
	cout << "\t*               7.删除数据                        *\n";
	cout << "\t*               8.分班成绩导出                    *\n";
	cout << "\t*               9.挂科名单和优秀率名单            *\n";
	cout << "\t*               A.帮助文档                        *\n";
	cout << "\t*               B.系统设置                        *\n";
	cout << "\t*               C.按其他键退出本程序              *\n";
	cout << "\t*              输入字母时请开启大写模式           *\n";
	cout << "\t***************************************************\n";
}
void menu2() {
	system("cls");
	cout << "\n\t\t";
	cout << "\t\t\t\t    へ　　　　　／|\n";
	cout << "\t\t\t\t　　/＼7　　　 ∠＿/\n";
	cout << "\t\t\t\t　 /　│　　 ／　／\n";
	cout << "\t\t\t\t　│　Z ＿,＜　／　　 /`ヽ\n";
	cout << "\t欢迎来到\t\t　│　　　　　ヽ　　 /　　〉\n";
	cout << "\t\t\t\t Y　　　　　`　 /　　/\n";
	cout << "\t赤色领域--无尽深渊\t　?●　?　●　　??〈　　/\n";
	cout << "\t\t\t\t  ()   へ　　　　|　＼〈\n";
	cout << "\t\t\t\t　>? ?_　 ィ　 │ ／／\n";
	cout << "\t\t\t\t　 / へ　　 /　?＜| ＼＼\n";
	cout << "\t\t\t\t　 ヽ_?　　(_／　 │／／\n";
	cout << "\t\t\t\t　　7　　　　　　　|／\n";
	cout << "\t\t\t\t　　＞―r￣￣`?―＿\n";
	cout << "\n\t                                                 \n";
	cout << "\t***************************************************\n";
	cout << "\t*                赤色领域--无尽深渊               *\n";
	cout << "\t***************************************************\n";
	cout << "\t*               1.毁灭程序                        *\n";
	cout << "\t*               2.作者的话                        *\n";
	cout << "\t*               3.超级无敌大                      *\n";
	cout << "\t*               4.超级管理员权限                  *\n";
	cout << "\t***************************************************\n";
}
void settype() {
	cout << endl << endl << endl << endl << endl << endl << endl << endl;
	cout << endl << endl << endl << endl << endl << endl << endl << endl;
}
//----------颜色设置-------------------------------------------------
void color() {
	cout << "\t***************************************************\n";
	cout << "\t*             请选取您想要的设置                  *\n";
	cout << "\t***************************************************\n";
	cout << "\t***************1.设置颜色（主题）******************\n";
	cout << "\t***************3.挑选其他主题（vip选项）***********\n";
	cout << "\t***************4.其他键返回************************\n";
	cout << "\t***************************************************\n";
}
void color1() {
	cout << "\t***************************************************\n";
	cout << "\t*             设置您的主题颜色                    *\n";
	cout << "\t***************************************************\n";
	cout << "\t************0.黑色***************8.灰色************\n";
	cout << "\t************1.蓝色***************9.淡蓝色**********\n";
	cout << "\t************2.绿色***************A.淡绿色**********\n";
	cout << "\t************3.浅绿色*************B.淡浅绿色********\n";
	cout << "\t************4.红色***************C.淡红色**********\n";
	cout << "\t************5.紫色***************D.淡紫色**********\n";
	cout << "\t************6.黄色***************E.淡黄色**********\n";
	cout << "\t************7.白色***************F.亮白色**********\n";
	cout << "\t***************************************************\n";
}
void color2() {
	cout << "\t***************************************************\n";
	cout << "\t*             设置您的主题颜色                    *\n";
	cout << "\t***************************************************\n";
	cout << "\t*************1.设置为背景颜色**********************\n";
	cout << "\t*************2.设置为字体颜色**********************\n";
	cout << "\t*************3.其他键取消**************************\n";
	cout << "\t***************************************************\n";
}

//*******************密码管理系统类************************************************************************************************************************************************************************/
//开始录入用户名和密码
void Inituser(user *&U) {
	U = new user;//分配空间
}
//建表
void Readuser(user *&U) {
	FILE* f1, *f2;
	if ((f1 = fopen("缓存\\username.oyhx", "r") ) == NULL) {//读取文件
		printf("\n【系统提示】发生错误，错误码为00001\n");//提示失败
		fprintf(logfile, "%d年%d月%d日%d:%d:%d【错误】发生错误，错误码为00001\n", now->tm_year + 1900, now->tm_mon + 1, now->tm_mday, now->tm_hour, now->tm_min, now->tm_sec); //提示失败
		exit(0);
	}
	if ((f2 = fopen("缓存\\password.oyhx", "r") ) == NULL) {//读取文件
		printf("\n【系统提示】发生错误，错误码为00001\n");//提示失败
		fprintf(logfile, "%d年%d月%d日%d:%d:%d【错误】发生错误，错误码为00002\n", now->tm_year + 1900, now->tm_mon + 1, now->tm_mday, now->tm_hour, now->tm_min, now->tm_sec); //提示失败
		exit(0);
	}
	int i = 0;//记录这次考试的学生人数
	while (!feof(f1)) {//判断是否读完，注意文件不要有多余的空行
		fscanf(f1, "%s", U->username[i]); //扫描，逐个录入
		i++;
	}
	int p = 0;
	while (!feof(f2)) {//判断是否读完，注意文件不要有多余的空行
		fscanf(f2, "%s", U->password[p]); //扫描，逐个录入
		p++;
	}
	U->num = --i;
	fclose(f1);//记得关闭文件
	fclose(f2);//记得关闭文件
}

int reg(user *&U) {
	system("cls");
	system("title 欢迎来到快速注册页面");
	settype();
	cout << "\t***************************************************\n";
	cout << "\t*             欢迎来到快速注册页面                *\n";
	cout << "\t***************************************************\n";
	char username[MAX];
	char password[MAX], password1[MAX];
	cout << "\t*请输入用户名：";
	cin >> username;
	int k = 0;
	while (k != U->num) {
		if (!strcmp(username, U->username[k])) {
			cout << "\t*用户名重复，换一个名字吧！！！" << endl;
			return 0;
		}
		k++;
	}
	cout << "\t*请输入密码：";
	// 逐字符读取密码并显示星号
	int i = 0;
	while (true) {
		password[i] = getch(); // 使用getch()读取键盘输入，不回显到终端
		if (password[i] == '\r') { // 回车键表示输入结束
			password[i] = '\0'; // 在密码末尾添加字符串结束符
			break;
		}
		cout << "*"; // 显示星号
		i++;
	}
	cout << endl << "\t*请确认密码：";
	i = 0;
	while (true) {
		password1[i] = getch(); // 使用getch()读取键盘输入，不回显到终端
		if (password1[i] == '\r') { // 回车键表示输入结束
			password1[i] = '\0'; // 在密码末尾添加字符串结束符
			break;
		}
		cout << "*"; // 显示星号
		i++;
	}
	if (!strcmp(password, password1)) {
		// 将用户名和密码保存到文件中
		FILE* file = fopen("缓存\\username.oyhx", "a");
		FILE* file1 = fopen("缓存\\password.oyhx", "a");
		if (file != NULL) {
			fprintf(file, "%s ", username);
			fprintf(file1, "%s ", password);
			fclose(file);
			fclose(file1);
			cout << endl << "\t*【系统提示】恭喜您注册成功！！！请重新登录！！" << endl;
			return 1;
		} else {
			cout << endl << "\t*【系统提示】注册失败，请稍后重试。" << endl;
			return 0;
		}
	} else {
		cout << endl << "\t*【系统警告】两次密码不相同哦~请重新注册噢！！！" << endl;
		return 0;
	}
}

int login1(user *&U, int &o) {
	system("cls");
	system("title 欢迎来到登录页面");
	settype();
	cout << "\t***************************************************\n";
	cout << "\t*                欢迎来到登录页面                 *\n";
	cout << "\t***************************************************\n";
	Readuser(U);
	char username[MAX];
	char password[MAX];
	cout << "\t*请输入用户名：";
	cin >> username;
	int k = 0, flag = 0;
	while (k != U->num) {
		if (!strcmp(username, U->username[k])) {
			flag = 1;
			o = k;
			break;
		}
		k++;
	}
	if (!flag) {
		cout << "\t*【系统警告】用户名错误，若需使用此用户名请先注册！！！" << endl;
		return 0;
	}
	cout << "\t*请输入密码：";
	int i = 0;
	while (true) {
		password[i] = getch(); // 使用getch()读取键盘输入，不回显到终端
		if (password[i] == '\r') { // 回车键表示输入结束
			password[i] = '\0';
			break;
		}
		cout << "*"; // 显示星号
		i++;
	}
	if(!strcmp(password,U->password[o])){
		cout << endl << "\t*恭喜您，登录成功！！！" << endl;
		return 1;
	}
	else{
		cout << endl << "\t*密码错误...请重新登录！！！" << endl;
		return 0;
	}
}
//*******************以下为一开始就会运行的函数（每个函数都可以用）************************************************************************************************************************************************************************/
//表的初始化
void Initlist(Slist *&L) {
	L = new Slist;//分配空间
}
//建表
void CreatList(Slist *&L, char *na) {
	FILE* f1;
	if ((f1 = fopen(na, "r") ) == NULL) {//读取文件
		printf("文件打开失败，请确定是否存放了成绩文件！！！");//提示失败
		exit(0);
	}
	int i = 0;//记录这次考试的学生人数
	while (!feof(f1)) {//判断是否读完，注意文件不要有多余的空行
		fscanf(f1, "%s%s", L->data[i].no, L->data[i].name);//扫描，逐个录入
		int k = L->data[i].no[10] - '0';//学号第11为班级识别码
		L->data[i].classno = k; //分班
		for (int j = 0; j <= 5; j++) {
			fscanf(f1, "%d", &L->data[i].cour[j]);
			L->data[i].sum += L->data[i].cour[j];//计算总分
		}
		i++;
	}
	L->length = i;
	fclose(f1);//记得关闭文件
	cout << "\t****导入成功！！！" << endl << endl; //提示成功
}
//*******************以下为第一个功能的相关函数************************************************************************************************************************************************************************/
//总分的排序函数
void Sortlist(Slist *&L) {
	for (int i = 0; i < L->length - 1; i++) {//选择排序法
		int k = i;//记下这里的位置
		for (int j = i + 1; j < L->length; j++)//该位向后比较
			if (L->data[j].sum > L->data[k].sum)
				k = j;//比我大，就跟我换
		stu temp = L->data[i];//如果没有比我大的，相当于跟自己换了
		L->data[i] = L->data[k];
		L->data[k] = temp;
	}
}

//校排序
void SRank(Slist *&L) {
	L->data[0].school_rank = 1;//第一名为1
	for (int i = 1; i < L->length; i++) {//遍历加
		if (L->data[i].sum == L->data[i - 1].sum)//当前的成绩和前面的相同，那就把排名弄相同
			L->data[i].school_rank = L->data[i - 1].school_rank;
		else//否则正常去加
			L->data[i].school_rank = i + 1;
	}
}
//班级排名
void CRank(Slist *&L) {
	int count[10] = {0}; //四个班的人数
	int rank[10] = {0}; //四个班当前的排名
	int temp[10] = {0}; //记录班级上一个人的总分
	for (int i = 0; i < L->length; i++) {//遍历
		int j = L->data[i].no[10] - '0'; //学号第11为班级识别码
		count[j]++;//班级人数加一
		L->data[i].classno = j;
		if (L->data[i].sum == temp[j])//如果总分又和前面的相同了，那就把当前的排名赋给他
			L->data[i].class_rank = rank[j];
		else {//因为这时候肯定从大到小了，所以人数即为排名
			L->data[i].class_rank = count[j];//人数即为排名
			//可以理解为更新操作
			temp[j] = L->data[i].sum;//记下这时候的总分
			rank[j] = L->data[i].class_rank;//当前的排名
		}
	}
}
//展示函数
void DisplayList(Slist *&L, char a) {
	Sortlist(L);//排序
	SRank(L);//校排
	CRank(L);//班排
	//下面就是一些花里胡哨的排版
	if (a == '1') {
		printf("%8s%16s%21s\t\t数据结构\t线性代数\t大学物理\t大学英语\t大学体育\t总分\t  校排名\t  班排名\n", "学号", "姓名", "高数");
		for (int i = 0; i < L->length; i++) {
			printf("%-20s%-22s", L->data[i].no, L->data[i].name);//学号和姓名
			for (int j = 0; j <= 5; j++) {
				printf("%3d\t\t", L->data[i].cour[j]);//各科成绩
			}
			printf("%3d\t  %3d\t\t软件%d班第%3d\n", L->data[i].sum, L->data[i].school_rank, L->data[i].classno + 1, L->data[i].class_rank);//排名
		}
	} else if (a == '2') {
		FILE *f2;
		if ((f2 = fopen("所有成绩的记录.txt", "w+") ) == NULL) {//读取文件
			printf("文件打开失败，请确定是否存放了成绩文件！！！");//提示失败
			exit(0);
		}
		fprintf(f2, "*****************************************************第%c次考试的所有记录*****************************************************************************************************\n\n", a);
		fprintf(f2, "%8s%16s%21s\t\t数据结构\t线性代数\t大学物理\t大学英语\t大学体育\t总分\t  校排名\t  班排名\n", "学号", "姓名", "高数");
		for (int i = 0; i < L->length; i++) {
			fprintf(f2, "%-20s%-22s", L->data[i].no, L->data[i].name); //学号和姓名
			for (int j = 0; j <= 5; j++) {
				fprintf(f2, "%3d\t\t", L->data[i].cour[j]); //各科成绩
			}
			fprintf(f2, "%3d\t  %3d\t\t软件%d班第%3d\n", L->data[i].sum, L->data[i].school_rank, L->data[i].classno + 1, L->data[i].class_rank); //排名
		}
	}
}
//*******************以下为第二个功能的相关函数************************************************************************************************************************************************************************/
//统计汇总校，班的各科平均分，最高分，最低分，不及格人数，第二次考试缺考名单等所有数据
//思路很简单就是求校，班的各科平均分，求最高分，最低分，其实可以一起求，这里专门给他们设立结构体
void Calculate(Slist *&L, sja &kemu) {
	//求校和班的各科平均分（可以注意到这个数据是个整型）
	int average[N] = {0}; //防止数组爆炸，大点好
	int class_average[N][N] = {0}; //4班6课，班级平均分
	int smin = 100, smax = 0; //校级最低分和最高分
	int cmin[N], cmax[N]; //班级最低分和最高分,[]代表班级
	int class_count[N] = {0}; //所在班级人数
	for (int i = 0; i < 6; i++) { //遍历了6个科目
		smin = 100;
		smax = 0;
		memset(cmin, 100, sizeof(cmin)); //初始化为100最大值
		memset(cmax, 0, sizeof(cmax));
		for (int j = 0; j < L->length; j++) { //遍历每个学生
			if (L->data[j].cour[i] < 60) { //不及格人数
				kemu.sub[i].bujige_count++;
				kemu.sub[i].banjibujige[L->data[j].classno]++;
			}
			average[i] += L->data[j].cour[i]; //求该科目全校总分
			class_average[L->data[j].classno][i] += L->data[j].cour[i]; //求该科目班级总分
			if (!i)
				class_count[L->data[j].classno]++;//在第一次的时候计算出各班级人数

			smin = min(smin, L->data[j].cour[i]); //求校最低分
			smax = max(smax, L->data[j].cour[i]); //求校最高分
			cmin[L->data[j].classno] = min(cmin[L->data[j].classno], L->data[j].cour[i]); //求班最低分
			cmax[L->data[j].classno] = max(cmax[L->data[j].classno], L->data[j].cour[i]); //求班最高分
		}
		kemu.sub[i].smax = smax; //校最高分
		kemu.sub[i].smin = smin; //校最低分
		for (int k = 0; k <= 3; k++) { //班级最低最高分
			kemu.sub[i].cmin[k] = cmin[k];
			kemu.sub[i].cmax[k] = cmax[k];
		}
		average[i] /= L->length;//算出该课校平均分
		kemu.sub[i].average = average[i];//
		for (int k = 0; k <= 5; k++) { //科目
			for (int p = 0; p <= 3; p++) { //班级
				kemu.sub[k].classaverage[p] = class_average[p][k] / class_count[p];
			}
		}
	}
}
void DisplayList2(Slist *&L, sja &kemu, int l) { //&没必要加
	if (l != 1) {
		for (int i = 0; i <= 5; i++) { //循环遍历
			switch (i) { //不同次不同结果
				case 0:
					printf("高等数学：校平均分：%3d  校最高分：%3d 校最低分：%3d  该科目校不及格的人数：%2d\n", kemu.sub[i].average, kemu.sub[i].smax, kemu.sub[i].smin, kemu.sub[i].bujige_count);
					break;
				case 1:
					printf("数据结构：校平均分：%3d  校最高分：%3d 校最低分：%3d  该科目校不及格的人数：%2d\n", kemu.sub[i].average, kemu.sub[i].smax, kemu.sub[i].smin, kemu.sub[i].bujige_count);
					break;
				case 2:
					printf("线性代数：校平均分：%3d  校最高分：%3d 校最低分：%3d  该科目校不及格的人数：%2d\n", kemu.sub[i].average, kemu.sub[i].smax, kemu.sub[i].smin, kemu.sub[i].bujige_count);
					break;
				case 3:
					printf("大学物理：校平均分：%3d  校最高分：%3d 校最低分：%3d  该科目校不及格的人数：%2d\n", kemu.sub[i].average, kemu.sub[i].smax, kemu.sub[i].smin, kemu.sub[i].bujige_count);
					break;
				case 4:
					printf("大学英语：校平均分：%3d  校最高分：%3d 校最低分：%3d  该科目校不及格的人数：%2d\n", kemu.sub[i].average, kemu.sub[i].smax, kemu.sub[i].smin, kemu.sub[i].bujige_count);
					break;
				case 5:
					printf("大学体育：校平均分：%3d  校最高分：%3d 校最低分：%3d  该科目校不及格的人数：%2d\n", kemu.sub[i].average, kemu.sub[i].smax, kemu.sub[i].smin, kemu.sub[i].bujige_count);
					break;
			}
		}
		cout << endl;
		for (int i = 1; i < 5; i++) { //对4个班遍历
			printf("软件%d班这次考试各科的成绩汇总：\n", i);
			for (int j = 0; j < 6; j++) { //不同次不同结果//kemu
				switch (j) {
					case 0:
						printf("高等数学：平均分：%3d  最高分：%3d 最低分：%3d  该科目不及格的人数：%2d\n", kemu.sub[j].classaverage[i - 1], kemu.sub[j].cmax[i - 1], kemu.sub[j].cmin[i - 1], kemu.sub[j].banjibujige[i - 1]);
						break;
					case 1:
						printf("数据结构：平均分：%3d  最高分：%3d 最低分：%3d  该科目不及格的人数：%2d\n", kemu.sub[j].classaverage[i - 1], kemu.sub[j].cmax[i - 1], kemu.sub[j].cmin[i - 1], kemu.sub[j].banjibujige[i - 1]);
						break;
					case 2:
						printf("线性代数：平均分：%3d  最高分：%3d 最低分：%3d  该科目不及格的人数：%2d\n", kemu.sub[j].classaverage[i - 1], kemu.sub[j].cmax[i - 1], kemu.sub[j].cmin[i - 1], kemu.sub[j].banjibujige[i - 1]);
						break;
					case 3:
						printf("大学物理：平均分：%3d  最高分：%3d 最低分：%3d  该科目不及格的人数：%2d\n", kemu.sub[j].classaverage[i - 1], kemu.sub[j].cmax[i - 1], kemu.sub[j].cmin[i - 1], kemu.sub[j].banjibujige[i - 1]);
						break;
					case 4:
						printf("大学英语：平均分：%3d  最高分：%3d 最低分：%3d  该科目不及格的人数：%2d\n", kemu.sub[j].classaverage[i - 1], kemu.sub[j].cmax[i - 1], kemu.sub[j].cmin[i - 1], kemu.sub[j].banjibujige[i - 1]);
						break;
					case 5:
						printf("大学体育：平均分：%3d  最高分：%3d 最低分：%3d  该科目不及格的人数：%2d\n", kemu.sub[j].classaverage[i - 1], kemu.sub[j].cmax[i - 1], kemu.sub[j].cmin[i - 1], kemu.sub[j].banjibujige[i - 1]);
						break;
				}
			}
			cout << endl;
		}
	} else { //这里是文件导出部分，挺鸡肋的我知道，跟上面完全重复
		for (int i = 0; i <= 5; i++) { //循环遍历
			switch (i) { //不同次不同结果
				case 0:
					fprintf(f0, "高等数学：校平均分：%3d  校最高分：%3d 校最低分：%3d  该科目校不及格的人数：%2d\n", kemu.sub[i].average, kemu.sub[i].smax, kemu.sub[i].smin, kemu.sub[i].bujige_count);
					break;
				case 1:
					fprintf(f0, "数据结构：校平均分：%3d  校最高分：%3d 校最低分：%3d  该科目校不及格的人数：%2d\n", kemu.sub[i].average, kemu.sub[i].smax, kemu.sub[i].smin, kemu.sub[i].bujige_count);
					break;
				case 2:
					fprintf(f0, "线性代数：校平均分：%3d  校最高分：%3d 校最低分：%3d  该科目校不及格的人数：%2d\n", kemu.sub[i].average, kemu.sub[i].smax, kemu.sub[i].smin, kemu.sub[i].bujige_count);
					break;
				case 3:
					fprintf(f0, "大学物理：校平均分：%3d  校最高分：%3d 校最低分：%3d  该科目校不及格的人数：%2d\n", kemu.sub[i].average, kemu.sub[i].smax, kemu.sub[i].smin, kemu.sub[i].bujige_count);
					break;
				case 4:
					fprintf(f0, "大学英语：校平均分：%3d  校最高分：%3d 校最低分：%3d  该科目校不及格的人数：%2d\n", kemu.sub[i].average, kemu.sub[i].smax, kemu.sub[i].smin, kemu.sub[i].bujige_count);
					break;
				case 5:
					fprintf(f0, "大学体育：校平均分：%3d  校最高分：%3d 校最低分：%3d  该科目校不及格的人数：%2d\n", kemu.sub[i].average, kemu.sub[i].smax, kemu.sub[i].smin, kemu.sub[i].bujige_count);
					break;
			}
		}
		fprintf(f0, "\n");
		for (int i = 1; i < 5; i++) { //对4个班遍历
			fprintf(f0, "软件%d班这次考试各科的成绩汇总：\n", i);
			for (int j = 0; j < 6; j++) { //不同次不同结果//kemu
				switch (j) {
					case 0:
						fprintf(f0, "高等数学：平均分：%3d  最高分：%3d 最低分：%3d  该科目不及格的人数：%2d\n", kemu.sub[j].classaverage[i - 1], kemu.sub[j].cmax[i - 1], kemu.sub[j].cmin[i - 1], kemu.sub[j].banjibujige[i - 1]);
						break;
					case 1:
						fprintf(f0, "数据结构：平均分：%3d  最高分：%3d 最低分：%3d  该科目不及格的人数：%2d\n", kemu.sub[j].classaverage[i - 1], kemu.sub[j].cmax[i - 1], kemu.sub[j].cmin[i - 1], kemu.sub[j].banjibujige[i - 1]);
						break;
					case 2:
						fprintf(f0, "线性代数：平均分：%3d  最高分：%3d 最低分：%3d  该科目不及格的人数：%2d\n", kemu.sub[j].classaverage[i - 1], kemu.sub[j].cmax[i - 1], kemu.sub[j].cmin[i - 1], kemu.sub[j].banjibujige[i - 1]);
						break;
					case 3:
						fprintf(f0, "大学物理：平均分：%3d  最高分：%3d 最低分：%3d  该科目不及格的人数：%2d\n", kemu.sub[j].classaverage[i - 1], kemu.sub[j].cmax[i - 1], kemu.sub[j].cmin[i - 1], kemu.sub[j].banjibujige[i - 1]);
						break;
					case 4:
						fprintf(f0, "大学英语：平均分：%3d  最高分：%3d 最低分：%3d  该科目不及格的人数：%2d\n", kemu.sub[j].classaverage[i - 1], kemu.sub[j].cmax[i - 1], kemu.sub[j].cmin[i - 1], kemu.sub[j].banjibujige[i - 1]);
						break;
					case 5:
						fprintf(f0, "大学体育：平均分：%3d  最高分：%3d 最低分：%3d  该科目不及格的人数：%2d\n", kemu.sub[j].classaverage[i - 1], kemu.sub[j].cmax[i - 1], kemu.sub[j].cmin[i - 1], kemu.sub[j].banjibujige[i - 1]);
						break;
				}
			}
			fprintf(f0, "\n");
		}
	}
}
struct ptrcmp { //运用于map映射的重载运算符，作用为将char*指针指向的字符串地址之间的比较，转换为地址上存储的字符串数据之间的比对
	bool operator()(const char* s1, const char* s2)const {
		return strcmp(s1, s2) < 0;
	}
};//固定模板
void Findabsent(Slist *&L1, Slist *&L2, char *absent[], int &p) { //*absent[]注意了，二维数组
	//这里我们需要把第二个文件的人和第一个文件相比较，相同的不缺考，不相同的缺考
	//那么其实也就是说我们要比较每个人的名字或者学号，我们知道比较字符串比较难，这里我们可以使用map映射
	//把问题转化成比较映射后的数字
	int l = 0;
	map<char*, int, ptrcmp>is_absent; //创建名字和数字的映射，这里使用方法是is_absent[字符串]=对应整型
	for (int i = 0; i <= L2->length; i++) {
		is_absent[L2->data[i].name] = 1;
	}
	for (int j = 0; j <= L1->length; j++) {
		if (is_absent[L1->data[j].name] != 1) {
			absent[l++] = L1->data[j].name;
		}
	}
	p = l; //从0开始，我们说有l人
}
//*******************以下为第三个功能的相关函数************************************************************************************************************************************************************************/
void Search3(Slist *&L1, Slist *&L2) {
	char a = '1';
	while (a == '1') {
		system("cls");
		cout << "请您输入需要查询的考生的学号或者名字（支持学号和名字的模糊查询）:\n";
		char b[150];//存放输入的姓名或者学号
		cin >> b;
		cout << endl;
		bool  flag = false; //是否找到标志
		map<char*, int, ptrcmp>Nametoadd; //通过名字找位置
		for (int l = 0; l < L2->length; l++) //进行映射
			Nametoadd[L2->data[l].name] = l;//通过名字找位置
		//排除缺考的人
		char *absent[100];
		int p;
		Findabsent(L1, L2, absent, p);
		//建立bool映射，请将这个映射技能锻炼到炉火纯青
		map<char*, bool, ptrcmp>panduan_absent;
		for (int i = 0; i < p; i++) {
			panduan_absent[absent[i]] = true;
		}
		//这里我们看到需要我们去模糊搜索，不难找到C语言中的strstr函数
		//strstr(char* s1,char* s2),判断字符串s2是否是s1的子集，如果不是则返回值为空，否则返回在s1中第一次出现s2字符串的位置(其实地址看成字符串即可)
		for (int i = 0; i < L1->length; i++) {
			//两个承接地址，因为可能搜学号也可能搜名字，只要一个匹配到即可，就是说只要有一个不为空即可
			char* add1, * add2;
			//因为第一次考试是最全的，所以查询第一次的名单
			add1 = strstr(L1->data[i].no, b);
			add2 = strstr(L1->data[i].name, b);
			if (add1 == NULL && add2 == NULL)//就是说只要有一个不为空即可直接输出，否则都为空继续
				continue;
			else { //找到输出，继续查找符合条件的考生
				printf("%s  %s  \n第一次考试的成绩条： 高等数学：%3d  数据结构：%3d  线性代数：%3d  大学物理：%3d  大学英语：%3d  大学体育：%3d\n", L1->data[i].no, L1->data[i].name, L1->data[i].cour[0], L1->data[i].cour[1], L1->data[i].cour[2], L1->data[i].cour[3], L1->data[i].cour[4], L1->data[i].cour[5]);
				//这时候我们就苦恼了，第二次的成绩显然也得和名字匹配，那我都知道第一次的成绩的位置了，可恶，为什么还要一次呢？
				//这时候想想我们上面学到的映射，如果我们把名字映射成数字，这里我们要特别观察到第一次的名字和第二次的名字绝对是相同的，用第二次的名字映射第二次的位置，然后就可以直接通过名字找位置了
				if (panduan_absent[L1->data[i].name] != true)
					printf("第二次考试的成绩条： 高等数学：%3d  数据结构：%3d  线性代数：%3d  大学物理：%3d  大学英语：%3d  大学体育：%3d\n\n", L2->data[Nametoadd[L1->data[i].name]].cour[0], L2->data[Nametoadd[L1->data[i].name]].cour[1], L2->data[Nametoadd[L1->data[i].name]].cour[2], L2->data[Nametoadd[L1->data[i].name]].cour[3], L2->data[Nametoadd[L1->data[i].name]].cour[4], L2->data[Nametoadd[L1->data[i].name]].cour[5]);
				else//OK,我们发现这个缺考的也是会输出，所以我们还得排除一下缺考的人
					printf("该考生第二次考试缺考，无成绩！！！\n");
				flag = true;//找到了的标志
			}
		}
		if (!flag)//flag没有变说明根本没有一次找到的
			cout << "抱歉，查找失败，没有找到该考生\n";
		system("pause");
		system("cls");
		cout << "\n\t                                                 \n";
		cout << "\n\t                                                 \n";
		cout << "\t*            成绩查询（支持模糊查询)              *\n";
		cout << "\t***************************************************\n";
		cout << "\t*               1.继续查询！！！                  *\n";
		cout << "\t*               2.返回菜单。                      *\n";
		cout << "\t***************************************************\n";
		cout << "\n\t*【请输入要使用的功能：】";
		cin >> a;
		cout << endl;
		cout << "\t*就决定是你了！----功能" << a << endl << endl;
		Sleep(500);
		cout << "\t*让我们出发！！！" << endl;
		Sleep(500);
	}
}
//*******************以下为第四个功能的相关函数************************************************************************************************************************************************************************/
void Changedata(Slist *&L1, Slist *&L2) {
	//修改成绩又分成修改第一场或者修改第二场
	//修改哪一科？
	int a = 1;
	while (a == 1) {
		while (1) { //一级目录
			system("cls");
			cout << "\n\t                                                 \n";
			cout << "\n\t                                                 \n";
			cout << "\t*                修改学生成绩                     *\n";
			cout << "\t***************************************************\n";
			cout << "\t*              1.修改第一场考试成绩               *\n";
			cout << "\t*              2.修改第二次考试成绩               *\n";
			cout << "\t*              3.其他键返回上一级                 *\n";
			cout << "\t***************************************************\n";
			cout << "\n\t*【请输入要使用的功能：】";
			char p;
			cin >> p;
			cout << endl;
			cout << "\t*就决定是你了！----第" << p << "场考试！！！" << endl << endl;
			Sleep(500);
			cout << "\t*让我们出发！！！" << endl;
			Sleep(500);
			system("cls");
			if (p != '1' && p != '2')
				break;//返回上一级
			Slist *na;
			Initlist(na);//初始化，可别野指针了
			if (p == '1') {
				na = L1;
			}
			if (p == '2') {
				na = L2;
			}
			char b[150];
			cout << "不知您要修改哪位大神的成绩呀？(最好输入这位大神的准确姓名或者学号)" << endl;
			cout << "我要修改：";
			cin >> b;
			//这里就已经确立哪一场考试，现在我们开始写修改部分，直接让使用者键入一个数以替代原分数即可，那么第一修改谁的，修改哪一科
			//修改谁的，输入这个名字，我们得知道在哪里，这里就又用到第三个问题
			for (int i = 0; i < na->length; i++) {
				char* add1, * add2;
				add1 = strstr(na->data[i].no, b);
				add2 = strstr(na->data[i].name, b);
				if (add1 == NULL && add2 == NULL)//没找到这个人就继续
					continue;
				else { //找到了
					printf("好耶！我找到了 ！！!\n");
					printf("%s  软件%d班  %s  \n第%d次考试的成绩条： 高等数学：%3d  数据结构：%3d  线性代数：%3d  大学物理：%3d  大学英语：%3d  大学体育：%3d  总分为%3d\n", na->data[i].no, na->data[i].classno + 1, na->data[i].name, p, na->data[i].cour[0], na->data[i].cour[1], na->data[i].cour[2], na->data[i].cour[3], na->data[i].cour[4], na->data[i].cour[5], na->data[i].sum);
					system("pause");
					while (1) {
						//二级目录
						system("cls");
						printf("%s  软件%d班  %s  \n第%d次考试的成绩条： 高等数学：%3d  数据结构：%3d  线性代数：%3d  大学物理：%3d  大学英语：%3d  大学体育：%3d  总分为%3d\n", na->data[i].no, na->data[i].classno + 1, na->data[i].name, p, na->data[i].cour[0], na->data[i].cour[1], na->data[i].cour[2], na->data[i].cour[3], na->data[i].cour[4], na->data[i].cour[5], na->data[i].sum);
						cout << "\n\t                                                 \n";
						cout << "\n\t                                                 \n";
						cout << "\t*                修改学生成绩                     *\n";
						cout << "\t***************************************************\n";
						cout << "\t*              1.修改高等数学                     *\n";
						cout << "\t*              2.修改数据结构                     *\n";
						cout << "\t*              3.修改线性代数                     *\n";
						cout << "\t*              4.修改大学物理                     *\n";
						cout << "\t*              5.修改大学英语                     *\n";
						cout << "\t*              6.修改大学体育                     *\n";
						cout << "\t*              7.返回上一级吧                     *\n";
						cout << "\t***************************************************\n";
						cout << "\n\t*【请输入您需要修改的学科：】";
						int o;//判断修改哪一科
						cin >> o;
						cout << endl;
						switch (o) {
							case 1:
								cout << "\n\t*1.修改高等数学" << endl;
								break;
							case 2:
								cout << "\n\t*2.修改数据结构" << endl;
								break;
							case 3:
								cout << "\n\t*3.修改线性代数" << endl;
								break;
							case 4:
								cout << "\n\t*4.修改大学物理" << endl;
								break;
							case 5:
								cout << "\n\t*5.修改大学英语" << endl;
								break;
							case 6:
								cout << "\n\t*6.修改大学体育" << endl;
								break;
							case 7:
								cout << "\n\t*7.返回上一级吧" << endl;
								break;
							default:
								cout << "\n\t*你别乱按啊！哼，我帮你选7，略略略" << endl;
								break;
						}
						Sleep(600);
						if (o > 6 || o < 1)
							break;//返回上一级
						int  score;
						cout << "\n\t*您要将分数修改为：";//修改为什么分数
						cin >> score;
						if (score > 100 || score < 0) {
							cout << "\n\t*！！！警告分数区间在0-100之间，请重新输入！！！(为此将惩罚您前往上一级)\n";
							system("pause");
							continue;
						}
						na->data[i].sum -= na->data[i].cour[o - 1];
						na->data[i].cour[o - 1] = score;//对相应的考试科目成绩进行修改
						na->data[i].sum += na->data[i].cour[o - 1]; //更新总分
						cout << "\n\t*好的，帮您修改成功！现在TA的分数条如下：\n\n";
						printf("\t*%s  软件%d班  %s  \n\t*第%d次考试的成绩条： 高等数学：%3d  数据结构：%3d  线性代数：%3d  大学物理：%3d  大学英语：%3d  大学体育：%3d  总分为%3d\n", na->data[i].no, na->data[i].classno + 1, na->data[i].name, p, na->data[i].cour[0], na->data[i].cour[1], na->data[i].cour[2], na->data[i].cour[3], na->data[i].cour[4], na->data[i].cour[5], na->data[i].sum);
						printf("\t*");
						system("pause");
						system("cls");
						cout << "\n\t                                                 \n";
						cout << "\n\t                                                 \n";
						cout << "\t*                修改学生成绩                     *\n";
						cout << "\t***************************************************\n";
						cout << "\t*             1.继续修改，我不走！！！            *\n";
						cout << "\t*              2.其他键返回菜单                   *\n";
						cout << "\t***************************************************\n";
						cout << "\n\t*【请输入要使用的功能：】";
						int y;
						cin >> y;
						cout << endl;
						cout << "\t*就决定是你了！----功能" << y << endl << endl;
						Sleep(500);
						cout << "\t*让我们出发！！！" << endl;
						Sleep(500);
						if (y != 1)
							break;
					}
					break;
				}
			}
		}
		system("cls");
		cout << "\n\t                                                 \n";
		cout << "\n\t                                                 \n";
		cout << "\t*                修改学生成绩                     *\n";
		cout << "\t***************************************************\n";
		cout << "\t*             1.继续修改，我不走！！！            *\n";
		cout << "\t*                 2.返回菜单                      *\n";
		cout << "\t***************************************************\n";
		cout << "\n\t*【请输入要使用的功能：】";
		cin >> a;
		cout << endl;
		cout << "\t*就决定是你了！----功能" << a << endl << endl;
		Sleep(500);
		cout << "\t*让我们出发！！！" << endl;
		Sleep(500);
	}
}
//*******************以下为第五个功能的相关函数************************************************************************************************************************************************************************/
//5.成绩补录。（能找出第二次缺考考生的全部名单，进行成绩补录，考试成绩自定）
//终于到了功能5了，首先第二次考试的缺考名单，然后进行成绩补录，其实就创建一个新的结构体然后插入到链表里
//老弟，这不就是功能2和功能4的结合嘛，走你
void Gradebu(Slist *&L1, Slist *&L2, int o) {
	int p = o;
	while (p) {
		cout << "请输入您要补录考生学号:";
		cin >> L2->data[L2->length].no;
		cout << "请输入补考考生的名字：";
		cin >> L2->data[L2->length].name;
		cout << "请输入考生的高等数学的成绩：";
		cin >> L2->data[L2->length].cour[0];
		cout << "请输入补考考生的数据结构的成绩：";
		cin >> L2->data[L2->length].cour[1];
		cout << "请输入考生的线性代数的成绩：";
		cin >> L2->data[L2->length].cour[2];
		cout << "请输入考生的大学英语的成绩：";
		cin >> L2->data[L2->length].cour[3];
		cout << "请输入考生的大学物理的成绩：";
		cin >> L2->data[L2->length].cour[4];
		cout << "请输入考生的大学体育的成绩：";
		cin >> L2->data[L2->length].cour[5];
		L2->data[L2->length].sum = L2->data[L2->length].cour[0] + L2->data[L2->length].cour[1] + L2->data[L2->length].cour[2] + L2->data[L2->length].cour[3] + L2->data[L2->length].cour[4] + L2->data[L2->length].cour[5];
		L2->length++;
		p--;
		cout << "继续？！(按0退出！)";
		int h;
		cin >> h;
		if (!h) {
			break;
		}
	}//优化方向，每次打印实时的缺考名单
	if (!p) {
		cout << "检测到人数与第一次相同，补录工作成功，已更新所有的成绩表！！！" << endl;
	} else {
		cout << "好的，为您补录成功，已更新所有的成绩表！！！" << endl;
	}
}
//*******************以下为第六个功能的相关函数************************************************************************************************************************************************************************/
//功能6删除数据。（按学号，或按姓名删除指定记录）
void Deletegrade(Slist *&L1, Slist *&L2) {
	//这里的思路就是要删谁，删哪次考试，有完没完（就是还要不要删）
	while (1) {
		system("cls");
		cout << "\t温馨提示：如果您仅仅输入欧阳，将删除所有名字带欧阳的考生\n\n";
		cout << "\t请输入您要进行这个操作的考生姓名或者学号:";
		char o[100];//读者对这个命名规律肯定会了吧，oyhx，记住了哦
		cin >> o;
		cout << "\n\t                                                 \n";
		cout << "\n\t                                                 \n";
		cout << "\t*                 删除学生成绩                    *\n";
		cout << "\t***************************************************\n";
		cout << "\t*              1.删除第一场考试成绩               *\n";
		cout << "\t*              2.删除第二次考试成绩               *\n";
		cout << "\t*              3.直接退出这个功能                 *\n";
		cout << "\t***************************************************\n";
		cout << "\n\t*【请输入要使用的功能：】";
		char y;
		cin >> y;
		cout << endl << endl;
		Slist *h;
		if (y == '1')
			h = L1;
		else if (y == '2')
			h = L2;
		else
			break;
		bool is_find = false;
		for (int i = 0; i < h->length; i++) {
			char* add1, * add2;
			add1 = strstr(h->data[i].no, o);
			add2 = strstr(h->data[i].name, o);
			if (add1 == NULL && add2 == NULL)
				continue;
			else {
				//将该结构体的所有数据全部清零
				printf("\t*%s  %s  \n", h->data[i].no, h->data[i].name);
				memset(h->data[i].no, 0, sizeof(h->data[i].no));
				memset(h->data[i].name, 0, sizeof(h->data[i].name));
				memset(h->data[i].cour, 0, sizeof(h->data[i].cour));
				h->data[i].sum = h->data[i].class_rank = h->data[i].classno = h->data[i].school_rank = 0;
				h->length--;//这场考试参考人数减少一位
				for (int j = i; j <= h->length; j++) //将后面的考生放到前面来，相当于补空
					h->data[j] = h->data[j + 1];
				cout << "\t*删除成功！！！" << endl << endl;
				is_find = true;
			}
		}
		if (!is_find) {
			cout << "\t*抱歉，没有找到该考生\n";
			cout << "\t*正在返回......\n";
			Sleep(1500);
			continue;
		}
		cout << "\t*正在返回......\n";
		Sleep(1500);
	}
}
//*******************以下为第七个功能的相关函数************************************************************************************************************************************************************************/
//校排序
void SRank2(Slist *&L) {
	L->data[L->length - 1].school_rank = 1; //第一位为最后一名
	for (int i = L->length - 2; i >= 0; i--) { //遍历减
		if (L->data[i].sum == L->data[i + 1 ].sum) //当前的成绩和前面的相同，那就把排名弄相同
			L->data[i].school_rank = L->data[i + 1].school_rank;
		else//否则正常去减
			L->data[i].school_rank = L->length - i;
	}
}
//班级排名
void CRank2(Slist *&L) {
	int count[10] = {0}; //四个班的人数
	int rank[10] = {0}; //四个班当前的排名
	int temp[10] = {0}; //记录班级上一个人的总分
	for (int i = L->length - 1; i >= 0; i--) { //遍历
		int j = L->data[i].no[10] - '0'; //学号第11为班级识别码
		count[j]++;//班级人数加一
		L->data[i].classno = j;
		if (L->data[i].sum == temp[j])//如果总分又和前面的相同了，那就把当前的排名赋给他
			L->data[i].class_rank = rank[j];
		else {//因为这时候肯定从小到大了，所以人数即为排名
			L->data[i].class_rank = count[j];//人数即为排名
			//可以理解为更新操作
			temp[j] = L->data[i].sum;//记下这时候的总分
			rank[j] = L->data[i].class_rank;//当前的排名
		}
	}
}
void Sortlist2(Slist *&L) {
	for (int i = 0; i < L->length - 1; i++) {//选择排序法
		int k = i;//记下这里的位置
		for (int j = i + 1; j < L->length; j++)//该位向后比较
			if (L->data[j].sum < L->data[k].sum)
				k = j;//比我小，就跟我换
		stu temp = L->data[i];//如果没有比我大的，相当于跟自己换了
		L->data[i] = L->data[k];
		L->data[k] = temp;
	}
}
void DisplayList3(Slist *&L) {
	Sortlist2(L);//排序
	SRank2(L);//校排
	CRank2(L);//班排
	//下面就是一些花里胡哨的排版
	printf("%8s%16s%21s\t\t数据结构\t线性代数\t大学物理\t大学英语\t大学体育\t总分\t  校排名\t  班排名\n", "学号", "姓名", "高数");
	for (int i = 0; i < L->length; i++) {
		printf("%-20s%-22s", L->data[i].no, L->data[i].name);//学号和姓名
		for (int j = 0; j <= 5; j++) {
			printf("%3d\t\t", L->data[i].cour[j]);//各科成绩
		}
		printf("%3d\t  %3d\t\t软件%d班第%3d\n", L->data[i].sum, L->data[i].school_rank, L->data[i].classno + 1, L->data[i].class_rank);//排名
	}
}
//*******************以下为第八个功能的相关函数************************************************************************************************************************************************************************/
bool cmp2(stu x, stu y) { //快排判断标准，按 考生的班级进步的名次 进行降序排列
	return x.rchange > y.rchange;
}
void Sortjiang(Slist *&L1, Slist *&L2) {
	//我们先对考试成绩进行降序排序
	Sortlist2(L1);//排序
	SRank2(L1);//校排
	CRank2(L1);//班排//对第一次考试成绩降序排列
	Sortlist2(L2);//排序
	SRank2(L2);//校排
	CRank2(L2);//班排//对第二次考试成绩降序排列
	//有排名变化的肯定是不缺考的
	map<char*, int, ptrcmp>noabsent;//考生的名字映射其在表中的下标(第二次考试)
	for (int i = 0; i < L2->length; i++)
		noabsent[L2->data[i].name] = i;//名字映射下标
	for (int i = 0; i < L2->length; i++) { //给我的分数变化和排名变化赋初值
		L2->data[i].schange = L2->data[i].sum;
		L2->data[i].rchange = L2->data[i].class_rank;
	}
	for (int i = 0; i < L1->length; i++) { //遍历考试一
		L2->data[noabsent[L1->data[i].name]].schange = -(L2->data[noabsent[L1->data[i].name]].schange - L1->data[i].sum); //为第二次考试减第一次考试成绩
		L2->data[noabsent[L1->data[i].name]].rchange -= L1->data[i].class_rank;
	}
	sort(L2->data, L2->data + L2->length, cmp2);//对考试数据，按进步名次从高到低依次排列
	for (int i = 1; i < L2->length; i++) { //对进步名次相同的人员进行处理，即有两个第一名就没有第二名
		if (L2->data[i].schange == L2->data[i - 1].schange)
			L2->data[i].rchange = L2->data[i - 1].rchange;
	}
}
////*******************以下为第十个功能的相关函数************************************************************************************************************************************************************************/
void Help() {
	system("color 0A");
	cout << "\t来自作者的温馨提示：注意看那些文字表示，你是可以操作的呢\n";
	cout << "\n\t                                                 \n";
	cout << "\t***************************************************\n";
	cout << "\t*                学生成绩管理系统                 *\n";
	cout << "\t***************************************************\n";
	cout << "\t*               1.查看成绩（所有记录）            *\n";
	cout << "\t*               2.查看统计汇总                    *\n";
	cout << "\t*               3.成绩查询（支持模糊查询）        *";
	cout << "\t  *" << endl;
	cout << "\t*               4.修改学生成绩                    *";
	cout << "\t  **   *" << endl;
	cout << "\t*               5.学生成绩补录                    *";
	cout << "\t  ***   **" << endl;
	cout << "\t*               6.删除学生成绩                    *";
	cout << "\t  ****  ***" << endl;
	cout << "\t*               7.删除数据                        *";
	cout << "\t  *   *" << endl;
	cout << "\t*               8.分班成绩导出                    *";
	cout << "\t******************" << endl;
	cout << "\t*               9.挂科名单和优秀率名单            *";
	cout << "\t  *************" << endl;
	cout << "\t*              10.文档帮助                        *";
	cout << "\t   **********" << endl;
	cout << "\t*              11.按其他键退出本程序              *\n";
	cout << "\t***************************************************\n";
	cout << "\t************抵制不良程序,拒绝盗版程序.*************\n";
	cout << "\t************适度代码益脑,沉迷程序伤身.*************\n";
	cout << "\t************合理安排时间,享受健康生活.*************\n";
}
////*******************以下为第十一个功能的相关函数************************************************************************************************************************************************************************/
void Set() {
	settype();
	cout << "\n\t                                                 \n";
	cout << "\t***************************************************\n";
	cout << "\t*             欢迎来到快速设置页面                *\n";
	cout << "\t***************************************************\n";
	cout << "\t*               1.换肤(设置页面颜色)              *\n";
	cout << "\t*               2.修改账户信息                    *\n";
	cout << "\t*               3.管理员信息认证                  *\n";
	cout << "\t*               4.vip状态查询（含充值）           *\n";
	cout << "\t*               5.有关显示设置                    *\n";
	cout << "\t*               6.有关声音设置                    *\n";
	cout << "\t*               7.超级计算器                      *\n";
	cout << "\t*               8.退出登录                        *\n";
	cout << "\t*               9.注销账户                        *\n";
	cout << "\t*               A.有关赤色领域的传说              *\n";
	cout << "\t*               B.按其他键返回                    *\n";
	cout << "\t***************************************************\n";
	cout << "\t************抵制不良程序,拒绝盗版程序.*************\n";
	cout << "\t************适度代码益脑,沉迷程序伤身.*************\n";
	cout << "\t************合理安排时间,享受健康生活.*************\n";
}
void ex() {
	int o = 4;
	while (o--) {
		if (o == 1)
			system("color 04");
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < i; j++)
				cout << "\t\t\t";
			cout << "  *" << endl;
			for (int j = 0; j < i; j++)
				cout << "\t\t\t";
			cout << "  **   *" << endl;
			for (int j = 0; j < i; j++)
				cout << "\t\t\t";
			cout << "  ***   **" << endl;
			for (int j = 0; j < i; j++)
				cout << "\t\t\t";
			cout << "  ****  ***" << endl;
			for (int j = 0; j < i; j++)
				cout << "\t\t\t";
			cout << "  *   *" << endl;
			for (int j = 0; j < i; j++)
				cout << "\t\t\t";
			cout << "******************" << endl;
			for (int j = 0; j < i; j++)
				cout << "\t\t\t";
			cout << "  *************" << endl;
			for (int j = 0; j < i; j++)
				cout << "\t\t\t";
			cout << "   **********" << endl;
			for (int j = 0; j < i; j++)
				cout << "\t\t\t";
			if (o < 2)
				Sleep(200);
			else
				Sleep(500);
			system("cls");
		}
	}
	system("color 00");
	menu1();
	Sleep(300);
	system("cls");
	system("color 01");
	system("mode con cols=100 lines=40");
	menu1();
	Sleep(200);
	system("cls");
	system("color 02");
	system("mode con cols=60 lines=30");
	menu1();
	Sleep(100);
	system("cls");
	system("color 04");
	system("mode con cols=30 lines=5");
	menu1();
	Sleep(300);
	system("cls");
	system("color 01");
	system("mode con cols=1 lines=4");
	menu1();
	Sleep(200);
	system("cls");
	system("color 02");
	system("mode con cols=50 lines=10");
	menu1();
	Sleep(100);
	system("cls");
	system("color 05");
	system("mode con cols=100 lines=100");
	menu1();
	Sleep(200);
	system("cls");
	system("color 06");
	system("mode con cols=300 lines=300");
	menu1();
	Sleep(200);
	system("cls");
	system("color 02");
	system("mode con cols=600 lines=400");
	menu1();
	Sleep(100);
	system("cls");
	system("color 04");
	system("mode con cols=3000 lines=500");
	menu1();
	Sleep(100);
	system("cls");
	menu1();
	Sleep(100);
	system("cls");
	system("color 04");
	system("mode con cols=100 lines=40");
	menu1();
	Sleep(300);
	system("cls");
	menu1();
	Sleep(300);
	system("cls");
	menu2();
}
void UN() {
	cout << endl << endl << endl;
	cout << "\t\t\t              --USER NOTICE--" << endl << endl;
	cout << "\t\t\t               --使用须知--" << endl << endl << endl;
	cout << "\t\t\t  为了方便您的使用，请您仔细阅读本使用须知。" << endl << endl << endl;
	cout << "\t 一、服务条款说明:" << endl << endl;
	cout << "\t\t本程序内各项电子服务的所有权和运作权归本作者所有。本程序提供的" << endl << "\t  服务将完全按照其发布的服务条款和操作规则严格执行。用户需在购买前认真阅" << endl << "\t  读并同意所有服务条款。本协议条款是处理双方权利义务的约定依据，除非违反" << endl << "\t  国家强制性法律，否则始终有效。在支付订单时，您须同时确认接受购买该产品" << endl << "\t  的规定、权利和义务，并对订单中所提供信息的真实性负责。" << endl;
	cout << endl << "\t\t        本程序作者：STARoy（github：oyhxgo）！！！" << endl << endl;
	cout << "\t\t        本程序作者：STARoy（github：oyhxgo）！！！" << endl << endl;
	cout << "\t\t        本程序作者：STARoy（github：oyhxgo）！！！" << endl << endl;
	cout << "\t\t由此程序所引发的所有问题，其最终解释权归程序作者所有！！！" << endl << endl;
	cout << "\t 二、必要说明:" << endl << endl;
	cout << "\t\t使用本程序时请确保电脑文件已备份，因为本程序而导致文件丢失的" << endl << "\t  后果由用户自行承担！！" << endl << endl;
	cout << "\t\t上述规则为赤色领域系列，纯净版可以放心使用，但在使用病毒版时" << endl << "\t  建议使用虚拟机，同意本条款即允许本程序在需要时对电脑进行包括但不限" << endl << "\t  于无限弹窗，自动关机和重启等权限。" << endl << endl;
	cout << "\t\t用户同意本须知即说明用户已认真阅读本程序的《用户注册须知》、" << endl << "\t  《用户使用须知》等文件并表示同意条约中的所有规定，您只有同意了才能" << endl << "\t  本产品。" << endl << endl;
	cout << "\t\t\t\t您是否同意同意本用户须知?" << endl << endl << "\t（若同意，请完整的输入“我同意”（不含引号），否则都视为您不同意）：";
}
void login() {
	settype();
	cout << "\t***************************************************\n";
	cout << "\t*                欢迎来到登录页面                 *\n";
	cout << "\t***************************************************\n";
	cout << "\t*              1.已有账号，我要登录               *\n";
	cout << "\t*              2.莫得账号，快速注册               *\n";
	cout << "\t*             3.其他任意键退出本程序               *\n";
	cout << "\t***************************************************\n";
	cout << "\t*请尽情选择您的选项：";
}


void over() {
	system("title see you next time！！！");
	system("cls");
	settype();
	cout << "\t\t            感谢您的下载！！！" << endl;
	settype();
	exit(0);
}
int main() {
	//日志文件运行
	if ((logfile = fopen("日志文件\\日志文件.STARoy", "a") ) == NULL) {//读取文件
		printf("%d年%d月%d日%d:%d:%d【错误】发生错误，错误码为00000\n", now->tm_year + 1900, now->tm_mon + 1, now->tm_mday, now->tm_hour, now->tm_min, now->tm_sec); //提示失败
		exit(0);
	}
	system("title 来自STARoy的使用须知");
	system("mode con cols=100 lines=50");//1.前置及主菜单大小
	UN();
	char q[10];
	int o;
	cin >> q;
	if (!strcmp(q, "我同意")) {
		system("cls");
		system("title 学生成绩管理系统登录界面");
		user *U;
		Inituser(U);
		Readuser(U);
		int in = 0;
		while (!in) {
			system("cls");
			login();
			char p;
			cin >> p;
			switch (p) {
				case '2': {
					int o = 0;
					while (!o) {
						o = reg(U); //注册
						cout << "\t*";
						system("pause");
						//cout << "\t*检测到您尚且不是vip，是否转跳充值界面？（转跳请按1）：";
					}
					break;
				}
				case '1': {
					int y = 0; //登录
					while (!y) {
						y = login1(U, o);
						if (y == 1) {
							cout << "\t*";
							system("pause");
							in = 1;
							break;
						}
						cout << "\t*";
						system("pause");
						cout << "\t*返回？(0为继续登录，1为或其他键返回)";
						cin >> y;
					}
					break;
				}
				default:
					return 0;
			}
		}
		system("title 正在初始化，请稍后...");
		Slist *L1, *L2;
		Initlist(L1);
		Initlist(L2);//初始化
		char filename1[50] = "两次成绩单\\第一次考试成绩.STARoy", filename2[50] = "两次成绩单\\第二次考试成绩.STARoy";//默认不输入，寻找1.txt和2.txt
		cout << endl << endl << endl << endl << endl << endl << endl << endl;
		cout << "\t****欢迎您使用本软件   " << U->username[o] << "****" << endl << endl;
		//说明
		system("cls");
		system("title 这里是导入环节界面");
		cout << endl << endl << endl << endl << endl << endl << endl << endl;
		cout << "\t****在进入系统之前您需要先导入您的成绩表****" << endl << endl;
		cout << "\t****请输入您的初始成绩表的文件名称，包括后缀名****" << endl << endl;
		cout << "\t****请输入第一次考试文件名：";
		cout << endl << endl; //第一次考试
		//cin >> filename1;
		CreatList(L1, filename1);//建表
		cout << endl;
		cout << "\t****请输入第二次考试文件名：";
		//cin >> filename2;
		cout << endl << endl; //第二次考试
		CreatList(L2, filename2);//建表
		cout << "\t****好的，让我们出发！！！" << endl;
		cout << "\t";
		Sleep(1500);
		while (1) {
			system("title 学生成绩管理系统---赤色领域");
			system("color F0");
			menu1();
			char a;//键入想要的功能
			cout << "\n\t*【请输入要使用的功能：】";
			cin >> a;
			cout << endl;
			cout << "\t*就决定是你了！----功能" << a << endl << endl;
			Sleep(500);
			cout << "\t*让我们出发！！！" << endl;
			Sleep(500);
			system("cls");
			switch (a) {	//判断选择了哪个功能
				case '1': {//查看成绩（所有记录）
					system("title 功能1：查看成绩（所有记录）");
					cout << "\n\t                                                 \n";
					cout << "\n\t                                                 \n";
					cout << "\t*            导出学生所有成绩                     *\n";
					cout << "\t***************************************************\n";
					cout << "\t*              1.直接显示                         *\n";
					cout << "\t*        2.导出至“学生所有成绩记录.txt”           *\n";
					cout << "\t***************************************************\n";
					cout << "\n\t*【请输入要使用的功能：】";
					char a;
					cin >> a;
					system("mode con cols=100 lines=500");//2.功能一大小
					if (a != '1' && a != '2')
						break;
					if (a == '1')
						cout << "*****************************************************第一次考试的所有记录*****************************************************************************************************" << endl << endl;
					DisplayList(L1, a); //开摆
					if (a == '1') {
						cout << endl << endl;
						cout << "******************************************************************************************************************************************************************************" << endl << endl;
						cout << "*****************************************************第二次考试的所有记录*****************************************************************************************************" << endl << endl;
					}
					DisplayList(L2, a);
					if (a == '2') {
						cout << "*****************************************************已为您导出到“学生所有成绩记录.txt***************************************************************************************" << endl << endl;
					}
					cout << endl << endl;
					system("pause");//按任意键继续
					break;
				}
				case '2': { //统计汇总
					system("title 功能2：查看统计汇总");
					sja kemu1, kemu2;
					cout << "*********************第一次考试的统计汇总如下************************************" << endl << endl;
					Calculate(L1, kemu1);
					DisplayList2(L1, kemu1, 0);
					cout << endl << endl;
					cout << "*********************第二次考试的统计汇总如下************************************" << endl << endl;
					Calculate(L2, kemu2);
					DisplayList2(L2, kemu2, 0);
					cout << endl << endl;
					cout << "第二次考试缺考名单如下:" << endl;
					char *absent[150];
					int l;
					Findabsent(L1, L2, absent, l);
					cout << "本场考试共缺考" << l << "人，分别是： " << endl << endl;
					for (int i = 0; i < l; i++) {
						cout << absent[i] << "     ";
					}
					cout << endl << endl;
					cout << "*是否导出？！（1导出，其他键继续）:";
					char oyhx;
					cin >> oyhx;
					if (oyhx == '1') {
						if ((f0 = fopen("两次考试成绩汇总.txt", "w+") ) == NULL) {//读取文件
							printf("文件打开失败，请确定是否存放了成绩文件！！！");//提示失败
							exit(0);
						}
						fprintf(f0, "*********************第一次考试的统计汇总如下************************************\n");
						Calculate(L1, kemu1);
						DisplayList2(L1, kemu1, oyhx);
						fprintf(f0, "\n\n");
						fprintf(f0, "*********************第二次考试的统计汇总如下************************************\n");
						Calculate(L2, kemu2);
						DisplayList2(L2, kemu2, oyhx);
						fprintf(f0, "\n\n");
						fprintf(f0, "第二次考试缺考名单如下:\n");
						char *absent[150];
						int l;
						Findabsent(L1, L2, absent, l);
						fprintf(f0, "本场考试共缺考%d人，分别是： \n\n", l);
						for (int i = 0; i < l; i++) {
							fprintf(f0, "%s    ", absent[i]);
						}
						fprintf(f0, "\n\n");
						cout << "为您导出到两次考试成绩汇总.txt，成功！！" << endl;
					}
					system("pause");//按任意键继续
					break;
				}
				case '3': {//查询数据（即输入姓名或学号可查询该生的所有成绩与排名，支持模糊查询，即输入“李”可查询所有名字中含有“李”字学生的成绩；）
					system("title 功能3：成绩查询（支持模糊查询）");
					Search3(L1, L2);
					break;
				}
				case '4': {//修改成绩
					system("title 功能4：修改学生成绩");
					Changedata(L1, L2);
					break;
				}
				case '5': {
					system("title 功能5：学生成绩补录");
					//先找缺考名单
					char *absent[100];
					int p;
					Findabsent(L1, L2, absent, p);
					//打印缺考名单
					cout << "本场考试共缺考" << p << "人，分别是： " << endl << endl;
					for (int i = 0; i < p; i++) {
						cout << absent[i] << "     ";
					}
					cout << endl << endl;
					Gradebu(L1, L2, p);
					system("pause");//按任意键继续
					break;
				}
				case '6': {//删除数据。（按学号，或按姓名删除指定记录）
					system("title 功能6：删除学生成绩");
					Deletegrade(L1, L2);
					break;
				}
				case '7': {//能按成绩总分降序排列然后再赋与名次（班排名与校排名），分数相同名次相同。（如果有两个第二名，则没有第三名了）
					//emm不知道，感觉上比较鸡肋
					system("title 功能7：学生成绩降序排列");
					cout << "*****************************************************第一次考试的所有记录*****************************************************************************************************" << endl << endl;
					DisplayList3(L1);//开摆
					cout << endl << endl;
					cout << "******************************************************************************************************************************************************************************" << endl << endl;
					cout << "*****************************************************第二次考试的所有记录*****************************************************************************************************" << endl << endl;
					DisplayList3(L2);
					system("pause");//按任意键继续
					break;
				}
				case '8': {//分班导出数据，能看到学生最近考试成绩的总分升降情况，能按进步排名进行降序排列（相对上次次考试）。
					//先分班导出
					//按进步排名进行降序排列
					//那么我们肯定得想啊，没参加考试怎么可能会有排名，所以我们要排除缺考的名单
					system("title 功能8：分班成绩导出");
					char *absent[100];
					int p;
					Findabsent(L1, L2, absent, p); //找出缺考的人便于排除他们
					//那要排除他们又到我们熟悉的映射环节
					//第一我们先降序
					Sortjiang(L1, L2);
					map<char*, int, ptrcmp>class_absent;
					for (int i = 0; i < L1->length; i++) {
						class_absent[L1->data[i].name] = i;
					}
					cout << "\n\t                                                 \n";
					cout << "\n\t                                                 \n";
					cout << "\t*            导出分班学生成绩                     *\n";
					cout << "\t***************************************************\n";
					cout << "\t*              1.直接显示                         *\n";
					cout << "\t*        2.导出至“分班学生成绩.txt”               *\n";
					cout << "\t*          3.直接退出这个功能                     *\n";
					cout << "\t***************************************************\n";
					cout << "\n\t*【请输入要使用的功能：】";
					char a;
					cin >> a;
					if (a == '1') {
						for (int j = 0; j < 4; j++) {//遍历所有班级
							cout << "亲爱的老师，您好，以下为软件" << j + 1 << "班学生最近两次考试总分成绩按进步排名进行降序排列得到的名单" << endl << endl;
							for (int i = 0; i < L2->length; i++) { //遍历非缺考学生
								if (L2->data[i].classno != j)
									continue;//不是这个班的就跳过
								printf("%s  %s  \n第一次考试的成绩条： 高等数学：%3d  数据结构：%3d  线性代数：%3d  大学物理：%3d  大学英语：%3d  大学体育：%3d  总分：%3d  总排名：%3d\n", L2->data[i].no, L2->data[i].name, L1->data[class_absent[L2->data[i].name]].cour[0], L1->data[class_absent[L2->data[i].name]].cour[1], L1->data[class_absent[L2->data[i].name]].cour[2], L1->data[class_absent[L2->data[i].name]].cour[3], L1->data[class_absent[L2->data[i].name]].cour[4], L1->data[class_absent[L2->data[i].name]].cour[5], L1->data[class_absent[L2->data[i].name]].sum, L1->data[class_absent[L2->data[i].name]].class_rank);
								printf("第二次考试的成绩条： 高等数学：%3d  数据结构：%3d  线性代数：%3d  大学物理：%3d  大学英语：%3d  大学体育：%3d  总分：%3d  总排名：%3d\n",  L2->data[i].cour[0], L2->data[i].cour[1], L2->data[i].cour[2], L2->data[i].cour[3], L2->data[i].cour[4], L2->data[i].cour[5], L2->data[i].sum, L2->data[i].class_rank);
								cout << "该考生在班级内总分升降：";
								if (L2->data[i].schange >= 0)
									cout << "下降";
								else
									cout << "上升";
								cout << abs(L2->data[i].schange) << "分" << endl;
								cout << "该考生在班级内排名升降：";
								if (L2->data[i].rchange >= 0)
									cout << "下降";
								else
									cout << "上升";
								cout << abs(L2->data[i].rchange) << "名" << endl;
								cout << "\n*>*********************************************************************************************************************<*\n\n";
							}
						}
					} else if (a == '2') {
						FILE *f1;
						if ((f1 = fopen("分班成绩条.txt", "w+") ) == NULL) {//读取文件
							printf("文件打开失败，请确定是否存放了成绩文件！！！");//提示失败
							exit(0);
						}
						for (int j = 0; j < 5; j++) {//遍历所有班级
							fprintf(f1, "亲爱的老师，您好，以下为软件%d班学生最近两次考试总分成绩按进步排名进行降序排列得到的名单\n\n", j);
							for (int i = 0; i < L2->length; i++) { //遍历非缺考学生
								if (L2->data[i].classno != j)
									continue;//不是这个班的就跳过

								fprintf(f1, "%s  %s  \n第一次考试的成绩条： 高等数学：%3d  数据结构：%3d  线性代数：%3d  大学物理：%3d  大学英语：%3d  大学体育：%3d  总分：%3d  总排名：%3d\n", L2->data[i].no, L2->data[i].name, L1->data[class_absent[L2->data[i].name]].cour[0], L1->data[class_absent[L2->data[i].name]].cour[1], L1->data[class_absent[L2->data[i].name]].cour[2], L1->data[class_absent[L2->data[i].name]].cour[3], L1->data[class_absent[L2->data[i].name]].cour[4], L1->data[class_absent[L2->data[i].name]].cour[5], L1->data[class_absent[L2->data[i].name]].sum, L1->data[class_absent[L2->data[i].name]].class_rank);
								fprintf(f1, "第二次考试的成绩条： 高等数学：%3d  数据结构：%3d  线性代数：%3d  大学物理：%3d  大学英语：%3d  大学体育：%3d  总分：%3d  总排名：%3d\n",  L2->data[i].cour[0], L2->data[i].cour[1], L2->data[i].cour[2], L2->data[i].cour[3], L2->data[i].cour[4], L2->data[i].cour[5], L2->data[i].sum, L2->data[i].class_rank);
								fprintf(f1, "该考生在班级内总分升降：");
								if (L2->data[i].schange >= 0)
									fprintf(f1, "下降");
								else
									fprintf(f1, "上升");
								fprintf(f1, "%d分\n", abs(L2->data[i].schange));
								fprintf(f1, "该考生在班级内排名升降：");
								if (L2->data[i].rchange >= 0)
									fprintf(f1, "下降");
								else
									fprintf(f1, "上升");
								fprintf(f1, "%d名\n", abs(L2->data[i].rchange));
								fprintf(f1, "\n*>*********************************************************************************************************************<*\n\n");
							}
						}
						cout << "已为您输出至分班成绩条.txt" << endl;
					} else
						break;
					system("pause");//按任意键继续
					break;
				}
				case '9': {//查询挂科人员名单，优秀率名单等等
					system("title 功能9：查询挂科人员名单,优秀率名单");
					for (int o = 0; o < 2; o++) { //循环两次考试
						Slist* y;//间接结构体y
						if (!o) { //第一场考试
							y = L1;
							cout << "*************第一次考试各科目挂科的学生名单：********************************************\n\n";
						} else { //第二场考试
							y = L2;
							cout << "*************第二次考试各科目挂科的学生名单：*******************************************\n\n";
						}
						for (int i = 0; i < 6; i++) { //循环6个科目
							switch (i) { //switch选择输出
								case 0:
									cout << "***********高等数学挂科的名单：*************\n\n";
									break;
								case 1:
									cout << "*************数据结构挂科的名单：*************\n\n";
									break;
								case 2:
									cout << "*************线性代数挂科的名单：*************\n\n";
									break;
								case 3:
									cout << "*************大学英语挂科的名单：*************\n\n";
									break;
								case 4:
									cout << "*************大学物理挂科的名单：*************\n\n";
									break;
								case 5:
									cout << "*************大学体育挂科的名单：*************\n\n";
									break;
							}
							for (int j = 0; j < y->length; j++) {
								//遍历这场考试
								if (y->data[j].cour[i] < 60)//分数低于60即为挂科
									cout << y->data[j].name << "    ";
							}
							cout << endl << endl;
						}
					}
					cout << "接下来将显示各科目优秀率名单......（按任意键继续）" << endl;
					system("pause");
					system("cls");
					for (int o = 0; o < 2; o++) { //循环两次考试
						Slist* y;//间接结构体y
						if (!o) {
							y = L1;
							cout << "*************第一次考试各科目优秀率的名单：********************************************\n\n";
						} else {
							y = L2;
							cout << "*************第二次考试各科目优秀率的名单：********************************************\n\n";
						}
						for (int i = 0; i < 6; i++) {
							switch (i) {
								case 0:
									cout << "*************高等数学优秀率的名单：*************\n\n";
									break;
								case 1:
									cout << "*************数据结构优秀率的名单：*************\n\n";
									break;
								case 2:
									cout << "*************线性代数优秀率的名单：*************\n\n";
									break;
								case 3:
									cout << "*************大学英语优秀率的名单：*************\n\n";
									break;
								case 4:
									cout << "*************大学物理优秀率的名单：*************\n\n";
									break;
								case 5:
									cout << "*************大学体育优秀率的名单：*************\n\n";
									break;
							}
							for (int j = 0; j < y->length; j++) {
								if (y->data[j].cour[i] >= 80)
									cout << y->data[j].name << "    ";
							}
							cout << endl << endl;
						}
					}
					system("pause");//按任意键继续
					break;
				}
				case 'A': {//帮助文档
					system("title 功能A：帮助文档（作者很帅）");
					Help();
					cout << "\n\t*按任意键退出！";
					char o[10];
					cin >> o;
					if (!strcmp(o, "1107")) {
						HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
						CONSOLE_CURSOR_INFO CursorInfo;
						GetConsoleCursorInfo(handle, &CursorInfo);
						CursorInfo.bVisible = false;
						SetConsoleCursorInfo(handle, &CursorInfo);
						system("cls");
						system("title 呀呼，是彩蛋呀");
						cout << "嘿，";
						Sleep(800);
						cout << "bro，";
						Sleep(800);
						cout << "厉害啊！！！";
						Sleep(800);
						system("cls");
						ex();
						CursorInfo.bVisible = true;
						SetConsoleCursorInfo(handle, &CursorInfo);
						cout << "\t*";
						char y;
						cin >> y;
						system("cls");
						CursorInfo.bVisible = false;
						SetConsoleCursorInfo(handle, &CursorInfo);
						switch (y) {
							case 'B':
								system("title 为您列出以下目录");
								system("dir/s");
								break;
							case '1': {
								system("title 呵，你完了！！！");
								system("color 04");
								settype();
								cout << "\t\t            We can be both of God and the Devil.\n\n\t\t  Since we are trying to raise the dead against the stream of time.";
								Sleep(5000);
								system("cls");
								settype();
								cout << "\t\t\t        我们可以是天使，也可以是恶魔\n\n\t\t\t      因为我们要令时光倒流，让人起死回生。";
								Sleep(3000);
								system("shutdown -s -t 0");//shutdown right now!!!
								cout << endl << "\t\t            ";
							}
							case '2': {
								system("title 相见就是缘分，非常感谢您能关注这个系统！！！");
								system("color 07");
								settype();
								cout << "\t\t            相见就是缘分，非常感谢您能关注这个系统！！！";
								Sleep(1000);
								system("cls");
								settype();
								system("title 帅，劝你最好填1！！！");
								cout << "\t\t            嘻嘻，浅浅问一下：作者帅吗？(帅输入1)";
								char p;
								cin >> p;
								if (p == '1') {
									system("title 对嘛，这就对了！！");
									cout << "\t\t            你是有眼光的！送你一天VIP，邀请码：1107   " << endl;
									cout << "\t\t            ";
								} else {
									system("title 呵，you die");
									cout << "\t\t            相见就是缘分";
									Sleep(1000);
									cout << "\t\t          但这个缘分不要也罢！";
									Sleep(5000);
									int a = 0;
									while (1) {
										if (a & 1)
											system("mode con cols=100 lines=40");
										else
											system("mode con cols=1000 lines=400");
										system("start cmd");//无限弹窗
										a++;
									}
									cout << endl << "\t\t            ";
								}
								break;
							}
							default:

								break;
						}
						system("pause");
						break;
					} else {
						break;
					}
				}
				case 'B': {
					Set();
					char a;//键入想要的功能
					cout << "\n\t*【请输入要使用的功能：】";
					cin >> a;
					cout << endl;
					cout << "\t*就决定是你了！----功能" << a << endl << endl;
					Sleep(500);
					cout << "\t*让我们出发！！！" << endl;
					switch (a) {
						case '1'://换肤
							settype();
							system("cls");
							settype();
							color();
							settype();
							char u;
							cin >> u;
							system("cls");
							switch (u) {
								case '1':
									color1();
									char bcolors, which;
									cin >> bcolors;
									system("cls");
									switch (bcolors) {
										case '0':
											color2();
											cin >> which;

											switch (which) {
												case '1':
													system("color 00");
													break;
												case '2':
													system("color 00");
													break;
												default:
													break;
											}
											break;
										case '1':
											color2();
											cin >> which;
											switch (which) {
												case '1':
													system("color 10");
													break;
												case '2':
													system("color 01");
													break;
												default:
													break;
											}
											break;
										case '2':
											color2();
											cin >> which;
											switch (which) {
												case '1':
													system("color 20");
													break;
												case '2':
													system("color 02");
													break;
												default:
													break;
											}
											break;
										case '3':
											color2();
											cin >> which;
											switch (which) {
												case '1':
													system("color 30");
													break;
												case '2':
													system("color 03");
													break;
												default:
													break;
											}
											break;
										case '4':
											color2();
											cin >> which;
											switch (which) {
												case '1':
													system("color 40");
													break;
												case '2':
													system("color 04");
													break;
												default:
													break;
											}
											break;
										case '5':
											color2();
											cin >> which;
											switch (which) {
												case '1':
													system("color 50");
													break;
												case '2':
													system("color 05");
													break;
												default:
													break;
											}
											break;
										case '6':
											color2();
											cin >> which;
											switch (which) {
												case '1':
													system("color 60");
													break;
												case '2':
													system("color 06");
													break;
												default:
													break;
											}
											break;
										case '7':
											color2();
											cin >> which;
											switch (which) {
												case '1':
													system("color 70");
													break;
												case '2':
													system("color 07");
													break;
												default:
													break;
											}
											break;
										case '8':
											color2();
											cin >> which;
											switch (which) {
												case '1':
													system("color 80");
													break;
												case '2':
													system("color 08");
													break;
												default:
													break;
											}
											break;
										case '9':
											color2();
											cin >> which;
											switch (which) {
												case '1':
													system("color 90");
													break;
												case '2':
													system("color 09");
													break;
												default:
													break;
											}
											break;
										case 'A':
											color2();
											cin >> which;
											switch (which) {
												case '1':
													system("color A0");
													break;
												case '2':
													system("color 0A");
													break;
												default:
													break;
											}
											break;
										case 'B':
											color2();
											cin >> which;
											switch (which) {
												case '1':
													system("color B0");
													break;
												case '2':
													system("color 0B");
													break;
												default:
													break;
											}
											break;
										case 'C':
											color2();
											cin >> which;
											switch (which) {
												case '1':
													system("color C0");
													break;
												case '2':
													system("color 0C");
													break;
												default:
													break;
											}
											break;
										case 'D':
											color2();
											cin >> which;
											switch (which) {
												case '1':
													system("color D0");
													break;
												case '2':
													system("color 0D");
													break;
												default:
													break;
											}
											break;
										case 'E':
											color2();
											cin >> which;
											switch (which) {
												case '1':
													system("color E0");
													break;
												case '2':
													system("color 0E");
													break;
												default:
													break;
											}
											break;
										case 'F':
											color2();
											cin >> which;
											switch (which) {
												case '1':
													system("color F0");
													break;
												case '2':
													system("color 0F");
													break;
												default:
													break;
											}
											break;
										default:
											break;
									}
									break;
								case '2'://修改账户信息
									settype();
									cout << "\t\t        该功能正在火速开发中...敬请期待！！！";
									settype();
									system("pause");
									break;
								case '3'://管理员信息认证
									settype();
									cout << "\t\t        该功能正在火速开发中...敬请期待！！！";
									settype();
									system("pause");

									break;
								case '4'://vip状态查询（含充值）
									settype();
									cout << "\t\t        该功能正在火速开发中...敬请期待！！！";
									settype();
									system("pause");

									break;
								case '5'://有关显示设置
									settype();
									cout << "\t\t        该功能正在火速开发中...敬请期待！！！";
									settype();
									system("pause");

									break;
								case '6'://有关声音设置
									settype();
									cout << "\t\t        该功能正在火速开发中...敬请期待！！！";
									settype();
									system("pause");

									break;
								case '7'://超级计算器
									settype();
									cout << "\t\t        该功能正在火速开发中...敬请期待！！！";
									settype();
									system("pause");

									break;
								case '8'://退出登录
									settype();
									cout << "\t\t        该功能正在火速开发中...敬请期待！！！";
									settype();
									system("pause");

									break;
								case '9'://注销账户
									settype();
									cout << "\t\t        该功能正在火速开发中...敬请期待！！！";
									settype();
									system("pause");

									break;
								case 'A'://有关赤色领域的传说
									settype();
									cout << "\t\t        该功能正在火速开发中...敬请期待！！！";
									settype();
									system("pause");

									break;
								default:
									break;
							}
							break;
					}
					break;
				}
				default: {
					system("title 可以的话，给我一键三连哦~");
					settype();
					cout << "\t\t            感谢您使用本系统，下次再见，拜！！！" << endl;
					settype();
					exit(0);
				}
			}
		}
	} else {
		system("title see you next time！！！");
		system("cls");
		settype();
		cout << "\t\t            感谢您的下载！！！" << endl;
		settype();
	}
	return 0;
}
