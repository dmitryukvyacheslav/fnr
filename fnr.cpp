#include <iostream>
#include "Model.h"

int main(int argc, char* argv[]) 
{
    if (argc != 1 && argc != 3) {
        std::cout << "Usage: fnr.exe <input=input.txt> <output=output.txt>\n";
        return 0;
    }
    Model* mdl;
    argc == 3 ?
        mdl = new Model(
            std::string(argv[1]), 
            std::string(argv[2])
        ):
        mdl = new Model(
            std::string("./input.txt"), 
            std::string("./output.txt")
        );
    mdl->write();
    return 0;
    

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
