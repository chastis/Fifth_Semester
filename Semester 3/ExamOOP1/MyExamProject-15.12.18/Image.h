#ifndef IMAGE_H
#define IMAGE_H

#include <ctime>
#include <chrono>
#include <vector>
#include "My_Data.h"
#include "Object_Of_Image.h"

//��������� ���� ����������
class Image {
public:
	Image(size_t _length = 1, size_t _width = 1);
	~Image();
	//������� ��� ���������
	std::tm creation_time();
	//������� �������
	size_t length();
	//������� ������
	size_t width();
	//������� �������������
	size_t id();
	//������� ��'���� �� ���������
	std::vector<Object *> &existing_objects();
	//������� ��������� ��'����
	std::vector<Object *> recognized_objects();
	//�������������
	void recognazing();
	//���������� ������������ ������, ��� ����������� ������
	Object * return_recognized_object(Object *);
private:
	//��������� �������������
	size_t _id;
	//��� ���������
	//std::chrono::steady_clock::time_point _creation_time;
	std::tm _creation_time;
	//�������
	size_t _length;
	//������
	size_t _width;

	//�������������
	//��'���� �� ���������
	std::vector<Object *> _existing_objects;
	//��������� ��'����
	std::vector<Object *> _recognized_objects;
};

//������� ��� ������ ����
std::ostream& operator << (std::ostream& os, const std::tm& obj);

//���������� ����������� �� �������
void sort_by_time(std::vector<Image>  &images);

//���������� ��������, �� ��� �������� ������ ���� �� ������ �ᒺ��� ���������
//��� ������� �ᒺ��� ������ 4 ��������,
//� ����� �������� ������� ���������� ��������� �ᒺ���.
//���������� ���������� ������������ ��������
size_t solved_four_values(std::vector<Image>  &images, std::vector<Object *>  &objects, std::tm low, std::tm up);
#endif // !IMAGE_H
