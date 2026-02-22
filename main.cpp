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
