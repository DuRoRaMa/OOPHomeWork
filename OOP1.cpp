#include <iostream>
#include <ctime>
#include <limits>
using namespace std;

int main()
{
    bool ok = true;
    int N, M, k;
    int* p1;
    int* p2;

    cout << "vvedite k" << endl;
    cin >> k;
    if (cin.fail() or k < 1){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "error"<< endl;
    }else{
    cout << "Vvedite N\n";
    cin >> N ;
    if (cin.fail() or N < 1){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "error"<< endl;
    }else{


        cout << "Vvedite M\n";
        cin >> M;
        if (cin.fail()or M < 1){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "error"<< endl;
    }else{


    if (k > N){
        cout << "error";
    }else{
    srand(time(0));


    int *B = new int[M];
    p1 = B;
    for (int i = 0; i < M; i++) {
            *p1 = rand()%20;
            p1++;
    }
    int **matrix = new int *[N];
    for (int i =  0; i < N; i++){
        matrix[i] =  new int [M];
    }

    for (int i =  0; i < N; i++){
        for (int j =  0; j < M; j++){
            matrix[i][j] =  rand()%2 + 1;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    p1 = &matrix[k-1][0];
    p2 = &matrix[k-1][M-1];
    for (int x = 0; x < M; x++){
        if (*p1 != *p2) ok = false;
        p1 = p1 + 1;
        p2 = p2 - 1;
    }
    cout << endl;
    if (ok) B[k-1] = 1; else B[k-1] = 0;
    cout << endl;
    p1 = B;
     for (int i = 0; i < M; i++) {
            cout << *p1 << " ";
            p1++;

     }
    delete []B;
    B=nullptr;
    delete []matrix;
    matrix = nullptr;
    }}}}
    return 0;
}
