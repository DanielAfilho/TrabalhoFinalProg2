#include <iostream>
#include <stdlib.h>

int qtd_alunos = 0;
aluno* alunos;

struct aluno
{
    std::string nome;
    int serie;
    char turma;
    int* notas;
    aluno* alunos = nullptr; //guarda o próximo aluno
};

void cadastrar_aluno() 
{
    if (qtd_alunos == 0) {
        qtd_alunos++;
        alunos = (aluno*) malloc(sizeof(aluno));
    }
    else {
        aluno* endereco_atual = alunos;
        aluno* ponteiro_atual;
        while (endereco_atual != nullptr) {
            ponteiro_atual = endereco_atual;
            endereco_atual = endereco_atual->alunos;
        }
        ponteiro_atual->alunos = (aluno*) malloc(sizeof(aluno));
    }
    return;
}

void cadastro_do_aluno(aluno* aluno_editado) //onde o mano ai colocar os baguioo do estudante, caô.
{
    std::cout << "Nome do aluno:  ";
    std::cin >> aluno_editado->nome;
    std::cout << "\n";
    std::cout << "Série (ano):  ";
    std::cin >> aluno_editado->serie;
    std::cout << "\n";
    std::cout << "Turma:  ";
    std::cin >> aluno_editado->turma;
    std::cout << "\n";
    return;
}
void menu(){
    std::cout << "Bem vindo ao sistema de registro escolar\n\n";
    std::cout << "Escolha uma opção:\n";
    int opcao;
    std::cin >> opcao;
    switch (opcao){
        case 1:
            cadastrar_aluno();
            break;
        case 2:
            //buscar_aluno();
            break;
        case 3:
            exit(0);
            break;
    } while(opcao != 3);
}