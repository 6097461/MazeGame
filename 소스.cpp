#include<iostream>
#include<stdlib.h>//exit �Լ�
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
	cout << " ī       ��       ��       �� " << endl;
	cout << "-----    -----    -----   -----" << endl;
	cout << "1.���ӽ���" << endl;
	cout << "2.���Ӽ���" << endl;
	cout << "3.��ǻ�Ϳ� ����" << endl;
	cout << "4.��������" << endl;
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
		cout << "�÷��̾���� �Է��ϼ���";
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
		cout << "*****************************���Ӽ���*******************************" << endl;
		cout << "ī�� ���ӿ� �����ϴ� �� �÷��̾�� �� 3���� ī�带 ������ �� �ִ�" << endl;
		cout << "�÷��̾��� ���� ���� ���� �� �ִ� ī���� ���ڴ� 1~(3*�÷��̾��� ��)�� �ȴ� " << endl;
		cout << "�� �÷��̾�κ��� ī�� 3���� �����ϵ��� �� �� �� ���� ���� ū �÷��̾ �¸��ϴ� �����Դϴ�" << endl;

		
	}
	
	else if (ch == '3')
	{
		cout << "��ǻ�Ϳ� ������ �����մϴ�" << endl;
		cout << "�÷��̾���� �Է��ϼ���";
		cin >> playernum;
		int i = 0;
		int *num1 = new int[3 * playernum];
		int *p = new int[playernum];
		int c[3];
		
		Noduplicate(num1, playernum);
		cout << "******************************" << endl;
		cout << "��ǻ��player�����Դϴ�" << endl;
		
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
		cout << "<<ī�� 3���� �����ϼ���>>" << endl;
		cin >> a >> b >> c;
		if (a > playernum*3)
		{
			cout << "!!!!<ù��° ī��> ī�� �� �� �ʰ��߽��ϴ�. �ٽ� �����ϼ���!!!!" << endl;
			cin >> a ;
		}
		 if (b > playernum*3)
		{
			cout << "!!!!<�ι�° ī��> ī�� �� �� �ʰ��߽��ϴ�. �ٽ� �����ϼ���!!!!" << endl;
			cin >>b;
		}
	   if (c > playernum*3)
		{
			cout << "!!!!<����° ī��> ī�� �� �� �ʰ��߽��ϴ�. �ٽ� �����ϼ���!!!!" << endl;
			cin >> c;
		}

		cout << "������ ī����� ����" << endl;
		cout<<num1[a - 1] << " " << num1[b - 1] << " " << num1[c - 1] << endl;
		int result = num1[a - 1] + num1[b - 1] + num1[c - 1];
		cout << "���� : " << result << endl;
		return result;

	}
}
int cplayer(int *c)
{
	
	cout << "������ ī����� ����" << endl;
	cout << c[0] <<" "<< c[1] <<" "<< c[2] << endl;
	int result = c[0] + c[1] + c[2];
	cout << "���� : " << result << endl;
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
				cout << "���º� �Դϴ�" << endl;
			}
			
		}
		cout << "*****���ڴ� ����" << Max << "�� �÷��̾��Դϴ�!!******";
		
	}
