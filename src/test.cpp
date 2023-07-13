#include <iostream>
#include <vector>
#include <algorithm>

#include "tile.hpp"

struct comma_out : std::numpunct<char>
{
    char do_thousands_sep()   const { return ','; }  // separate with spaces
    std::string do_grouping() const { return "\3"; } // groups of 3 digit
};
 


int main() {
    std::cout << "Hello World\n";
    std::cout.imbue(std::locale(std::cout.getloc(), new comma_out));

    std::vector<tile> tiles;
    tiles.emplace_back( tile::Type::trap );
    tiles.emplace_back( tile::Type::trap );
    tiles.emplace_back( tile::Type::trap );

    tiles.emplace_back( tile::Type::left );
    tiles.emplace_back( tile::Type::left );
    tiles.emplace_back( tile::Type::left );

    tiles.emplace_back( tile::Type::right );
    tiles.emplace_back( tile::Type::right );
    tiles.emplace_back( tile::Type::right );

    tiles.emplace_back( tile::Type::cross );
    tiles.emplace_back( tile::Type::cross );
    tiles.emplace_back( tile::Type::cross );

    tiles.emplace_back( tile::Type::squiggle );
    tiles.emplace_back( tile::Type::squiggle );
    tiles.emplace_back( tile::Type::squiggle );



    std::sort( tiles.begin(), tiles.end() );


    uint64_t cnt = 0;
    do{
        // for( const auto& t: tiles ) {
        //     t.put(std::cout) << " ";
        // }
        // std::cout << "\n";
        cnt++;
    } 
    while (std::next_permutation(tiles.begin(), tiles.end()));
   
    std::cout << "Total cnt = " << cnt << std::endl;
}
