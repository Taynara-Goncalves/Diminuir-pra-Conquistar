// Interpolation Search.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.

//A pesquisa por interpolação é um algoritmo para pesquisar uma chave em uma 
//matriz que foi ordenada por valores numéricos atribuídos às chaves 
//( valores de chave ). A pesquisa por interpolação se assemelha ao método 
//pelo qual as pessoas pesquisam um nome em uma lista telefônica 


#include <iostream>
#include <vector>

template <typename T>
void print_vector(std::vector<T>& v) {//função para imprimir um vetor
    for (auto i = v.begin(); i != v.end(); i++) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void bubble_sort(std::vector<T>& v)
{
    int i, j;
    for (i = 0; i < size(v) - 1; i++)
    {
        for (j = 0; j < size(v) - 1 - i; j++)
        {
            if (v[j + 1] < v[j])
            {
                std::swap(v[j], v[j + 1]); //troca os elementos de posição um com o outro
            }
        }
    }
}

template <typename T>
void interpolation_search(std::vector<T> v, T k) {
    int n = v.size();
    int l = 0;
    int r = n - 1;
    bool flag = false;
    while ((l <= r) && (k >= v[l]) && (k <= v[r])) {
        T x = l + ((k - v[l]) * (r - l)) / (v[r] - v[l]);

        if (((l == r) && (v[l] == k))) {
            std::cout << "O indice da senha " << k << " eh: " << l << std::endl;
            flag = true;
            break;
        }
        else if (v[x] == k) {
            std::cout << "O indice da senha " << k << " eh: " << x << std::endl;
            flag = true;
            break;
        }
        else {
            if (v[x] < k) { l = x + 1; }
            else { r = x - 1; }
        }

    }
    if (!flag) {
        std::cout << "Chave " << k << " nao encontrada!" << std::endl;
    }

    //relação de recorrencia para a versão recursiva:
    // Cworst = Cworst(n/2) + 1 (divide o problema em dois a cada enlace e faz uma operação)

}



int main()
{
    //Exemplo com entrada de inteiros:
    std::vector<int> vetor_in = { 10,7,55,23,24,12,11,8,19,50 };
    int k = 10;


    //Exemplo com entrada de double:
    //std::vector<float> vetor_in = { 11.4,312.54,34.0,2.3,6.75,89.4,23.5,5.65,65.4,8.43 };
    //float k = 11.4;

    bubble_sort(vetor_in);
    std::cout << "Arranjo: ";
    print_vector(vetor_in);

    interpolation_search(vetor_in, k);

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
