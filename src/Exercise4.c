/*
4. Input an array of m x n. Provide the following functions:
	a.	Insert one row
	b.	Remove one row
	c.	Insert one column
	d.	Remove one column
Ex:
____________________________________________________________________
| Input: 5(row) 4(col) 1(choice) 2(location) 1 2 3 4 (insert array) |
| 10 21 12 53 64 53 86 72 68 99 10 11 12 13 14 15 16 17 18 19       |
| Output:                                                           |
| 10 21 12 53                                                       |
| 64 53 86 72                                                       |
| 1 2 3 4                                                           |
| 68 99 10 11                                                       |
| 12 13 14 15                                                       |
| 16 17 18 19                                                       |
|___________________________________________________________________|
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int main(int argc, char *argv[]) {
	//testing variable, applying it to your algorithm for auto-evaluating
	int row = atoi(argv[1]);
	int col = atoi(argv[2]);
	int action = atoi(argv[3]);
	int location = atoi(argv[4]);
    int i = 5;
	argc-=i;
    int rows[100][100];
    if(action == 1){
        // Insert row
        row += 1;
        int insert_row[col];
        for(int j = 0; j < col; j++){
            insert_row[j] = atoi(argv[i+j]);
        }
        i += col;
        
        // Build 2D array
        for(int r = 0; r < row; r++){
            if(r == location){
                for(int c = 0; c < col; c++){
                    rows[r][c] = insert_row[c];
                }
            }else{
                for(int c = 0; c < col; c++){
                    rows[r][c] = atoi(argv[i]);
                    i++;
                }
            }
        }
    }else if(action == 2){
        // Remove row
        // Build 2D array
        for(int r = 0; r < row; r++){
            if(r == location){
                i += col;
                row -= 1;
            }
            for(int c = 0; c < col; c++){
                rows[r][c] = atoi(argv[i]);
                i++;
            }
        }
    }else if(action == 3){
        // Insert column
        col += 1;
        int insert_col[row];
        for(int j = 0; j < row; j++){
            insert_col[j] = atoi(argv[i+j]);
        }
        i += row;
        
        // Build 2D array
        for(int r = 0; r < row; r++){
            for(int c = 0; c < col; c++){
                if(c == location){
                    rows[r][c] = insert_col[r];
                }else{
                    rows[r][c] = atoi(argv[i]);
                    i++;
                }
            }
        }
    }else if(action == 4){
        // Remove column
        // Build 2D array
        bool is_skip = false;
        for(int r = 0; r < row; r++){
            for(int c = 0; c < col; c++){
                if(c == location){
                    i += 1;
                    if(!is_skip){
                        is_skip = true;
                        col -= 1;
                    }
                }
                rows[r][c] = atoi(argv[i]);
                i++;
            }
        }
    }else{
        printf("Invalid option!");
    }

    for(int r = 0; r < row; r++){
		for(int c = 0; c < col; c++){
            printf("%d ", rows[r][c]);
        }
        printf("\n");
	}
	
    printf("\n");
	return 0;
}