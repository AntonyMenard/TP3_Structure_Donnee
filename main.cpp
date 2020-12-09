#include <iostream>
#include <string>
#include "BST.h"


using namespace std;

void DoCommand();

string userInput;
BST bst(nullptr);

int main() {
    std::cout << "Write one of the following commands:\n\n"
                 "I,d to insert an element of d value in the binary search tree. \n"
                 "S,d to delete the element of d value in the binary search tree. \n"
                 "A to show the elements level by level in the binary search tree. \n"
                 "H to show the height of the binary search tree.\n"
                 "G,d to show the uppers of the node of d value.\n"
                 "T to archive the binary search tree in a text file in sequential implementation.\n"
                 << std::endl;
while (true)
{
    getline(cin, userInput);

    DoCommand();
}


    return 0;
}

void DoCommand()
{
    int nodeValue = 0;

    if (userInput.length() >= 3)
        nodeValue = std::stoi(userInput.substr(2));

    if (userInput.at(0) == 'I')
    {
        bst.Insert(nodeValue);
        cout << "insert, " + to_string(nodeValue) + "\n";
    }
    else
        if (userInput.at(0) == 'S')
        {
            bst.Delete(nodeValue);
            cout << "delete, " + to_string(nodeValue) + "\n";
        }
        else
            if (userInput.at(0) == 'A')
            {
                bst.Show_Tree();
                cout << "show tree\n";
            }
            else
                if (userInput.at(0) == 'H')
                {
                    bst.Show_Height();
                    cout << "show height\n";
                }
                else
                    if (userInput.at(0) == 'G')
                    {
                        bst.Show_Uppers(nodeValue);
                        cout << "show upper nodes, " + to_string(nodeValue) + "\n";
                    }
                    else
                        if (userInput.at(0) == 'T')
                        {
                            bst.Archive();
                            cout << "archive\n";
                        }
}