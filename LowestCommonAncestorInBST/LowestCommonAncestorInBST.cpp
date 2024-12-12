// LowestCommonAncestorInBST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include <vector>

class Node
{
public:
    Node* left;
    Node* right;
    int data;

    Node(int d)
        : data(d)
        , left(nullptr)
        , right(nullptr)
    {
    }
};

Node* ArrayToTree(const std::vector<int>& v)
{
    if (v.size() == 0)
        return nullptr;
    Node* root = new Node(v[0]);
    std::queue<Node*> q;
    q.push(root);
    bool l = true;
    for (size_t i = 1; i < v.size(); ++i, l = !l)
    {
        Node* pNode = q.front();
        if (!l)
            q.pop();
        if (v[i] != -1)
        {
            if (l)
            {
                pNode->left = new Node(v[i]);
                q.push(pNode->left);
            }
            else
            {
                pNode->right = new Node(v[i]);
                q.push(pNode->right);
            }
        }
    }

    return root;
}

void FreeTree(Node* pNode)
{
    if (pNode == nullptr)
        return;

    FreeTree(pNode->left);
    FreeTree(pNode->right);

    delete pNode;
}

Node* Find(Node* pNode, int n)
{
    if (pNode == nullptr)
        return nullptr;

    if (pNode->data == n)
        return pNode;

    if (n < pNode->data)
        return Find(pNode->left, n);

    return Find(pNode->right, n);
}

Node* Find(Node* pNode, Node* p)
{
    if (pNode == nullptr)
        return nullptr;

    if (pNode == p)
        return pNode;

    if (p->data < pNode->data)
        return Find(pNode->left, p);

    return Find(pNode->right, p);
}

Node* CommonAncestor(Node* pNode, Node* pSmaller, Node* pLarger)
{
    if (pNode == nullptr)
        return nullptr;

    if (pLarger->data < pNode->data)
        return CommonAncestor(pNode->left, pSmaller, pLarger);

    if (pLarger->data == pNode->data)
        if (Find(pNode->left, pSmaller))
            return pNode;
    if (pSmaller->data == pNode->data)
        if (Find(pNode->right, pLarger))
            return pNode;

    if (pSmaller->data > pNode->data)
        return CommonAncestor(pNode->right, pSmaller, pLarger);

    if (Find(pNode->left, pSmaller) && Find(pNode->right, pLarger))
        return pNode;

    return nullptr;
}

Node* LowestCommonAncestor(Node* root, Node* p, Node* q)
{
    Node* pSmaller = nullptr;
    Node* pLarger = nullptr;
    if (p->data < q->data)
    {
        pSmaller = p;
        pLarger = q;
    }
    else
    {
        pSmaller = q;
        pLarger = p;
    }

    return CommonAncestor(root, pSmaller, pLarger);
}

int main()
{
    while (true)
    {
        std::cout << "Number of nodes in the tree: ";
        int count = 0;
        std::cin >> count;
        if (count == 0)
            break;

        std::cout << "Values of the tree nodes: ";
        std::vector<int> v(count, 0);
        for (int i = 0; i < count; ++i)
            std::cin >> v[i];

        std::cout << "The indexes of the two nodes to find ancestor of: ";
        int pv = 0, qv = 0;
        std::cin >> pv >> qv;
        if (pv >= count || qv >= count)
        {
            std::cout << "There are only " << count << " nodes!" << std::endl;
            continue;
        }

        Node* root = ArrayToTree(v);

        Node* p = Find(root, v[pv]);
        Node* q = Find(root, v[qv]);

        Node* pNode = LowestCommonAncestor(root, p, q);
        std::cout << "The lowest ancester is: " << (pNode ? pNode->data : -1) << std::endl;
        FreeTree(root);
    }
}
