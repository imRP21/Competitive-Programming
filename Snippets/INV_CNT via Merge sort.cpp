ll inv;
int a[N];
int aux[N];

void merge(int l, int r)
{
  int mid = (l + r) >> 1;
  f(i, l, r + 1) aux[i - l] = a[i];

  int i = l, j = mid + 1, ptr = l;
  while(i <= mid && j <= r)
  {
    if(aux[i - l] <= aux[j - l]) a[ptr++] = aux[i++ - l];
    else aux[ptr++] = aux[j++ - l], inv += (mid - i + 1);
  }

  while(i <= mid) a[ptr++] = aux[i++ - l];                 
  while(j <= r) a[ptr++] = aux[j++ - l];
}

void mergesort(int l, int r)
{
  if(l >= r) return;
  
  int mid = (l + r) >> 1;

  mergesort(l, mid);
  mergesort(mid + 1, r);

  merge(l, r);
}