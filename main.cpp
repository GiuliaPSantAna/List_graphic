int main() {
    GraphMatriz gMatrix = loadGraficoDoArquivoMatriz("graph.txt");
    gMatriz.printGrafico();
    gMatriz.BFS(0, 3);
    gMatriz.DFS(0);

    GraficoLista gList = carregarGraficoDoArquivoLista("graph.txt");
    gList.printGrapico();
    gList.BFS(0, 3);
    gList.DFS(0);

    return 0;
}
