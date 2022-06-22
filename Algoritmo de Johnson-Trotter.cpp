// Algoritmo de Johnson-Trotter.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

// Exercicio2_JohnsonTrotter.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
// Referencia: https://www.geeksforgeeks.org/johnson-trotter-algorithm/

// Gera todas as permutações de n elementos. 
//Cada permutação na sequência que gera difere da permutação anterior
//trocando dois elementos adjacentes da sequência. 


#include <iostream>
#include <vector>


template <typename T>
void print_vector(std::vector<T>& v) {//função para imprimir um vetor
    for (auto i = v.begin(); i != v.end(); i++) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}

int acha_mobile(std::vector<int>& a, std::vector<bool>& dir) {
    int mobile_prev = 0, mobile = 0;
    for (int i = 0; i < a.size(); i++)
    {
        // direção 0 representa direita para a esquerda
        if (dir[a[i] - 1] == false && i != 0) {
            if (a[i] > a[i - 1] && a[i] > mobile_prev) {
                mobile = a[i];
                mobile_prev = mobile;
            }
        }

        // direção 1 representa esquerda para a direita
        if (dir[a[i] - 1] == true && i != a.size() - 1) {
            if (a[i] > a[i + 1] && a[i] > mobile_prev) {
                mobile = a[i];
                mobile_prev = mobile;
            }
        }
    }

    if (mobile == 0 && mobile_prev == 0)
        return 0;
    else
        return mobile;
}

void print_perm(std::vector<int>& a, std::vector<bool>& dir) {
    int mobile = acha_mobile(a, dir); // acha o maior elemento móvel
    int pos;

    for (int i = 0; i < a.size(); i++) { // acha a posição do maior elemento móvel
        if (a[i] == mobile)
            pos = i + 1;
    }

    // troca os elementos de acordo com a direção
    if (dir[a[pos - 1] - 1] == false)
        std::swap(a[pos - 1], a[pos - 2]);

    else if (dir[a[pos - 1] - 1] == true)
        std::swap(a[pos], a[pos - 1]);

    //troca a direção dos elementos maiores que o maior elemento móvel
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] > mobile)
        {
            if (dir[a[i] - 1] == true)
                dir[a[i] - 1] = false;
            else if (dir[a[i] - 1] == false)
                dir[a[i] - 1] = true;
        }
    }

    print_vector(a);

}

void JohnsonTrotterPermutation(int n)
{
    std::vector<int> a;
    std::vector<bool> dir;

    for (int i = 0; i < n; i++) {
        a.push_back(i + 1);
    }
    print_vector(a);

    for (int i = 0; i < n; i++) // inicializa todas as posições com falso
        dir.push_back(false);

    int fatorial = 1; // calcula o fatorial de n
    for (int i = 1; i <= n; i++) {
        fatorial = fatorial * i;
    }

    for (int i = 1; i < fatorial; i++) { // gera n! permutação
        print_perm(a, dir);
        //print_vector(dir);
    }
}


int main()
{
    int n = 3;
    JohnsonTrotterPermutation(n);

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
