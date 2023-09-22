#include <stdio.h>

//TreeNode ����ü
typedef struct treeNode {
	int data;
	struct treeNode* left, * right;
	int is_thread;
}TreeNode;

// ������ ���� Ʈ�� ����
TreeNode n11 = { 11,NULL,NULL,0 };
TreeNode n10 = { 10,NULL,NULL,0 };
TreeNode n9 = { 9, &n10,&n11, 0 };
TreeNode n8 = { 8, NULL,NULL,0 };
TreeNode n7 = { 7, &n8,&n9,0 };
TreeNode n6 = { 6,NULL,NULL,0 };
TreeNode n5 = { 5, NULL,NULL,0 };
TreeNode n4 = { 4,NULL,NULL,0 };
TreeNode n3 = { 3,&n4,&n5,0 };
TreeNode n2 = { 2,&n3,&n6,0 };
TreeNode n1 = { 1,&n2,&n7,0 };

TreeNode* root = &n1; // n1�� root

// ���� ����� ���� ���� �� ã��
TreeNode* find_successor(TreeNode* p)
{
	TreeNode* q = p->right;

	if (q == NULL || p->is_thread == 1)
		return q;

	while (q->left != NULL) q = q->left;
	return q;
}

// �θ� ã�� �Լ�
TreeNode* parent(TreeNode* child)
{
	// ���� child�� root �� ���
	if (child == root)
	{
		printf("��Ʈ�Դϴ�(�θ� �����ϴ�)");
		return 0;
	}

	// child�� root�� �ƴ� ��� �θ� ã�� ����

	TreeNode* q = child->right;

	// child�� right ���� Thread ��� �� ���
	if (child->is_thread == 1) {
		// left�� ���� thread �� ��� (thread�� �θ� ����ġ�� ������ �ٷ� ���)
		if (q->left->data == child->data) {
			printf("%d", q->data);
		}

		// right�� ���� thread �� ��� (thread�� �θ��� �θ� ����ġ�� ������ �ѹ� �����ͼ� ���)
		else if (q->left->data != child->data) {
			printf("%d", q->left->data);
		}

		return 0;
	}

}

// ������ ����Ʈ�� ���
void thread_inorder(TreeNode* t)
{
	TreeNode* q;
	q = t;
	while (q->left != NULL) q = q->left;
	do {
		printf("%d ", q->data);
		q = find_successor(q);
	} while (q != NULL);
}

int main()
{
	// thread �������ֱ�
	n4.right = &n3;
	n4.is_thread = 1;

	n5.right = &n2;
	n5.is_thread = 1;

	n6.right = &n1;
	n6.is_thread = 1;

	n8.right = &n7;
	n8.is_thread = 1;

	n10.right = &n9;
	n10.is_thread = 1;

	printf("1. ���� ��ȸ ���\n");
	thread_inorder(root);

	printf("\n");

	printf("2. Node 4�� �θ� : ");
	parent(&n4);
	printf("\n");

	printf("3. Node 5�� �θ� : ");
	parent(&n5);
	printf("\n");

	printf("4. Node 6�� �θ� : ");
	parent(&n6);
	printf("\n");

	return 0;
}