#include <iostream>
#include<fstream>
#include<vector>
#include<string>
#include <chrono>
#include<algorithm>

static void insererBonPosition(std::vector<std::string> &V, std::string W) {
    if (V.empty()) {
        V.push_back(W);
        return;
    }
    for (int i = 0; i < V.size(); i++) {
        if (W < V[i])
        {
            V.insert(V.begin() + i, W);
            return;
        }
    }
    V.push_back(W);
    return;
}
static int calculerNbrOccur(std::vector<std::string> &A, std::string W) {
    if (A.empty()) return 0;
    int i = 0;
    std::vector<std::string>::iterator it;
    for (it = A.begin(); it != A.end(); it++)
        if (*it == W) i++;
    return i;
}
int main()
{
    auto start = std::chrono::high_resolution_clock::now();

    std::ifstream MyFile("filename.txt");
    std::string content;
    std::vector<std::string> A;
    while (MyFile >> content) {
        if (content != "")
            //insererBonPosition(A, content);
            A.push_back(content);
       
    }
    sort(A.begin(), A.end());
    std::cout <<"nombre des mots est : " << A.size() << std::endl;
    std::vector<std::string>::iterator it;
    for (it = A.begin(); it != A.end(); it++)
            std::cout << *it << std::endl;
    MyFile.close();
    std::string Word = "the";
    std::cout << "nombre d'occurance de " << Word << " est : " << calculerNbrOccur(A, Word)<<std::endl;
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Execution time: " << duration.count() << " seconds." << std::endl;
    return 1;

}

