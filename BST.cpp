//
// Created by Antony Ménard and Nicolas Bisson on 2020-12-07.
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

//Permet d'insérer une valeur dans l'arbre
void BST::Insert(int d)
{
    //Si l'arbre ne possède pas de racine, la valeur est placé à celle-ci
    if (root == nullptr)
        root = new node(d);
    else
        Insert(d, root);
}

//Permet de chercher récursivement pour la position ou la valeur doit être insérée dans l'arbre et effectue l'insertion
void BST::Insert(int d, node *root)
{
    //Vérifie si la valeur a insérée est plus petite ou plus grande que la valeur de la node courante
    if (root->value > d)
    {
        //Dans le cas où elle est plus petite
        //Si il n'y a pas de valeur à gauche, la valeur va être inséré à cette position
        //Sinon cette fonction est réexécuté à la node de gauche
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
        //Dans le cas où elle est plus grande
        //Si il n'y a pas de valeur à droite, la valeur va être inséré à cette position
        //Sinon cette fonction est réexécuté à la node de droite
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

//Supprime une valeur
void BST::Delete(int d)
{
    if (root == nullptr)    //S'assure que l'arbre n'est pas nul
        cout << "The tree is empty, the value cannot be deleted\n";
    else
        Delete(d, root);    //Commence la récursivité
}

//Supprime une valeur
void BST::Delete(int d, node *newRoot)
{
    if(root->value == d)    //Si la valeur est trouvé, supprime les éléments en dessous et les réinsert dans l'arbre
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
    else    //Si la valeur est trouvé à gauche, supprime les éléments en dessous et les réinsert dans l'arbre
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
        else    //Si la valeur est trouvé à droite, supprime les éléments en dessous et les réinsert dans l'arbre
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
            else    //Continue la récursivité à gauche
                if (newRoot->left != nullptr && newRoot->value > d)
                {
                    Delete(d, newRoot->left);
                }
                else    //Continue la récursivité à droite
                    if (newRoot->right != nullptr && newRoot->value < d)
                    {
                        Delete(d, newRoot->right);
                    }
                    else
                    {
                        cout << "The value is not in the tree, the value cannot be deleted\n";
                    }

    if (newRoot != nullptr)
        root = newRoot;         //Met à jour la variable globale
}

//Cherche les valeurs en dessous de celle passée en paramètre et les supprime
vector<int> BST::GetLowerNodesValues(vector<int> values, node *root)
{
    if (root->left != nullptr)      //Ajoute une valeur à la liste si le prochain noeud n'est pas nul à gauche
    {
        values.push_back(root->left->value);
        values = GetLowerNodesValues(values, root->left);
    }

    if (root->right != nullptr )    //Ajoute une valeur à la liste si le prochain noeud n'est pas nul à droite
    {
        values.push_back(root->right->value);
        values = GetLowerNodesValues(values, root->right);
    }

    if(root->right == nullptr && root->left == nullptr) //supprime la valeur en arrivant à la fin d'une branche
        delete root;

    return values;
}

//Permet d'afficher l'arbre dans la console
void BST::Show_Tree()
{
    //Contient le nombre de niveau dans l'arbre
    int height = Show_Height();
    //Contient le nombre maximal d'élément contenu dans l'arbre selon le nombre de niveau
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

    //Génére le tableau à l'aide de l'arbre
    Add_Tree_Element_To_Array(treeContent, root, 1, 1);

    //Indique la hauteur de l'élément ajouté à la console
    int currentHeight = 1;

    //Ajoute le nombre d'espace nécessaire pour positionner la racine au centre de l'arbre affiché à la console
    for (int i = 1; i < pow(2, height - currentHeight); i++)
    {
        cout << " ";
    }

    //Affiche le tableau sous format d'arbre à la console
    for (int i = 0; i < treeMaxSize; i++)
    {
        //Affiche la valeur courante à l'écran si elle n'est pas nulle
        if (treeContent[i] != -1)
            cout << treeContent[i];
        else
            cout << " ";

        //Ajoute le nombre d'espace n'écessaire entre les valeurs du niveau courant
        for (int i = 1; i < pow(2, height - currentHeight + 1); i++)
        {
            cout << " ";
        }

        //Effectue le changement de niveau lorsque nécessaire
        if (i == pow(2, currentHeight) - 2)
        {
            cout << endl;
            currentHeight++;
            //Ajoute le nombre d'espace nécessaire au début du niveau
            for (int i = 1; i < pow(2, height - currentHeight); i++)
            {
                cout << " ";
            }
        }
    }
}

//Génére le tableau récursivement à l'aide de l'arbre
void BST::Add_Tree_Element_To_Array(int* treeContent, node* root, int currentHeight, int levelPosition)
{
    //Ajoute la valeur courante au tableau
    treeContent[(int)pow(2, currentHeight - 1) + levelPosition - 2] = root->value;
    //Si il y a une valeur à gauche et/ou à droite appel cette fonction pour cette/ces node
    if (root->left != nullptr)
        Add_Tree_Element_To_Array(treeContent, root->left, currentHeight + 1, levelPosition * 2 - 1);
    if (root->right != nullptr)
        Add_Tree_Element_To_Array(treeContent, root->right, currentHeight + 1, levelPosition * 2);
}

//Montre la taille de l'arbre
int BST::Show_Height()
{
    return Get_Height(root);
}

//Calcule la taille de l'arbre
int BST::Get_Height(node* root)
{
    if (root == nullptr)
        return 0;   //Teste si la taille est 0
    else
    {
        int leftHeight = Get_Height(root->left);    //Calcule la taille des branches de gauche
        int rightHeight = Get_Height(root->right);    //Calcule la taille des branches de droite

        if (leftHeight > rightHeight)
            return(leftHeight + 1);
        else return(rightHeight + 1);
    }
}

//Affiche les valeurs au dessus de celle écrite par l'utilisateur
void BST::Show_Uppers(int d)
{
    vector<int> nodeValues;
    nodeValues.push_back(d);
    if (root == nullptr || root->value == d)    //Teste s'il y a des valeurs au dessus
        cout << "There is no value above\n";
    else
    {
        nodeValues = Get_Uppers(root, nodeValues);

        if (nodeValues.size() != 1)
        {
            reverse(nodeValues.begin(), nodeValues.end());  //Affiche les valeurs
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

//Calcule les valeurs au dessus de celle écrite par l'utilisateur
vector<int> BST::Get_Uppers(node *currentRoot, vector<int> nodeValues)
{
    //Commence la remonté de la fonction récursive si la valeur est la dernière de sa branche
    if (currentRoot->left == nullptr && currentRoot->right == nullptr)
        return nodeValues;

    //Ajoute une valeur à la liste si elle est trouvé à gauche ou à droite
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

    //Descend plus loin dans l'arbre
    if (currentRoot->value > nodeValues[nodeValues.size() - 1])
        nodeValues = Get_Uppers(currentRoot->left, nodeValues);
    else if (currentRoot->value < nodeValues[nodeValues.size() - 1])
        nodeValues = Get_Uppers(currentRoot->right, nodeValues);

    //Ajoute une valeur à la liste si elle est trouvé à gauche ou à droite
    if (currentRoot->left != nullptr && currentRoot->left->value == nodeValues[nodeValues.size() - 1])
        nodeValues.push_back(currentRoot->value);
    else if (currentRoot->right != nullptr && currentRoot->right->value == nodeValues[nodeValues.size() - 1])
        nodeValues.push_back(currentRoot->value);

    return  nodeValues;
}

//Permet de conserver l'arbre en implémentation séquentielle dans un fichier texte
void BST::Archive ()
{
    //Permet de contenir l'implémentation séquentielle à ajouter au fichier
    string *archive = new string();
    *archive = "";
    
    //Crée l'implémentation séquentielle si il y a une racine
    if (root != nullptr)
        Generate_Archive(archive, root);

    //Supprime et créé le fichier texte afin qu'il soit vide avant d'écrire
    remove("../../../Fichier-Arbre.txt");
    ofstream fichierArbre("../../../Fichier-Arbre.txt");

    //Si le fichier est ouvert, ajoute l'implémentation séquentielle de l'arbre dans celui-ci
    if (!fichierArbre.fail())
        fichierArbre << *archive;

    fichierArbre.close();
}

//Permet de générer récursivement l'implémentation séquentielle de l'arbre dans un pointer de string
//Des espaces sont ajoutées après les valeurs afin d'indiquer où les chiffres finissent
void BST::Generate_Archive(string *archive, node *root)
{
    //Ajoute la valeur courante à la string archive
    *archive += to_string(root->value) + " ";

    //Appelle cette fonction sur la prochaine node de droite et gauche si elles existent
    //Sinon la valeur "/" est ajouté à l'implémentation séquentielle
    if (root->left != nullptr)
        Generate_Archive(archive, root->left);
    else
        *archive += "/ ";

    if (root->right != nullptr)
        Generate_Archive(archive, root->right);
    else
        *archive += "/ ";
}
