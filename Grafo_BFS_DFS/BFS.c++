#include <iostream>
#include <queue> 
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

	
	void bfs(int v);
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

void Grafo::bfs(int v)
{
	queue<int> fila;
	bool visitados[V];

	for(int i = 0; i < V; i++)
		visitados[i] = false;

	cout << "Visitando vertice " << v << " ...\n";
	visitados[v] = true; 

	while(true)
	{
		list<int>::iterator it;
		for(it = adj[v].begin(); it != adj[v].end(); it++)
		{
			if(!visitados[*it])
			{
				cout << "Visitando vertice " << *it << " ...\n";
				visitados[*it] = true;
				fila.push(*it);
			}
		}

		if(!fila.empty())
		{
			v = fila.front(); 
			fila.pop();
		}
		else
			break;
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
	cout << "Conteudo do arquivo: " << endl;
	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << m[i][j] << " - ";
		}
		cout << endl;
	}


	grafo.bfs(0);

	return 0;
}