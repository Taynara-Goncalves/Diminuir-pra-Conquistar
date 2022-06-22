// _LexicographicPermute.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
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

void Lexicographic_permutation(int n) {
    std::vector<int> perm;
    for (int i = 0; i < n; i++) {
        perm.push_back(i);
    }
    print_vector(perm);//0,1,2,3

    while (true) {
        int maior_i = -1;// index inválido, quer dizer que não foi encontrado nada  
        //encontra o maior index "i " de tal forma que ai<ai+1 para ai+1>ai+2...
        for (int i = 0; i < perm.size() - 1; i++) {
            if (perm[i] < perm[i + 1]) {
                maior_i = i;
            }
        }
        if (maior_i == -1) {
            break;
        }

        //encontra o maior index "j " de tal forma que ai<aj para j>=i... já que ai<ai+1
        int maior_j = -1;
        for (int j = 0; j < perm.size(); j++) {
            if (perm[maior_i] < perm[j]) {
                maior_j = j;

            }
        }
        //troca ai como aj 
        std::swap(perm[maior_i], perm[maior_j]);

        //inverte a ordem dos elementos de ai+1 até an
        std::vector<int> perm_end;
        std::reverse(perm.begin() + (maior_i + 1), perm.end());

        print_vector(perm);
    }

}

int main()
{
    int n = 4;
    Lexicographic_permutation(n);
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
