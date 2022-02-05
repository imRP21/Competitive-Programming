__builtin_popcount(n);

////////////
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
////////////

////////////
// unordered_set<T> or unordered_map<T, T> boost up tricks.
s.reserve(32768); 
s.max_load_factor(0.25); 

// manual hashing for not int first key.
struct HASH 
{
    ll operator()(const vector<int> &v) const 
    {
        ll seed = rnd(1, INF);
        for(const int &x : v) 
            seed ^= x + 0x39A7F172 + (seed << 6) + (seed >> 2);
        return hash<int>()(seed);
    }
};
unordered_map<vector<int>, ll, HASH> dp[20][2][2];

////////////

////////////
#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed: " << (1000.0 * clock()) / CLOCKS_PER_SEC << " ms \n";
    time_t time = chrono::system_clock::to_time_t(chrono::system_clock::now());
    cout << (ctime(&time)) << endl;
#endif
///////////

///////////
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#ifndef ONLINE_JUDGE
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
//////////

//////////
#define dbg1(x) cerr << #x << ": " << x << ' ' << endl
#define dbg2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl
#define dbg3(x, y, z) cerr << #x << ":" << x << " | " << #y <<": "<< y << " | " << #z << ": " << z << endl
#define dbg4(a, b, c, d) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl
//////////


//////////
// interconversions btw string and int(both 32_t, 64_t)
stoi(); // [s - std::string or c_string] TO [int]
stoll(); // [s - std::string or c_string] TO [long long int]

// so convert if string is of type std::string 
// string(s) to c_string -> s.c_str();
atoi(); // [c_string only] TO [int] 
atoll(); // [c_string only] TO [long long int]

to_string(); // [int or long long int] TO [std::string] 
//////////
