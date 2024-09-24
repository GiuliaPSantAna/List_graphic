#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <fstream>
#include <list>

class GraficoMatriz {
    int numeroVertices;
    std::vector<std::vector<int>> adjacenciaMatriz;

public:
    GraficoMatriz(int vertices) : numeroVertices(vertices) {
        adjacenciaMatriz.resize(vertices, std::vector<int>(vertices, 0));
    }

    void adicionarPonta(int src, int dest) {
        adjacenciaMatriz[src][dest] = 1;
        adjacenciaMatriz[dest][src] = 1;  // Grafo que não é direcionado
    }

    bool BFS(int iniciar, int terminar) {
        std::vector<bool> visitado(numeroVertices, false);
        std::vector<int> ligacao(numeroVertices, -1);
        std::queue<int> queue;

        visitado[iniciar] = true;
        queue.push(iniciar);

        while (!queue.vazio()) {
            int vertice = queue.front();
            queue.pop();

            if (vertice == terminar) {
                std::cout << "Caminho encontrado: ";
                printPath(ligacao, terminar);
                return true;
            }

            for (int i = 0; i < numeroVertices; i++) {
                if (adjacenciaMatriz[vertices][i] == 1 && !visitado[i]) {
                    visitado[i] = true;
                    queue.push(i);
                    ligacao[i] = vertice;
                }
            }
        }

        std::cout << "Não existe caminho entre os vértices abordados" << iniciar << " e " << end << std::endl;
        return false;
    }

    void printarGrafico() {
        for (int i = 0; i < numeroVertices; i++) {
            for (int j = 0; j < numeroVertices; j++) {
                std::cout << adjacenciaMatriz[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    void printCaminho(const std::vector<int>& ligacao, int vertice) {
        if (vertice == -1) return;
        printCaminho(ligacao, ligacao[vertice]);
        std::cout << vertice << " ";
    }

    void DFS(int iniciar) {
        std::vector<bool> visitado(numeroVertices, false);
        std::stack<int> stack;

        stack.push(iniciar);

        while (!stack.empty()) {
            int vertice = stack.top();
            stack.pop();

            if (!visitado[vertice]) {
                std::cout << vertice << " ";
                visitado[vertice] = verdadeiro;
            }

            for (int i = 0; i < numeroVertices; i++) {
                if (adjacenciaMatriz[vertice][i] == 1 && !visitado[i]) {
                    stack.push(i);
                }
            }
 }
        std::cout << std::endl;
    }

    class GraficoLista {
    int numeroVertices;
    std::vector<std::list<int>> adjacenciaLista;

public:
    GraficoLista(int vertices) : numeroVertices(vertices) {
        adjacenciaLista.resize(vertices);
    }

    void adicionarPonta(int src, int dest) {
        adjacenciaLista[src].push_back(dest);
        adjacenciaLista[dest].push_back(src);  // Grafo que não é direcionado
    }

    void printarGrafico() {
        for (int i = 0; i < numeroVertices; i++) {
            std::cout << i << ": ";
            for (int vertices : adjacenciaLista[i]) {
                std::cout << vertice << " ";
            }
            std::cout << std::endl;
        }
    }

    bool BFS(int iniciar, int terminar) {
        std::vector<bool> visitado(numeroVertices, false);
        std::vector<int> ligacao(numeroVertices, -1);
        std::queue<int> queue;

        visitado[iniciar] = true;
        queue.push(iniciar);

        while (!queue.empty()) {
            int vertice = queue.front();
            queue.pop();

            if (vertice == terminar) {
                std::cout << "Caminho que foi encontrado: ";
                printCaminho(ligacao, terminar);
                return true;
            }

            for (int vizinho : adjacenciaLista[vertice]) {
                if (!visitado[vizinho]) {
                    visitado[vizinho] = true;
                    queue.push(vizinho);
                    ligacao[vizinho] = vertice;
                }
            }
        }

        std::cout << "Não existe caminho entre os vértices " << start << " e " << end << std::endl;
        return false;
    }

    void DFS(int iniciar) {
        std::vector<bool> visitado(numeroVertices, false);
        std::stack<int> stack;

        stack.push(iniciar);

        while (!stack.empty()) {
            int vertices = stack.top();
            stack.pop();

            if (!visitado[vertice]) {
                std::cout << vertice << " ";
                visitado[vertice] = true;
            }

            for (int vizinho : adjacenciaLista[vertice]) {
                if (!visitado[vizinho]) {
                    stack.push(vizinho);
                }
            }
        }
        std::cout << std::endl;
    }

    void printCaminho(const std::vector<int>& ligacao, int vertice) {
        if (vertice == -1) return;
        printCaminho(ligacao, ligacao[vertice]);
        std::cout << vertice << " ";
    }

GraficoMatriz loadGraficoDoArquivoMatriz(const std::string& filename) {
    std::ifstream file(filename);
    int numeroVertices, numeroPontas;
    file >> numeroVertices >> numeroPontas;

    GraficoMatriz grafico(numeroVertices);
    for (int i = 0; i < numeroPontas; i++) {
        int src, dest;
        file >> src >> dest;
        grafico.adicionarPonta(src, dest);
    }

    return grafico;
}

GraficoLista carregarGraficoDoArquivoLista(const std::string& filename) {
    std::ifstream file(filename);
    int numeroVertices, numeroPontas;
    file >> numeroVertices >> numeroPontas;

    GraficoLista grafico(numeroVertices);
    for (int i = 0; i < numeroPontas; i++) {
        int src, dest;
        file >> src >> dest;
        grafico.adicionarPonta(src, dest);
    }

    return grafico;
}
};


