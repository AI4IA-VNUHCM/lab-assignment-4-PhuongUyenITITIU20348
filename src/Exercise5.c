/*
5.	Receive an array of m x n with all distinguished elements.
Find the minimum element of each row then find the maximum
number from those.
Ex:
___________________________________________________________________________________
| Input: 5(row) 4(col) 10 21 22 54 64 53 86 72 68 99 30 11 12 23 69 15 16 77 98 19 |
| The converted 2D array will be like this:                                        |
| 10 21 22 54                                                                      |
| 64 53 86 72                                                                      |
| 68 99 30 11                                                                      |
| 12 23 69 15                                                                      |
| 16 77 98 19                                                                      |
| Output:                                                                          |
| 53                                                                               |
|__________________________________________________________________________________|
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int main(int argc, char *argv[]) {
	//testing variable, applying it to your algorithm for auto-evaluating
	int row = atoi(argv[1]);
	int col = atoi(argv[2]);
    int i = 3;
	argc-=i;
    int minArr[row];

    for(int r = 0; r < row; r++){
        int min = 999999;
        for(int c = 0; c < col; c++){
            int n = atoi(argv[i]);
            if(n < min){
                min = n;
                minArr[r] = min;
            }
            i++;
        }
    }

   int max = -999999;
    for(int m = 0; m < row; m++){
        int n = minArr[m];
        if(n > max){
           max = n;
        }
    }

    printf("%d\n", max);
    printf("\n");
	return 0;
}
