#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;


/* =========================
CLASSE BASE (HERANÇA)
=========================*/

class Pessoa{

protected:

string nome;

public:

Pessoa(string n)
: nome(n){}

virtual void render() const=0;

virtual ~Pessoa(){}

};
/*
=========================
CLASSE PROFESSOR
=========================*/

class Professor:public Pessoa{

private:

string departamento;

public:

Professor(string n,
string d)

:Pessoa(n),
departamento(d){}


void render() const override{

cout<<"Professor:"
<<nome

<<" Dept:"
<<departamento

<<endl;

}

};
