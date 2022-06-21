// dividirpraconquistarbusca.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <vector>
#include <iostream>

using namespace std;


int busca(vector<vector<int>>& matriz, int li, int lf, int ci, int cf, int valor) {
	if ((lf - li) == 0 && (cf - ci) == 0)
		return matriz [li][ci];

	else
	{
		int divl = (li + lf) / 2;
		int divc = (ci + cf) / 2;
		int matriz1 = busca(matriz, li, divl, ci, divc, valor);
		int matriz2 = busca(matriz, li, divl, divc + 1, cf, valor);
		int matriz3 = busca(matriz, divl + 1, lf, ci, divc, valor);
		int matriz4 = busca(matriz, divl + 1, lf, divc + 1, cf, valor);
		
		//Se o valor for encontrado retorna o valor
		if (matriz1 == valor || matriz2 == valor || matriz3 == valor || matriz4 == valor)
			return valor;
		
		//caso o valor não esteja na matriz retorna 0
		else
			return 0;
	}
}

int main()
{

	vector<vector<int>> matriz = { { 1, 2, 3, 4 },
									{ 5, 6, 7, 8 },
									{ 9, 10, 11, 12 },
									{ 13, 14, 15, 16 } };


	int valor = 24;
	cout << busca (matriz, 0, 3, 0, 3, valor) << " ";
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
