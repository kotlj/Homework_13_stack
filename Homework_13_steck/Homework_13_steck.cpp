
#include <iostream>
#include <conio.h>

class Stack
{
private:
    char* chr;
    int size;
    int curIndx;

public:
    Stack()
    {
        size = 1;
        curIndx = -1;
        chr = new char;
    }
    Stack(int _size)
    {
        size = _size;
        curIndx = -1;
        chr = new char[size];
    }
    
    void put(char a)
    {
        if (!isFull())
        {
            ++curIndx;
            chr[curIndx] = a;
        }
        else
        {
            addSize(size, 5);
            put(a);
        }
    }
    char pull()
    {
        if (!isEmpty())
        {
            return chr[curIndx--];
        }
        return '0';
    }

    bool isFull()
    {
        if (curIndx < size - 1)
        {
            return false;
        }
        return true;
    }
    bool isEmpty()
    {
        if (curIndx == -1)
        {
            return true;
        }
        return false;
    }
    void addSize(int size, int grow = 1)
    {
        char* tample = new char[size + grow];
        if (!isEmpty())
        {
            for (int i = 0; i < size; i++)
            {
                tample[i] = chr[i];
            }
        }
        delete[] chr;
        chr = tample;
    }

    ~Stack()
    {
        delete[] chr;
    }
};

void checkStr(char* _str)
{
    char find = '0';
    Stack chr(1);
    for (int i = 0; _str[i] != '\n'; i++)
    {
        if (_str[i] == '(' || _str[i] == '[' || _str[i] == '{')
        {
            if (_str[i] == '(')
            {
                if (find == '0')
                {
                    find = ')';
                }
                else
                {
                    chr.put(find);
                    find = ')';
                }
            }
            else if (_str[i] == '[')
            {
                if (find == '0')
                {
                    find = ']';
                }
                else
                {
                    chr.put(find);
                    find = ']';
                }
            }
            else if (_str[i] == '{')
            {
                if (find == '0')
                {
                    find = '}';
                }
                else
                {
                    chr.put(find);
                    find = '}';
                }
            }

        }
        else if (_str[i] == ')' || _str[i] == ']' || _str[i] == '}')
        {
            if (_str[i] == ')')
            {
                if (find == ')')
                {
                    find = chr.pull();
                }
                else
                {
                    for (int j = 0; j != i; j++)
                    {
                        std::cout << _str[j];
                    }
                    break;
                }
            }
            else if (_str[i] == ']')
            {
                if (find == ']')
                {
                    find = chr.pull();
                }
                else
                {
                    for (int j = 0; j != i; j++)
                    {
                        std::cout << _str[j];
                    }
                    break;
                }
            }
            else if (_str[i] == '}')
            {
                if (find == '}')
                {
                    find = chr.pull();
                }
                else
                {
                    for (int j = 0; j != i; j++)
                    {
                        std::cout << _str[j];
                        break;
                    }
                }
            }
        }
        if (_str[i] == ';')
        {
            if (find == '0')
            {
                std::cout << "This string is correct;";
                break;
            }
            else
            {
                for (int j = 0; j != i; j++)
                {
                    std::cout << _str[j];
                }
                break;
            }
        }
    }
}

int main()
{
    int size = 100;
    char* str = new char[size + 1];
    int indx = 0;
    char key = '0';
    while (indx < size && key != ';')
    {
        key = _getch();
        str[indx] = key;
        indx++;
        std::cout << key;
    }
    str[indx] = '\0';
    std::cout << '\n';
    checkStr(str);
}