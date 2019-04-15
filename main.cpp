#include <iostream>
#include <vector>
#include <unordered_map>

class TheSumOfTwoNumber {
    public:
        // The first solution that might come to the mind, search all pairs.
        // O ( n^2 )
        std::vector < int > SimpleSolution( std::vector < int > list, int target ) {
            int n = list.size();
            for(int i = 0; i < n -1 ; i++ )
                for (int j = i + 1; j < n; j++)
                    if (list[i] + list[j] == target)
                        return { i, j }; //return the first solution
            return {}; // There is no solution
        }

        // The next solution uses a hash table, this needs two pass of the array
        // O ( n )
        std::vector < int > MapBasedSolution ( std::vector < int > list, int target ) {
            int n = list.size();
            std::unordered_map < int, int > mm;

            for ( int i = 0; i < n; i++ )
                mm[ list[i] ] = i;

            for ( int i = 0; i < n; i++) {
                int complement = target - list[ i ];
                if ( complement == list[i] )
                    continue;

                auto tt = mm.find( complement );
                if ( tt != mm.end() )
                    return { i , tt->second };

            }
            return {}; // There is no solution
        }

        // A little bit more efficient solution?? We check for solution everytime we insert one number into the list
        // O ( n )
        std::vector < int > MapBasedSolutionOnePass ( std::vector < int > list, int target ) {
            int n = list.size();
            std::unordered_map < int, int > mm;

            for ( int i = 0; i < n; i++) {
                // check for solution
                int complement = target - list[ i ];
                auto tt = mm.find( complement );
                if ( tt != mm.end() )
                    return { i , tt->second };
                
                // add the item to list, if it is not already added
                auto t = mm.find( list[i] );
                if ( t == mm.end() )
                    mm[ list[i] ] = i;
            }
            return {}; // There is no solution
        }



};

int main( int argc, char* argv[] ) {
    using namespace std;

    TheSumOfTwoNumber p;

    std::vector < int > list = { 3, 5, 4, 5, 6 };
    int target = 10;
    auto s = p.SimpleSolution(list, target);

    if ( s.size() == 0 )
        cout << "No solution found..." << endl;
    else if (s.size() == 2 )
        cout << "The solution:" << endl
             << s[0] << "," << s[1] << ": " 
             << list[ s[0] ]  << " + " << list[ s[1] ] << " = " << target << endl;
    else cout << "Wrong number of the output" << endl;

    s = p.MapBasedSolution(list, target);
    
    if ( s.size() == 0 )
        cout << "No solution found..." << endl;
    else if (s.size() == 2 )
        cout << "The solution:" << endl
             << s[0] << "," << s[1] << ": " 
             << list[ s[0] ]  << " + " << list[ s[1] ] << " = " << target << endl;
    else cout << "Wrong number of the output" << endl;
    
     s = p.MapBasedSolutionOnePass(list, target);
    
    if ( s.size() == 0 )
        cout << "No solution found..." << endl;
    else if ( s.size() == 2 )
        cout << "The solution:" << endl
             << s[0] << "," << s[1] << ": " 
             << list[ s[0] ]  << " + " << list[ s[1] ] << " = " << target << endl;
    else cout << "Wrong number of the output" << endl;
    return 0;
}
