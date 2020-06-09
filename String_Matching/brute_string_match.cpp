#include <iostream>
#include <string>
using std::string;

/*
 * @author ani1998ket
 *
 * Matches pattern string within a text string
 * 
 * @param pattern String to be searched for
 * @param text String to be searched on
 * @param pos Index of the `text` to start the search
 * @return index of first match, or len(`text`) if didn't match or `pattern` was empty
 */
int brute_string_match( string const& pattern, string const& text, int pos = 0);

int brute_string_match( string const& pattern, string const& text, int pos){
    int p_len = pattern.size();
    
    //length of substring to be searched
    int t_len = text.size() - pos;
    
    if( pattern == "" )
        return text.size();

    if( t_len < p_len )
        return text.size();
    
    for( int i = pos; i < ( text.size() - p_len + 1 ); i++ ){
         if( text.compare( i, p_len, pattern ) == 0 ){
            return i;
         }
    }

    return text.size();
}


int main(){
    string p = "aaaaab";
    string t = "aaaaabaaaaaabaaabaaaaaabaaaab";
    int pos = brute_string_match( p, t );
    while( pos != t.size() ){
        std::cout << pos << std::endl;
        pos = brute_string_match( p, t, pos + 1 );
    }
}
