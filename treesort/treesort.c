#include <stdlib.h>

#include "treesort.h"

#define  nil		0
#define	 false		0
#define  true		1

/* tree */
struct node {
	struct node *left,*right;
	int val;
};

void CreateNode (Node **t, int n) {
		*t = (struct node *)malloc(sizeof(struct node));
		(*t)->left = nil; (*t)->right = nil;
		(*t)->val = n;
}

void Insert(int n, Node *t) {
     /* insert n into tree */
     if ( n > t->val ) {
        if ( t->left == nil ) {
           CreateNode(&t->left,n);
        }
        else {
           Insert(n,t->left);
        }
     }
     else if ( n < t->val ) {
        if ( t->right == nil ) {
           CreateNode(&t->right,n);
        }
        else {
           Insert(n,t->right);
        }
     }
}

int Checktree(Node *p) {
    /* check by inorder traversal */
    int result;
    result = true;
    if ( p->left != nil ) {
       if ( p->left->val <= p->val ) {
          result = false;
       }
       else {
          result = Checktree(p->left) && result;
       }
    }

    if ( p->right != nil ){
       if ( p->right->val >= p->val ) {
          result = false;
       }
       else {
          result = Checktree(p->right) && result;
       }
    }
    return (result);
} /* checktree */

int treesort(int srtelements, int *sortlist, Node **tree) {
    int i;

    CreateNode (tree, sortlist[0]);

    for ( i = 1; i < srtelements; i++ )
        Insert(sortlist[i],*tree);

    return Checktree(*tree);
}

