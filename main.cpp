#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;


// CLASSE BASE (HERANCA)

class Pessoa{

protected:

    string nome;

public:

    Pessoa(string n) : nome(n){}

    // Metodo Virtual Puro: define a interface obrigatoria para as filhas
    virtual void render() const=0;

    // Destrutor Virtual: garante a limpeza correta em subclasses
    virtual ~Pessoa(){}

};

// CLASSE ALUNO

    // Heranca: Aluno estende Pessoa
class Aluno:public Pessoa{

private:

    string matricula;

    vector<float> notas;

public:

    Aluno(string n, string m) :Pessoa(n), matricula(m){
    notas.resize(4);
    }

    // Encapsulamento: validacao de dados de entrada
    void setNota(int i,float n){
        if(n<0||n>10) throw invalid_argument("Nota invalida");
        notas[i]=n;
    }


    float media() const{
        float soma=0;
        for(float n:notas) soma+=n;
        return soma/4;
    }


    string getMatricula() const{
        return matricula;
    }

    // Polimorfismo: implementacao especifica para Aluno
    void render() const override{
        cout<<"Aluno:" <<   nome <<" Mat:" << matricula << " Media:" << media() << endl;
    }

};

//CLASSE PROFESSOR

// Heranca: Professor estende Pessoa
class Professor:public Pessoa{
private:
    string departamento;

public:

    Professor(string n, string d) :Pessoa(n), departamento(d){}

    // Polimorfismo: implementacao especifica para Professor
    void render() const override{ cout << "Professor:" << nome << " Dept:" << departamento << endl;
    }
};

//CLASSE TURMA

class Turma{

private:

string codigo;


// vetor dos aunos
vector<
unique_ptr<Aluno>>
alunos;

public:

// construtor da turma
Turma(string c)
:codigo(c){}

// matricula um aluno
void matricular(
string nome,
string mat){

alunos.push_back(

make_unique<Aluno>(
nome,mat));

}

// busca aluno pela matricula

Aluno* buscar(
string mat){

for(auto& a:alunos)

if(a->getMatricula()==mat)

return a.get();

return nullptr;

}


// mostra alunos da turma
void render() const{

cout<<"\nTurma "
<<codigo

<<endl;

for(auto& a:alunos)

a->render();

}

};

// CLASSE SISTEMA: agregação de turmas e professores 

class Sistema{

private:

// vetor das turmas
vector<
unique_ptr<Turma>>
turmas;

// vetor dos professores
vector<
unique_ptr<Professor>>
professores;

public:


// cria uma nova turma
void criarTurma(
string c){

turmas.push_back(

make_unique<Turma>(c));

}


// retorna a primeira turma cadastrada
Turma* pegarTurma(){

if(turmas.empty())

throw runtime_error(
"Sem turmas");

return turmas[0].get();

}

// cria um professor
void criarProfessor(
string n,
string d){

professores.push_back(

make_unique<Professor>(
n,d));

}


// mostra dados do sistema
void render() const{

cout<<"\nSistema\n";

for(auto& p:professores)

p->render();

for(auto& t:turmas)

t->render();

}

};


// TESTES: exemplo de uso

void teste(){

Sistema s;

s.criarTurma("6A");

s.criarProfessor(
"Joao",
"Matematica");

// pega a turma criada
Turma* t=

s.pegarTurma();

t->matricular(
"Ana",
"100");

// busca o aluno matriculado
Aluno* a=

t->buscar("100");

// define as notas
a->setNota(0,8);
a->setNota(1,7);
a->setNota(2,9);
a->setNota(3,6);

// mostra o sistema
s.render();

};


// MAIN: inicio do programa

int main(){

try{

teste();

}

catch(exception& e){

cout<<e.what();

}

};
