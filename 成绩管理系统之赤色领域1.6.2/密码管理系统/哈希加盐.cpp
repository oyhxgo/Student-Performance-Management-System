////�������
//#include<bits/stdc++.h>
//using namespace std;
//const int base=131;//�����ǽ��ַ������ɵĽ���
//int hash1(string str) {
//	int ans=0;
//	for(int i=0;i<str.size();++i) 
//		ans=ans*base+(int)str[i];
//	return ans;
//}
//int main(){
//	string a="abcdefg",b;
//	int ans=hash1(a);
//	cout<<ans<<endl;
//	cin>>b;
//	if(hash1(b)==hash1(a))
//		cout<<"good!";
//	else
//		cout<<"bad";
//	return 0;
//}
////��ѧ��ϣ������ֵΪsize_t(%llu),��Ȼ��������
//#include<bits/stdc++.h>
//using namespace std;
//int main(){
//	string a="123456",b;
//	hash<string>hash1;
//	cout<<hash1(a)<<endl;
//	cin>>b;
//	cout<<hash1(b)<<endl;
//	if(hash1(a)==hash1(b))
//		cout<<"good!";
//	else
//		cout<<"bad";
//	return 0;
//}
//����ʵ�ֹ�ϣ����
//���Ȳ�����������ַ�������
#include<bits/stdc++.h>
using namespace std;
string rand_str(const int len)  
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
int main()
{
	string str;                 
	str = rand_str(20);         
	cout << str << endl;  
	string a="123456",b;
	a.append(str);
	hash<string>hash1;
	cout<<hash1(a)<<endl;
	cin>>b;b.append(str);
	cout<<hash1(b)<<endl;
	if(hash1(a)==hash1(b))
		cout<<"good!";
	else
		cout<<"bad";

	return 0;
}



