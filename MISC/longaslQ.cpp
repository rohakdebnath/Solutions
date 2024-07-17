#include <stdio.h>
#include <stdlib.h>

#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define min(a, b) ((a) > (b) ? (b) : (a))

const int MAX = 1001;

typedef struct treenode* BTptr;
typedef struct treenode {int num1; int num2; BTptr left; BTptr right; } BT;

typedef struct qnode* QNodeptr;
typedef struct qnode {
    BTptr node;
    QNodeptr next;
} QNode;

// Queue Operations
QNodeptr makeQNode(BTptr node) {
    QNodeptr newQNode = (QNodeptr)malloc(sizeof(QNode));
    newQNode->node = node;
    newQNode->next = NULL;
    return newQNode;
}

QNodeptr enqueue(QNodeptr rear, BTptr node) {
    QNodeptr newQNode = makeQNode(node);
    if (rear != NULL) {
        rear->next = newQNode;
    }
    return newQNode;
}

QNodeptr dequeue(QNodeptr* front) {
    if (*front == NULL) {
        return NULL;
    }
    QNodeptr temp = *front;
    *front = (*front)->next;
    return temp;
}

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

BTptr maketreenode(int x, int y) {
    BTptr newnode = (BTptr)malloc(sizeof(BT));
    if (x > y) swap(&x, &y);
    // if (x == -1 && y == -1) x = MAX, y = MAX;
    newnode->num1 = x;
    newnode->num2 = y;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

// Main Tree Construction Function
BTptr maketree() {
    int N; scanf("%d", &N);

    BTptr head = NULL;
    QNodeptr front = NULL, rear = NULL;

    rep(i, 0, N) {
        int x, y; scanf("%d%d", &x, &y);
        BTptr newNode = maketreenode(x, y);

        if (head == NULL) { // First node is always the head of the tree
            head = newNode;
        } else {
            while (front != NULL && front->node->left != NULL && front->node->right != NULL) {
                QNodeptr temp = dequeue(&front);
                free(temp);
            }

            if (front != NULL) {
                if (front->node->left == NULL) {
                    front->node->left = newNode;
                } else if (front->node->right == NULL) {
                    front->node->right = newNode;
                }
            }
        }

        // Enqueue the new node for its future children
        if (rear == NULL) {
            front = rear = enqueue(rear, newNode);
        } else {
            rear = enqueue(rear, newNode);
        }
    }

    return head;
}

int findmin(BTptr currnode) {
    if (currnode == NULL || currnode ->num1 == -1) return MAX;
    // if (currnode == NULL) return MAX;
    int mini = min(currnode->num2, min(findmin(currnode->left), findmin(currnode->right)));
    return mini;
}

int main() {
    BTptr root = maketree();
    int ans = findmin(root);
    printf("%d\n", ans);
    return 0;
}
