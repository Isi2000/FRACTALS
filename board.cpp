#include<vector>
#include<iostream>
//std::vector<std::vector<int>> isi(rows, std::vector<int>(cols, 256));

struct complex
{
  int r;
  int i;
};

class BOARD
{
private:
  int m_dim;
  std::vector<int> m_board;
public:
  BOARD(int dim): m_dim{dim}, m_board(m_dim*m_dim,256)
  {
  };

void print_board()
{
  for (int i=0; i<m_dim*m_dim; ++i)
    {
      std::cout<< m_board[i] << ' ';
      if (i%(m_dim-1) == 0)
	{
	  std::cout<<'\n';
	}
    }
};
  complex get_coordinates(int n)
  {
    complex c;
    int row;
    c.i = n/m_dim;
    c.r = n%m_dim;
    return c;
      };
  void get_coordinates_test(){
    for (int i = 0; i<100; ++i)
      {
	std::cout<< get_coordinates(i).i<< ' '<< get_coordinates(i).r<<'\n';
      }
  };
  
    
};


