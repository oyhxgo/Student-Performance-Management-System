#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
void settype() {
	cout << endl << endl << endl << endl << endl << endl << endl << endl;
	cout << endl << endl << endl << endl << endl << endl << endl << endl;
}
void color() {
	cout << "\t***************************************************\n";
	cout << "\t*             ��ѡȡ����Ҫ������                  *\n";
	cout << "\t***************************************************\n";
	cout << "\t***************1.������ɫ�����⣩******************\n";
	cout << "\t***************3.��ѡ�������⣨vipѡ�***********\n";
	cout << "\t***************4.����������************************\n";
	cout << "\t***************************************************\n";
}
void color1() {
	cout << "\t***************************************************\n";
	cout << "\t*             ��������������ɫ                    *\n";
	cout << "\t***************************************************\n";
	cout << "\t************0.��ɫ***************8.��ɫ************\n";
	cout << "\t************1.��ɫ***************9.����ɫ**********\n";
	cout << "\t************2.��ɫ***************A.����ɫ**********\n";
	cout << "\t************3.ǳ��ɫ*************B.��ǳ��ɫ********\n";
	cout << "\t************4.��ɫ***************C.����ɫ**********\n";
	cout << "\t************5.��ɫ***************D.����ɫ**********\n";
	cout << "\t************6.��ɫ***************E.����ɫ**********\n";
	cout << "\t************7.��ɫ***************F.����ɫ**********\n";
	cout << "\t***************************************************\n";
}
void color2() {
	cout << "\t***************************************************\n";
	cout << "\t*             ��������������ɫ                    *\n";
	cout << "\t***************************************************\n";
	cout << "\t*************1.����Ϊ������ɫ**********************\n";
	cout << "\t*************2.����Ϊ������ɫ**********************\n";
	cout << "\t*************3.������ȡ��**************************\n";
	cout << "\t***************************************************\n";
}

int main() {
	while (1) {
		cout<<"�밴1";
		char a;//������Ҫ�Ĺ���
		cout << "\n\t*��������Ҫʹ�õĹ��ܣ���";
		cin >> a;
		cout << endl;
		cout << "\t*�;��������ˣ�----����" << a << endl << endl;
		Sleep(500);
		cout << "\t*�����ǳ���������" << endl;
		switch (a) {
			case '1': { //����
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
					case '2':
						cout << "���ڼ��ٿ�����....�����ڴ�...";
						break;
					default:
						break;
				}
				break;
			}
		}
	}
}

