//�ļ���ȡ������
#include<bits/stdc++.h>
using namespace std;
int main(){
	FILE *F1,*f2;
	if((F1=fopen("��һ�ο��Գɼ�.STARoy","r"))==NULL){
		cout<<"�ļ�1��ȡʧ�ܣ�����"<<endl;
	}
	if((f2=fopen("�����ļ�.txt","w+"))==NULL){
		cout<<"�ļ���ȡʧ�ܣ�����"<<endl;
	}
	cout<<"��ʼ���ɹ�������"<<endl;
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
