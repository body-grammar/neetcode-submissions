class Solution {
public:
    bool backtrack(vector<vector<char>>& board, string& word, int row, int col, int wordIndex)
    {
        if(row < 0 || col < 0 || row >= board.size() || col >= board[0].size())
        {
            return false;
        }

        char og = board[row][col];

        if(board[row][col] != word[wordIndex])
        {
            return false;
        } else 
        {
            board[row][col] = '#';
        }

        if(wordIndex == word.size() - 1)
        {
            board[row][col] = og;
            return true;
        }

        bool first = backtrack(board, word, row + 1, col, wordIndex + 1);
        bool second = backtrack(board, word, row - 1, col, wordIndex + 1);
        bool third = backtrack(board, word, row, col + 1, wordIndex + 1);
        bool fourth = backtrack(board, word, row, col - 1, wordIndex + 1);

        board[row][col] = og;

        return first || second || third || fourth;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                if(backtrack(board, word, i, j, 0))
                {
                    return true;
                }
            }
        }

        return false;
    }
};
