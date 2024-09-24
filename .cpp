#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <fstream>

class GraficoMatriz {
    int numeroVertices;
    std::vector<std::vector<int>> adjMatriz;

public:
    GraficoMatriz(int vertices) : numeroVertices(vertices) {
        adjacenciaMatriz.resize(vertices, std::vector<int>(vertices, 0));
    }

    void adicionarMatriz(int src, int dest) {
        adjacenciaMatriz[src][dest] = 1;
        adjacenciaMatriz[dest][src] = 1;  // Grafo que não é direcionado
    }

    bool BFS(int iniciar, int terminar) {
        std::vector<bool> visitado(numeroVertices, falso);
        std::vector<int> ligacao(numeroVertices, -1);
        std::queue<int> queue;

        visitado[iniciar] = verdadeiro;
        queue.push(iniciar);

        while (!queue.vazio()) {
            int vertice = queue.front();
            queue.pop();

            if (vertice == terminar) {
                std::cout << "Caminho encontrado: ";
                printPath(ligacao, terminar);
                return verdadeiro;
            }

            for (int i = 0; i < numeroVertices; i++) {
                if (adjacenciaMatriz[vertices][i] == 1 && !visitado[i]) {
                    visitado[i] = verdadeiro;
                    queue.push(i);
                    ligacao[i] = vertice;
                }
            }
        }

        std::cout << "Não existe caminho entre os vértices abordados" << iniciar << " e " << end << std::endl;
        return falso;
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
        std::vector<bool> visitado(numeroVertices, falso);
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
};
