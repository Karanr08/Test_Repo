class Solution {
public:
    bool isValid(int i, int j, int R, int C)
{
	return (i >= 0 && i < R && j >= 0 && j < C);
}



bool isDelim(pair<int, int> temp)
{
	return(temp.first == -1 && temp.second == -1);
}
bool checkall(vector<vector<int>> grid)
{
	for(int i = 0; i < grid.size(); i++)
	{
		for(int j = 0; j < grid[0].size(); j++)
		{
			if(grid[i][j] == 1)
			{
				return true;
			}
		}
	}

	return false;
}

int rotOranges(vector<vector<int>> grid)
{
	queue<pair<int, int>> Q;

	pair<int, int> temp;

	int ans = -1;


	int R = grid.size();

	int C = grid[0].size();


	for(int i = 0; i < R; i++)
	{
		for(int j = 0; j < C; j++)
		{
			if(grid[i][j] == 2)
			{
				temp.first = i;
				temp.second = j;
				Q.push(temp);
			}
		}
	}

	temp.first = -1;
	temp.second = -1;

	Q.push(temp);


	int[][] directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
	while(!Q.empty())
	{
		bool flag = false;


		while(!isDelim(Q.front()))
		{
			temp = Q.front();

			if(isValid(temp.first + 1, temp.second) && grid[temp.first + 1][temp.second] == 1)
			{
				if(!flag) ans++, flag = true;

				grid[temp.first + 1][temp.second] = 2;

				temp.first ++;
				Q.push(temp);
				temp.first--;
			}
			if(isValid(temp.first -1, temp.second) && grid[temp.first - 1][temp.second] == 1)
			{
				if(!flag) ans++, flag = true;

				grid[temp.first - 1][temp.second] = 2;

				temp.first --;
				Q.push(temp);
				temp.first ++ ;
			}
			if(isValid(temp.first , temp.second + 1) && grid[temp.first ][temp.second + 1] == 1)
			{
				if(!flag) ans++, flag = true;

				grid[temp.first ][temp.second + 1] = 2;

				temp.second ++;
				Q.push(temp);
				temp.second--;
			}
			if(isValid(temp.first , temp.second - 1) && grid[temp.first ][temp.second - 1] == 1)
			{
				if(!flag) ans++, flag = true;

				grid[temp.first + 1][temp.second] = 2;

				temp.second --;
				Q.push(temp);
				
			}

			Q.pop();
		}
		Q.pop();
	}

	if(!Q.empty())
	{
		temp.first = -1;
		temp.second = -1;
		Q.push(temp);
	}


	return (checkall(grid)) ? -1 : ans;
}
    int orangesRotting(vector<vector<int>>& grid) {
        return rotOranges(grid);
        
    }
};