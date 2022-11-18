#include <iostream>
#include <algorithm>
#include <stack>
#include <fstream>
#include <list>

using namespace std;
 
class Grafo
{
	int V;
	list<int> *adj;
 
public:
	Grafo(int V);
	void adicionarAresta(int v1, int v2);
 
	void dfs(int v);
};
 
Grafo::Grafo(int V)
{
	this->V = V;
	adj = new list<int>[V];
}
 
void Grafo::adicionarAresta(int v1, int v2)
{
	adj[v1].push_back(v2);
}
 
void Grafo::dfs(int v)
{
	stack<int> pilha;
	bool visitados[V];
 
	for(int i = 0; i < V; i++)
		visitados[i] = false;
 
	while(true)
	{
		if(!visitados[v])
		{
			cout << "Visitando vertice " << v << " ...\n";
			visitados[v] = true;
			pilha.push(v);
		}
 
		bool achou = false;
		list<int>::iterator it;
 
		for(it = adj[v].begin(); it != adj[v].end(); it++)
		{
			if(!visitados[*it])
			{
				achou = true;
				break;
			}
		}
 
		if(achou)
			v = *it;
		else
		{
			pilha.pop();
			if(pilha.empty())
				break;
			v = pilha.top();
		}
	}
}
 
int main()
{
	int V = 100;
	Grafo grafo(V);
    int m[10][10];
	int l,c;
	ifstream arquivoE;
	arquivoE.open("pcv10.txt");
	arquivoE >> l >> c;

	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < c; j++)
		{
			arquivoE >> m[i][j];
			grafo.adicionarAresta(i, j);
		}
	
	}
	
	printf("\n\n==================================================\n\n");

	cout << "A matriz lida do arquivo tem tamanho: " << l << " x " << c << endl;
	cout << "Conteudo da matriz no arquivo: " << endl;
	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << m[i][j] << " - ";
		}
		cout << endl;
	}
	
	grafo.dfs(0);
 
	return 0;
}