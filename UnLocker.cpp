#include <iostream>
#include "Lock.h"
#include <omp.h>
#include <time.h>
#include <conio.h>



int main()
{
    char choice;

    using namespace std;

    cout << "Enter the size of Lock\n";
    int digits_num;
    cin >> digits_num;
    long unsigned int* Lock = new long unsigned int[digits_num];

    GenerateLock(Lock, digits_num);
    do
    {
        cout << "Set number of threads\n";
        int threads_num;
        cin >> threads_num;
        omp_set_num_threads(threads_num);

        long unsigned int* result = new long unsigned int[digits_num];


        // Распараллеливание
        clock_t begin = clock();

    #pragma omp parallel for collapse(2)
        for (int i = 0; i < digits_num; i++)
        {
            for (int j = 0; j < digits_num; j++)
            {
                if (j == Lock[i])
                {
                    result[i] = j;
                    break;
                }

            }
        }

        clock_t end = clock();

        /*
        cout << endl << "Lock =\t\t";
        for (int i = 0; i < digits_num; i++)
            cout << Lock[i] << " ";
        cout << endl;

        cout << "Result =\t";
        for (int i = 0; i < digits_num; i++)
            cout << result[i] << " ";
        cout << endl;
        */


        //Время параллелбных вычеслений
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        cout << endl << time_spent * 1000 << "ms";

        //
        delete[] result;
        cout << endl << "Repeat? (Y/N)" << endl;
        cin >> choice;
    }while (tolower(choice) == 'y');
    return 0;
 }


