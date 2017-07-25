#include <iostream>
#include "analyse.h"


int main(int argc, char **argv)
{
    int ret;

    std::cout << "** TEST DEPENDANCY LOAD **" << std::endl;

    if(argc < 3)
    {
        std::cout << "usage: test_dep input_file output_file" << std::endl;
        return -1;
    }

    std::cout << "analyse(\"" << argv[1] << "\",\"" << argv[2] << "\") ... " << std::endl;
    ret=analyse(argv[1],argv[2]);
    if(!ret)
        std::cout << "Correct!" << std::endl;
    else
        std::cout << "ERROR: " << ret << std::endl;

    return ret;
}