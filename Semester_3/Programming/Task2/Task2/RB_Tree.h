#ifndef RBTREE_H
#define RBTREE_H

#include<stdio.h>
#include<stdlib.h>

// ���� ������
#define ERROR_STRUCT	1
#define ERROR_BALANCE	2
#define SIZE 1000	//!< ������ ������� ��������


//! ���������� (����� ������� ��� ��������� ��������)
struct stat_st {
	struct st {
		int max_count;		//!< ��������� ���������� ��������� �� ���
		int sum_count;		//!< �������� ����� ���������
		int sum_divider;	//!< ���������� ��������, ��� ���������� ��������
	};
	int max_depth;		//!< ������� ������������� ����
	int black_depth;	//!< ������ ������� ������
	int nodes_count;	//!< ���������� ������ � ������
	int turn_count;		//!< ���������� ���������� �� ��� ��������� (������� ���������)
	st insert;			//!< ���������� �������
	st remove;			//!< ���������� ��������
};

// value - ��������
// p1,p2 - ����� ������ �����
// red   - ���� (true - ���� �������)
struct node_st { node_st *p1, *p2; int value; bool red; }; // ��������� ����

														   // ����� ������-������� ������
class RBTree {
private:
	node_st *tree_root;	//!< ������

						// ��������� ������� 

	//! ��������� ����� �������
	node_st *NewItem(int value);

	//! �������� �������
	void DelItem(node_st *node);

	//! ���� ������ (����������� �����)
	void Clear(node_st *node);

	//! ����� ������, ����������� �����
	//! \param node ����
	//! \param depth �������
	//! \param dir   ������
	//! \code Show(root,0,'*'); \endcode
	void Show(node_st *node, int depth, char dir);

	//! �������� �����
	//! \param index ������ �������
	//! \result ����� ������� ������
	node_st *Rotate21(node_st *node);

	//! �������� ������
	//! \param index ������ �������
	//! \result ����� ������� ������
	node_st *Rotate12(node_st *node);

	//! ������������ �������
	void BalanceInsert(node_st **root);

	bool BalanceRemove1(node_st **root);

	bool BalanceRemove2(node_st **root);

	//! ����������� ����� �������
	//! \result true ���� ��������� ������ ��� ������������ � ������ ������� �� �����
	bool Insert(int value, node_st **root);

	//! ����� � ������ ������������ ���� ���������
	//! \param root ������ ������ � ������� ���� ����� �������
	//! \retval res �������� ������� ��� �����
	//! \result true ���� ����� ������
	bool GetMin(node_st **root, node_st **res);

	//! ����������� ����� ��������
	//! \result true ���� ����� ������
	bool Remove(node_st **root, int value);

	//��������

	//! �������� ������ (����������� �����)
	//! \param tree ������
	//! \param b_d  ������� ������ �������
	//! \param d    ������� ������� �������
	//! \param h    ��������� ������ �������
	//! \result 0 ��� ��� ������
	int Check(node_st *tree, int b_d, int d);

	//! ����� ������ � ������ �������� � �������� (����������� �����)
	//! \param node  ������ ������
	//! \param array ������ ��� ������
	//! \param size  ������ �������
	bool TreeWalk(node_st *node, bool *array, int size);

public:
	stat_st stat; //! ���������� (����� ������� ��� ��������� ��������)

				  // ������� �������

	// �����������
	RBTree() {
		tree_root = NULL;
	}

	//! ���������� ���������� �������/��������
	void UpdateStat(stat_st::st &item);

	//! ����� ������
	void Show();

	//! ������� �������
	void Insert(int value);

	//! �������� ����
	void Remove(int value);

	//! ���� ������
	void Clear();

	//! �������� ������
	int Check();

	//! ����� ������ � ������ �������� � ��������
	//! \param array ������ ��� ������
	//! \param size  ������ �������
	bool TreeWalk(bool *array, int size);
};

#endif // RBTREE_H

