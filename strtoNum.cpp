#include <iostream>
#include <string>
#include <sstream>
//enables us to use a string like file input
//istringstream - for input
//ostringstream - for output

using namespace std;

bool isValid(double score){
    if (score >=0>) && (score <= 100){
    return true;
    }
    else{
    return false;
    }
}

int strtoNum()
{
double assign1=0, assign2=0, assign3=0, test1=0, test2=0;
string line="";

cout << "Enter all 5 scores(3 assignments & 2 exams):\n";
getline(cin, line);
if (istringstream(line) >> assign1 >> assign2 >> assign3 >> test1 >> test2){

cout << "Weighted total: "
<< (assign1 + assign2 + assign3) * 0.10
+ (test1 + test2)* 0.35;
}
else
cout << "Intalid set of values.";

}
