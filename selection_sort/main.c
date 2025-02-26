/********************************************
* Program: Optimized selection sort algorithm
* Author: Insane
* Date: 26-02-25
* License: None Obv xD
*********************************************/


#include <stdio.h>


void selectionSort(int arr[], int n);
void print_arr(int arr[], int len);


int main(void)
{
    int arr[] = {1, -1};
    int len = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, len);
    print_arr(arr, len);
    return 0;
}


/*************************************
 * Selection sort algorithm function *
 *************************************/
void selectionSort(int arr[], int n)
{   
    int steps = 0;

    for (int i = 0; i < n-1; i++) {

        int minIdx = i;
        int isSorted = 1;
        steps++;

        // Selection sort will always sort the array within n - 1 times.
        for (int j = i+1; j < n; j++) {

            // Standard selection sort checking
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }

            /*

                Explaing the early termination code:
            
                Example: 5    2    3    4    1
                       
                ------------------------------
                Step 1:  5    2    3    4    1
                        (i)
                        minIdx = 0
                        
                i is locked at 5 (idx=0) and minIdx will eventually go from minIdx = 0 
                to minIdx = 4 as at idx = 4 we have the smallet number which is 1.
                Also we are also checking the following as j goes from idx = 1 to idx = 4
                (5 > 2)? = True
                (2 > 3)? = False
                (3 > 4)? = False
                (4 > 1)? = False
                
                This sets isSorted = 0 so no early termination happens.
                ------------------------------
                
                Step2: 1    2    3    4    5
                           (i)

                Now i is locked at 2 and j goes idex = 2 to idx = 4. Here we also checked
                (2 > 3)? -> False
                (3 > 4)? -> False
                (4 > 5)? -> False
                Since none of them resulted to false, isSorted is remains to the value of 1 and loop breaks out early.
                ------------------------------
                
                Note: Checking (j-1 > j)? is neccessary then (j > j+1 && j != n-1) because of this case:
                        1    5    1    2    3
                            (i)

                Here i is locked at 5, but j goes from idx = 2 to idx = 4 checks:
                (1 > 2)? -> False
                (2 > 3)? -> False
                And isSorted is never set to 0, leading to wrong early termination.
                ------------------------------
            */
            if ((arr[j-1] > arr[j])) {
                    isSorted = 0;
                    printf("Reached here <%d,%d>\n", i,j);
             }
        }

        // Standard selection sort swap if needed
        if (minIdx != i) {
            int tmp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = tmp;
        }
        
        // For early termination, its working is explained above in block comments
        if (isSorted) {
            break;
        }
    }

    // Print number of steps required to sort the array
    printf("Steps: %d\n", steps);
}


/*******************************
 *  Function to print an array *
 *******************************/
void print_arr(int arr[], int len)
{
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
