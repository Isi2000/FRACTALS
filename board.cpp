#include<vector>
#include<iostream>
//std::vector<std::vector<int>> isi(rows, std::vector<int>(cols, 256));
class BOARD
{
private:
  int m_dim = 10;
  std::vector<int> m_board;
public:
  BOARD(int dim): m_dim{dim}, m_board(m_dim*m_dim,256))
  { 
  };

};


