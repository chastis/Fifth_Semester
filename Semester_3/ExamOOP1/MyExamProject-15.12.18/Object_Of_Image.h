#ifndef OBJECT_OF_IMAGE_H
#define OBJECT_OF_IMAGE_H

#include <string>
#include <vector>
//#include "Image.h"

//���� �������� ��'����
enum class objects {
	//������
	people,
	//������
	car,
	//������ ������
	shell,
	//������ ������
	wheel,
	//������
	tree,
	//������� ������
	trunk,
	//����� ������
	leaves,
	//�������� ���
	unknown,
	//��� � ������������ ��'����
	none,
	//���������
	lorry,
	//���
	bush
};

//��� ������ �����-������������ objects
std::ostream& operator << (std::ostream& os, const objects& obj);

//����������� ���� ��'���
class Object {
	friend class Image;
	friend size_t solved_four_values(std::vector<Image>  &images, std::vector<Object *>  &objects, std::tm low, std::tm up);
	friend std::ostream& operator << (std::ostream& os, const Object* obj);
public:
	explicit Object(std::string _name = "", size_t _length = 0, size_t _width = 0);
	~Object();
	//������� ��'�
	std::string name();
	//������� �������
	size_t length();
	//������� ������
	size_t width();
	//������� ���
	objects type();
	//������� ��'����-�����
	std::vector<Object *> &neighbour();
	//������� ��'����-������
	std::vector<Object *> part();
	//��������� ������-��������
	void push_part(Object *);
	//������� ���� ��'����
	std::vector<objects> &similar();
	//���������� ������� ��������-�������� ���������� �� ������� �������
	//��� ��������, ���� ������ ������ ������
	double part_area();

	//
	//������ ���� �� �������� � ��� ���������
	size_t positive();
	//������� ����, �� �� � ����� ���������
	size_t negative();
	//������� ���, �� �� ��� ���������
	size_t false_positive();
	//������ ����, �� �� ��� ���������
	size_t false_negative();
private:
protected:
	//��'�
	std::string _name;
	//�������
	size_t _length;
	//������
	size_t _width;
	//���
	objects _type;
	//��'����-�����
	std::vector<Object *> _neighbour;
	//��'����-������
	std::vector<Object *> _part;
	//����� ��������-��������
	size_t _part_area;
	//���� ��'����
	std::vector<objects> _similar;

	//������ ���������� �� �����������
	//
	//������ ���� �� �������� � ��� ���������
	size_t _positive;
	//������� ����, �� �� � ����� ���������
	size_t _negative;
	//������� ���, �� �� ��� ���������
	size_t _false_positive;
	//������ ����, �� �� ��� ���������
	size_t _false_negative;
};

//��� ������ ����� Object
std::ostream& operator << (std::ostream& os, const Object* obj);

//���� ������
class People : public Object {
public:
	enum positions
	{
		seat, stand, run, lay
	};
	explicit People(std::string _name = "", size_t _length = 0, size_t _width = 0);
	~People();
	positions position();
private:
	positions _position;
};

//���� ������
class Car : public Object {
public:
	enum positions
	{
		stand, ride
	};
	explicit Car(std::string _name, size_t _length, size_t _width);
	~Car();
	positions position();
	void set_position(positions pos);
private:
	positions _position;
};

//���� ������� ������
class Shell : public Object {
public:
	enum positions
	{
		normal, broken, open_door, without_roof
	};
	explicit Shell(std::string _name, size_t _length, size_t _width);
	~Shell();
	positions position();
private:
	positions _position;


};

//���� ������ ������
class Wheel : public Object {
public:
	enum positions
	{
		rotate, stand
	};
	explicit Wheel(std::string _name, size_t _length, size_t _width);
	~Wheel();
	positions position();
private:
	positions _position;

};

//���� Unknown
class Unknown : public Object {
public:
	enum positions
	{
		unknown
	};
	explicit Unknown();
	~Unknown();
	positions position();

private:
	positions _position;

};

//���� ���������
class Lorry : public Object {
public:
	enum positions
	{
		stand, ride
	};
	explicit Lorry(std::string _name, size_t _length, size_t _width);
	~Lorry();
	positions position();

private:
	positions _position;

};

//
class Universal : public Object {
private:
	enum positions
	{
		one, two, three, four, five, six, seven, eight, nine, ten
	} _position;
public:
	explicit Universal()
	{
	};
	explicit Universal(Object * temp)
	{
		//_position = temp->_position;
	};
	~Universal() {};
	positions position()
	{
		return _position;
	}
};
#endif // !OBJECT_OF_IMAGE_H
