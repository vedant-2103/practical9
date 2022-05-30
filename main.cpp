#include <iostream>
#include <string>
#include <stack>
#include "PrefixToInfix.h"

int main()
{
    std::string input;
    std::getline(std::cin, input);

    PrefixToInfix op;
    std::string out = op.prefixtoinfix(input);
    std::cout << out << std::endl;
    return 0;
}