#include <iostream>
#include <iomanip>
using namespace std;

class Pet
{
public:
    Pet(string nm)
    {
        name = nm;
    }

    //pure virtual fuction
    virtual string talk() = 0; //static binding --> dynamic binding
    string getName()  //static binding -- compiler decides the binding
    {
        return name;
    }

protected:
    string name;
};

//Dog is a type of Pet
class Dog : public Pet
{
public:
    Dog(string nm) : Pet(nm)
    {
    }
    string talk()  //static binding -- compiler decides the binding
    {
        return "Wof!";
    }
};

class BigDog : public Dog
{
public:
    BigDog(string nm) : Dog(nm) {}
    string talk()
    {
        return "ARFFFFFFF!";
    }
};

class Cat : public Pet
{
public:
    Cat(string nm) : Pet(nm)
    {
    }
    string talk()
    {
        return "Meow!";
    }
};

int inheritance()
{
    Pet *pets[] =
    {
        new Dog("Billy"),
        new Cat("Ms.X"),
        new Dog("Max"),
        //new Pet("WhoamI"), can't create object based on abstract class. 
        new Cat("Jill"),
        new BigDog("Mr.Big")
    };

    for(int i=0; i<5; i++)
        cout << "My name is " << pets[i]->getName()
             << ". I say " << pets[i]->talk() << endl;

    //cout << "My name is " << dog1.getName() << ". I say " << dog1.talk() << endl;
    //cout << "My name is " << cat1.getName() << ". I say " << cat1.talk() << endl;
}

