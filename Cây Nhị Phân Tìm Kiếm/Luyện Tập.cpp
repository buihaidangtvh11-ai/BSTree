#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
//======================================================================
typedef int ItemType;


struct BSTNode
{
	ItemType info;
	BSTNode* left;
	BSTNode* right;
};

struct BSTree
{
	BSTNode* root;
};

//======================================================================
BSTNode* createBSTNode(ItemType x);

int Menu();

void showBSTNode(BSTNode* p);
void deleteBSTNode(BSTNode* p);
void initBSTree(BSTree& bt);

int insertBSTNode(BSTNode*& root, BSTNode* p);

void createBSTree_FromArray(BSTree& bt, ItemType a[], int n);
void createBSTree_random(BSTree& bt);
void createBSTree_Fromfile(BSTree& bt, char fileName[]);

void LNR(BSTNode* root);


//======================================================================
int main()
{
	BSTree bt;
	initBSTree(bt);

	int chon;

	do
	{
		system("cls");

		chon = Menu();

		switch (chon)
		{
		case 1:
		{
			createBSTree_random(bt);
			printf("\nDa tao cay ngau nhien!");
			break;
		}

		case 2:
		{
			ItemType a[] = { 50,30,70,20,40,60,80 };
			int n = sizeof(a) / sizeof(a[0]);

			createBSTree_FromArray(bt, a, n);

			printf("\nDa tao cay tu mang!");
			break;
		}

		case 3:
		{
			char filename[50];

			printf("\nNhap ten file: ");
			scanf("%s", filename);

			createBSTree_Fromfile(bt, filename);

			printf("\nDa doc file thanh cong!");
			break;
		}

		case 4:
		{
			printf("\nDuyet LNR: ");
			LNR(bt.root);
			break;
		}

		case 0:
		{
			printf("\nKet thuc chuong trinh!");
			break;
		}

		default:
		{
			printf("\nLua chon khong hop le!");
		}
		}

		if (chon != 0)
		{
			printf("\n\nNhan phim bat ky de tiep tuc...");
			_getch();
		}

	} while (chon != 0);

	return 0;
}


//======================================================================

int Menu()
{
	int chon;

	printf("\n================ MENU BST ================");
	printf("\n1. Tao cay ngau nhien");
	printf("\n2. Tao cay tu mang");
	printf("\n3. Tao cay tu file");
	printf("\n4. Duyet cay LNR");
	printf("\n0. Thoat");
	printf("\n==========================================");
	printf("\nNhap lua chon: ");
	scanf("%d", &chon);

	return chon;
}

BSTNode* createBSTNode(ItemType x)
{
	BSTNode* p = new BSTNode;
	if (p == 0)
	{
		printf("\nKhong du bo nho de cap pha nut moi!");
		_getch();
		return NULL;
	}
	p->info = x;
	p->left = NULL;
	p->right = NULL;
	return p;
}

void showBSTNode(BSTNode* p)
{
	printf("\n%4d", p->info);
}

void deleteBSTNode(BSTNode* p)
{
	if (p == NULL)
		return;
	p->left = NULL;
	p->right = NULL;
	delete p;
}

void initBSTree(BSTree& bt)
{
	bt.root = NULL;
}

int insertBSTNode(BSTNode*& root, BSTNode* p)
{
	if (p == NULL)
		return 0;
	if (root == NULL)
	{
		root = p;
		return 1;
	}
	if (root->info == p->info)
		return 0;
	if (p->info < root->info)
		insertBSTNode(root->left, p);
	else
		insertBSTNode(root->right, p);
	return 1;
}

void createBSTree_FromArray(BSTree& bt, ItemType a[], int n)
{
	initBSTree(bt);
	for (int i = 0;i < n;i++)
	{
		BSTNode* p = createBSTNode(a[i]);
		insertBSTNode(bt.root, p);
	}
}

void createBSTree_random(BSTree& bt)
{
	int n;
	ItemType x;
	printf("\nCho Biet So nut Cua Cay");
	scanf("%d", &n);
	initBSTree(bt);
	srand((unsigned)time(NULL));
	for (int i = 0;i <= n;i++)
	{
		x = (rand() % 199) - 99;
		BSTNode* p = createBSTNode(x);
		insertBSTNode(bt.root, p);
	}
}

void createBSTree_Fromfile(BSTree& bst, char fileName[])
{
	FILE* f;
	f = fopen(fileName, "rt");
	if (!f)
		return;
	int n;
	fscanf(f, "%d\n", &n);
	ItemType x;
	initBSTree(bst);
	for (int i = 0;i < n;i++)
	{
		fscanf(f, "%d", &x);
		BSTNode* p = createBSTNode(x);
		insertBSTNode(bst.root, p);
	}
	fclose(f);
}

//======================================================================

void LNR(BSTNode* root)
{
	if (root == NULL)
		return;

	LNR(root->left);
	printf("%4d", root->info);
	LNR(root->right);
}

