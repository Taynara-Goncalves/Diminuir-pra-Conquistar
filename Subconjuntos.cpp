// Subconjuntos.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <vector>

template <typename T>
void print_matrix(std::vector<std::vector<T>>& v) {//função para imprimir um vetor
    for (const auto& v1 : v) {
        for (auto x : v1) std::cout << x << " ";
        std::cout << std::endl;
    }

}


std::vector<std::vector<int>> BRGC(int n) { // gera 2^n n-bit string, cada uma diferente da anterior, mudando apenas 1 elemento de uma para a outra 
    std::vector<std::vector<int>> L;
    if (n == 1) //caso base
    {
        L.push_back({ 0 });
        L.push_back({ 1 });

    }
    else {

        //inicia L1 com n-1 elemento chando a função recursiva BRGC
        std::vector<std::vector<int>> L1 = BRGC(n - 1);
        std::vector<std::vector<int>> L2(L1);
        std::reverse(L2.begin(), L2.end());

        //Adiciona "0" na frente de cada bit string
        for (std::vector<int>& s : L1) {
            s.emplace(s.begin(), 0);
        }


        //Adiciona "1" na frente de cada bit string
        for (std::vector<int>& s : L2) {
            s.emplace(s.begin(), 1);
        }


        //concatena L2 e L1 , nesta ordem para formar L
        L.insert(L.begin(), L1.begin(), L1.end());
        L.insert(L.end(), L2.begin(), L2.end());

    }
    return L;

    //Relação de recorrência:
    //x(n) = x(n-1) + 2^(n-1) = 2^(n+1) - 3
}

std::vector<int> gera_set(int n) {
    std::vector<int> v;
    for (int i = 1; i <= n; i++) {
        v.push_back(i);
    }
    return v;
}

void gera_subsets(std::vector<std::vector<int>>& v, std::vector<int>& v_set) {
    int n = v_set.size();

    std::cout << "Todos os subconjunto diferentes gerados a partir do conjunto {";
    for (auto x : v_set) std::cout << x << " ";
    std::cout << "} sao:" << std::endl;

    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j])
            {
                std::cout << v_set[j] << " ";
            }
            else std::cout << "- ";
        }
        std::cout << std::endl;

    }

}

int main()
{
    int n = 4;

    std::vector<std::vector<int>> v;
    std::vector<int> v_set;

    v = BRGC(n);
    print_matrix(v);
    v_set = gera_set(n);
    //print_vector(v_set);

    gera_subsets(v, v_set);


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
