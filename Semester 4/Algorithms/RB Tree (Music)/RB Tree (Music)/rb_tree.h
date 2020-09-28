#ifndef RB_TREE
#define RB_TREE

#include <string>
#include "music_shop.h"

class RB_Tree;
class RB_Node;
void update(RB_Node * temp);

class RB_Node
{
public:
	friend class RB_Tree;
	friend void update(RB_Node * temp);
	RB_Node();
private:
	Performer _data;
	RB_Node * _left;
	RB_Node * _right;
	RB_Node * _prev;
	bool _is_black;
	//���������� ��������� � ������� ����
	size_t _rate;
	size_t _number;
};

class RB_Tree
{
public:
	friend void update(RB_Node * temp);
	RB_Tree();
	void add(const Performer &data);
	Performer find(const std::string &key);
	Performer find_i(const size_t &i);
	void print();
private:
	RB_Node * _head;
	size_t _size;
	void print_rec(RB_Node *);
};
#endif // !RB_TREE
