#include<stdio.h>
#include<iostream>
#include<string>

using namespace std;

class Grade
{
public:    
    Grade (string);
    void setCourse (string);
    string getCourseName();
    void display();

private:
    string CourseName;

};

Grade :: Grade(string nome)
{
    setCourse(nome);
}

void Grade :: setCourse(string name)
{
    CourseName = name;
}

string Grade :: getCourseName()
{
    return CourseName;
}

void Grade :: display()
{

}

int main()
{
    
}