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
    vector<int> nodeValues;
    nodeValues.push_back(d);
    if (root == nullptr || root->value == d)
        cout << "There is no value above\n";
    else
    {
        nodeValues = Get_Uppers(root, nodeValues);

        if (nodeValues.size() != 1)
        {
            reverse(nodeValues.begin(), nodeValues.end());
            cout << "The values above your input, from top to bottom of the tree, are such:\n";
            for (int i = 0; i < nodeValues.size(); ++i)
            {
                cout << to_string(nodeValues[i]) + ", ";
            }
            cout << "\n";
        }
        else
            cout << "The value does not exist in the tree\n";
    }
}

vector<int> BST::Get_Uppers(node *currentRoot, vector<int> nodeValues)
{
    if (currentRoot->left == nullptr && currentRoot->right == nullptr)
        return nodeValues;

    if (currentRoot->left != nullptr && currentRoot->left->value == nodeValues[nodeValues.size() - 1])
    {
        nodeValues.push_back(currentRoot->value);
        return nodeValues;
    }
    else
        if (currentRoot->right != nullptr && currentRoot->right->value == nodeValues[nodeValues.size() - 1])
        {
            nodeValues.push_back(currentRoot->value);
            return nodeValues;
        }

    if (currentRoot->value > nodeValues[nodeValues.size() - 1])
        nodeValues = Get_Uppers(currentRoot->left, nodeValues);
    else
        if (currentRoot->value < nodeValues[nodeValues.size() - 1])
            nodeValues = Get_Uppers(currentRoot->right, nodeValues);

    if (currentRoot->left != nullptr && currentRoot->left->value == nodeValues[nodeValues.size() - 1])
    {
        nodeValues.push_back(currentRoot->value);
    }
    else
        if (currentRoot->right != nullptr && currentRoot->right->value == nodeValues[nodeValues.size() - 1])
        {
            nodeValues.push_back(currentRoot->value);
        }

    return  nodeValues;
}

void BST::Archive ()
{

}