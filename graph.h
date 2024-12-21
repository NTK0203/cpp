#include <iostream>
#include <string>

using namespace std;

class Graph
{
    private:
        int **array;
        int size;
    public:
        void LoadMatrix(std::string& filename);
        void PrintMatrix();
        int GetSize();
        void PrintShortestPathWeight(int s);
        void PrintShortestPath(int s);
};