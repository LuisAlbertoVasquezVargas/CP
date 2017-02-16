using namespace std;
struct Node{
    int key , priority , size;
    Node* left , *right;
    Node( int k ): key( k ) , left( NULL ) , right( NULL ) , priority( rand() ) , size( 0 ){}
};

int sz( Node* root ){
    if( root == NULL ) return 0; return root -> size;
}

Node* upd( Node* root ){
    if( root != NULL ){
        root -> size = 1 + sz( root -> left ) + sz( root -> right );
    }
    return root;
}

bool find( Node* root , int key ){
    bool ans = false;
    if( root == NULL ) return ans;
    if( root -> key == key ) return ans = true;
    if( root -> key > key ) ans = find( root -> left , key );
    else if( root -> key < key ) ans = find( root -> right , key );
    return ans;
}

Node* rotRight( Node *root ){
    Node* tmp = root -> left;
    root -> left = tmp -> right;
    tmp -> right = root;
    upd( root );
    return upd( tmp );
}

Node* rotLeft( Node *root ){
    Node* pivot = root -> right;
    root -> right = pivot -> left;
    pivot -> left = root;
    upd( root );
    return upd( pivot );
}

//insercion mediante rotaciones en maxheap
Node* insert( Node *root , Node *novo ){
    if( root == NULL ) return upd( novo );
    if( root -> key < novo -> key ){
        root -> right = insert( root -> right , novo );
        if( root -> right -> priority > root -> priority ) root = rotLeft( root );
    }
    else if( root -> key > novo -> key ){
        root -> left = insert( root -> left , novo );
        if( root -> left -> priority > root -> priority ) root = rotRight( root );
    }
    return upd( root );
}

//borrado con rotaciones
Node* erase( Node* root , int key ){
    if( root == NULL ){ return root; }
    if( root -> key < key ) root -> right = erase( root -> right , key );
    else if( root -> key > key ) root -> left = erase( root -> left , key );
    else{
        if( root -> left != NULL ){
            if( root -> right != NULL ){
                if( root -> left -> priority < root -> right -> priority ){
                    root = rotLeft( root );
                    root -> left = erase( root -> left , key );
                }else{
                    root = rotRight( root );
                    root -> right = erase( root -> right , key );
                }
            }
            else{
                Node* aux = root -> left;
                delete root;
                return aux;
            }
        }
        else{
            if( root -> right != NULL ){
                Node* aux = root -> right;
                delete root;
                return aux;
            }
            else{
                delete root;
                return NULL;
            }
        }
    }
    return upd( root );
}
Node* clear( Node* root ){
    if( root != NULL ){
        clear( root -> left );
        clear( root -> right );
        delete root;
    }
}

Node* find_kth( Node *root , int k ){
    if( sz( root ) < k ) return NULL;
    int ans = 1 + sz( root -> left );
    if( ans == k ) return root;
    if( ans < k ) return find_kth( root -> right , k - ans );
    return find_kth( root -> left , k );
}

vector<int> index;
void Traverse( Node *root ){
    if( root == NULL ) return;
    index.push_back( root -> key );
    Traverse( root -> left );
    Traverse( root -> right );
}

int main(){
    int k , n , p;
    string s = "", aux;
    char c;
    cin>>k>>aux>>n;

    for( int i = 0 ; i < k ; ++i ) s += aux;
    Node* tree[ 27 ];
    for( int i = 0 ; i < 27 ; ++i ) tree[ i ] = NULL;
    for( int i = 0 ; i < s.length() ; ++i ){
        tree[ s[ i ] - 'a' ] = insert( tree[ s[ i ] - 'a' ] , new Node( i ) );
    }
    while( n-- ){
        cin>>p>>c;
        Node* aux = find_kth( tree[ c - 'a' ] , p );
        tree[ c - 'a' ] = erase( tree[ c - 'a' ] , aux -> key );
    }
    for( int i = 0 ; i < 27 ; ++i ) Traverse( tree[ i ] );
    sort( index.begin() , index.end() );
    aux = "";
    for( int i = 0 ; i < index.size() ; ++i ) aux += s[ index[ i ] ];
    for( int i = 0 ; i < 27 ; ++i ) clear( tree[ i ] );
    cout<<aux<<endl;
    return 0;
}
