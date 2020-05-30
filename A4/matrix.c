#include<stdio.h>
#include<stdlib.h> // rand(), srand()
#include <time.h> // time()
#define rows 5 // rows is a global constant having value of 5
#define cols 5 // cols is global constant having value of 5

void fillMatrix(int matrix[rows][cols]);
void printMatrix(int matrix[rows][cols]);
void transposeMatrix(int matrix[rows][cols]);
void multiplyMatrix(int m1[2][cols], int m2[rows][cols], int resultMatrix[rows][cols]);

int main(){
	int matrix[rows][cols];
	fillMatrix(matrix);
	printf("Filled matrix: \n");
	printMatrix(matrix);
	printf("Transposed matrix: \n");
	transposeMatrix(matrix);
	printMatrix(matrix);
	int matrix2[2][cols] = {0,1,2,3,4,5,6,7,8,9};
	int matrixResult[rows][cols];
	multiplyMatrix(matrix2, matrix, matrixResult);
	printf("Multiplied Matrix: \n");
	printMatrix(matrixResult);
	return 0;
}

void fillMatrix(int matrix[rows][cols]){
	srand(time(NULL)); // prevents repetition 
	for (int x=0; x<rows; x++){ // go row by row
		for (int y=0; y<cols; y++){ // go column by column
			matrix[x][y] = rand() %100 + 1; // number between 1 and 100 randomly generated and placed in matrix [x][y]
		}
	}	
}


void printMatrix(int matrix[rows][cols]){
	for (int x=0; x<rows; x++){ // go row by row
		for (int y=0; y<cols; y++){ // go column by column
			printf("%d	", matrix[x][y]); // print value at matrix[x][y] with tab between values
		}
		printf("\n"); // print new line after each row printed
	}
	printf("\n"); // print new line after finished printing matrix
}

void transposeMatrix(int matrix[rows][cols]){
	int *mat = &matrix[0][0]; // set pointer to start of matrix

	for(int x=0; x<rows;x++){ // go through row by row
		for (int y=x; y<cols; y++){ // go through column by column 
			int data = *(mat+x * cols+y); // save value that is pointed to at mat[x][y] and save
			matrix[x][y] = *(mat+y * cols+x); // replace [x][y] with [y][x] value
			matrix[y][x] = data; // replace [y][x] with data value b/c [x][y] has already been changed to [y][x] value
		}
	}	
}
void multiplyMatrix(int m1[2][cols], int m2[rows][cols], int resultMatrix[rows][cols]){
	int *mat1 = &m1[0][0]; // set pointer to start of m1
	int *mat2 = &m2[0][0]; // set pointer to start of m2
	
	for (int x=0; x<2; x++){ // go row by row through m1
		for (int a=0; a<cols; a++){ // set values of resultMatrix column by column
			resultMatrix[x][a]=0; // set result[x][a] to 0 and add to later
			for (int c=0; c<cols; c++){ // go column by column through m1 and row by row through m2
				int m1Val = *(mat1+x * cols+c); // set m1Val to value pointed to at m1[x][c]
				int m2Val = *(mat2+c* cols+a); // set m2Val to value pointed to at m2[c][a]
				resultMatrix[x][a] += m1Val * m2Val; // multiply values and add to already multiplied values
			}
		}
	}

	for(int fillX=2; fillX < rows; fillX++){ // go row by row
		for (int fillY=0; fillY < cols; fillY++){ // go column by column
			resultMatrix[fillX][fillY] = 0; // fill rest of matrix with 0s
		}
	}
}
