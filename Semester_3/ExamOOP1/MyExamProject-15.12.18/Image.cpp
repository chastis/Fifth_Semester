#include <time.h>
#include <stdlib.h>
#include <cmath>
#include <algorithm>
#include <iostream>
#include "Image.h"
#include "My_Data.h"

std::ostream& operator << (std::ostream& os, const std::tm& obj)
{
	os << "(" << obj.tm_hour << "h, " << obj.tm_min << "m, " << obj.tm_sec << "s)";
	return os;
}

Image::Image(size_t _length, size_t _width)
	: _length(_length), _width(_width)
{
	_creation_time.tm_hour = rand() % 24;
	_creation_time.tm_min = rand() % 60;
	_creation_time.tm_sec = rand() % 60;
	_id = gl::current_id++;
}

Image::~Image()
{

}

std::tm Image::creation_time()
{
	return _creation_time;
}

size_t Image::width()
{
	return _width;
}

size_t Image::length()
{
	return _length;
}

size_t Image::id()
{
	return _id;
}

std::vector<Object *> &Image::existing_objects()
{
	return _existing_objects;
}

std::vector<Object *> Image::recognized_objects()
{
	return _recognized_objects;
}

Object * Image::return_recognized_object(Object * temp)
{
	//������ ������� ������� / �� ������� �������� ���������� �� 100
	//���� �������� �������� ������ ������� ���� ������� ������������ ������ 100%
	//������ ����������� ������� � �������� �������
	int rnd = rand() % 100 - gl::chance_unknown;
	double ex = (temp->length() * temp->width() * 100) / (double) (this->length() * this->width());
	if ( rnd < ex)
		return temp;
	else return gl::unknown_object;
}

void Image::recognazing()
{
	//������� �� ���� ������
	_recognized_objects.clear();

	//
	// ������ ���� //
	//

	//������� ������ ��� �������, ��� ������� �� ����������� ���� ��� ������

	std::vector<Object *> temp = _existing_objects;
	//�������� �� ���� ����� ��������
	for (int i = 0; i < temp.size(); i++)
	{
		std::vector<int> buffer;
		//��� �������� ������� �������� �� ���� ��� �������
		for (int j = 0; j < temp[i]->neighbour().size(); j++)
		{
			int find = -1;
			//���������� ������� ������ � ������ ����������� �� ��������
			for (int k = 0; k < temp.size() && find == -1; k++)
			{
				if (temp[i]->neighbour()[j] == temp[k])
					find = k;
			}
			//���� ����� ���������� ��������� � ����� ������
			 if (find != -1) buffer.push_back(find);
			 else break;
		}
		//���� �� ����� ���� ������� ������ ��������
		//�� �� ����� �� �������
		//� �������� ��� ������ ��� ������������

		//���� ��������� ��� ��'���
		int rnd = rand() % 100;

		if (rnd > gl::chance_neighbour && buffer.size() != 0 && buffer.size() == temp[i]->neighbour().size())
		{
			//��������� ������
			_recognized_objects.push_back(return_recognized_object(temp[i]));
			//������ ����� ���������� �������, ��� �� ����� �������� �� ��������� �� temp[i], �������� ���
			//��� ��� �� ��� �������
			Object * current_object = temp[i];
			//��������� ����� ����� ��'����
			for (auto now : buffer)
			{
				temp.erase(temp.begin()+now);
			}
			//�������� ��� ����� �������
			int find = -1;
			for(int j = 0; j < temp.size(); j++)
				if (temp[j] == current_object)
				{
					find = j;
					break;
				}
			if (find != -1) temp.erase(temp.begin() + find);
			i = 0;
		}
		buffer.clear();
	}

	//
	//������ ����
	//


	//������ ������ ��� �������, ��� ������� ���� �������

	//(����� ������� ������)
	/*//�������� �� ���� ���������
	for (int i = 0; i < temp.size(); i++)
	{
		//� ��� ��� �� ���� ���������
		for (int j = i; j < temp.size(); j++)
		{
			//��������� �� �������� �� ������� ������� �� ���
			for (int k = 0; k < temp[i]->similar().size(); k++)
			{
				//���� � ��� ���������� ��� � ��� ���������� �������

				//���� ��������� ��� ��'���
				int rnd = rand() % 100;

				if (rnd > gl::chance_part && temp[j]->type() == temp[i]->similar()[k] && ((Universal *)temp[j])->position() == ((Universal *)temp[i])->position())
				{
					_recognized_objects.push_back(return_recognized_object(temp[j]));
					temp.erase(temp.begin() + i);
					i--;
					j--;
					break;
				}
			}
		}
	}*/
	///////////////////////

	//�������� �� ���� ���������� ���������
	for (int i = 0; i < temp.size(); i++)
	{
		//��� ��� ����� �� ������� �������
		//��� ����
		bool flag = false;
		//� ��� ��� �� ���� ��������� (���� ���� ����)
		for (int j = 0; j < _existing_objects.size(); j++)
		{
			if (flag) break;
			//���� �� ���������� ��� ���������� ��������, �� ���� ����� ����
			if (temp[i] == _existing_objects[j]) continue;

			//��������� �� �������� �� ������� ������� �� ���
			for (int k = 0; k < temp[i]->similar().size(); k++)
			{
				//���� � ��� ���������� ��� � ��� ���������� �������

				//���� ��������� ��� ��'���
				int rnd = rand() % 100;

				if (rnd > gl::chance_part && _existing_objects[j]->type() == temp[i]->similar()[k] && ((Universal *)_existing_objects[j])->position() == ((Universal *)temp[i])->position())
				{
					_recognized_objects.push_back(return_recognized_object(_existing_objects[j]));
					temp.erase(temp.begin() + i);
					if (i != 0) i--;
					if (j != 0) j--;
					flag = true;
					break;
				}
			}
		}
	}

	//
	//������ ����
	//

	//�������� �� ���������� �������� � ���������� ��
	//���� ������ ������ �� ����� � ��������� ����������� ������ ������ ���� ��� �����

	for (int i = 0; i < temp.size(); i++)
	{
		//���� ��������� ������� �����
		int rnd = rand() % 100;

		//���� ������ ������ �� ����� � ���� ������
		//� + ���� �������� �������� �� �������� ��������� ��������� � ������
		//std::cout << temp[i]->part().size() << " " << temp[i]->part_area() << std::endl;
		if (temp[i]->part().size() > 0 && rnd > gl::chance_part && temp[i]->part_area() > gl::calc_error)
			//�������� �� ���� ��� ������ � ��������� ��
			for (auto now : temp[i]->part())
				_recognized_objects.push_back(return_recognized_object(now));
		//����� ������ ��������� ��� ���������� ������
		else _recognized_objects.push_back(return_recognized_object(temp[i]));
	}

}

void sort_by_time(std::vector<Image>  &images)
{
	auto compare = [](Image a, Image b) {
		bool answer = 0;
		//hours
		if (a.creation_time().tm_hour > b.creation_time().tm_hour) answer = 1;
		else if (a.creation_time().tm_hour < b.creation_time().tm_hour) answer = 0;
		//minets
		else if (a.creation_time().tm_min > b.creation_time().tm_min) answer = 1;
		else if (a.creation_time().tm_min < b.creation_time().tm_min) answer = 0;
		//sec
		else if (a.creation_time().tm_sec > b.creation_time().tm_sec) answer = 1;
		else answer = 0;

		return !answer;
	};
	std::sort(images.begin(), images.end(), compare);
}

size_t solved_four_values(std::vector<Image>  &images, std::vector<Object *>  &objects, std::tm low, std::tm up)
{
	auto more = [](std::tm one, std::tm two) {
		bool answer = 0;
		//hours
		if (one.tm_hour > two.tm_hour) answer = 1;
		else if (one.tm_hour < two.tm_hour) answer = 0;
		//minets
		else if (one.tm_min > two.tm_min) answer = 1;
		else if (one.tm_min < two.tm_min) answer = 0;
		//sec
		else if (one.tm_sec > two.tm_sec) answer = 1;
		else answer = 0;

		return answer;
	};
	/*auto less = [](std::tm one, std::tm two) {
		bool answer = 0;
		//hours
		if (one.tm_hour > two.tm_hour) answer = 1;
		else if (one.tm_hour < two.tm_hour) answer = 0;
		//minets
		else if (one.tm_min > two.tm_min) answer = 1;
		else if (one.tm_min < two.tm_min) answer = 0;
		//sec
		else if (one.tm_sec > two.tm_sec) answer = 1;
		else answer = 0;

		return !answer;
	};*/

	//�������� �� ���� ��������
	for (auto current_object : objects)
	{
		//��� ������� ������� �������� �� ���� ������������
		for (auto current_image : images)
		{
			//���� ����������� ��������� � ���������� ��� ������� �������
			if (more(current_image.creation_time(), low) && !more(current_image.creation_time(), up))
			{
				//������� ���� �� ��� ������� ������ � ������� �����������
				bool exist = false;
				for (auto temp_object : current_image.existing_objects())
					if (current_object == temp_object) exist = true;
				bool recognized = false;
				for (auto temp_object : current_image.recognized_objects())
					if (current_object == temp_object) recognized = true;

				//����������� �������� � ����� �������
				if (exist && recognized) current_object->_positive++;
				if (!exist && !recognized) current_object->_negative++;
				if (exist && !recognized) current_object->_false_negative++;
				if (!exist && recognized) current_object->_false_positive++;
			}
		}
	}

	//���������� ������������ ��������
	size_t count_unknown = 0;

	//�������� �� ���� ������������
	for (auto current_image : images)
	{
		//���� ����������� ��������� � ���������� ��� ������� �������
		if (more(current_image.creation_time(), low) && !more(current_image.creation_time(), up))
		{

			for (auto temp_object : current_image.recognized_objects())
				if (gl::unknown_object == temp_object) count_unknown++;
			
		}
	}

	return count_unknown;
}