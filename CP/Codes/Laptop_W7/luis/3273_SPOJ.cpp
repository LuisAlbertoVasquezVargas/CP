#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define vvi vector< vector<int> >
#define pii pair< int , int >
#define pll pair< ll , ll >
#define mp make_pair
#define fi first
#define se second
#define sc(x) scanf("%d",&x)
#define me(t,val) memset( t , val , sizeof(t) )
#define ones(x) __builtin_popcount(x)
#define test puts("test");
#define sync ios_base::sync_with_stdio(false);

#define N 100005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

struct Node {
    int key;
    int cnt;
    int priority;

    Node *left, *right;

    Node(){cnt = 0; priority = 0; left = right = NULL;}
    Node(int _key){cnt = 1; key = _key; priority = rand(); left = right = NULL;}
    Node(int _key, int pr){cnt = 1; key = _key; priority = pr; left = right = NULL;}
};

struct Treap {
    Node* root;

    Treap(){root = NULL; srand(time(NULL));}

    int TreeSize(Node* T)
    {
        return T==NULL?0:T->cnt;
    }

    void UpdateCnt(Node* &T)
    {
        if(T)
        {
            T->cnt = 1 + TreeSize(T->left) + TreeSize(T->right);
        }
    }

    void LeftRotate(Node* &T)
    {
        Node* temp = T->left;
        T->left = temp->right;
        temp->right = T;
        T = temp;

        UpdateCnt(T->right);
        UpdateCnt(T);
    }

    void RightRotate(Node* &T)
    {
        Node* temp = T->right;
        T->right = temp->left;
        temp->left = T;
        T = temp;

        UpdateCnt(T->left);
        UpdateCnt(T);
    }

    void Insert(Node* &T, int _key)
    {
        if(T == NULL)
        {
            T = new Node(_key);
            return;
        }

        if(T->key > _key)
        {
            Insert(T->left, _key);

            if(T->priority < T->left->priority)
                LeftRotate(T);
        }
        else if(T->key < _key)
        {
            Insert(T->right, _key);

            if(T->priority < T->right->priority)
                RightRotate(T);
        }

        UpdateCnt(T);
    }

    void Insert(int _key)
    {
        Insert(root, _key);
    }

    void Delete(Node* &T, int _key)
    {
        if(T == NULL)
            return;

        if(T->key > _key)
            Delete(T->left, _key);
        else if(T->key < _key)
            Delete(T->right, _key);
        else
        {
            if(T->left && T->right)
            {
                if(T->left->priority > T->right->priority)
                    LeftRotate(T);
                else
                    RightRotate(T);

                Delete(T, _key);
            }
            else
            {
                Node* temp = T;

                if(T->left)
                    T = T->left;
                else
                    T = T->right;

                delete temp;
            }
        }


        UpdateCnt(T);
    }

    void Delete(int _key)
    {
        Delete(root, _key);
    }

    int Count(Node* T, int bound)
    {
        if(T == NULL)
            return 0;

        if(T->key < bound)
            return 1 + TreeSize(T->left) + Count(T->right, bound);

        return Count(T->left, bound);
    }

    int Count(int bound)
    {
        return Count(root,bound);
    }

    int FindKth(Node* T, int k)
    {
        if(TreeSize(T) < k)
            return -INF;

        int sz = 1 + TreeSize(T->left);

        if(sz == k)
            return T->key;

        if(sz < k)
            return FindKth(T->right, k-sz);

        return FindKth(T->left,k);
    }

    int FindKth(int k)
    {
        return FindKth(root, k);
    }
};
char s[4];
int x;

int main()
{
	Treap T;
	int Q;
	sc( Q );
	while( Q-- )
	{
		scanf( "%s", s );
		sc( x );
		if( s[0] == 'D' )
			T.Delete(x);
		else if( s[0] == 'I' )
			T.Insert(x);
		else if( s[0] == 'C' )
			printf( "%d\n" , T.Count(x) );
		else
		{
			int val = T.FindKth(x);
			if( val<=-INF )
				puts( "invalid" );
			else printf( "%d\n" , val );
		}
	}
}


