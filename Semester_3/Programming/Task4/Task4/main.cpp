#include <iostream>
#include <conio.h>
#include <time.h>

using namespace std;

double func(double x, double y) {
	return x*x + y*y;
}

int main() {
	double x;
	double y;
	double upX = 1;
	double upY = 2 * upX - 1;
	double lowX = 0.5;
	double lowY = 0;
	double checkLowY = 0, checkUpY = 0;
	double sum = 0;

	int N;
	cout << "Enter N = ";
	cin >> N;

	srand(time(NULL));

	for (int i = 0; i < N; i++) {
		x = lowX + (upX - lowX)*(double(rand()) / RAND_MAX);
		y = lowY + (upY - lowY)*(double(rand()) / RAND_MAX);

		checkUpY = 2 * x - 1;
		if ((y > checkLowY) && (y < checkUpY))
			sum += func(x, y);

	}
	//�������������� ����� ��� �����
	//����� ��� ������� ��������� �� ������
	//������� ��������� ��������� � ����� (upX - lowX) * (upY - lowY)
	//��� ������ ������� ��������� ��������� �������� ������
	//���������� ��� ������ � ����� �� ���������� ������� (N)
	//������� �� ������ (upX - lowX) * (upY - lowY) / N
	//� ������� �������� ����� �����, ��� ������ ��������� sum
	double integral = sum * (upX - lowX) * (upY - lowY) / N;
	cout << "Integral: " << integral << endl;
	cout << "Calculation error: " << (double)7 / 32 - integral;
	cout << endl << "That's all folks!" << endl;
	_getch();
}