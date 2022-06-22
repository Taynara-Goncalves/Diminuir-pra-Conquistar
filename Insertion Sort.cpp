// Insertion Sort.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
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

template <typename T>
void InsertionSort(std::vector<T>& v) {
    int n = v.size();
    int j;
    T valor;
    for (int i = 1; i < n; i++) {
        valor = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > valor) {
            v[j + 1] = v[j];
            j -= 1;
        }
        v[j + 1] = valor;
    }
}

int main()
{
    //Exemplo com entrada de inteiros:
    std::vector<int> vector_in = { 10,7,55,23,24,10,11,8,19,50 };

    //Exemplo com entrada de string:
    //std::vector<std::string> vector_in = { "gadf","eadf","etdf","hfaf","naw","zqdd","raf","fbf","zaf","ado" };

    //Exemplo com entrada de double:
    //std::vector<float> vector_in = { 11.4,312.54,34.0,2.3,6.75,89.4,23.5,5.65,65.4,8.43 };

    std::cout << "Vetor nao ordenado: ";
    print_vector(vector_in);
    InsertionSort(vector_in);
    std::cout << "Vetor ordenado por Insertion Sort: ";
    print_vector(vector_in);
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
