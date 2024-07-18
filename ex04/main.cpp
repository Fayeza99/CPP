#include "Replace.hpp"


int main(int argc, char **argv)
{
    if (argc != 4 || argv[1][0] == '\0' || argv[2][0] == '\0' || argv[3][0] == '\0') {
        std::cerr << "Program needs parameters" << std::endl;
        return 1;
    }

    std::string file_name = argv[1];
    std::string search_str = argv[2];
    std::string replace_str = argv[3];

    Replace replacer(file_name, search_str, replace_str);
    if (!replacer.replaceInFile())
	{
        return 1;
    }

    return 0;
}