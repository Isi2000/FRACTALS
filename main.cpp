//this isn't a true main, I just need to have fast calculations to pass to np ar
#include<iostream>
#include<vector>



int main()
{
  int rows = 3;
  int cols = 3;
  std::vector<std::vector<int>> isi(rows, std::vector<int>(cols, 256));  
  for (int i = 0; i<rows; ++i)
    for (int j = 0; j <cols; ++j)
      {
	{
	  std::cout<< isi[i][j];
	}
      }
  return 0;
  
}
