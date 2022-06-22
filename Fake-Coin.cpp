// Fake-Coin.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <vector>

template <typename T>
void print_vector(std::vector<T>& v) {//função para imprimir um vetor
    for (auto i = v.begin(); i != v.end(); i++) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}


int fake_coin(const std::vector<int>& v, int begin, int end) { //o const não deixa alterar o vetor v

    int f_coin = -1;

    if ((end - begin) == 1) {
        return begin;
    }
    else {
        int tamanho_pilha = (end - begin) / 2; //tamanho das pilhas
        int resto = (end - begin) % 2; //numero de moedas impar ou par 
        int inicio_pilha2 = begin + tamanho_pilha;

        end = (resto != 0) ? end - 1 : end;

        int peso_p1 = 0; // = std::accumulate(v.begin() + begin, v.begin() + inicio_pilha2, 0);
        for (auto i = v.begin() + begin; i != v.begin() + inicio_pilha2; i++) {
            peso_p1 += *i;
        }
        int peso_p2 = 0; // = std::accumulate(v.begin() + inicio_pilha2, v.begin() end, 0);
        for (auto i = v.begin() + inicio_pilha2; i != v.begin() + end; i++) {
            peso_p2 += *i;
        }

        if (peso_p1 < peso_p2) {
            f_coin = fake_coin(v, begin, inicio_pilha2);
        }
        else if (peso_p1 > peso_p2) {
            f_coin = fake_coin(v, inicio_pilha2, end);
        }
        else {
            f_coin = end;
            return f_coin;
        }
    }


}


int main()
{
    std::vector<int> v(30, 2);
    v[9] = 1;
    //std::cout << v.size();
    int f_coin;

    std::cout << "Vetor de moedas: ";
    print_vector(v);

    f_coin = fake_coin(v, 0, v.size());
    std::cout << "Moeda falsa esta na posicao: " << f_coin;
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
