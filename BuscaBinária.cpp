// BuscaBinária.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

//A busca binária é um eficiente algoritmo para encontrar um item em uma lista ordenada .
//Ela funciona dividindo repetidamente pela metade a porção da lista que deve 
//conter o item, até reduzir as localizações possíveis a apenas uma.


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
void busca_binaria(std::vector<T> v, T k) {
    int n = v.size();
    int l = 0;
    int r = n - 1;
    bool flag = false;
    while (l <= r) {
        int m = (l + r) / 2;

        if (k == v[m]) {
            std::cout << "O indice da senha " << k << " eh: " << m << std::endl;
            flag = true;
            break;
        }
        else if (k < v[m]) {
            r = m - 1;
        }
        else l = m + 1;
    }
    if (!flag) {
        std::cout << "Chave " << k << " nao encontrada!" << std::endl;
    }

}



int main()
{
    //Exemplo com entrada de inteiros:
    //std::vector<int> vetor_in = { 10,7,55,23,24,12,11,8,19,50 };
    //int k = 19;

    //Exemplo com entrada de string:
    //std::vector<std::string> vetor_in = { "gadf","eadf","etdf","hfaf","naw","zqdd","raf","fbf","zaf","ado" };
    //std::string k = "zaf";

    //Exemplo com entrada de double:
    std::vector<float> vetor_in = { 11.4,312.54,34.0,2.3,6.75,89.4,23.5,5.65,65.4,8.43 };
    float k = 12;

    bubble_sort(vetor_in);
    std::cout << "Arranjo: ";
    print_vector(vetor_in);

    busca_binaria(vetor_in, k);


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
