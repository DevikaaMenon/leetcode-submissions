class Solution {
public:

    bool isValidBox(vector<vector<char>>& board,int sr,int er,int sc,int ec){
        unordered_set<int>st;
        for(int i=sr;i<=er;i++){
            for(int j=sc;j<=ec;j++){
                if(board[i][j]=='.') continue;
                else if(st.find(board[i][j])!=st.end()) return false;
                st.insert(board[i][j]);
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        //validate rows
        for(int r=0;r<9;r++){
            unordered_set<char>st;
            for(int c=0;c<9;c++){
                if(board[r][c]=='.') continue;
                else if(st.find(board[r][c])!=st.end()) return false;
                else st.insert(board[r][c]);
            }
        }
        //validate cols
        for(int c=0;c<9;c++){
            unordered_set<char>st;
            for(int r=0;r<9;r++){
                if(board[r][c]=='.') continue;
                else if(st.find(board[r][c])!=st.end()) return false;
                else st.insert(board[r][c]);
            }
        }
        //validate boxes
        for(int sr=0;sr<9;sr+=3){
            int er=sr+2;
            for(int sc=0;sc<9;sc+=3){
                int ec=sc+2;
                if(!isValidBox(board,sr,er,sc,ec)) return false;
            }
        }
        return true;
    }
};