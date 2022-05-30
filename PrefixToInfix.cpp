#include "PrefixToInfix.h"
#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <vector>


bool PrefixToInfix::OperatorOrNot(std::string symbol)
{
    if ((symbol == "/") || (symbol == "*") || (symbol == "+") || (symbol == "-"))
    {
        return true;
    }
    else
    {
        return false;
    }
}

std::string PrefixToInfix::prefixtoinfix(std::string prompt)
{
    std::vector<std::string> list = {};

    std::stringstream inputline;
    inputline << prompt;
    std::string empty_line;

    while (!inputline.eof())
    {
        inputline >> empty_line;
        list.push_back(empty_line);
    }

    std::stack<std::string> line;
    std::stack<std::string> val;
    int string_length = list.size();

    for (int i=string_length-1; i >= 0; i--)
    {
        if (OperatorOrNot(list[i]) == true)
        {
            if (line.size() < 1)
            {
                return "Error";
            }
            std::string operator1 = line.top();
            std::string operand1 = val.top();
            line.pop();
            val.pop();
            if (line.size() < 1)
            {
                return "Error";
            }

            std::string operator2 = line.top();
            line.pop();
            std::string operand2 = val.top();
            val.pop();

            std::string temp = "(" + operator1 + " " + list[i] + " " + operator2 + ")";
            line.push(temp);

            if (list[i] == "+")
            {
                val.push(std::to_string(stoi(operand1) + stoi(operand2)));
            }
            else if (list[i] == "-")
            {
                val.push(std::to_string(stoi(operand1) - stoi(operand2)));
            }
            else if (list[i] == "*")
            {
                val.push(std::to_string(stoi(operand1) * stoi(operand2)));
            }
            else
            {
                if (stoi(operand2) == 0)
                {
                    return "Error";
                }
                val.push(std::to_string(stoi(operand1) / stoi(operand2)));
            }
        }
        else
        {
            if (stoi(list[i]) > 99 || stoi(list[i]) < 0)
            {
                return "Error";
            }
            line.push(list[i]);
            val.push(list[i]);
        }
    }
    if (line.size() != 1)
    {
        return "Error";
    }
    else
    {
        std::string temp = line.top();
        if (temp[0] == '(')
        {
            temp = temp.substr(1, temp.size() - 2);
        }
        if (temp == "")
        {
            return "";
        }
        return temp + " = " + val.top();
        return temp;
    }
}
