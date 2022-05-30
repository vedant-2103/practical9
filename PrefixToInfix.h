#ifndef PREFIXTOINFIX_H
#define PREFIXTOINFIX_H
#include <iostream>
#include <string>

class PrefixToInfix
{
    public:
    std::string prefixtoinfix(std::string prompt);
    
    private:
    bool OperatorOrNot(std::string symbol);
};

#endif
