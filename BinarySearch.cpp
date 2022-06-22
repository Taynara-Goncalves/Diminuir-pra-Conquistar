// BinarySearch.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
using namespace std;

class No
{
private:
    No* esq, * dir;
    int chave;

public:
    No(int chave)
    {
        this->chave = chave;
        esq = NULL;
        dir = NULL;
    }

    int getChave()
    {
        return chave;
    }

    // funções getters e setters

    No* getEsq()
    {
        return esq;
    }

    No* getDir()
    {
        return dir;
    }

    void setEsq(No* no)
    {
        esq = no;
    }

    void setDir(No* no)
    {
        dir = no;
    }
};

class Arvore
{
private:
    No* raiz;

public:
    Arvore()
    {
        raiz = NULL;
    }

    void inserir(int chave)
    {
        if (raiz == NULL) // verifica se a árvore está vazia
            raiz = new No(chave); // cria um novo nó
        else
            inserirAux(raiz, chave);
    }

    void inserirAux(No* no, int chave)
    {
        // se for menor, então insere à esquerda
        if (chave < no->getChave())
        {
            // verifica se a esquerda é nula
            if (no->getEsq() == NULL)
            {
                No* novo_no = new No(chave);
                no->setEsq(novo_no); // seta o novo_no à esquerda
            }
            else
            {
                // se não, continua percorrendo recursivamente
                inserirAux(no->getEsq(), chave);
            }
        }
        // se for maior, então insere à direita
        else if (chave > no->getChave())
        {
            // verifica se a direita é nulo
            if (no->getDir() == NULL)
            {
                No* novo_no = new No(chave);
                no->setDir(novo_no); // seta o novo_no à direita
            }
            else
            {
                // senão, continua percorrendo recursivamente
                inserirAux(no->getDir(), chave);
            }
        }
        // se for igual, não vai inserir
        // não pode existir 2 chaves iguais
    }

    No* getRaiz()
    {
        return raiz;
    }

    void emOrdem(No* no)
    {
        if (no != NULL)
        {
            emOrdem(no->getEsq());
            cout << no->getChave() << " ";
            emOrdem(no->getDir());
        }
    }
};

int main(int argc, char* argv[])
{
    Arvore arv;

    // insere as chaves
    arv.inserir(7);
    arv.inserir(2);
    arv.inserir(9);
    arv.inserir(13);
    arv.inserir(12);
    arv.inserir(1);
    arv.inserir(5);
    arv.inserir(3);
    arv.inserir(8);

    // percorre em ordem iniciando da raiz
    cout << "Percorrendo em ordem...\n";
    arv.emOrdem(arv.getRaiz());

    return 0;
}


// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
