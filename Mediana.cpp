// Mediana.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

// Exercicio8_Mediana.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <vector>

template <typename T>
void print_vector(std::vector<T>& v) {//função para imprimir um vetor
    for (auto i = v.begin(); i != v.end(); i++) {
        std::cout << *i << " ";
    }

}

template <typename T>
int lomutoPartition(std::vector<T>& v) {
    int l = 0;
    int r = v.size() - 1;
    int p = v[l];
    int s = l;
    for (int i = l + 1; i <= r; i++) {
        if (v[i] < p) {
            s = s + 1;
            std::swap(v[s], v[i]);

        }
    }

    std::swap(v[l], v[s]);

    return s;

}

template <typename T>
int quickselect(std::vector<T>& v, int k) {
    int l = 0;
    int r = v.size() - 1;
    int s = lomutoPartition(v);
    if (s == k - 1) {
        std::cout << v[s];
        return v[s];
    }
    else if (s > l + k - 1) {
        std::vector<int> v1;
        v1.insert(v1.begin(), v.begin() + l, v.end() - (s - 1));
        quickselect(v1, k);
    }
    else {
        std::vector<int> v1;
        v1.insert(v1.begin(), v.begin() + s + 1, v.end());
        quickselect(v1, k - 1 - s);
    }
}

int main()
{
    //Exemplo com entrada de inteiros:
    std::vector<int> vetor_in = { 10,13,55,23,24,4,11,8,19,50,44,12,48, 31,20 }; //{4,8,10,11,12,13,19,20,23,24,31,44,48,50,55}

    int k;
    if (vetor_in.size() % 2 == 0) {
        k = (vetor_in.size()) / 2;
    }
    else {
        k = (vetor_in.size() + 1) / 2;
    }

    std::cout << " A mediana do vetor: {";
    print_vector(vetor_in);
    std::cout << "} eh :";
    quickselect(vetor_in, k);
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
