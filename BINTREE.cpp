#include <iostream>
using namespace std;

struct Node
{
    Node* head = NULL;
    int data;
    Node* left = NULL;
    Node* right = NULL;
};

class Bin_Tree {
    Node* node;
    int size = 0;
public:
    Node* create(Node* head, Node*& nodes, int in, int& j) {

        if (in <= 0) { return NULL; }
        nodes = new Node;
        nodes->head = head;
        nodes->data = ++j;
        in--;
        create(nodes, nodes->left, in, j);
        create(nodes, nodes->right, in, j);


        return nodes;
    }
    Bin_Tree(int in) {
        create(NULL, node, in, size);
    }

    Node* getNode() {
        return node;
    }
    int sumq() {
        int res = sumqq(Bin_Tree::node);
        return res;
    }
    int sumqq(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        int result1 = sumqq(node->left);
        int result2 = sumqq(node->right);
        int resultitog = node->data + result1 + result2;
        return resultitog;
    }
    void print(ostream& ost, Node* node) {
        ost << node->data << endl;
        if (node->left != NULL) {
            print(ost, node->left);
        }
        if (node->right != NULL) {
            print(ost, node->right);
        }
    }
    friend ostream& operator<< (ostream& ost, Bin_Tree& bt) {
        bt.print(ost, bt.node);
        return ost;
    }
};

int main()
{
    Bin_Tree BT(3);
    cout << BT;
    cout << "summa: " << BT.sumq();
    
}
