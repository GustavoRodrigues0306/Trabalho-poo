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

