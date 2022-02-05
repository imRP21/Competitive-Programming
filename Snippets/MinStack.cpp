class MinStack()
{
  public:
    stack<pii> st;

  public:
    void push(int val)
    {
      int mn = (sz(s) ? min(val, s.top.ss) : val);
      st.push({val, min});
    }

    void pop()
    {
      // int removed = st.top().ff;
      st.pop();
    }

    getMin()
    {
      return st.top().ss;
    }
};
