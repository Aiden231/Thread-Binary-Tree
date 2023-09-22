#include <stdio.h>

//TreeNode 구조체
typedef struct treeNode {
	int data;
	struct treeNode* left, * right;
	int is_thread;
}TreeNode;

// 스레드 이진 트리 생성
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

TreeNode* root = &n1; // n1이 root

// 중위 출력을 위한 다음 값 찾기
TreeNode* find_successor(TreeNode* p)
{
	TreeNode* q = p->right;

	if (q == NULL || p->is_thread == 1)
		return q;

	while (q->left != NULL) q = q->left;
	return q;
}

// 부모 찾기 함수
TreeNode* parent(TreeNode* child)
{
	// 만약 child가 root 일 경우
	if (child == root)
	{
		printf("루트입니다(부모가 없습니다)");
		return 0;
	}

	// child가 root가 아닌 경우 부모 찾기 실행

	TreeNode* q = child->right;

	// child의 right 값이 Thread 노드 일 경우
	if (child->is_thread == 1) {
		// left의 값이 thread 인 경우 (thread가 부모를 가르치기 때문에 바로 출력)
		if (q->left->data == child->data) {
			printf("%d", q->data);
		}

		// right이 값이 thread 인 경우 (thread가 부모의 부모를 가르치기 때문에 한번 내려와서 출력)
		else if (q->left->data != child->data) {
			printf("%d", q->left->data);
		}

		return 0;
	}

}

// 스레드 이진트리 출력
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
	// thread 연결해주기
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

	printf("1. 중위 순회 결과\n");
	thread_inorder(root);

	printf("\n");

	printf("2. Node 4의 부모 : ");
	parent(&n4);
	printf("\n");

	printf("3. Node 5의 부모 : ");
	parent(&n5);
	printf("\n");

	printf("4. Node 6의 부모 : ");
	parent(&n6);
	printf("\n");

	return 0;
}