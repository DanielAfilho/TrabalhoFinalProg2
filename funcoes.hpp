#include <iostream>
#include <stdlib.h>
#include <new>

int qtd_alunos = 0;

struct aluno
{
    std::string nome;
    int serie;
    int* notas;
    aluno* prox_aluno = nullptr; //guarda o próximo aluno
};

aluno* alunos = nullptr; //guarda o endereço do primeiro aluno

void cadastrar_aluno(aluno* aluno_editado)
{
    std::cout << "Nome do aluno:  ";
    std::cin >> aluno_editado->nome;
    std::cout << "\n";
    std::cout << "Série (ano):  ";
    std::cin >> aluno_editado->serie;
    std::cout << "\n";
    return;
}

void criar_aluno() 
{
    if (qtd_alunos == 0) {
        qtd_alunos++;
        alunos = new aluno;
        cadastrar_aluno(alunos);
    }
    else {
        aluno* endereco_atual = alunos;
        aluno* ponteiro_atual;
        while (endereco_atual != nullptr) {
            ponteiro_atual = endereco_atual;
            endereco_atual = endereco_atual->prox_aluno;
        }
        ponteiro_atual->prox_aluno = new aluno;
        cadastrar_aluno(ponteiro_atual->prox_aluno);
    }
    return;
}

void imprimir_alunos() {
    aluno* aluno_atual = alunos;
    while (aluno_atual != nullptr) {
        std::cout << aluno_atual->nome << "    " << aluno_atual->serie;
    }
}

void menu(){
    std::cout << "Bem vindo ao sistema de registro escolar\n\n";
    std::cout << "1. Cadastrar aluno " << "\n";
    std::cout << "2. Exibir alunos " << "\n";
    std::cout << "3. Sair " << "\n";
    std::cout << "Escolha uma opção:\n";
    int opcao;
    std::cin >> opcao;
    switch (opcao){
        case 1:
            criar_aluno();
            break;
        case 2:
            imprimir_alunos();
            break;
        case 3:
            exit(0);
            break;
    } while(opcao != 3);
}