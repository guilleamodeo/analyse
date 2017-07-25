#include <dlfcn.h>
#include <iostream>

typedef int (*analyse_t)(const char *,const char *);


int main(int argc, char **argv)
{
    int ret;
    void *lib;
    analyse_t analyse;

    std::cout << "** TEST DYNAMIC LOADING **" << std::endl;

    if(argc < 3)
    {
        std::cout << "usage: test_dep input_file output_file" << std::endl;
        return -1;
    }

    lib = dlopen("./libAnalyse.A.dylib", RTLD_NOW);
    if (!lib)
    {
        std::cout << "ERROR loading library" << std::endl;
        return -1;
    }

    analyse=(analyse_t)dlsym(lib, "analyse");
    if (!analyse)
    {
        dlclose(lib);
        std::cout << "ERROR finding the function analyse()" << std::endl;
        return -1;
    }

    std::cout << "analyse(\"" << argv[1] << "\",\"" << argv[2] << "\") ... " << std::endl;
    ret=analyse(argv[1],argv[2]);
    if(!ret)
        std::cout << "Correct!" << std::endl;
    else
        std::cout << "ERROR: " << ret << std::endl;
    dlclose(lib);
    return ret;
}

