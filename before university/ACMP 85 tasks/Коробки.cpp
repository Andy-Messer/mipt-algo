#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
 
int
main ()
{
  int a[3], b[3];
 
  cin >> a[0] >> a[1] >> a[2] >> b[0] >> b[1] >> b[2];
  sort (a, a + 3);
  sort (b, b + 3);
  if (a[0] == b[0] && a[1] == b[1] && a[2] == b[2])
    {
      cout << "Boxes are equal";
    }
  else
    {
      if (a[0] == b[0])
    {
      if (a[1] >= b[1])
        {
          if (a[2] >= b[2])
        {
          cout << "The first box is larger than the second one";
        }
          else
        {
          cout << "Boxes are incomparable";
        }
        }
      else
        {
          if (a[2] <= b[2])
        {
          cout << "The first box is smaller than the second one";
        }
          else
        {
          cout << "Boxes are incomparable";
        }
        }
    }
      else
    {
      if (a[1] == b[1])
        {
          if (a[0] >= b[0])
        {
          if (a[2] >= b[2])
            {
              cout << "The first box is larger than the second one";
            }
          else
            {
              cout << "Boxes are incomparable";
            }
        }
          else
        {
          if (a[2] <= b[2])
            {
              cout << "The first box is smaller than the second one";
            }
          else
            {
              cout << "Boxes are incomparable";
            }
        }
        }
      else
        {
          if (a[2] == b[2])
        {
          if (a[1] >= b[1])
            {
              if (a[0] >= b[0])
            {
              cout <<
                "The first box is larger than the second one";
            }
              else
            {
              cout << "Boxes are incomparable";
            }
            }
          else
            {
              if (a[0] <= b[0])
            {
              cout <<
                "The first box is smaller than the second one";
            }
              else
            {
              cout << "Boxes are incomparable";
            }
            }
        }
          else
        {
          if (a[0] > b[0] && a[1] > b[1] && a[2] > b[2])
            {
              cout << "The first box is larger than the second one";
            }
          else
            {
              if (a[0] < b[0] && a[1] < b[1] && a[2] < b[2])
            {
              cout <<
                "The first box is smaller than the second one";
            }
              else
            {
              cout << "Boxes are incomparable";
            }
 
            }
        }
        }
    }
     
      return 0;
    }
}