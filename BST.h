//
// Created by Antony on 2020-12-07.
//
#include "node.h"

#ifndef TP3_STRUCTURE_DONNEE_BST_H
#define TP3_STRUCTURE_DONNEE_BST_H


class BST {
private:
    node *root; // La racine de l’arbre binaire de recherche.
public:
    BST (node *root);                    // Construit l’arbre dont la racine est à l’adresse racine.
    ~BST( );                               // Supprime l’espace mémoire occupé par l’arbre dont la racine est à l’adresse racine.
    void Insert(int d);        // insère le nœud de valeur d dans l’arbre.
    void Delete(int d);        // Supprime le nœud de valeur d de l’arbre.
    void Show_Tree();            //Affiche les éléments de l’arbre niveau par niveau.
    int Show_Height();           //Affiche la hauteur de l’arbre.
    void Show_Uppers(int d);   // Affiche les ascendants du nœud de valeur d.
    void Archive ();            // Archiver en implémentation séquentielle l’arbre dont la racine est
                                           //dans un fichier texte que vous allez définir.
};


#endif //TP3_STRUCTURE_DONNEE_BST_H
