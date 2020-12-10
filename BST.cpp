//
// Created by Antony M�nard and Nicolas Bisson on 2020-12-07.
//
#include "BST.h"
#include <math.h>
#include <iostream>
#include <fstream>

BST::BST (node *root)
{

}

BST::~BST( )
{

}

//Permet d'ins�rer une valeur dans l'arbre
void BST::Insert(int d)
{
    //Si l'arbre ne poss�de pas de racine, la valeur est plac� � celle-ci
    if (root == nullptr)
        root = new node(d);
    else
        Insert(d, root);
}

//Permet de chercher r�cursivement pour la position ou la valeur doit �tre ins�r�e dans l'arbre et effectue l'insertion
void BST::Insert(int d, node *root)
{
    //V�rifie si la valeur a ins�r�e est plus petite ou plus grande que la valeur de la node courante
    if (root->value > d)
    {
        //Dans le cas o� elle est plus petite
        //Si il n'y a pas de valeur � gauche, la valeur va �tre ins�r� � cette position
        //Sinon cette fonction est r�ex�cut� � la node de gauche
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
        //Dans le cas o� elle est plus grande
        //Si il n'y a pas de valeur � droite, la valeur va �tre ins�r� � cette position
        //Sinon cette fonction est r�ex�cut� � la node de droite
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

//Permet d'afficher l'arbre dans la console
void BST::Show_Tree()
{
    //Contient le nombre de niveau dans l'arbre
    int height = Show_Height();
    //Contient le nombre maximal d'�l�ment contenu dans l'arbre selon le nombre de niveau
    int treeMaxSize = 0;
    for (int i = 0; i < height; i++)
    {
        treeMaxSize += pow(2, i);
    }
    //Contient tous les valeurs de l'arbre, si la valeur est -1
    int* treeContent = new int[treeMaxSize];

    //Initie les valeurs du tableau
    for (int i = 0; i < treeMaxSize; i++)
    {
        treeContent[i] = -1;
    }

    //G�n�re le tableau � l'aide de l'arbre
    Add_Tree_Element_To_Array(treeContent, root, 1, 1);

    //Indique la hauteur de l'�l�ment ajout� � la console
    int currentHeight = 1;

    //Ajoute le nombre d'espace n�cessaire pour positionner la racine au centre de l'arbre affich� � la console
    for (int i = 1; i < pow(2, height - currentHeight); i++)
    {
        cout << " ";
    }

    //Affiche le tableau sous format d'arbre � la console
    for (int i = 0; i < treeMaxSize; i++)
    {
        //Affiche la valeur courante � l'�cran si elle n'est pas nulle
        if (treeContent[i] != -1)
            cout << treeContent[i];
        else
            cout << " ";

        //Ajoute le nombre d'espace n'�cessaire entre les valeurs du niveau courant
        for (int i = 1; i < pow(2, height - currentHeight + 1); i++)
        {
            cout << " ";
        }

        //Effectue le changement de niveau lorsque n�cessaire
        if (i == pow(2, currentHeight) - 2)
        {
            cout << endl;
            currentHeight++;
            //Ajoute le nombre d'espace n�cessaire au d�but du niveau
            for (int i = 1; i < pow(2, height - currentHeight); i++)
            {
                cout << " ";
            }
        }
    }
}

//G�n�re le tableau r�cursivement � l'aide de l'arbre
void BST::Add_Tree_Element_To_Array(int* treeContent, node* root, int currentHeight, int levelPosition)
{
    //Ajoute la valeur courante au tableau
    treeContent[(int)pow(2, currentHeight - 1) + levelPosition - 2] = root->value;
    //Si il y a une valeur � gauche et/ou � droite appel cette fonction pour cette/ces node
    if (root->left != nullptr)
        Add_Tree_Element_To_Array(treeContent, root->left, currentHeight + 1, levelPosition * 2 - 1);
    if (root->right != nullptr)
        Add_Tree_Element_To_Array(treeContent, root->right, currentHeight + 1, levelPosition * 2);
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
    else if (currentRoot->right != nullptr && currentRoot->right->value == nodeValues[nodeValues.size() - 1])
    {
        nodeValues.push_back(currentRoot->value);
        return nodeValues;
    }

    if (currentRoot->value > nodeValues[nodeValues.size() - 1])
        nodeValues = Get_Uppers(currentRoot->left, nodeValues);
    else if (currentRoot->value < nodeValues[nodeValues.size() - 1])
        nodeValues = Get_Uppers(currentRoot->right, nodeValues);

    if (currentRoot->left != nullptr && currentRoot->left->value == nodeValues[nodeValues.size() - 1])
        nodeValues.push_back(currentRoot->value);
    else if (currentRoot->right != nullptr && currentRoot->right->value == nodeValues[nodeValues.size() - 1])
        nodeValues.push_back(currentRoot->value);

    return  nodeValues;
}

//Permet de conserver l'arbre en impl�mentation s�quentielle dans un fichier texte
void BST::Archive ()
{
    //Permet de contenir l'impl�mentation s�quentielle � ajouter au fichier
    string *archive = new string();
    *archive = "";
    
    //Cr�e l'impl�mentation s�quentielle si il y a une racine
    if (root != nullptr)
        Generate_Archive(archive, root);

    //Supprime et cr�� le fichier texte afin qu'il soit vide avant d'�crire
    remove("../../../Fichier-Arbre.txt");
    ofstream fichierArbre("../../../Fichier-Arbre.txt");

    //Si le fichier est ouvert, ajoute l'impl�mentation s�quentielle de l'arbre dans celui-ci
    if (!fichierArbre.fail())
        fichierArbre << *archive;

    fichierArbre.close();
}

//Permet de g�n�rer r�cursivement l'impl�mentation s�quentielle de l'arbre dans un pointer de string
//Des espaces sont ajout�es apr�s les valeurs afin d'indiquer o� les chiffres finissent
void BST::Generate_Archive(string *archive, node *root)
{
    //Ajoute la valeur courante � la string archive
    *archive += to_string(root->value) + " ";

    //Appelle cette fonction sur la prochaine node de droite et gauche si elles existent
    //Sinon la valeur "/" est ajout� � l'impl�mentation s�quentielle
    if (root->left != nullptr)
        Generate_Archive(archive, root->left);
    else
        *archive += "/ ";

    if (root->right != nullptr)
        Generate_Archive(archive, root->right);
    else
        *archive += "/ ";
}
