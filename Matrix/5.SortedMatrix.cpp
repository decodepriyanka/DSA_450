Given an NxN matrix Mat. Sort all elements of the matrix.

Input:
N=4
Mat=[[10,20,30,40],
[15,25,35,45] 
[27,29,37,48] 
[32,33,39,50]]
Output:
10 15 20 25 
27 29 30 32
33 35 37 39
40 45 48 50
 --------------------------------------------------------------------------------
   vector<vector<int>> sortedMatrix(int N, vector<vector<int>> matrix) {
        // code here
        vector<int>v ; 
        for(int i = 0;i<N;i++){
            for(int j =0;j<N;j++){
                v.push_back(matrix[i][j]);
            }
        }
        sort(v.begin(),v.end());
        int index = 0;
        for(int i =0;i<N;i++){
            for(int j =0;j<N;j++){
                matrix[i][j]= v[index++];
            }
        }
        return matrix;
        
    }
