#include<iostream>
#include<stdlib.h>//exit 함수
#include<conio.h>
#include<windows.h>
using namespace std;

int menu(int playernum);
void Noduplicate(int *num1, int playernum);
int player(int *num1, int playernum);
void Maxsum(int *p,int playernum);
int cplayer(int *c);

int main()
{
	int playernum=0;
	
	cout << "----------------------------------------" << endl;
	cout << "-----    -----    -----   -----" << endl;
	cout << " 카       드       게       임 " << endl;
	cout << "-----    -----    -----   -----" << endl;
	cout << "1.게임시작" << endl;
	cout << "2.게임설명" << endl;
	cout << "3.컴퓨터와 게임" << endl;
	cout << "4.게임종료" << endl;
	cout << "----------------------------------------" << endl;
	
	menu(playernum);
	
	return 0;
}


int menu(int playernum)
{
	char ch;
	ch = getch();
	system("cls");
	if (ch == '1')
	{
		cout << "플레이어수를 입력하세요";
		cin >> playernum;
		int *num1 = new int[3 * playernum];
		 Noduplicate(num1, playernum);

		int *p = new int[playernum];

		for (int i = 0; i < playernum; i++)
		{
			p[i] = player(num1, playernum);
		}


		Maxsum(p, playernum);

		delete[] num1;
		delete[] p;
	}
	else if (ch == '2')
	{
		cout << "*****************************게임설명*******************************" << endl;
		cout << "카드 게임에 참여하는 각 플레이어는 총 3장의 카드를 선택할 수 있다" << endl;
		cout << "플레이어의 수에 따라 나올 수 있는 카드의 숫자는 1~(3*플레이어의 수)가 된다 " << endl;
		cout << "각 플레이어로부터 카드 3장을 선택하도록 한 후 그 합이 가장 큰 플레이어가 승리하는 게임입니다" << endl;

		
	}
	
	else if (ch == '3')
	{
		cout << "컴퓨터와 게임을 시작합니다" << endl;
		cout << "플레이어수를 입력하세요";
		cin >> playernum;
		int i = 0;
		int *num1 = new int[3 * playernum];
		int *p = new int[playernum];
		int c[3];
		
		Noduplicate(num1, playernum);
		cout << "******************************" << endl;
		cout << "컴퓨터player순서입니다" << endl;
		
		i = 0;
		for (int j = 0; j < 3; j++)
		{
			c[j] = num1[rand() % (playernum * 3)];
			
		}

		for (int i = 0; i < playernum; i++)
		{
			if (i == 0)
			{
				p[i] = cplayer(c);
			}
			else
			{
			
			p[i] = player(num1, playernum);
		    }
		}
		
		Maxsum(p,playernum);
		delete[] p;
		delete[] num1;
	
				

	}
	else if (ch == '4')
	{
		exit(0);
	}
	
	return playernum;
}

void Noduplicate(int *num1, int playernum)
{
	
	int i = 0;
	while (true)
	{
		int num = (int)(rand() % (3 * playernum)+1);//1~3*playernum

		for (int k = 0; k <= i; k++)
		{
			if (i == k)
			{
				num1[i] = num;

				i++;
			}
			if (num1[k] == num)
				break;
		}
		if (i == playernum * 3)
			break;
	}
	
}
int player(int *num1, int playernum)
{
	for (int i = 0; i < playernum; i++)
	{
		int a, b, c;
		cout << "*****************************" << endl;
		cout << "<<카드 3개를 선택하세요>>" << endl;
		cin >> a >> b >> c;
		if (a > playernum*3)
		{
			cout << "!!!!<첫번째 카드> 카드 수 를 초과했습니다. 다시 선택하세요!!!!" << endl;
			cin >> a ;
		}
		 if (b > playernum*3)
		{
			cout << "!!!!<두번째 카드> 카드 수 를 초과했습니다. 다시 선택하세요!!!!" << endl;
			cin >>b;
		}
	   if (c > playernum*3)
		{
			cout << "!!!!<세번째 카드> 카드 수 를 초과했습니다. 다시 선택하세요!!!!" << endl;
			cin >> c;
		}

		cout << "선택한 카드들의 숫자" << endl;
		cout<<num1[a - 1] << " " << num1[b - 1] << " " << num1[c - 1] << endl;
		int result = num1[a - 1] + num1[b - 1] + num1[c - 1];
		cout << "총합 : " << result << endl;
		return result;

	}
}
int cplayer(int *c)
{
	
	cout << "선택한 카드들의 숫자" << endl;
	cout << c[0] <<" "<< c[1] <<" "<< c[2] << endl;
	int result = c[0] + c[1] + c[2];
	cout << "총합 : " << result << endl;
	return result;
}

void Maxsum(int *p,int playernum)
	{
		int Max=0;
		for (int i = 0; i < playernum-1; i++){
			
			if (p[i]>p[i+1])
			{
			Max = p[i];
			
		   }
			
			else if (Max< p[i+1])
			{
				Max = p[i+1];
				
			}
		
			else if (Max== p[i+1])
			{
				cout << "무승부 입니다" << endl;
			}
			
		}
		cout << "*****승자는 합이" << Max << "인 플레이어입니다!!******";
		
	}
