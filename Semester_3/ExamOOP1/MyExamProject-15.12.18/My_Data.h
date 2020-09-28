#ifndef MY_DATA_H
#define MY_DATA_H

#include "Object_Of_Image.h"

//global namespace
namespace gl {

	//��� ���������� ���
	static size_t current_id = 0;
	//������� ��� ��'���� ������
	static const double calc_error = 0.1;

	//������ �����, ��� ���� ���������� - ��� ������ ����!

	//���� ��������� ������ ��'���
	static const double chance_similar = 50;
	//���� ��������� ������ ������
	static const double chance_part = 50;
	//���� ��������� ���� ��'��� ������ �����
	static const double chance_neighbour = 50;
	//���� ��������� �������� ��'���
	static const double chance_unknown = 25;
	//�������� ��'���
	static Unknown * unknown_object = new Unknown;

}

#endif // !MY_DATA_H
