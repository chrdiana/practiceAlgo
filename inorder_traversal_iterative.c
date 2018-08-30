#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


struct TreeNode* insertTree (struct TreeNode *root, int data){

    if (!root){
        root = malloc(sizeof(struct TreeNode));
        root->val = data;
        root->right = NULL;
        root->left = NULL;
        return root;
    } else if (root->val <= data) {
        root->right = insertTree(root->right, data);
    } else {
        root->left = insertTree(root->left, data);
    }
    return root;

}

void printTree(struct TreeNode *root) {
    //inorder recursive
    if (!root)
        return;
    if (root->left)
        printTree(root->left);
    printf("%d-->", root->val);
    if (root->right)
        printTree(root->right);
}

struct TreeNode* arrToTree(int arr[], int size) {

    struct TreeNode* tree = NULL;
    if (size < 1)
        return NULL;
    tree = malloc(sizeof(struct TreeNode));
    tree->val = arr[0];
    tree->right = NULL;
    tree->left = NULL;
    if (size == 1) {
        return tree;
    }
    int i = 1, idx=0;
    struct TreeNode *p = tree;
    while((2*idx+2)<size){
        if (arr[2*idx+1] != INT_MAX){
            tree->left = malloc(sizeof(struct TreeNode));
            tree->left->val = arr[2*idx+1];
            printf("Inserted left: arr[%d]: %d\n", 2*idx+1, arr[2*idx+1]);
            tree->left->left = NULL;
            tree->left->right = NULL;
        } 
        if (arr[2*idx+2] != INT_MAX) {
            tree->right = malloc(sizeof(struct TreeNode));
            tree->right->val = arr[2*idx+1];
            printf("Inserted right: arr[%d]: %d\n", 2*idx+2, arr[2*idx+2]);
            tree->right->left = NULL;
            tree->right->right = NULL;
        }
        idx++;
        if (idx%2){
            tree = p->right;
        }
        else {
            p = tree;
            tree = tree->left;  
        }
    }
    return tree;
}

struct TreeNode* arrToTreeRecur(int arr[], int size, struct TreeNode *node, int idx) {

    if (idx > size){
        return NULL;
    }
    if (arr[idx] == INT_MAX)
        return NULL;
    if (!node) {
        node = malloc(sizeof(struct TreeNode));
        node->val = arr[idx];
        node->left = NULL;
        node->right = NULL;
    }
    node->left = arrToTreeRecur(arr, size, node->left, 2*idx+1);

    node->right = arrToTreeRecur(arr, size, node->right, 2*idx+2);
    return node;
}


struct stack {
    struct TreeNode **arr;
    int capacity;
    int top; //top index
};

struct stack* create_stack(int capacity) {
    struct stack *stack_ins = (struct stack*) malloc (sizeof(struct stack));
    if (!stack_ins) {
        return NULL;
    }
    stack_ins->arr = (struct TreeNode **) malloc (sizeof(struct TreeNode*) * capacity);
    if (!stack_ins->arr) {
        return NULL;
    }
    stack_ins->capacity = capacity;
    stack_ins->top = -1; //no items
    return stack_ins;
}

bool is_empty(struct stack *stack_ins) {
    if (stack_ins->top == -1)
        return true;
    return false;
}

bool is_full(struct stack *stack_ins) {
    if (stack_ins->top == (stack_ins->capacity - 1))
        return true;
    return false;
}

struct stack* resize_stack(struct stack *stack_ins, int capacity) {
    stack_ins->arr = (struct TreeNode **) realloc (stack_ins->arr, sizeof(struct TreeNode*) * capacity);
    if (!stack_ins->arr) {
        return NULL;
    }
    stack_ins->capacity = capacity;
    return stack_ins;
}

void push(struct stack *stack_ins, struct TreeNode *data) {
    if (is_full(stack_ins)) { //reached MAX capacity, resize or could return error
        stack_ins = resize_stack(stack_ins, stack_ins->capacity*2);
        if (!stack_ins)
            return;
    }
    stack_ins->top++;
    stack_ins->arr[stack_ins->top] = data;
}

struct TreeNode* pop (struct stack *stack_ins) {
    struct TreeNode* data = NULL;
    if (!is_empty(stack_ins)) {
        data = stack_ins->arr[stack_ins->top];
        stack_ins->top--;
    }
    return data;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int *inorder_arr = NULL;
    int ret = *returnSize;
    struct stack *inorder_st = create_stack(10);
    if (!inorder_st)
        return NULL;
    while(root || !is_empty(inorder_st)){
        if (root){
            push(inorder_st, root);
            root = root->left;
        } else {
            struct TreeNode *tmp = pop(inorder_st);
            printf("(%d)%d-->", ret, tmp->val);
            ++ret;
            inorder_arr = realloc(inorder_arr, ret*sizeof(int));
            inorder_arr[ret-1] = tmp->val;
            root = tmp->right;
        } 
    }
    printf("\n");
    *returnSize = ret;
    free(inorder_st->arr);
    free(inorder_st);
    return inorder_arr;
}


int main() {

    struct TreeNode *tree = NULL;
    tree = insertTree(tree, 34);
    tree = insertTree(tree, 36);
    tree = insertTree(tree, 37);
    tree = insertTree(tree, 39);
    tree = insertTree(tree, 48);
    tree = insertTree(tree, 49);
    tree = insertTree(tree, 50);
    tree = insertTree(tree, 52);
    tree = insertTree(tree, 53);
    tree = insertTree(tree, 54);
    tree = insertTree(tree, 59);
    printf("Tree: ");
    printTree(tree);
    printf("\n");
    int tree_arr[] =
{37,-34,-48,INT_MAX,-100,-100,48,INT_MAX,INT_MAX,INT_MAX,INT_MAX,-54,INT_MAX,-71,-22,INT_MAX,INT_MAX,INT_MAX,8};
    struct TreeNode *newTree = arrToTreeRecur(tree_arr, 21, NULL, 0);
    printf("NewTree: ");
    printTree(newTree);
    printf("\n");
    int size = 0;
    int *arr = inorderTraversal(newTree, &size);
    printf("ReturnSize: %d\n", size);
    for (int i = 0; i< size; i++)
        printf("%d-->", arr[i]);
    printf("\n");
     
    return 0;
}
