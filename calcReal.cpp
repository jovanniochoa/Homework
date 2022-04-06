#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int calcReal()
{
    char operation = 0;
double operand = 0;
string line="";
getline(cin, line);
istringstream sinput(line);
double result=0;
sinput >> result;
while (sinput >> operation >> operand){
    if (operation == '+'){
        result = result + operand;
    }
        if (operation == '-'){
        result = result - operand;
    }
        if (operation == '/'){
        result = result / operand;
    }
        if (operation == '*'){
        result = result * operand;
    }
}
cout << result << endl;

}
