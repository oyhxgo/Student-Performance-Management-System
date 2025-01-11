////最初设想
//#include<bits/stdc++.h>
//using namespace std;
//const int base=131;//这里是将字符串看成的进制
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
////初学哈希，返回值为size_t(%llu),竟然属于整型
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
//尝试实现哈希加盐
//首先测试随机生成字符串函数
#include<bits/stdc++.h>
using namespace std;
string rand_str(const int len)  
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



