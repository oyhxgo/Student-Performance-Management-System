#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
void settype() {
	cout << endl << endl << endl << endl << endl << endl << endl << endl;
	cout << endl << endl << endl << endl << endl << endl << endl << endl;
}
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

int main() {
	while (1) {
		cout<<"请按1";
		char a;//键入想要的功能
		cout << "\n\t*【请输入要使用的功能：】";
		cin >> a;
		cout << endl;
		cout << "\t*就决定是你了！----功能" << a << endl << endl;
		Sleep(500);
		cout << "\t*让我们出发！！！" << endl;
		switch (a) {
			case '1': { //换肤
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
						cout << "正在加速开发中....敬请期待...";
						break;
					default:
						break;
				}
				break;
			}
		}
	}
}

