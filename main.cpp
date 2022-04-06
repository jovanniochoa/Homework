#include "TestResult.h"

TestResult::TestResult(int count, string correctResponses)
{
    numQuestions = count;
    
    correctResponses = correctResponses;

    //allocate dynamic array and initialize the contents to false
    responses = new bool [numQuestions+1];
    for(int i=0; i<=numQuestions; i++)
        responses[i] = false;

    //conversion logic  "1-5,8,10-15"
    istringstream istr(correctResponses);
    char temp;
    int start, stop;
    while (istr >> start)
    {
        responses[start] = true; //stand-alone

        if (istr.peek() == '-')   //is it a range?
        {
            istr >> temp >> stop;
            while (start <= stop)
            {
                responses[start] = true;
                start++;
            }
        }
        istr >> temp; //to get rid of ,
    }
}

ostream& operator<<(ostream& stream, const TestResult &result)
{

    int start=0, stop=0;
    for(int i=1; i<=result.numQuestions; i++)
        if (result.responses[i])
        {
            stop = i;
            if (!start)
                start = i;
        }
        else if (start > 0) //responses[i] is false
        {
            if (stop > start) //output a range
                stream << start << "-" << stop;
            else
                stream << start; //output individual value
            stream << " ";
            start = stop = 0;
        }

    if (start > 0)
    {
        if (stop > start)
            stream << start << "-" << stop;
        else
            stream << start;
    }
    return stream;
}

TestResult TestResult::operator+(const TestResult &second) const {
    //we are assuming both objects have same # of questions
    TestResult newResult = TestResult(numQuestions, "");
    for(int i=1; i<=numQuestions; i++)
        newResult.responses[i] =  responses[i] || second.responses[i];
    return newResult;
}
//checks if one got right insread of other
TestResult TestResult::operator-(const TestResult &second) const {
    TestResult newResult1 = TestResult(numQuestions, "");
    TestResult nnewResult1 = TestResult(numQuestions, "");
    for(int i=1; i<=numQuestions; i++)
        newResult1.responses[i] =  responses[i];
        
for(int i=1; i<=numQuestions; i++)
        nnewResult1.responses[i] =  second.responses[i];
    return newResult1-nnewResult;
}

// checks if the operator is false... only outputs false ones why does != not work
TestResult TestResult::operator%(const TestResult &second) const {
    TestResult newResult2 = TestResult(numQuestions, "");
    TestResult nnewResult2 = TestResult(numQuestions, "");
    for(int i=1; i<=numQuestions; i++)
        newResult2.responses[i] = responses[i] || second.responses[i];
        
    //if equals the number count upward, dont put it in new result
    for (int j = 1;<= numQuestions; i++){
        if (newResult2 == j){
            nnewResult2.responses[j];
        }
    }

    return nnewResult2;
}

//both got it right
TestResult TestResult::operator^(const TestResult &second) const{
    TestResult newResult3 = TestResult(numQuestions, "");
    for(int i=1; i<=numQuestions; i++){
        newResult3.responses[i] =  responses[i] && second.responses[i];
        if (&second[i] = false){
            second.responses[i];
        }
    }
    
        
    return second.responses[0];
}



//destructor
TestResult::~TestResult()
{
    //delete all the dynamic memory associated with current object
    delete [] responses;
}



