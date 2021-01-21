#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXI 50
typedef struct node {
  int x;
  struct node* left;
  struct node* right;
}BN;

void buildTree(BN** rootptr);

void outputTree(BN* root);

int main() {
    BN* root;
    BN* que[MAXI];    /*used for free*/
    int head = 0;   /*head of que*/
    int tail = 1;   /*tail of que*/
    buildTree(&root);
    outputTree(root);
    /*the free procedure*/
    que[0] = root;
    while (head != tail) {
        if (que[head]->left != NULL) {
            que[tail] = que[head]->left;
            tail = (tail + 1) % MAXI;
        }
        if (que[head]->right != NULL) {
            que[tail] = que[head]->right;
            tail = (tail + 1) % MAXI;
        }
        free(que[head]);
        head = (head + 1) % MAXI;
    }
    return 0;
}

void buildTree(BN** rootptr){
    int value;
    BN** tree[MAXI];
    tree[0]=rootptr;
    int top=1;
    int low=0;
    scanf("%d",&value);
    while(value!=-1){
        *tree[low]=(BN*)malloc(sizeof(BN));
        (*tree[low])->x=value;
        tree[top]=&((*tree[low])->left);
        top++;
        tree[top]=&((*tree[low])->right);
        top++;
        low++;
        scanf("%d",&value);
    }
    while(low<top){
        *tree[low]=NULL;
        low++;
    }
    return;
}

void outputTree(BN* root){
	if(root){
		outputTree(root->left);
		printf("%d ",root->x);
		outputTree(root->right);
	}
	return;
}

