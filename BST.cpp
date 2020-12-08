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

void BST::Insert(node *root, int d)
{
    if (root->valeur > d)
    {
        if (root->gauche == nullptr)
        {
            root->gauche = new node(d);
        }
        else
        {
            Insert(root->gauche, d);
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
            Insert(root->droit, d);
        }   
    }
}

void BST::Delete(node *root, int d)
{

}

void BST::Show_Tree(node *root)
{

}

int BST::Show_Height(node *root)
{

    return 0;
}

void BST::Show_Uppers(node *root, int d)
{

}

void BST::Archive (node *root)
{

}