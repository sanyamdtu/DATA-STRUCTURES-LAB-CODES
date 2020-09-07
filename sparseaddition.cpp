#include <iostream>
#define size 20

using namespace std;

struct sparse
{
  int nrow, ncol, nz;
  int row[size], col[size], value[size];
};

sparse addition(sparse s1, sparse s2)
{
  sparse s3;
  s3.nrow = s1.nrow;
  s3.ncol = s1.ncol;
  int i = 0, j = 0, k = 0;
  while (i < s1.nz && j < s2.nz)
  {
    if (s1.row[i] < s2.row[j] || s1.row[i] == s2.row[j] && s1.col[i] < s2.col[j])
    {
      s3.row[k] = s1.row[i];
      s3.col[k] = s1.col[i];
      s3.value[k] = s1.value[i];
      i++;
      k++;
    }
    else if (s1.row[i] == s2.row[j] && s1.col[i] == s2.col[j])
    {
      if (s1.value[i] + s2.value[j] != 0)
      {
        s3.row[k] = s1.row[i];
        s3.col[k] = s1.col[i];
        s3.value[k] = s1.value[i] + s2.value[j];
        k++;
      }
      i++;
      j++;
    }
    else
    {
      s3.row[k] = s2.row[j];
      s3.col[k] = s2.col[j];
      s3.value[k] = s2.value[j];
      j++;
      k++;
    }
  }
  while (i < s1.nz)
  {
    s3.row[k] = s1.row[i];
    s3.col[k] = s1.col[i];
    s3.value[k] = s1.value[i];
    i++;
    k++;
  }
  while (j < s2.nz)
  {
    s3.row[k] = s2.row[j];
    s3.col[k] = s2.col[j];
    s3.value[k] = s2.value[j];
    j++;
    k++;
  }

  s3.nz = k;
  return s3;
}

void display(sparse s)
{
  int i, j, k = 0;

  for (i = 0; i < s.nrow; i++)
  {
    for (j = 0; j < s.ncol; j++)
    {
      if (s.col[k] == j && s.row[k] == i)
      {
        cout << s.value[k] << "  ";
        k++;
      }
      else
        cout << "0  ";
    }
    cout << "\n";
  }
}
main()
{
  sparse s1, s2, s3;
  int i;
  cout << "Enter no. of row, column and non-zero elements in matrix 1:";
  cin >> s1.nrow >> s1.ncol >> s1.nz;
  s2.nrow = s1.nrow;
  s2.ncol = s1.ncol;

  cout << "Enter the elements of sparse matrix:";
  for (i = 0; i < s1.nz; i++)
  {
    cin >> s1.row[i] >> s1.col[i] >> s1.value[i];
    if (s1.row[i] >= s1.nrow || s1.col[i] >= s1.ncol)
    {
      cout << "\nWrong row or column. Type again";
      cin >> s1.row[i] >> s1.col[i] >> s1.value[i];
    }
  }
  cout << "Enter no. of  non-zero elements in matrix 2:";
  cin >> s2.nz;

  cout << "Enter the elements of sparse matrix:";

  for (i = 0; i < s2.nz; i++)
  {
    cin >> s2.row[i] >> s2.col[i] >> s2.value[i];
    if (s2.row[i] >= s2.nrow || s2.col[i] >= s2.ncol)
    {
      cout << "\nWrong row or column. Type again:";
      cin >> s2.row[i] >> s2.col[i] >> s2.value[i];
    }
  }
  s3 = addition(s1, s2);
  cout << "\ns1\n";
  display(s1);
  cout << "\ns2\n";
  display(s2);
  cout << "\ns3\n";
  display(s3);

  return 0;
}
