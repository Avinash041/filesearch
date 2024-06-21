#include <iostream>
#include "searchFile.h"

int main(int argv, char* argc[])
{
    std::string filename;
    std::string dirToSearch;

    if (argv < 2)
    {
        std::cout << "No file name is given" << std::endl;
        return 0;
    }

    switch(argv)
    {
        case 1:
            std::cout << "No filename and directory is given" << std::endl;
            return 0;
        case 2:
            std::cout << "No directory name is given. Searching in current directory" << std::endl;
            filename = argc[1];
            dirToSearch = "./";
            searchFile(filename, dirToSearch);
            break;
        case 3:
            filename = argc[1];
            dirToSearch = argc[2]; 
            std::cout << "Searching " << filename << " in " << dirToSearch << std::endl;
            searchFile(filename, dirToSearch);
            break;
        default:
            std::cout << "Search in multiple directories not supported yet" << std::endl;
            return 0;

    }
}