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
    if (root->valeur > d)
    {
        if (root->gauche == nullptr)
        {
            root->gauche = new node(d);
        }
        else
        {
            Insert(d, root->gauche);
        }
    }
    else if (root->valeur < d)
    {
        if (root->droit == nullptr)
        {
            root->droit = new node(d);
        }
        else
        {
            Insert(d, root->droit);
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
    if(root->valeur == d)
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
    if (newRoot->gauche != nullptr && newRoot->gauche->valeur == d)
    {
        vector<int> valueArray;
        valueArray = GetLowerNodesValues(valueArray, newRoot->gauche);
        newRoot->gauche = nullptr;

        for (int i = 0; i < valueArray.size(); ++i)
        {
            Insert(valueArray[i]);
        }
    }
    else
        if (newRoot->droit != nullptr && newRoot->droit->valeur == d)
        {
            vector<int> valueArray;
            valueArray = GetLowerNodesValues(valueArray, newRoot->droit);
            newRoot->droit = nullptr;

            for (int i = 0; i < valueArray.size(); ++i)
            {
                Insert(valueArray[i]);
            }
        }
        else
            if (newRoot->gauche != nullptr && newRoot->gauche->valeur < d)
            {
                Delete(d, newRoot->gauche);
            }
            else
                if (newRoot->droit != nullptr && newRoot->droit->valeur > d)
                {
                    Delete(d, newRoot->droit);
                }
                else
                {
                    cout << "The value is not in the tree, the value cannot be deleted\n";
                }

    root = newRoot;
}


vector<int> BST::GetLowerNodesValues(vector<int> values, node *root)
{
    if (root->gauche != nullptr)
    {
        values.push_back(root->gauche->valeur);
        values = GetLowerNodesValues(values, root->gauche);
    }

    if (root->droit != nullptr )
    {
        values.push_back(root->droit->valeur);
        values = GetLowerNodesValues(values, root->droit);
    }

    if(root->droit == nullptr && root->gauche == nullptr)
        delete root;

    return values;
}

void BST::Show_Tree()
{

}

int BST::Show_Height()
{

    return 0;
}

void BST::Show_Uppers(int d)
{

}

void BST::Archive ()
{

}