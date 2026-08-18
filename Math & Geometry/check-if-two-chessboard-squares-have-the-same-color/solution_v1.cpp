class Solution {
public:
    int checkparity(string c){
        int r=c[0]-'a';
        int col=c[1]-'1';

        return (r+col)%2;
    }
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        return checkparity(coordinate1)==checkparity(coordinate2);
    }
};