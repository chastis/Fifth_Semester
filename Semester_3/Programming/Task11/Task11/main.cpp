#include <cassert>
#include <cmath>
#include <vector>
#include <algorithm>
#include <limits>
#include <iostream>
#include <conio.h>

struct Point { int x, y; };

double distance(const Point &p1, const Point &p2)
{
	Point delta = { p2.x - p1.x, p2.y - p1.y };
	return std::sqrt((double)delta.x * delta.x + (double)delta.y * delta.y);
}

static std::vector<std::vector<double>> s_solutions;

double MWT(const Point poly[], unsigned n, unsigned i, unsigned j)
{
	assert(i < j && j < n);

	if (j == i + 1)
		// �������� ����� - ���������� ��� 0
		return 0;

	if (s_solutions[i][j] >= 0)
		// ����� ��������� �� ��� ������ - ���������� ������� �������
		return s_solutions[i][j];

	// ����� ��������� �� ��� �� ������ - ������ �� ���������

	// ��� ���������
	double weight_ij = i > 0 || j < n - 1 ? distance(poly[i], poly[j]) : 0;
	// �� ��������, ��� ��������� [0, n - 1] - ��� �������� ����� � �� ��� ����� 0

	double min_weight = std::numeric_limits<double>::max();
	for (unsigned k = i + 1; k < j; ++k)
	{
		double weight = MWT(poly, n, i, k) + MWT(poly, n, k, j);
		min_weight = std::min(min_weight, weight);
	}

	// ������� ����� ���������
	double weight = weight_ij + min_weight;

	// ���������� ������� �� �������
	s_solutions[i][j] = weight;

	return weight;
}

double MWT(const Point poly[], unsigned n)
{
	return MWT(poly, n, 0, n - 1);
}

int main()
{
	Point poly[] = { { 0, 0 },{ 180, -50 },{ 195, -50 },{ 200, 0 },{ 195, 50 } };
	unsigned n = sizeof poly / sizeof *poly;

	s_solutions.resize(n);
	for (auto &s : s_solutions) s.resize(n, -1);

	std::cout << MWT(poly, n) << std::endl;
	std::cout << std::endl << "That's all Folks!" << std::endl;
	_getch();
	return 0;
}
/*

�������� ������� �����
����� ��� ������ �� ��������
��� ������� �����
Point poly[] = { { 0, 0 },{ 180, -50 },{ 195, -50 },{ 200, 0 },{ 195, 50 } };
					0			1			2			3			4
�� "����" �������� ��� ��������������� �� ���������
������� �� �������� � ������ 0 � 4
�������� ������� ������ �� ����� �������� (��� = 0)
��� �� �������� 0 � 4 ����������� ����� ��������
0 1 // ���  = 0 // �������� �������
1 4 //��� ����� ������� � ����������� � ��������
��� �� ����� ��������� 1 � 4?
1 � 2//0
2 � 4
��� �� ����� ��������� 2 � 4?
2 � 3//0
3 � 4//0
������ 2 � 4 �� �������� �� 100 (��� ����� 2 � 4) + 0 (��������� ����)
����������� � 1 � 4, ������ �� ����� ��������� ����� 1 2, 2 3, 3 4, 2 4.
�� ��� ��� ���� �� �������� 100 (��� ����� 2 � 4) � 101 (��� ����� 1 � 4)

��������� �� �������
��� �� ����� �������� 1 � 4?
1 � 3, � ����� 3 � 4
��� �� ����� ��������� 1 � 3?
1 � 2//0
2 � 3//0
������ �� 1 � 3 �� ������  53 (��� ����� 1 � 3) + 0 (��������� ����)
3 � 4//0

������������ � 1 � 4
�� �������� ����� ���� ����� : 53 + 101, ������� ������ ��� 100 + 101
������� ���������

�� ���� ������� �� ������������ � 0 � 4 � ����������� 154


� ��� �� ������� ������?
���������!
��������� �� ������� 0 � 4
���?
0 2 � 2 4
� ��� �����


*/