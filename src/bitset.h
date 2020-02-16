#include <bitset>

template<size_t Len>
class Bitset {
    using BS = std::bitset<Len>;

    BS bits;

    class iterator {
        BS* _p;

        public:
        iterator(int i, BS* p) : _i(i), _p(p) {}
        void operator++() {_i--;}
        bool operator!=(const iterator & other) const { return _i >= other._i;}
        auto operator*() const { 
          auto& p = *_p;
          auto x = p[_i];
          return x; 
        }
        int _i = 0;
   };

 public:
    Bitset(unsigned long b) : bits(BS(b)) {}
    iterator begin() { return iterator(bits.size() - 1, &bits); }
    iterator end() { return iterator(0, &bits); }
};