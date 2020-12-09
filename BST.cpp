//
// Created by Antony on 2020-12-07.
//

#include "BST.h"

BST::BST (node *root)
{

}

BST::~BST( )
{

}

void BST::Insert(int d)
{
    if (root == nullptr)
        root = new node(d);
    else
        Insert(d, root);
}

void BST::Insert(int d, node *root)
{
    if (root->value > d)
    {
        if (root->left == nullptr)
        {
            root->left = new node(d);
        }
        else
        {
            Insert(d, root->left);
        }
    }
    else if (root->value < d)
    {
        if (root->right == nullptr)
        {
            root->right = new node(d);
        }
        else
        {
            Insert(d, root->right);
        }   
    }
}

void BST::Delete(int d)
{
    if (root == nullptr)
        cout << "The tree is empty, the value cannot be deleted\n";
    else
        Delete(d, root);
}

void BST::Delete(int d, node *newRoot)
{
    if(root->value == d)
    {
        vector<int> valueArray;
        valueArray = GetLowerNodesValues(valueArray, newRoot);
        newRoot = nullptr;
        root = nullptr;

        for (int i = 0; i < valueArray.size(); ++i)
        {
            Insert(valueArray[i]);
        }
    }
    else
        if (newRoot->left != nullptr && newRoot->left->value == d)
        {
            vector<int> valueArray;
            valueArray = GetLowerNodesValues(valueArray, newRoot->left);
            newRoot->left = nullptr;

            for (int i = 0; i < valueArray.size(); ++i)
            {
                Insert(valueArray[i]);
            }
        }
        else
            if (newRoot->right != nullptr && newRoot->right->value == d)
            {
                vector<int> valueArray;
                valueArray = GetLowerNodesValues(valueArray, newRoot->right);
                newRoot->right = nullptr;

                for (int i = 0; i < valueArray.size(); ++i)
                {
                    Insert(valueArray[i]);
                }
            }
            else
                if (newRoot->left != nullptr && newRoot->value > d)
                {
                    Delete(d, newRoot->left);
                }
                else
                    if (newRoot->right != nullptr && newRoot->value < d)
                    {
                        Delete(d, newRoot->right);
                    }
                    else
                    {
                        cout << "The value is not in the tree, the value cannot be deleted\n";
                    }

    if (newRoot != nullptr)
        root = newRoot;
}

vector<int> BST::GetLowerNodesValues(vector<int> values, node *root)
{
    if (root->left != nullptr)
    {
        values.push_back(root->left->value);
        values = GetLowerNodesValues(values, root->left);
    }

    if (root->right != nullptr )
    {
        values.push_back(root->right->value);
        values = GetLowerNodesValues(values, root->right);
    }

    if(root->right == nullptr && root->left == nullptr)
        delete root;

    return values;
}

void BST::Show_Tree()
{

}

int BST::Show_Height()
{
    return Get_Height(root);
}

int BST::Get_Height(node* root)
{
    if (root == nullptr)
    {
        return 0;
    }
    else
    {
        int leftHeight = Get_Height(root->left);
        int rightHeight = Get_Height(root->right);

        if (leftHeight > rightHeight)
            return(leftHeight + 1);
        else return(rightHeight + 1);
    }
}

void BST::Show_Uppers(int d)
{

}

void BST::Archive ()
{

}