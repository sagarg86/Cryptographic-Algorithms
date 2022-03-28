#include<iostream>
#include<vector>
#include<cstdlib>
#include<math.h>
using namespace std;

vector<vector<char>> encrypt_step_1(vector<vector<char>> matrix, vector<int> row_permute, int row){
    vector<vector<char>> temp_matrix(row);
    for(int i=0; i<row; i++){
        temp_matrix[i] = matrix[row_permute[i]-1];
    }
    return temp_matrix;
}

vector<vector<char>> encrypt_step_2(vector<vector<char>> matrix, vector<int> col_permute, int row, int col){
    vector<vector<char>> temp_matrix(row,vector<char>(col));
    for(int i=0; i<col; i++){
        for(int j=0; j<row; j++){
            temp_matrix[j][i] = matrix[j][col_permute[i]-1];
        }
    }
    return temp_matrix;
}

vector<vector<char>> decrypt_step_1(vector<vector<char>> matrix, vector<int> col_permute, int row, int col){
    vector<vector<char>> temp_matrix(row,vector<char>(col));
    for(int i=0; i<col; i++){
        for(int j=0; j<row; j++){
            temp_matrix[j][col_permute[i]-1] = matrix[j][i];
        }
    }
    return temp_matrix;
}


vector<vector<char>> decrypt_step_2(vector<vector<char>> matrix, vector<int> row_permute, int row){
    vector<vector<char>> temp_matrix(row);
    for(int i=0; i<row; i++){
        temp_matrix[row_permute[i]-1] = matrix[i];
    }
    return temp_matrix;
}

string print_message(vector<vector<char>> matrix){
    string msg;
    int r = matrix.size();
    int c = matrix[0].size();
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(matrix[i][j] != '0')
                msg.push_back(matrix[i][j]);
        }
    }
    return msg;
}


int main(){
    while(1){
        string msg;
        cout << "\nEnter The Message: \n";
        cin.ignore();
        getline(cin,msg);
        int len = msg.length();

        int col = ceil(sqrt(len));
        int row = sqrt(len);
        if(row*col<len)
            row = col;
        vector<vector<char>> matrix(row,vector<char>(col,'0'));

        for(int i=0, k=0; i<row && k<len; i++){
            for(int j=0; j<col && k<len; j++){
                matrix[i][j] = msg[k++];
            }
        }

        vector<int> row_permute(row);
        for(int i=0; i<row; i++)
            row_permute[i] = i+1;
        for(int i=1; i<row; i++)
            swap(row_permute[i], row_permute[rand()%i]);
        
        vector<int> col_permute(col);
        for(int i=0; i<col; i++)
            col_permute[i] = i+1;
        for(int i=1; i<col; i++)
            swap(col_permute[i], col_permute[rand()%i]);

        matrix = encrypt_step_1(matrix, row_permute, row);
        matrix = encrypt_step_2(matrix,col_permute,row,col);
        cout<<"Encrypted Message: "<<print_message(matrix)<<"\n";
        matrix = decrypt_step_1(matrix,col_permute,row,col);
        matrix = decrypt_step_2(matrix,row_permute,row);
        cout<<"Decrypted Message: "<<print_message(matrix)<<"\n";
    }
    return 0;
}
