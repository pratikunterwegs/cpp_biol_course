#include <iostream>
#include <vector>

int main()
{
    //spec matrix dims
    const int iNrRows = 3;
    const int iNrCols = 4;

    //make a vector of iNrRows row vectors
    std::vector< std::vector<int> > matrix(iNrRows);

    //initialise matrix elements
    for(int i = 0; i < iNrRows; ++i){
        matrix[i] = std::vector<int>(iNrCols);
        for(int j = 0; j < iNrCols; ++j)
            matrix[i][j] = i + j;
    }

    //show matrix
    for(int i = 0; i < iNrRows; ++i){
        for(int j = 0; j < iNrCols; ++j)
            std::cout << matrix[i][j] << " ";
        std::cout << std::endl;
    }

    //end script
    return 0;
}
