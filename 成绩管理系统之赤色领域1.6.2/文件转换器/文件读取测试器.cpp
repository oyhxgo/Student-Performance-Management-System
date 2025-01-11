//文件读取测试器
#include<bits/stdc++.h>
using namespace std;
int main(){
	FILE *F1,*f2;
	if((F1=fopen("第一次考试成绩.STARoy","r"))==NULL){
		cout<<"文件1读取失败！！！"<<endl;
	}
	if((f2=fopen("测试文件.txt","w+"))==NULL){
		cout<<"文件读取失败！！！"<<endl;
	}
	cout<<"初始化成功！！！"<<endl;
	char a[5000][50],b[5000][50];int c[5000][50];
	int i=0;
	while (!feof(F1)) {
		fscanf(F1,"%s %s",a[i],b[i]);
		fprintf(f2,"%s %s ",a[i],b[i]);
		for (int j = 0; j <= 5; j++) {
			fscanf(F1,"%d", &c[i][j]);
			fprintf(f2,"%d ",c[i][j]);
		}
		fprintf(f2,"\n");
		i++;
	}
	cout<<"good"<<endl;
	fclose(F1);
	fclose(f2);
	return 0;
}
