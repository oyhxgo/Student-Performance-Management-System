#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
#define MAX 1000//用户密码最长为1000
time_t t = time(nullptr); // 获取1970年到现在的毫秒数
struct tm* now = localtime(&t); // 把毫秒转换为日期时间的结构体
//用户的属性
typedef struct log {
	char username[MAX][MAX];//用户名
	size_t password[MAX];
	int num;
	char salt[MAX][MAX];
} user;
FILE *logfile;
//开始录入用户名和密码
void Inituser(user *&U) {
	U = new user;//分配空间
}
string rand_str(const int len)  //随机字符串生成（盐）
{
	srand(time(NULL));              //以时间为种子；
	string str;                 
	char c;                    
	int i;                   
	for(i = 0;i < len;i ++)
	{
		c = 'a' + rand()%26;
		str.push_back(c);       /*push_back()是string类尾插函数。这里插入随机字符c*/
	}
	return str;                
}
hash<string>hash1;
//为了美观
void settype() {
	cout << endl << endl<< endl;
	cout << endl << endl  << endl << endl;
}
//建表
void Readuser(user *&U) {
	FILE* f1, *f2,*f3;
	if ((f1 = fopen("username.oyhx", "r") ) == NULL) {//读取文件
		printf("\n【系统提示】发生错误，错误码为00001\n");//提示失败
		fprintf(logfile, "%d年%d月%d日%d:%d:%d【错误】发生错误，错误码为00001:username.txt创建失败\n", now->tm_year + 1900, now->tm_mon + 1, now->tm_mday, now->tm_hour, now->tm_min, now->tm_sec); //提示失败
		exit(0);
	}
	if ((f2 = fopen("password.oyhx", "r") ) == NULL) {//读取文件
		printf("\n【系统提示】发生错误，错误码为00002\n");//提示失败
		fprintf(logfile, "%d年%d月%d日%d:%d:%d【错误】发生错误，错误码为00002：password.txt创建失败\n", now->tm_year + 1900, now->tm_mon + 1, now->tm_mday, now->tm_hour, now->tm_min, now->tm_sec); //提示失败
		exit(0);
	}
	if ((f3 = fopen("salt.save", "r") ) == NULL) {//读取文件
		printf("\n【系统提示】发生错误，错误码为00003\n");//提示失败
		fprintf(logfile, "%d年%d月%d日%d:%d:%d【错误】发生错误，错误码为00003：创建失败\n", now->tm_year + 1900, now->tm_mon + 1, now->tm_mday, now->tm_hour, now->tm_min, now->tm_sec); //提示失败
		exit(0);
	}
	int i = 0;//记录这次考试的学生人数
	while (!feof(f1)) {//判断是否读完，注意文件不要有多余的空行
		fscanf(f1, "%s", U->username[i]); //扫描，逐个录入
		i++;
	}
	int p = 0;
	while (!feof(f2)) {//判断是否读完，注意文件不要有多余的空行
		fscanf(f2, "%llu", &U->password[p]); //扫描，逐个录入
		p++;
	}
	p = 0;
	while (!feof(f3)) {//判断是否读完，注意文件不要有多余的空行
		fscanf(f3, "%s", U->salt[p]); //扫描，逐个录入
		p++;
	}
	U->num = --i;
	fclose(f1);//记得关闭文件
	fclose(f2);//记得关闭文件
	fclose(f3);//记得关闭文件
}
int reg(user *&U) {
	system("cls");
	system("title 欢迎来到快速注册页面");
	settype();
	cout << "\t***************************************************\n";
	cout << "\t*             欢迎来到快速注册页面                *\n";
	cout << "\t***************************************************\n";
	Readuser(U);
	char username[MAX];
	char password[MAX], password1[MAX];
	string oypassword,oypassword1;
	string str;                 
	str = rand_str(50);
	cout << "\t*请输入用户名：";
	cin >> username;
	int k = 0;
	while (k != U->num) {
		if (!strcmp(username, U->username[k])) {
			cout << "\t*用户名重复，换一个名字吧！！！" << endl;
			cout<<"\t*";
			system("pause");
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
	oypassword.append(password);
	oypassword.append(str);
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
		FILE* file = fopen("username.oyhx", "a");
		FILE* file1 = fopen("password.oyhx", "a");
		FILE* file2=fopen("salt.save","a");
		if (file != NULL) {
			fprintf(file, "%s ",username);
			fprintf(file1, "%llu ", hash1(oypassword));
			fprintf(file2, "%s ",str.c_str());
			fclose(file);
			fclose(file1);
			fclose(file2);
			cout << endl << "\t*【系统提示】恭喜您注册成功！！！请重新登录！！" << endl;
			cout<<"\t*";
			system("pause");
			return 1;
		} else {
			cout << endl << "\t*【系统提示】注册失败，请稍后重试。" << endl;
			cout<<"\t*";
			system("pause");
			return 0;
		}
	} else {
		cout << endl << "\t*【系统警告】两次密码不相同哦~请重新注册噢！！！" << endl;
		cout<<"\t*";
		system("pause");
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
		cout<<"\t*";
		system("pause");
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
	string oypassword;
	oypassword.append(password);
	oypassword.append(U->salt[o]);
	if(hash1(oypassword)==U->password[o]){
		cout << endl << "\t*恭喜您，登录成功！！！" << endl;
		cout<<"\t*";
		system("pause");
		return 1;
	}
	else{
		cout << endl << "\t*密码错误...请重新登录！！！" << endl;
		cout<<"\t*";
		system("pause");
		return 0;
	}
}

int main() {
	if ((logfile = fopen("日志文件.txt", "a") ) == NULL) {//读取文件
		printf("【系统提示】发生错误，错误码为00000\n");//提示失败
		exit(0);
	}
	user *U;
	Inituser(U);
	Readuser(U);
	settype();
	cout<<"\t*初始化成功！！！"<<endl;
	while (1) {
		system("cls");
		settype();
		cout << "\t   *这是一个简单的菜单*" << endl;
		cout << "\t     1.注册   2.登录" << endl;
		cout<<"\t   ";
		char p;
		cin >> p;
		switch (p) {
			case '1': {
				int o = 0;
				while (!o) {
					o = reg(U); //注册
				}
				break;
			}
			case '2': {
				int y = 0; //登录
				while (!y) {
					int o;
					y = login1(U,o);
				}
				break;
			}
			default:
				return 0;
		}
	}
}
