typedef struct 
{
    int x;
    int y;
    int size;
} PGCB;


int **createMatrix(int nrows, int ncols);
void freeMatrix(int **matrix);
void initMatrix(int **matrix, int size_t, int numberOne);
void printMatrixSquare(int **matrix, int size_t, PGCB square);
PGCB maxSquare(int **matrix, int size_t);