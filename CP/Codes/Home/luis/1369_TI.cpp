
#include <cstdio>
#include <cassert>
#include <cmath>

#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair

typedef long double dbl;

const int MIN = 2;
const dbl eps = 1e-8;
const int maxn = (int)1e5;
const int maxt = (int)1e6;
const dbl inf = 1e100;
const dbl M = 10003;

struct tree
{
  int n, *p, l, r;
  dbl x1, y1, x2, y2;
};

int n, p[maxn];
dbl cx, cy, x[maxn], y[maxn];
int tpos = 0;
tree t[maxt];

inline bool less1( int i, int j ) { return mp(x[i], y[i]) < mp(x[j], y[j]); }
inline bool less2( int i, int j ) { return mp(y[i], x[i]) < mp(y[j], x[j]); }

int Build( int n, int *p, int dep, dbl lx, dbl ly, dbl rx, dbl ry )
{
  int k = tpos++;
  assert(k < maxt);
  t[k].n = n, t[k].p = p;
  t[k].l = t[k].r = 0;

  if (n > MIN)
  {
    int f = (dep & 1);
    int i = 0;
    dbl m = (f ? (lx + rx) : (ly + ry)) * 0.5;
    sort(p, p + n, f ? less1 : less2);
    while (i + 1 < n && (f ? x[p[i]] : y[p[i]]) < m)
      i++;
      
    t[k].p += i;
    if (f)
    {
      t[k].l = Build(i, p, dep + 1, lx, ly, m, ry);
      t[k].r = Build(n - i - 1, p + i + 1, dep + 1, m, ly, rx, ry);
    }
    else
    {
      t[k].l = Build(i, p, dep + 1, lx, ly, rx, m);
      t[k].r = Build(n - i - 1, p + i + 1, dep + 1, lx, m, rx, ry);
    }
  }
  return k;
}

dbl res;
int rn, r[maxn];

inline dbl sqr( dbl x )
{
  return x * x;
}

void Search( int v, int dep, dbl lx, dbl ly, dbl rx, dbl ry )
{
  int num = (t[v].n <= MIN ? t[v].n : 1);
  forn(i, num)
  {
    int a = t[v].p[i];
    dbl tmp = sqr(x[a] - cx) + sqr(y[a] - cy);
    if (fabs(tmp - res) < eps)
      r[rn++] = a;
    else if (tmp < res - eps)
      rn = 1, r[0] = a, res = tmp;
  }
  if (t[v].n <= MIN)
    return;

  dbl dx = (cx < lx ? (lx - cx) : (cx > rx ? (rx - cx) : 0));
  dbl dy = (cy < ly ? (ly - cy) : (cy > ry ? (ry - cy) : 0));
  if (sqr(dx) + sqr(dy) > res + eps)
    return;

  dbl m;
  if (dep & 1)
  {
    m = (lx + rx) * 0.5;
    Search(t[v].l, dep + 1, lx, ly, m, ry);
    Search(t[v].r, dep + 1, m, ly, rx, ry);
  }
  else
  {
    m = (ly + ry) * 0.5;
    Search(t[v].l, dep + 1, lx, ly, rx, m);
    Search(t[v].r, dep + 1, lx, m, rx, ry);
  }
}

inline dbl read()
{
  double x;
  scanf("%lf", &x);
  return x;
}

int main()
{
  scanf("%d", &n);
  forn(i, n)
    x[i] = read(), y[i] = read(), p[i] = i;
  int root = Build(n, p, 0, -M, -M, M, M);
  scanf("%d", &n);
  while (n--)
  {
    cx = read(), cy = read();
    res = inf;
    rn = 0;
    Search(root, 0, -M, -M, M, M);
    sort(r, r + rn);
    forn(i, rn)
      printf("%d%c", r[i] + 1, " \n"[i == rn - 1]);
  }
  return 0;
}

