#include <iostream>
#include <string>
using std::string;

/*
 *@author ani1998ket
 *
 * Matches pattern string within a text string
 * 
 * @param pattern String to be searched for
 * @param text String to be searched on
 * @return index of first match, or len(`text`) if didn't match or `pattern` was empty
 */
int brute_string_match( string const& pattern, string const& text );

int brute_string_match( string const& pattern, string const& text ){
    int p_len = pattern.size();
    int t_len = text.size();
    
    if( pattern == "" )
        return t_len;

    if( t_len < p_len )
        return t_len;
    
    for( int i = 0; i < ( t_len - p_len + 1 ); i++ ){
         if( text.compare( i, p_len, pattern ) == 0 ){
            return i;
         }
    }

    return t_len;
}


int main(){
    string p = "aaaab";
    string t = "aaaaaabaaaaabaaaaab";
    int pos = brute_string_match( p, t );
    while( pos != t.size() ){
        std::cout << pos << std::endl;
        pos++;
        pos += brute_string_match( p, t.substr(pos) );
    }
}
