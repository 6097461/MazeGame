#include<iostream>
#include<math.h>
#include<conio.h>
#include<windows.h>
using namespace std;
void queen(int i, int n, int col[]);  
void printscreen(int n, int col[]);     
int promising(int i, int col[]);    

int main()
{
	LARGE_INTEGER liCounter1, liCounter2, liFrequency;
	int i;
	int n;
	int* col;
	
	cout << ">>> n*n 체스판을 입력하세요 <<< ";
	cin >> n;
	
	// 퀸이 해당행의 몇번째 열에 있는지 저장
	col = (int*)malloc(sizeof(int)*n);

	
	QueryPerformanceFrequency(&liFrequency); 
	QueryPerformanceCounter(&liCounter1);
	queen(0, n, col);
	QueryPerformanceCounter(&liCounter2);
	cout << "Time : " << (double)(liCounter2.QuadPart - liCounter1.QuadPart) / (double)liFrequency.QuadPart;

	exit(1);
	free(col);

	return 0;
}

void queen(int i, int n, int col[])
{
	int j;

	if (promising(i, col)) // 유망한가?
		if (i == n) 
			printscreen(n, col); 
		else
			for (j = 1; j <= n; j++) {    
				col[i + 1] = j;           
				queen(i + 1, n, col);  
			}
}

void printscreen(int n, int col[])   
{
	int j, k;
	
	

	for (j = 1; j <= n; j++) {
	
		for (k = 1; k < col[j]; k++) {
			cout << "X"<<"  ";
		}
		cout << "Q"<<"  ";      
		for (k = col[j]; k < n; k++)
			cout << "X"<<"  ";
		cout<<endl;   
		for (int a = 0; a <n+(n * 2); a++)
		{
			cout << "-";
		}
		cout << endl;
		
	}
	cout << endl;
	Sleep(500);//0.5초씩 출력

	

}

int promising(int i, int col[]) // 유망한지 판단하는 함수
{
	int k;
	int Switch;

	k = 1;
	Switch = 1;
	while (k < i && Switch) {
		
		if (col[i] == col[k] || abs(col[i] - col[k]) == i - k)
			Switch = 0;
		k++;
	}
	return Switch;
}