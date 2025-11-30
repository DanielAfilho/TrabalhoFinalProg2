#include <iostream>
#include <cstdlib>
#include <string>
#include <new>

struct aluno
{
    std::string nome;
    int serie;
    int* notas;
    aluno* prox_aluno = nullptr; //guarda o próximo aluno
};

aluno* alunos = nullptr; //guarda o endereço do primeiro aluno
int qtd_alunos = 0;

void cadastrar_aluno(aluno* aluno_editado)
{
    std::cout << "\n";
    std::cout << "Nome do aluno:  ";
    std::cin.ignore();
    std::getline(std::cin, aluno_editado->nome);
    std::cout << "Serie (1 a 3):  ";
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

void ordenar_alunos() //implementei um selection sort que ordena os alunos por ordem alfabetica
{
    if (alunos == nullptr || alunos->prox_aluno == nullptr) {
        return;
    }

    aluno* i = alunos;

    while (i != nullptr) {
        aluno* menor = i;
        aluno* j = i->prox_aluno;

        while (j != nullptr) {
            if(j->nome < menor->nome) {
                menor = j;
            }
            j = j->prox_aluno;
        }

        if (menor != i) {
            std::swap(i->nome, menor->nome);
            std::swap(i->serie, menor->serie);
            //tem que fazer um swap nas notas se for implementar
        }

        i = i->prox_aluno;

    }

    std::cout << "\n";
    i = alunos;
    while (i != nullptr) {
        std::cout << "Aluno: " << i->nome << "    Serie: " << i->serie << " ano\n";
        i = i->prox_aluno;
    }
    std::cout << "\n";
}

void imprimir_alunos() 
{
    std::cout << "\nQuer visualizar a lista de alunos em ordem alfabetica? (sim/nao): ";
    std::string resposta;
    std::cin >> resposta;

    while (resposta != "sim" && resposta != "nao") {
        std::cout << "\nResposta invalida. Digite novamente (sim/nao): ";
        std::cin >> resposta;
    }

    if (resposta == "sim") {
        ordenar_alunos();
    }
    else {
        std::cout << "\n";
        aluno* aluno_atual = alunos;
        while (aluno_atual != nullptr) {
            std::cout << "Aluno: " << aluno_atual->nome << "    Serie: " << aluno_atual->serie << " ano\n";
            aluno_atual = aluno_atual->prox_aluno;
        }
        std::cout << "\n";
        return;
    }
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
            }
            aluno_atual = aluno_atual->prox_aluno;
        }
    }
    else {
        bool encontrou = false;
        
        std::cout << "Digite o nome que deseja pesquisar: ";
        std::string nome_pesquisa;
        std::cin.ignore();
        std::getline(std::cin, nome_pesquisa);
        aluno* aluno_atual = alunos;
        std::cout << std::endl;
        while(aluno_atual != nullptr) {
            if (aluno_atual->nome == nome_pesquisa){
                encontrou = true;
                std::cout << "Aluno: " << aluno_atual->nome << "\tSerie: " << aluno_atual->serie << std::endl;
            }
            aluno_atual = aluno_atual-> prox_aluno;

        }
        if (encontrou == false){
            std::cout << "Aluno nao encontrado\n";
        }
    }
}

void menu()
{
    int opcao;

    do {
        std::cout << "\n1. Cadastrar aluno\n";
        std::cout << "2. Exibir alunos\n";
        std::cout << "3. Pesquisar aluno\n";
        std::cout << "4. Sair\n";
        std::cout << "Escolha uma opcao:\n";
    
        std::cin >> opcao;
        switch (opcao) {
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
                //tem que colocar um delete aqui pra liberar a memoria que alocou
                break;
            default:
                std::cout << "\nOpcao invalida. Tente novamente.\n\n";
                break;
        };
    } while (opcao != 4);
}