class Solution 
{
public:

    bool f(int i, int j, int queensleft,
           vector<vector<int>> marked,
           vector<vector<char>>& board,
           vector<vector<string>>& ans)
    {
        // all queens placed
        if(queensleft == 0)
        {
            vector<string> temp;

            for(int x = 0; x < board.size(); x++)
            {
                string row = "";

                for(int y = 0; y < board.size(); y++)
                {
                    row += board[x][y];
                }

                temp.push_back(row);
            }

            ans.push_back(temp);

            return true;
        }

        // add queen at i,j

        // marking everything

        // column
        for(int x = 0; x < board.size(); x++)
        {
            marked[x][j] = 1;
        }

        // row
        for(int x = 0; x < board.size(); x++)
        {
            marked[i][x] = 1;
        }

        marked[i][j] = 1;

        // -------------------------
        // diagonals
        // -------------------------

        // ↘
        int x = i + 1;
        int y = j + 1;

        while(x < board.size() && y < board.size())
        {
            marked[x][y] = 1;
            x++;
            y++;
        }

        // ↖
        x = i - 1;
        y = j - 1;

        while(x >= 0 && y >= 0)
        {
            marked[x][y] = 1;
            x--;
            y--;
        }

        // ↙
        x = i + 1;
        y = j - 1;

        while(x < board.size() && y >= 0)
        {
            marked[x][y] = 1;
            x++;
            y--;
        }

        // ↗
        x = i - 1;
        y = j + 1;

        while(x >= 0 && y < board.size())
        {
            marked[x][y] = 1;
            x--;
            y++;
        }

        // actually put queen
        board[i][j] = 'Q';

        // now search for next queen
        for(int ni = 0; ni < board.size(); ni++)
        {
            for(int nj = 0; nj < board.size(); nj++)
            {
                if(marked[ni][nj] == 1)
                {
                    continue;
                }

                f(ni, nj, queensleft - 1,
                  marked, board, ans);
            }
        }

        // remove queen
        board[i][j] = '.';

        return true;
    }

    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> ans;

        vector<vector<char>> board(
            n,
            vector<char>(n, '.')
        );

        vector<vector<int>> marked(
            n,
            vector<int>(n, 0)
        );

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                f(i, j, n, marked, board, ans);
            }
        }

        return ans;
    }
};