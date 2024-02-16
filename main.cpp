  vector<pair<int,int>> bomb_coordinates(vector<vector<int>> &matrix){
     int row = matrix.size();
     int col = matrix[0].size();
      vector<pair<int,int>> bc;
      for(int i=0; i<row; i++){
        for(int j=0 ; j<col; j++){
            if(matrix[i][j]==1){
                bc.push_back(make_pair(i,j));
            }
        }
      }
      return bc;
        
  }