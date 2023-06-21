//this isn't a true main, I just need to have fast calculations to pass to np ar
#include<iostream>
#include<vector>
#include<complex>
#include"board.cpp"
/*
std::complex<double> next_f(std::complex<double> c)
{
  //function that computes the next fractal with the recursive formula:
  //zn+1 = zn*zn + c
  //  std::complex<double> z1(0,0);
  std::complex<double> z0(1,1);
  std::complex<double> z1 = real(z0)*real(z0) - imag(z0)*imag(z0) + 2*real(z0)*imag(z0) + c;
  return z1;
};
*/

int main()
{
  BOARD a(1000);
  a.print_board();
  a.board_iter();
  return 0;
}
