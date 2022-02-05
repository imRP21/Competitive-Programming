#define debug(args...) {string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); dbg(_it, args);}

inline void dbg(istream_iterator<string> it) { cerr << '\n'; }
template<typename T, typename... Args>
inline void dbg(istream_iterator<string> it, T a, Args... args) {
  cerr << "[" << *it << " : " << a << "]";
  dbg(++it, args...);
}