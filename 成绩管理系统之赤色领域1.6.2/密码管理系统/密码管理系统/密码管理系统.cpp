#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
#define MAX 1000//�û������Ϊ1000
time_t t = time(nullptr); // ��ȡ1970�굽���ڵĺ�����
struct tm* now = localtime(&t); // �Ѻ���ת��Ϊ����ʱ��Ľṹ��
//�û�������
typedef struct log {
	char username[MAX][MAX];//�û���
	size_t password[MAX];
	int num;
	char salt[MAX][MAX];
} user;
FILE *logfile;
//��ʼ¼���û���������
void Inituser(user *&U) {
	U = new user;//����ռ�
}
string rand_str(const int len)  //����ַ������ɣ��Σ�
{
	srand(time(NULL));              //��ʱ��Ϊ���ӣ�
	string str;                 
	char c;                    
	int i;                   
	for(i = 0;i < len;i ++)
	{
		c = 'a' + rand()%26;
		str.push_back(c);       /*push_back()��string��β�庯���������������ַ�c*/
	}
	return str;                
}
hash<string>hash1;
//Ϊ������
void settype() {
	cout << endl << endl<< endl;
	cout << endl << endl  << endl << endl;
}
//����
void Readuser(user *&U) {
	FILE* f1, *f2,*f3;
	if ((f1 = fopen("username.oyhx", "r") ) == NULL) {//��ȡ�ļ�
		printf("\n��ϵͳ��ʾ���������󣬴�����Ϊ00001\n");//��ʾʧ��
		fprintf(logfile, "%d��%d��%d��%d:%d:%d�����󡿷������󣬴�����Ϊ00001:username.txt����ʧ��\n", now->tm_year + 1900, now->tm_mon + 1, now->tm_mday, now->tm_hour, now->tm_min, now->tm_sec); //��ʾʧ��
		exit(0);
	}
	if ((f2 = fopen("password.oyhx", "r") ) == NULL) {//��ȡ�ļ�
		printf("\n��ϵͳ��ʾ���������󣬴�����Ϊ00002\n");//��ʾʧ��
		fprintf(logfile, "%d��%d��%d��%d:%d:%d�����󡿷������󣬴�����Ϊ00002��password.txt����ʧ��\n", now->tm_year + 1900, now->tm_mon + 1, now->tm_mday, now->tm_hour, now->tm_min, now->tm_sec); //��ʾʧ��
		exit(0);
	}
	if ((f3 = fopen("salt.save", "r") ) == NULL) {//��ȡ�ļ�
		printf("\n��ϵͳ��ʾ���������󣬴�����Ϊ00003\n");//��ʾʧ��
		fprintf(logfile, "%d��%d��%d��%d:%d:%d�����󡿷������󣬴�����Ϊ00003������ʧ��\n", now->tm_year + 1900, now->tm_mon + 1, now->tm_mday, now->tm_hour, now->tm_min, now->tm_sec); //��ʾʧ��
		exit(0);
	}
	int i = 0;//��¼��ο��Ե�ѧ������
	while (!feof(f1)) {//�ж��Ƿ���꣬ע���ļ���Ҫ�ж���Ŀ���
		fscanf(f1, "%s", U->username[i]); //ɨ�裬���¼��
		i++;
	}
	int p = 0;
	while (!feof(f2)) {//�ж��Ƿ���꣬ע���ļ���Ҫ�ж���Ŀ���
		fscanf(f2, "%llu", &U->password[p]); //ɨ�裬���¼��
		p++;
	}
	p = 0;
	while (!feof(f3)) {//�ж��Ƿ���꣬ע���ļ���Ҫ�ж���Ŀ���
		fscanf(f3, "%s", U->salt[p]); //ɨ�裬���¼��
		p++;
	}
	U->num = --i;
	fclose(f1);//�ǵùر��ļ�
	fclose(f2);//�ǵùر��ļ�
	fclose(f3);//�ǵùر��ļ�
}
int reg(user *&U) {
	system("cls");
	system("title ��ӭ��������ע��ҳ��");
	settype();
	cout << "\t***************************************************\n";
	cout << "\t*             ��ӭ��������ע��ҳ��                *\n";
	cout << "\t***************************************************\n";
	Readuser(U);
	char username[MAX];
	char password[MAX], password1[MAX];
	string oypassword,oypassword1;
	string str;                 
	str = rand_str(50);
	cout << "\t*�������û�����";
	cin >> username;
	int k = 0;
	while (k != U->num) {
		if (!strcmp(username, U->username[k])) {
			cout << "\t*�û����ظ�����һ�����ְɣ�����" << endl;
			cout<<"\t*";
			system("pause");
			return 0;
		}
		k++;
	}
	cout << "\t*���������룺";
	// ���ַ���ȡ���벢��ʾ�Ǻ�
	int i = 0;
	while (true) {
		password[i] = getch(); // ʹ��getch()��ȡ�������룬�����Ե��ն�
		if (password[i] == '\r') { // �س�����ʾ�������
			password[i] = '\0'; // ������ĩβ����ַ���������
			break;
		}
		cout << "*"; // ��ʾ�Ǻ�
		i++;
	}
	oypassword.append(password);
	oypassword.append(str);
	cout << endl << "\t*��ȷ�����룺";
	i = 0;
	while (true) {
		password1[i] = getch(); // ʹ��getch()��ȡ�������룬�����Ե��ն�
		if (password1[i] == '\r') { // �س�����ʾ�������
			password1[i] = '\0'; // ������ĩβ����ַ���������
			break;
		}
		cout << "*"; // ��ʾ�Ǻ�
		i++;
	}
	if (!strcmp(password, password1)) {
		// ���û��������뱣�浽�ļ���
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
			cout << endl << "\t*��ϵͳ��ʾ����ϲ��ע��ɹ������������µ�¼����" << endl;
			cout<<"\t*";
			system("pause");
			return 1;
		} else {
			cout << endl << "\t*��ϵͳ��ʾ��ע��ʧ�ܣ����Ժ����ԡ�" << endl;
			cout<<"\t*";
			system("pause");
			return 0;
		}
	} else {
		cout << endl << "\t*��ϵͳ���桿�������벻��ͬŶ~������ע���ޣ�����" << endl;
		cout<<"\t*";
		system("pause");
		return 0;
	}
}

int login1(user *&U, int &o) {
	system("cls");
	system("title ��ӭ������¼ҳ��");
	settype();
	cout << "\t***************************************************\n";
	cout << "\t*                ��ӭ������¼ҳ��                 *\n";
	cout << "\t***************************************************\n";
	Readuser(U);
	char username[MAX];
	char password[MAX];
	cout << "\t*�������û�����";
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
		cout << "\t*��ϵͳ���桿�û�����������ʹ�ô��û�������ע�ᣡ����" << endl;
		cout<<"\t*";
		system("pause");
		return 0;
	}
	cout << "\t*���������룺";
	int i = 0;
	while (true) {
		password[i] = getch(); // ʹ��getch()��ȡ�������룬�����Ե��ն�
		if (password[i] == '\r') { // �س�����ʾ�������
			password[i] = '\0';
			break;
		}
		cout << "*"; // ��ʾ�Ǻ�
		i++;
	}
	string oypassword;
	oypassword.append(password);
	oypassword.append(U->salt[o]);
	if(hash1(oypassword)==U->password[o]){
		cout << endl << "\t*��ϲ������¼�ɹ�������" << endl;
		cout<<"\t*";
		system("pause");
		return 1;
	}
	else{
		cout << endl << "\t*�������...�����µ�¼������" << endl;
		cout<<"\t*";
		system("pause");
		return 0;
	}
}

int main() {
	if ((logfile = fopen("��־�ļ�.txt", "a") ) == NULL) {//��ȡ�ļ�
		printf("��ϵͳ��ʾ���������󣬴�����Ϊ00000\n");//��ʾʧ��
		exit(0);
	}
	user *U;
	Inituser(U);
	Readuser(U);
	settype();
	cout<<"\t*��ʼ���ɹ�������"<<endl;
	while (1) {
		system("cls");
		settype();
		cout << "\t   *����һ���򵥵Ĳ˵�*" << endl;
		cout << "\t     1.ע��   2.��¼" << endl;
		cout<<"\t   ";
		char p;
		cin >> p;
		switch (p) {
			case '1': {
				int o = 0;
				while (!o) {
					o = reg(U); //ע��
				}
				break;
			}
			case '2': {
				int y = 0; //��¼
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
