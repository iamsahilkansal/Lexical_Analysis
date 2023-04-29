#include <bits/stdc++.h>
using namespace std;

vector<string> Keyword;
vector<string> Operator;
vector<string> Variable;
vector<string> Constant;
vector<string> Special;

bool isMultiple(vector<string> a, string test)
{
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        if (a[i] == test)
        {
            return false;
        }
    }
    return true;
}

bool isKeyword(string a)
{
    if ((a == "int") || (a == "char") || (a == "float") || (a == "double") || (a == "bool") || (a == "string") ||
        (a == "using") || (a == "namespace") || (a == "string") || (a == "std") || (a == "main") || (a == "cout") ||
        (a == "cin") || (a == "include") || (a == "iostream") || (a == "for") || (a == "while") || (a == "do") || 
        (a == "struct") || (a == "auto") || (a == "break") || (a == "case") || (a == "const") || (a == "continue") || 
        (a == "if") || (a == "else") || (a == "void") || (a == "long"))
    {
        return true;
    }
    return false;
}

bool isOperator(string a)
{
    if ((a == ">") || (a == "<") || (a == "=") || (a == ">=") || (a == "<=") || (a == "+") || (a == "-") || (a == "++") ||(a == "--") ||
        (a == "==") || (a == "*") || (a == "/") || (a == "%"))
    {
        return true;
    }
    return false;
}

bool isVariable(string a)
{
    if (isalpha(a[0]) || a[0] == '_')
    {
        return true;
    }
    return false;
}

bool isConstant(string a)
{
    for (int i = 0; i < a.length(); i++)
    {
        if (!isdigit(a[i]))
        {
            return false;
        }
    }
    return true;
}

bool isSpecialSymbol(string a)
{
    if ((a == ";") || (a == ":") || (a == ",") || (a == "#") || (a == "_") || (a == "^") || (a == "{}") || (a == "[]") ||
        (a == "()") || (a == "(") || (a == ")") || (a == "}") || (a == "{") || (a == "[") || (a == "]") || (a == "|"))
    {
        return true;
    }
    return false;
}

void parse(vector<string> a)
{
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        if (isKeyword(a[i]))
        {
            if (isMultiple(Keyword, a[i]))
            {
                Keyword.push_back(a[i]);
            }
        }
        else if (isOperator(a[i]))
        {
            if (isMultiple(Operator, a[i]))
            {
                Operator.push_back(a[i]);
            }
        }
        else if (isVariable(a[i]))
        {
            if (isMultiple(Variable, a[i]))
            {
                Variable.push_back(a[i]);
            }
        }
        else if (isConstant(a[i]))
        {
            if (isMultiple(Constant, a[i]))
            {
                Constant.push_back(a[i]);
            }
        }
        else if (isSpecialSymbol(a[i]))
        {
            if (isMultiple(Special, a[i]))
            {
                Special.push_back(a[i]);
            }
        }
    }
}

void lexical_analysis()
{
    if (Keyword.size() > 0)
    {
        cout << "Keywords: " << Keyword[0];
        for (int i = 1; i < Keyword.size(); i++)
        {
            cout << ", " << Keyword[i];
        }
    }
    cout << endl;
    if (Operator.size() > 0)
    {
        cout << "Operators: " << Operator[0];
        for (int i = 1; i < Operator.size(); i++)
        {
            cout << ", " << Operator[i];
        }
    }
    cout << endl;
    if (Variable.size() > 0)
    {
        cout << "Variables: " << Variable[0];
        for (int i = 1; i < Variable.size(); i++)
        {
            cout << ", " << Variable[i];
        }
    }
    cout << endl;
    if (Constant.size() > 0)
    {
        cout << "Constants: " << Constant[0];
        for (int i = 1; i < Constant.size(); i++)
        {
            cout << ", " << Constant[i];
        }
    }
    cout << endl;
    if (Special.size() > 0)
    {
        cout << "Special Symbols: " << Special[0];
        for (int i = 1; i < Special.size(); i++)
        {
            cout << ", " << Special[i];
        }
    }
    cout << endl;
}

vector<string> substr(string a)
{
    vector<string> test;
    int n = a.length();
    string word;
    for (int i = 0; i < n; i++)
    {
        if (!isspace(a[i]))
        {
            word += a[i];
        }
        if ((isspace(a[i]) && word != "") || (i + 1) >= n)
        {
            test.push_back(word);
            word.clear();
        }
    }
    return test;
}

int main()
{
    ifstream in("program.txt");
    string a;
    for (int j = 0; j < INT_MAX; j++)
    {
        getline(in, a);
        auto test = substr(a);
        parse(test);
        int n = a.length();
        if (a[n - 1] == '$')
        {
            break;
        }
    }
    lexical_analysis();
}
