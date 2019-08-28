#include <iostream>
#include <vector>
using namespace std;

/**
 * Cubic maximum contiguous subsequence sum algorithm.
 */
int maxSubSumCubic( const vector<int> & a )
{
  int maxSum = 0;

  for( int i = 0; i < a.size( ); ++i )
    for( int j = i; j < a.size( ); ++j )
    {
      int thisSum = 0;

      for( int k = i; k <= j; ++k )
        thisSum += a[ k ];

      if( thisSum > maxSum )
        maxSum   = thisSum;
    }

  return maxSum;
}

// Careful when doing this.  It makes it difficult to use maxSubSumCubic elsewhere
int main() {

  vector<int> v1 = {1, 2, 3, 4, 5};
  cout << "Max of {1, 2, 3, 4, 5}: " << maxSubSumCubic(v1) << endl;

  vector<int> v2 = {1, 2, -13, 4, 5};
  cout << "Max of {1, 2, -4, 4, 5}: " << maxSubSumCubic(v2) << endl;

  vector<int> v3 = {1, 2, -1, 4, 5};
  cout << "Max of {1, 2, -1, 4, 5}: " << maxSubSumCubic(v3) << endl;


}