#include <iostream>
#include <string>

using namespace std;

class TextInput
{
    string data;
public:
    virtual void add(char c) 
    {
        data.push_back(c);
    }

    virtual std::string getValue() 
    { 
        return data; 
    }
};

class NumericInput : public TextInput 
{
    string data;
public:
    void add(char c) 
    {
        if(c >= 48 && c <= 57)
            data.push_back(c);
    }

    std::string getValue() 
    { 
        return data; 
    }
};

#ifndef RunTests
int main()
{
    TextInput* input = new NumericInput();
    input->add('1');
    input->add('a');
    input->add('0');
    std::cout << input->getValue();
}
#endif