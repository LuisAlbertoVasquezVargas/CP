//--------------------------- FAST FOURIER TRANSFORM ---------------------------

Let A be array of length m, w be primitive mth root of unity.
Goal: produce DFT F(A): evaluation of A at 1, w, w^2,...,w^{m-1}.
FFT(A, m, w)
{
  if (m==1) return vector (a_0)
  else {
    A_even = (a_0, a_2, ..., a_{m-2})
    A_odd  = (a_1, a_3, ..., a_{m-1})
    F_even = FFT(A_even, m/2, w^2)    //w^2 is a primitive m/2-th root of unity
    F_odd = FFT(A_odd, m/2, w^2)
    F = new vector of length m
    x = 1
    for (j=0; j < m/2; ++j) {
      F[j] = F_even[j] + x*F_odd[j]
      F[j+m/2] = F_even[j] - x*F_odd[j]
      x = x * w
  }
  return F
}

Let F_A = FFT(A, m, w)                        // time O(n log n)
Let F_B = FFT(B, m, w)                        // time O(n log n)
For i=1 to m, let F_C[i] = F_A[i]*F_B[i]      // time O(n)
Output C = 1/m * FFT(F_C, m, w^{-1}).         // time O(n log n)

// GENERAL FFT

#include <bits/stdc++.h>

typedef long double lf;
const lf eps=1e-8,pi=acos(-1.0);
struct cp{
    lf a,b;
    cp(){}
    cp(lf a,lf b):a(a),b(b){}
    cp operator+(const cp&x)const{return (cp){a+x.a,b+x.b};}
    cp operator-(const cp&x)const{return (cp){a-x.a,b-x.b};}
    cp operator*(const cp&x)const{return (cp){a*x.a-b*x.b,a*x.b+b*x.a};}
};
void rev(cp *a,int n){
    int i,j,k;
    for (i=1,j=n>>1;i<n-1;i++){
        if(i<j)std::swap(a[i],a[j]);
        for (k=n>>1;j>=k;j-=k,k>>=1);j+=k;
    }
}
void dft(cp *a,int n,int flag=1){
    rev(a,n);
    for (int m=2;m<=n;m<<=1)
    {
        cp wm=(cp){cos(flag*2*pi/m),sin(flag*2*pi/m)};
        for (int k=0;k<n;k+=m)
        {
            cp w=(cp){1.0,0.0};
            for (int j=k;j<k+(m>>1);j++,w=w*wm)
            {
                cp u=a[j],v=a[j+(m>>1)]*w;
                a[j]=u+v;
                a[j+(m>>1)]=u-v;
            }
        }
    }
}
void mul(cp *a,cp *b,int n){
    dft(a,n);dft(b,n);
    for (int i=0;i<n;i++)a[i]=a[i]*b[i];
    dft(a,n,-1);for (int i=0;i<n;i++)a[i].a/=n;
}

// FFT modulo prime

void rev(int *a,int n){
    int i,j,k;
    for (i=1,j=n>>1;i<n-1;i++){
        if(i<j)std::swap(a[i],a[j]);
        for (k=n>>1;j>=k;j-=k,k>>=1);j+=k;
    }
}
int fpow(int n,int e){
    int a=1,b=n;
    while(e){
        if(e&1){
            a=(1LL*a*b)%MOD;
        }
        e>>=1;
        b=(1LL*b*b)%MOD;
    }
    return a;
}
int inv(int n){
    return fpow(n, MOD-2);
}
void dft(int *a,int n,bool flag=true){
    rev(a,n);
    for (int m=2;m<=n;m<<=1)
    {
        // root is a primitive root, and root_inv is multiplicative inverse
        // (ask lemur :P)
        int wm = flag ? root : root_inv;
        wm = fpow(wm, (MOD-1)/m);
        for (int k=0;k<n;k+=m)
        {
            int w = 1;
            for (int j=k;j<k+(m>>1);j++,w=(1LL*w*wm)%MOD)
            {
                int u=a[j],v=(1LL*a[j+(m>>1)]*w)%MOD;
                a[j]=(u+v)%MOD;
                a[j+(m>>1)]=(u+MOD-v)%MOD;
            }
        }
    }
}
void mul(int *a,int *b,int n){
    int j=inv(n);
    dft(a,n);dft(b,n);
    for (int i=0;i<n;i++)a[i]=(1LL*a[i]*b[i])%MOD;
    dft(a,n,false);for (int i=0;i<n;i++)a[i]=(1LL*a[i]*j)%MOD;
}

