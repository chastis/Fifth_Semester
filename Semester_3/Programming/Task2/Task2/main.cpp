#include <iostream>

struct node // ��������� ��� ������������� ����� ������
{
	int key;
	unsigned char height;
	node* left;
	node* right;
	node(int k) { key = k; left = right = nullptr; height = 1; }
};

unsigned char height(node* p) // ���������� ������ ����
{
	return p ? p->height : 0;
}

int bfactor(node* p) // ���������� balance factor
{
	return height(p->right) - height(p->left);
}

void fixheight(node* p) // ��������������� ���������� �������� ���� height
{
	unsigned char hl = height(p->left);
	unsigned char hr = height(p->right);
	p->height = (hl>hr ? hl : hr) + 1;
}

node* rotateright(node* p) // ������ ������� ������ p
{
	node* q = p->left;
	p->left = q->right;
	q->right = p;
	fixheight(p);
	fixheight(q);
	return q;
}

node* rotateleft(node* q) // ����� ������� ������ q
{
	node* p = q->right;
	q->right = p->left;
	p->left = q;
	fixheight(q);
	fixheight(p);
	return p;
}

node* balance(node* p) // ������������ ���� p
{
	fixheight(p);
	if (bfactor(p) == 2) {
		if (bfactor(p->right) < 0) // ������� �������
			p->right = rotateright(p->right);
		return rotateleft(p);
	}
	if (bfactor(p) == -2) {
		if (bfactor(p->left) > 0) // ������� �������
			p->left = rotateleft(p->left);
		return rotateright(p);
	}
	return p; // ������������ �� �����
}

node* insert(node* p, int k) // ������� ����� k � ������ � ������ p
{
	if (!p) return new node(k);
	if (k<p->key)
		p->left = insert(p->left, k);
	else
		p->right = insert(p->right, k);
	return balance(p);
}

node* findmin(node* p) // ����� ���� � ����������� ������ � ������ p
{
	return p->left ? findmin(p->left) : p;
}

node* removemin(node* p) // �������� ���� � ����������� ������ �� ������ p
{
	if (p->left == 0) // ���� ��� ������ ����� � p
		return p->right;
	p->left = removemin(p->left);
	return balance(p);
}

node* remove(node* p, int k) // �������� ����� k �� ������ p
{
	if (!p) return 0;
	if (k < p->key)
		p->left = remove(p->left, k);
	else if (k > p->key)
		p->right = remove(p->right, k);
	else //  k == p->key
	{
		node* q = p->left;
		node* r = p->right;
		delete p;
		if (!r) return q;
		node* min = findmin(r);
		min->right = removemin(r);
		min->left = q;
		return balance(min);
	}
	return balance(p);
}

int main(int argc, const char * argv[]) {



	return 0;
}
