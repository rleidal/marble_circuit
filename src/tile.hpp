#include <compare>
#include <iostream>

class tile {
public:
    enum class Type { trap, left, right, cross, squiggle, empty, final };

    tile( tile::Type t );

    friend auto operator<=>(const tile& a, const tile& b)
    { return a._type <=> b._type; }

    std::ostream& put(std::ostream& out) const { return out << (int)_type; };
private:
    tile::Type _type;
};
