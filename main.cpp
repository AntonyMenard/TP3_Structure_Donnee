#include <iostream>
#include <string>

using namespace std;

string userInput;

int main() {
    std::cout << "Write one of the following commands:\n\n"
                 "I,d to insert an element of d value in the binary search tree. \n"
                 "S,d to delete the element of d value in the binary search tree. \n"
                 "A to show the elements level by level in the binary search tree. \n"
                 "H to show the height of the binary search tree.\n"
                 "G,d pour afficher les ascendants du nœud de valeur d.\n"
                 "G,d to show the uppers of the node of d value.\n"
                 "T to archive the binary search tree in a text file in sequential implementation.\n"
                 << std::endl;

    getline(cin, userInput);

    return 0;
}
