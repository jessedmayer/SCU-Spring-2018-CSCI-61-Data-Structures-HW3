#include <iostream>

using namespace std;

int NumTrees(int n){
    if(n<=1){
        return 1;
    }
    else{
        int count = 0;
        for(int i = 1; i <= n; i++){
            count += NumTrees(i-1)*NumTrees(n-i);
        }
        return count;
    }
}

int main() {                        //expected results
    cout << NumTrees(2) <<endl;     //2
    cout << NumTrees(3) <<endl;     //5
    cout << NumTrees(4) <<endl;     //14
    return 0;
}