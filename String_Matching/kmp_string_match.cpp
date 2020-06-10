/* Knuth Morris Prat algorithm for string matching */

#include <iostream>

#include <string>
using std::string;

#include <vector>
using std::vector;

void preprocess(string const& pattern, vector<int>& lps ){

    lps.resize( pattern.size(), 0 ); 

    // i is the index of the next element of longest common prefix before jth index
    for( int i = 0, j = 1; j < lps.size(); ){
        if( pattern[j] == pattern[i] ){
            ++i;
            lps[j] = i;
            ++j;
        }else{
            if( i == 0 ){
                ++j;
            }else{
                i = lps[ i - 1 ]; 
            }
        }
    }
}

void kmp_string_match( string const& pattern, string const& text, vector<int>& result){
    
    int p_len = pattern.size();
    int t_len = text.size();
    
    //length of longest proper prefix which is equal to the suffix
    vector<int> lps;
    preprocess( pattern, lps );

    if( pattern == "" )
        return;

    if( t_len < p_len )
        return;

    for( int pi = 0,  j = 0; j < ( text.size() - p_len + 1 ); ){
        if( text[ j ] == pattern[ pi ] ){
            pi++;
            j++;
        }else{
            if( pi == 0 ){
                ++j;
            }else{
                pi = lps[ pi - 1 ];
            }
        }
        if( pi == p_len ){
            result.push_back( j - p_len );
            pi = lps[ p_len - 1 ];
       } 
    }

    return;
}

int main(){
    string p = "aaaaab";
    string t = "aaaaabaaaaaabaaabaaaaaabaaaab";
    
    vector <int> result;
    kmp_string_match( p, t, result ); 
    
    for( auto& i : result )
        std::cout << i << " ";
}
