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

void BST::Delete(int d)
{

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