#include <iostream>
#include <vector>
// std::vector<std::vector<int>> isi(rows, std::vector<int>(cols, 256));

struct complex {
  double r;
  double i;
};

  double mod_2(complex a)
  {
    return (a.r*a.r + a.i*a.i);
  };

class BOARD {
private:
  int m_dim;
  std::vector<int> m_board;

public:
  BOARD(int dim) : m_dim{dim}, m_board(m_dim * m_dim, 256){};

  void print_board() {
    for (int i = 0; i < m_dim * m_dim; ++i)
      {
      std::cout << m_board[i] << ' ';
      if (i % (m_dim - 1) == 0) {
        std::cout << '\n';
      }
    }
  };
  complex get_coordinates(int n) {
    complex c;
    //type conversions are ugly, but int division is efficient
    int _i = c.i;
    int _r = c.r;
    _i = n / m_dim;
    _r = n % m_dim;
    double i_ = _i;
    double r_ = _r;
    c.i = (i_/m_dim)*2.26 - 1.13;
    c.r = (r_/m_dim)*2.48 - 2;
    return c;
  };
  void test() {
    for (int i = 0; i < 100; ++i) {
      std::cout << get_coordinates(i).i << ' ' << get_coordinates(i).r << '\n';
    }
  };
  complex next_s(complex z0) 
    // this function calculates the number of iterations for each pixel
  {
    //maybe implement mod in struct
    //use the recursive formula:
    complex z;
    complex c;
    c.i = 0;
    c.r = 0;
    z.i = 2*z0.i*z0.r + c.i;
    z.r = z.r*z.r - z.i*z.i + c.r;
    return z;
  };

  int num_iter(complex z, int max_iter)
  {
    int iter = 0;
    while (iter<max_iter && mod_2(z)<4)
      {
	z = next_s(z);
	++iter;
      }
    return iter;
  };

  void board_iter()
  {
    for (int i=0; i<m_dim*m_dim; ++i)
      {
	std::cout<< num_iter(get_coordinates(i), 200) << '\n';
      }
  };
};
