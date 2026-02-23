Este projeto implementa um Sistema de Gestão Acadêmica Simplificado, cujo objetivo é modelar a estrutura básica de uma instituição de ensino.

O sistema permite:

- Criar turmas
- Cadastrar professores
- Matricular alunos
- Registrar notas
- Calcular média dos alunos
- Exibir informações completas do sistema

A implementação foi desenvolvida aplicando os principais conceitos de Programação Orientada a Objetos (POO):

- Abstração
- Encapsulamento
- Herança
- Polimorfismo
- Gerenciamento automático de memória (RAII)

  

O sistema foi estruturado utilizando uma hierarquia de classes com responsabilidades bem definidas.

| Requisito Funcional                 | Classe Responsável | Método Implementado                      |
| ----------------------------------- | ------------------ | ---------------------------------------- |
| Criar turma                         | `Sistema`          | `criarTurma(string c)`                   |
| Criar professor                     | `Sistema`          | `criarProfessor(string n, string d)`     |
| Matricular aluno em turma           | `Turma`            | `matricular(string nome, string mat)`    |
| Buscar aluno pela matrícula         | `Turma`            | `buscar(string mat)`                     |
| Registrar notas do aluno            | `Aluno`            | `setNota(int i, float n)`                |
| Calcular média do aluno             | `Aluno`            | `media()`                                |
| Exibir dados do aluno               | `Aluno`            | `render()`                               |
| Exibir dados do professor           | `Professor`        | `render()`                               |
| Exibir dados da turma               | `Turma`            | `render()`                               |
| Exibir dados completos do sistema   | `Sistema`          | `render()`                               |
| Garantir polimorfismo               | `Pessoa`           | `virtual void render() const = 0`        |
| Garantir encapsulamento             | Todas              | Uso de `private`, `protected` e `public` |
| Gerenciamento automático de memória | `Sistema`, `Turma` | Uso de `unique_ptr`                      |

Um diagrama de classes simples:

                    +----------------+
                    |    Pessoa      |  <<Classe Abstrata>>
                    +----------------+
                    | - nome: string |
                    +----------------+
                    | + render() = 0 |
                    +--------▲-------+
                             |
               -----------------------------
               |                           |
     +----------------+           +----------------+
     |     Aluno      |           |   Professor    |
     +----------------+           +----------------+
     | - matricula    |           | - departamento |
     | - notas[4]     |           +----------------+
     +----------------+           | + render()     |
     | + setNota()    |           +----------------+
     | + media()      |
     | + render()     |
     +----------------+

     +----------------+
     |     Turma      |
     +----------------+
     | - codigo       |
     | - alunos       | (vector<unique_ptr<Aluno>>)
     +----------------+
     | + matricular() |
     | + buscar()     |
     | + render()     |
     +----------------+

     +----------------+
     |    Sistema     |
     +----------------+
     | - turmas       | (vector<unique_ptr<Turma>>)
     | - professores  | (vector<unique_ptr<Professor>>)
     +----------------+
     | + criarTurma() |
     | + criarProfessor() |
     | + pegarTurma() |
     | + render()     |
     +----------------+


Este projeto foi desenvolvido por:

- Gustavo de Jesus Rodrigues
- Kelvin Fagundes Gomes de Souza
- Mizael Paris Leite
- Murilo Gois Mesquita
