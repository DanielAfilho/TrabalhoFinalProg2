#include <iostream>
#include <stdlib.h>
#include <string>
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
    std::cout << "\n";
    std::cout << "Nome do aluno:  ";
    std::cin.ignore();
    std::getline(std::cin, aluno_editado->nome);
    std::cout << "Serie (ano):  ";
    std::cin >> aluno_editado->serie;
    while (aluno_editado->serie < 1 || aluno_editado->serie > 3) {
        std::cout << "\nSerie invalida. Digite novamente:  ";
        std::cin >> aluno_editado->serie;
    }
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
        qtd_alunos++;
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

void imprimir_alunos() 
{
    std::cout << "\n";
    aluno* aluno_atual = alunos;
    while (aluno_atual != nullptr) {
        std::cout << "Aluno: " << aluno_atual->nome << "    Serie: " << aluno_atual->serie << " ano\n";
        aluno_atual = aluno_atual->prox_aluno;
    }
    std::cout << "\n";
    return;
}
void pesquisar_aluno()
{
    std::cout << "\n\n1- pesquisa por serie";
    std::cout << "\n2- pesquisa por nome\n";
    int opcao;
    std::cin >> opcao;
    if (opcao == 1) {
        std::cout << "Digite a serie que deseja pesquisar: ";
        int serie_pesquisa;
        std::cin >> serie_pesquisa;
        aluno* aluno_atual = alunos;
        std::cout << std::endl;
        while (aluno_atual != nullptr) {
            if (aluno_atual->serie == serie_pesquisa) {
                std::cout << "Aluno: " << aluno_atual->nome << "\tSerie: " << aluno_atual->serie << std::endl;
                aluno_atual = aluno_atual->prox_aluno;
            }
        }
    }
    else {
        std::cout << "Digite o nome que deseja pesquisar: ";
        std::string nome_pesquisa;
        std::cin.ignore();
        std::getline(std::cin, nome_pesquisa);
        aluno* aluno_atual = alunos;
        std::cout << std::endl;
        while(aluno_atual != nullptr) {
            if (aluno_atual->nome == nome_pesquisa){
                std::cout << "Aluno: " << aluno_atual->nome << "\tSerie: " << aluno_atual->serie << std::endl;
            }
            else {
                std::cout << "Aluno nao encontrado\n";
            }
            aluno_atual = aluno_atual-> prox_aluno;

        }
    }
}

void menu() 
{
    std::cout << "\n1. Cadastrar aluno\n";
    std::cout << "2. Exibir alunos\n";
    std::cout << "3. Pesquisar aluno\n";
    std::cout << "4. Sair\n";
    std::cout << "Escolha uma opcao:\n";
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
            pesquisar_aluno();
            break;
        case 4:
            exit(0);
            break;
        default:
            std::cout << "\nOpcao invalida. Tente novamente.\n\n";
            break;
    };
    menu();
    return;
}