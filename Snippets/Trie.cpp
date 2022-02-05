struct node
{
  // int cnt = 0;
  static const int ALPHA = 26;
  node* nxt[ALPHA]{};
};

class Trie
{
  public:
    node* root;

  public:
    Trie() { root = new node(); }

    void insert(const string &s)
    {
      node* curr = root;
      for(int i = 0; i < sz(s); i++)
      {
        int idx = s[i] - 'a';
        if(!curr -> nxt[idx])
          curr -> nxt[idx] = new node();
        curr = curr -> nxt[idx];
        // curr -> cnt++;
      }
    }

    void remove(const string &s)
    {
      node* curr = root;
      for(int i = 0; i < sz(s); i++)
      {
        int idx = s[i] - 'a';
        curr = curr -> nxt[idx];
        // curr -> cnt--;
      }
    }

    void query(const string &s)
    {
      
    }
};