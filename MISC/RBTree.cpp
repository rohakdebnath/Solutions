#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
struct node;
enum Color { RED, BLACK };

struct node {
    int val;
    Color color;
    node *left, *right, *parent;
    int size;
    i64 sum;
    i64 lazy;
    bool rev;
};
node* find(node* r, int i);
void left_rotate(node*& root, node* x);
void right_rotate(node*& root, node* x);
void rb_delete_fixup(node*& root, node* x);
void rb_insert_fixup(node*& root, node* z);
inline void push(node* t);
inline void pull(node* t);
node* NIL;
void init_nil() {
    static node singleton{0, BLACK, nullptr, nullptr, nullptr, 0, 0, 0, false};
    singleton.left = &singleton;
    singleton.right = &singleton;
    singleton.parent = &singleton;
    NIL = &singleton;
}

node* new_node(int val) {
    node* z = new node{val, RED, NIL, NIL, NIL, 1, val, 0, false};
    return z;
}

bool is_nil(node* x) {
    return (x == NIL);
}

inline void apply_add(node* t, i64 a);
inline bool is_red(node* x) { return !is_nil(x) and x->color == RED; }
inline bool is_black(node* x) { return is_nil(x) || x->color == BLACK; }
inline int  sz(node* t) { return is_nil(t) ? 0 : t->size; }
inline i64 sm(node* t) { return is_nil(t) ? 0LL : t->sum; }



int black_height(node* t) {
    int bh = 0;
    while (!is_nil(t)) {
        push(t);                       
        bh += is_black(t);
        t = t->left;                   
    }
    return bh;                         
}

node* maximum(node* x) {
    if (is_nil(x)) return NIL;
    for (;;) {
        push(x);                                
        if (is_nil(x->right)) break;
        x = x->right;
    }
    return x;
}

node* minimum(node* x) {
    if (is_nil(x)) return NIL;
    for (;;) {
        push(x);                              
        if (is_nil(x->left)) break;
        x = x->left;
    }
    return x;
}

node* predecessor(node* x) {
    if (is_nil(x)) return NIL;
    push(x);       
    if (!is_nil(x->left)) return maximum(x->left);
    node* y = x->parent;
    while (!is_nil(y) and x == y->left) { x = y; y = y->parent; }
    return y;
}

node* successor(node* x) {
    if (is_nil(x)) return NIL;
    push(x);       
    if (!is_nil(x->right)) return minimum(x->right);
    node* y = x->parent;
    while (!is_nil(y) and x == y->right) { x = y; y = y->parent; }
    return y;
}


inline void apply_add(node* t, i64 a) {
    if (is_nil(t)) return;
    t->val += a;                  
    t->sum += a * t->size;        
    t->lazy += a;                 
}

inline void apply_rev(node* t) {
    if (is_nil(t)) return;
    t->rev ^= 1;
    swap(t->left, t->right);
}


inline void push(node* t) {
    if (is_nil(t)) return;

    if (t->lazy != 0) {
        if (!is_nil(t->left))  apply_add(t->left,  t->lazy);
        if (!is_nil(t->right)) apply_add(t->right, t->lazy);
        t->lazy = 0;
    }

    if (t->rev) {
        apply_rev(t->left);
        apply_rev(t->right);
        t->rev = 0;
    }
}

inline void pull(node* t) {
    if (is_nil(t)) return;
    assert(t->lazy == 0);
    t->size = 1 + sz(t->left) + sz(t->right);
    t->sum  = sm(t->left) + t->val + sm(t->right);
}

void deletenode(node*& r, int i) {
    assert(i >= 0 and i < r->size);

    node* z = find(r, i);
    if (is_nil(z)) return;

    node* y;
    if (!is_nil(z->right) and !is_nil(z->left)) {
        push(z);
        y = minimum(z->right);
        swap(z->val, y->val);
        for (node* t = z; !is_nil(t); t = t->parent) pull(t);
    } else {
        y = z;
    }
    push(y); 
    node* x = !is_nil(y->left) ? y->left : y->right;
    Color yoc = y->color;

    if (is_nil(y->parent)) {
        r = x;
    } else if (y == y->parent->left) {
        y->parent->left = x;
    } else {
        y->parent->right = x;
    }
    x->parent = y->parent;
    delete y;

    node* t = x->parent;
    while (!is_nil(t)) {
        pull(t);
        t = t->parent;
    }
    
    if (yoc == BLACK) {
        if (x->color == RED) x->color = BLACK;
        else rb_delete_fixup(r, x);
    }

    if (!is_nil(r)) r->parent = NIL;
}

node* find(node* r, int i) {
    assert(i >= 0 and i < r->size);

    node* x = r;
    while (!is_nil(x)) {
        push(x);
        int L = x->left->size;

        if (i < L) {
            x = x->left;
        } else if (i == L) {
            return x;
        } else {
            x = x->right;
            i -= 1 + L;
        }
    }

    return NIL;
}

void insert(node*& r , int i, int val) { 
    int n = r->size;
    assert(i >= 0 and i <= n);

    node* x = r;
    node* p = NIL;
    int dir = -1; //0 if left 1 is right

    int j = i;
    while (!is_nil(x)) {
        push(x);
        int L = x->left->size;
        p = x;
        if (j <= L) {
            x = x->left;
            dir = 0;
        } else {
            j -= L + 1;
            x = x->right;
            dir = 1;
        }
    }

    node* z = new_node(val);
    z->parent = p;

    if (is_nil(p)) {
        r = z;
    } else if (dir == 0) {
        p->left = z;
    } else {
        p->right = z;
    }

    node* t = z;

    while (!is_nil(t)) {
        pull(t);
        t = t->parent;
    }
    rb_insert_fixup(r, z);
    if (!is_nil(r)) r->parent = NIL;
}


void left_rotate(node*& root, node* x) {
    push(x); 
    
    node* y = x->right;
    push(y);

    x->right = y->left;
    if (x->right != NIL) x->right->parent = x;
    y->parent = x->parent;
    if (x->parent == NIL) root = y;
    else if (x == x->parent->left) x->parent->left = y;
    else x->parent->right = y;
    y->left = x;
    x->parent = y;
    
    pull(x);
    pull(y);
}

void right_rotate(node*& root, node* x) {
    push(x); 
    node* y = x->left;
    push(y);

    x->left = y->right;
    if (x->left != NIL) x->left->parent = x;
    y->parent = x->parent;
    if (x->parent == NIL) root = y;
    else if (x == x->parent->right) x->parent->right = y;
    else x->parent->left = y;
    y->right = x;
    x->parent = y;
    
    pull(x);
    pull(y);
}

void rb_delete_fixup(node*& root, node* x) {
    while (x != root and is_black(x)) {
        node* a = x->parent;
        if (is_nil(a)) break;    

        push(a);
        bool x_on_left = (x == a->left);
        node* b = x_on_left ? a->right : a->left;
        if (!is_nil(b)) push(b);

        if (x_on_left) {
            if (is_red(b)) {
                b->color = BLACK; a->color = RED;
                left_rotate(root, a);
                push(a);                 
                b = a->right; if (!is_nil(b)) push(b);
            }
            if (is_black(b->left) and is_black(b->right)) {
                if (!is_nil(b)) b->color = RED;
                x = a;
            } else {
                if (is_black(b->right)) {
                    if (!is_nil(b->left)) b->left->color = BLACK;
                    b->color = RED;
                    right_rotate(root, b);
                    push(a);
                    b = a->right; if (!is_nil(b)) push(b);
                }
                b->color = a->color;
                a->color = BLACK;
                if (!is_nil(b->right)) b->right->color = BLACK;
                left_rotate(root, a);
                x = root;
            }
        } else {
            if (is_red(b)) {
                b->color = BLACK; a->color = RED;
                right_rotate(root, a);
                push(a);
                b = a->left; if (!is_nil(b)) push(b);
            }
            if (is_black(b->right) and is_black(b->left)) {
                if (!is_nil(b)) b->color = RED;
                x = a;
            } else {
                if (is_black(b->left)) {
                    if (!is_nil(b->right)) b->right->color = BLACK;
                    b->color = RED;
                    left_rotate(root, b);
                    push(a);
                    b = a->left; if (!is_nil(b)) push(b);
                }
                b->color = a->color;
                a->color = BLACK;
                if (!is_nil(b->left)) b->left->color = BLACK;
                right_rotate(root, a);
                x = root;
            }
        }
    }
    x->color = BLACK;
}

void rb_insert_fixup(node*& root, node* z) {
    while (!is_nil(z->parent) and is_red(z->parent)) {
        node* p = z->parent;
        node* g = p->parent;
        assert(!is_nil(g));

        push(g); 
        push(p);

        node* u = (p == g->left) ? g->right : g->left;
        if (!is_nil(u)) push(u); 

        if (is_red(u)) {
            p->color = BLACK;
            u->color = BLACK;
            g->color = RED;
            z = g;
        } else {
            if (p == g->left) {
                if (z == p->right) {
                    push(p);
                    
                    left_rotate(root, p);
                    z = p;
                    p = z->parent;  
                }
                push(g);
                
                right_rotate(root, g);
                swap(p->color, g->color);
            } else {
                if (z == p->left) {
                    push(p);
                    
                    right_rotate(root, p);
                    z = p;
                    p = z->parent;
                }
                push(g);
                
                left_rotate(root, g);
                std::swap(p->color, g->color);
            }
            break;
        }
    }

    while (!is_nil(root->parent)) root = root->parent;
    root->color = BLACK;
}

void print(node* root) {
    if (is_nil(root)) return;
    push(root);
    print(root->left);
    cout << (root->val) << " ";
    print(root->right);
}

void range_add(node* t, int base, int L, int R, i64 delta) {
    if (is_nil(t) || R < base || L > base + sz(t) - 1) return; 
    if (L <= base and base + sz(t) - 1 <= R) {
        apply_add(t, delta);  
        return;
    }
    push(t);
    int mid = base + sz(t->left);
    if (L <= mid - 1) range_add(t->left, base, L, R, delta);
    if (L <= mid and mid <= R) {
        t->val += delta;
    }
    if (mid + 1 <= R) range_add(t->right, mid + 1, L, R, delta);
    pull(t);
}

void add_range(node*& root, int l, int r, i64 delta) {
    if (is_nil(root) or l > r) return;
    assert(l >= 0 and r < root->size);
    range_add(root, 0, l, r, delta);
}

i64 range_sum(node* t, int base, int L, int R) {
    if (is_nil(t) or R < base or L > base + sz(t) - 1) return 0LL;
    if (L <= base and base + sz(t) - 1 <= R) return t->sum;

    push(t);
    int mid = base + sz(t->left);
    i64 ans = 0;
    if (L <= mid - 1) ans += range_sum(t->left, base, L, R);
    if (L <= mid and mid <= R) ans += t->val;
    if (mid + 1 <= R) ans += range_sum(t->right, mid + 1, L, R);
    return ans;
}

i64 sum_range(node* root, int l, int r) {
    if (is_nil(root) or l > r) return 0;
    assert(l >= 0 and r < root->size);
    return range_sum(root, 0, l, r);
}


node* join_with_separator(node* small, int bhSmall, node* large, int bhLarge, node* x, bool small_on_left) {
    if (!is_nil(small)) push(small);
    if (!is_nil(large)) push(large);
    if (!is_nil(x))     push(x); 
    if (is_nil(small) and is_nil(large)) {
        if (!is_nil(x)) { x->left = x->right = NIL; x->parent = NIL; x->color = BLACK; pull(x); }
        return x;
    }
    if (bhSmall > bhLarge) {
        swap(small, large);
        swap(bhSmall, bhLarge);
        small_on_left = !small_on_left;
    }

    if (bhLarge == bhSmall) {
        if (small_on_left) { x->left = small;  if (!is_nil(small))  small->parent = x;
            x->right= large;  if (!is_nil(large))  large->parent = x; 
        } else { x->left = large;  if (!is_nil(large))  large->parent = x;
            x->right= small;  if (!is_nil(small))  small->parent = x; 
        }
        x->parent = NIL; x->color = BLACK; pull(x);
        return x;
    }

    node* root = large;
    node* v = large;
    int curBH = bhLarge;   

    if (small_on_left) {
        while (true) {
            push(v);
            node* Lc = v->left;
            if (!is_nil(Lc)) push(Lc);
            int leftBH = curBH - (is_black(v) ? 1 : 0);
            if (leftBH == bhSmall and is_black(Lc)) break;
            v = Lc;                         
            curBH = leftBH;   
        }

        node* Tpp = v->left;  
        if (!is_nil(Tpp)) push(Tpp);               
        x->left  = small; if (!is_nil(small)) small->parent = x;
        x->right = Tpp;   if (!is_nil(Tpp))   Tpp->parent   = x;
        x->parent = v; x->color = RED;
        v->left = x;

        pull(x);
        for (node* t = v; !is_nil(t); t = t->parent) pull(t);
        if (is_red(v)) rb_insert_fixup(root, x);

    } else {
        while (true) {
            push(v);
            node* Rc = v->right;
            if (!is_nil(Rc)) push(Rc);
            int rightBH = curBH - (is_black(v) ? 1 : 0);
            if (rightBH == bhSmall and is_black(Rc)) break;
            v = Rc;                          
            curBH = rightBH;
        }

        node* Tpp = v->right;          
        if (!is_nil(Tpp)) push(Tpp);     
        x->right = small; if (!is_nil(small)) small->parent = x;
        x->left  = Tpp;   if (!is_nil(Tpp))   Tpp->parent   = x;
        x->parent = v; x->color = RED;
        v->right = x;

        pull(x);
        for (node* t = v; !is_nil(t); t = t->parent) pull(t);
        if (is_red(v)) rb_insert_fixup(root, x);
    }

    if (!is_nil(root)) { root->parent = NIL; root->color = BLACK; }
    return root;
}

node* special_union(node*& L, node*& R) {
    if (!is_nil(L)) push(L);
    if (!is_nil(R)) push(R);
    if (is_nil(L)) { if (!is_nil(R)) { R->parent = NIL; R->color = BLACK; } return R; }
    if (is_nil(R)) { if (!is_nil(L)) { L->parent = NIL; L->color = BLACK; } return L; }

    int bhL = black_height(L);
    int bhR = black_height(R);

    if (bhR >= bhL) {
        i64 xval = minimum(R)->val;
        deletenode(R, 0);                     
        if (!is_nil(R)) { R->parent = NIL; R->color = BLACK; }
        bhR = is_nil(R) ? 0 : black_height(R);
        node* x = new_node(xval); 
        return join_with_separator(L, bhL, R, bhR, x, true);
    }

    i64 xval = maximum(L)->val;
    deletenode(L, L->size - 1);
    if (!is_nil(L)) { L->parent = NIL; L->color = BLACK; }
    bhL = is_nil(L) ? 0 : black_height(L);
    node* x = new_node(xval);
    return join_with_separator(R, bhR, L, bhL, x, false);
}

inline int bh_child_of(node* v, int bh_v) {
    return bh_v - is_black(v);
}

inline void make_separator(node* x) {
    push(x);
    node* Lc = x->left;
    node* Rc = x->right;
    if (!is_nil(Lc)) push(Lc), Lc->parent = NIL; 
    if (!is_nil(Rc)) push(Rc), Rc->parent = NIL;
    x->left  = NIL;
    x->right = NIL;
    x->parent = NIL;
    x->color  = RED;
    x->size   = 1;
    x->sum    = x->val;
}

inline int joined_bh(int bhA, int bhB) {
    return (bhA == bhB) ? (bhA + 1) : max(bhA, bhB);
}

inline void insert_max(node*& root, node* x) {
    make_separator(x); 
    if (is_nil(root)) {
        x->color = BLACK;
        pull(x);
        root = x;
        return;
    }

    node* cur = root;
    for (;;) {
        push(cur);                             
        if (is_nil(cur->right)) break;         
        cur = cur->right;
    }
    cur->right = x; x->parent = cur;

    rb_insert_fixup(root, x);

    for (node* t = x; !is_nil(t); t = t->parent) pull(t);
    while (!is_nil(root->parent)) root = root->parent;
}

inline void insert_min(node*& root, node* x) {
    make_separator(x);

    if (is_nil(root)) {
        x->color = BLACK;
        pull(x);
        root = x;
        return;
    }

    node* cur = root;
    for (;;) {
        push(cur);                              
        if (is_nil(cur->left)) break;        
        cur = cur->left;
    }
    cur->left = x; x->parent = cur;

    rb_insert_fixup(root, x);

    for (node* t = x; !is_nil(t); t = t->parent) pull(t);
    while (!is_nil(root->parent)) root = root->parent;
}

pair<node*, node*> special_split(node* root, int i) {
    if (is_nil(root)) return {NIL, NIL};
    push(root);  

    node *L = NIL, *R = NIL;      
    node *l = NIL, *r = NIL; 
    int bhL = 0, bhR = 0;

    int bhCur = black_height(root);
    node* cur = root;
    int idx = i;

    while (!is_nil(cur)) {
        push(cur);
        int leftSize = cur->left->size;
        int bhChild  = bhCur - (is_black(cur) ? 1 : 0); 

        if (idx < leftSize) {
            node* P = cur->right;
            cur->right = NIL;
            if (!is_nil(P)) {
                push(P);    
                P->parent = NIL;
            }
            if (!is_nil(P)) {
                if (is_nil(R)) {
                    R = P;
                    bhR = bhChild + (!is_black(R) ? 1 : 0);
                    R->parent = NIL;       
                    R->color  = BLACK;     
                    pull(R);               
                } else {
                    assert(!is_nil(r));
                    R   = join_with_separator(P, bhChild, R, bhR, r, true);
                    bhR = joined_bh(bhChild, bhR);
                    r   = NIL;
                }
            } else {
                if (!is_nil(r)) {
                    if (is_nil(R)) {
                        R = r;
                        R->parent = NIL;
                        R->color  = BLACK;
                        pull(R);
                        bhR = 1;
                    } else {
                        insert_min(R, r);
                        bhR = black_height(R);
                    }
                    r = NIL;
                }
            }

            auto temp = cur;
            cur = cur->left;
            bhCur = bhChild; 
            make_separator(temp);
            r = temp;

            bhCur = bhChild;
            continue;
        }


        if (idx == leftSize) {
            if (!is_nil(cur->left)) {
                node* P = cur->left;
                cur->left = NIL;
                if (!is_nil(P)) {
                    push(P);    
                    P->parent = NIL;
                }
                if (is_nil(L)) {
                    L = P;
                    bhL = bhChild + (!is_black(L) ? 1 : 0);
                    L->parent = NIL;       
                    L->color  = BLACK;     
                    pull(L);               
                } else {
                    assert(!is_nil(l));
                    L = join_with_separator(L, bhL, P, bhChild, l, true);
                    bhL = joined_bh(bhL, bhChild);
                    l = NIL;
                }
            }

            if (!is_nil(cur->right)) {
                node* P = cur->right;
                cur->right = NIL;
                if (!is_nil(P)) {
                    push(P);    
                    P->parent = NIL;
                }
                if (is_nil(R)) {
                    R = P;
                    bhR = bhChild + (!is_black(R) ? 1 : 0);
                    R->parent = NIL;       
                    R->color  = BLACK;     
                    pull(R);  
                } else {
                    assert(!is_nil(r));
                    R = join_with_separator(P, bhChild, R, bhR, r, true);
                    bhR = joined_bh(bhChild, bhR);
                    r = NIL;
                }
            }
            
            if (!is_nil(l)) {
                if (is_nil(L)) {
                    L = l;
                    L->parent = NIL;
                    L->color  = BLACK;
                    pull(L);
                    bhL = 1;
                } else {
                    insert_max(L, l);
                    bhL = black_height(L);
                }
                l = NIL;
            }

            make_separator(cur);
            if (is_nil(L)) {
                L = cur;
                L->parent = NIL;
                L->color = BLACK;
                pull(L);
                bhL = 1;
            } else {
                insert_max(L, cur);
                bhL = black_height(L);
            }
            if (!is_nil(r)) {
                if (is_nil(R)) {
                    R = r;
                    R->parent = NIL;
                    R->color = BLACK;
                    pull(R);
                    bhR = 1;  
                } else {
                    insert_min(R, r);
                    bhR = black_height(R);
                }
                r = NIL;
            }

            if (!is_nil(L)) { L->parent = NIL; L->color = BLACK; }
            if (!is_nil(R)) { R->parent = NIL; R->color = BLACK; }
            return {L, R};
        }

        if (!is_nil(cur->left)) {
            node* P = cur->left;
            cur->left = NIL;
            if (!is_nil(P)) {
                push(P);    
                P->parent = NIL;
            }
            if (is_nil(L)) {
                L = P;
                bhL = bhChild + (!is_black(L) ? 1 : 0);
                L->parent = NIL;       
                L->color  = BLACK;     
                pull(L);               
            } else {
                assert(!is_nil(l));
                L   = join_with_separator(L, bhL, P, bhChild, l, true);
                bhL = joined_bh(bhL, bhChild);
                l   = NIL;
            }
        } else {
            if (!is_nil(l)) {
                if (is_nil(L)) {
                    L = l;
                    L->parent = NIL;
                    L->color  = BLACK;
                    pull(L);
                    bhL = 1; 
                } else {
                    insert_max(L, l);
                    bhL = black_height(L);
                }
                l = NIL;
            }
        }

        idx -= (leftSize + 1);
        auto temp = cur;
        cur = cur->right;
        bhCur = bhChild; 
        make_separator(temp);
        l = temp;

        bhCur = bhChild;
    }

    if (!is_nil(l)) {
        if (is_nil(L)) {
            L = l;
            L->parent = NIL;
            L->color  = BLACK;
            pull(L);
            bhL = 1;                        
        } else {
            insert_max(L, l);
            bhL = black_height(L);       
        }
        l = NIL;
    }

    if (!is_nil(r)) {
        if (is_nil(R)) {
            R = r;
            R->parent = NIL;
            R->color  = BLACK;
            pull(R);
            bhR = 1;
        } else {
            insert_min(R, r);
            bhR = black_height(R);
        }
        r = NIL;
    }

    if (!is_nil(L)) { L->parent = NIL; L->color = BLACK; }
    if (!is_nil(R)) { R->parent = NIL; R->color = BLACK; }
    return {L, R};
}

void range_reverse(node*& root, int l, int r) {
    if (is_nil(root) || l > r) return;
    assert(l >= 0 and r < root->size);

    auto [A, B] = l - 1 < 0 ? make_pair(NIL, root) : special_split(root, l - 1);          
    auto [M, C] = special_split(B, r - l);       
    if (!is_nil(M)) apply_rev(M);     
    auto t = special_union(M, C);
    root = special_union(A, t);
    if (!is_nil(root)) { root->parent = NIL; root->color = BLACK; }
}


signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    init_nil();
    node* root = NIL;

    while (true) {
        int t; cin >> t;
        if (t == 0) { //insert
            int b, c; cin >> b >> c;
            insert(root, b, c);
        } else if (t == 1) { //delete
            int b; cin >> b;
            deletenode(root, b);
        } else if (t == 2) {
            int b, c, d; cin >> b >> c >> d;
            add_range(root, b, c, d);
        } else if (t == 3) {
            int b, c; cin >> b >> c;
            cout << sum_range(root, b, c) << '\n';
        } else if (t == 4){
            print(root);
            cout << '\n';
        } else if (t == 5) {
            int b, c; cin >> b >> c;
            range_reverse(root, b, c);
        } else {
            int b; cin >> b;
            auto x = special_split(root, b);
            print(x.first);
            cout << '\n';
            print(x.second);
            cout << '\n';

            root = special_union(x.first, x.second);

            print(root);
        }
    }

    return 0;
}


// ============================ TEST HARNESS (DROP-IN) ============================

// // ---------- DEBUG PRINTING ----------
// enum OpType { OP_INSERT=0, OP_ERASE=1, OP_ADD=2, OP_SUM=3, OP_REV=4 };

// struct OpRec {
//     OpType op;
//     int a=0, b=0, c=0;   // meaning depends on op
//     long long ret=LLONG_MIN; // for SUM results (tree)
// };

// static uint64_t g_seed = 0x0000000000ULL;
// static int g_step = 0;               // 1-based step counter
// static std::vector<OpRec> g_ops;     // full history

// static const char* opname(OpType t) {
//     switch (t) {
//         case OP_INSERT: return "INSERT";
//         case OP_ERASE:  return "ERASE";
//         case OP_ADD:    return "ADD";
//         case OP_SUM:    return "SUM";
//         case OP_REV:    return "REVERSE";
//     }
//     return "?";
// }

// static void print_last_ops(int k = 20) {
//     int n = (int)g_ops.size();
//     int s = std::max(0, n - k);
//     std::cerr << "=== Last " << (n - s) << " ops (most recent last) ===\n";
//     for (int i = s; i < n; ++i) {
//         const auto& o = g_ops[i];
//         std::cerr << "#" << (i+1) << " " << opname(o.op) << " ";
//         if (o.op == OP_INSERT) std::cerr << "pos=" << o.a << " val=" << o.b;
//         else if (o.op == OP_ERASE) std::cerr << "pos=" << o.a;
//         else if (o.op == OP_ADD) std::cerr << "L=" << o.a << " R=" << o.b << " d=" << o.c;
//         else if (o.op == OP_SUM) std::cerr << "L=" << o.a << " R=" << o.b << " treeSum=" << o.ret;
//         else if (o.op == OP_REV) std::cerr << "L=" << o.a << " R=" << o.b;
//         std::cerr << "\n";
//     }
// }

// static inline const char* col(node* t) { return is_nil(t) ? "B" : (is_black(t) ? "B" : "R"); }

// static void dump_tree(node* t, int depth = 0) {
//     if (is_nil(t)) {
//         std::cerr << std::string(depth*2, ' ') << "·(NIL,B)\n";
//         return;
//     }
//     // Push so children reflect the real orientation before printing
//     push(t);

//     // Print as rotated tree: right subtree on top
//     dump_tree(t->right, depth + 1);

//     std::cerr << std::string(depth*2, ' ')
//               << (void*)t << " "
//               << (is_black(t) ? "[B] " : "[R] ")
//               << "val=" << t->val
//               << " size=" << t->size
//               << " sum="  << t->sum
//               << " lazy=" << t->lazy
//               << " rev="  << (t->rev ? 1 : 0)
//               << " L=" << (is_nil(t->left)  ? "NIL" : col(t->left))
//               << " R=" << (is_nil(t->right) ? "NIL" : col(t->right))
//               << " P=" << (is_nil(t->parent)? "NIL" : (is_black(t->parent) ? "B" : "R"))
//               << "\n";

//     dump_tree(t->left, depth + 1);
// }

// // In-order dump (compact)
// static void dump_inorder(node* t) {
//     if (is_nil(t)) return;
//     push(t);
//     dump_inorder(t->left);
//     std::cerr << t->val << (is_black(t) ? "[B]" : "[R]") << " ";
//     dump_inorder(t->right);
// }


// static inline void inorder_to_vec(node* t, std::vector<int>& out) {
//     if (is_nil(t)) return;
//     push(t); // ensure orientation & lazies are applied before using children
//     inorder_to_vec(t->left, out);
//     out.push_back(t->val);
//     inorder_to_vec(t->right, out);
// }

// static inline long long total_sum(node* t) {
//     return is_nil(t) ? 0LL : t->sum;
// }

// static inline void assert_tree_equals_vec(node* root, const std::vector<int>& v) {
//     std::vector<int> tv;
//     tv.reserve(is_nil(root) ? 0 : root->size);
//     inorder_to_vec(root, tv);

//     if (tv.size() != v.size()) {
//         std::cerr << "SIZE mismatch: tree=" << tv.size() << " vec=" << v.size() << "\n";
//         std::exit(1);
//     }
//     for (size_t i = 0; i < v.size(); ++i) {
//         if (tv[i] != v[i]) {
//             std::cerr << "VALUE mismatch at i=" << i << " tree=" << tv[i] << " vec=" << v[i] << "\n";
//             std::cerr << "Tree: "; for (int x: tv) std::cerr << x << " "; std::cerr << "\n";
//             std::cerr << "Vec : "; for (int x: v ) std::cerr << x << " "; std::cerr << "\n";
//             std::exit(1);
//         }
//     }
//     long long vsum = 0;
//     for (int x : v) vsum += x;
//     long long tsum = total_sum(root);
//     if (tsum != vsum) {
//         std::cerr << "SUM mismatch: tree=" << tsum << " vec=" << vsum << "\n";
//         std::exit(1);
//     }
// }

// // returns (ok, black_height), prints details on failure
// static std::pair<bool,int> rb_check_rec_report(node* t) {
//     if (is_nil(t)) return {true, 1};
//     push(t);
//     auto [okL, bhL] = rb_check_rec_report(t->left);
//     auto [okR, bhR] = rb_check_rec_report(t->right);
//     bool ok = okL and okR and (bhL == bhR);
//     if (t->color == RED) {
//         if (!is_black(t->left) || !is_black(t->right)) ok = false;
//     }
//     return {ok, bhL + (is_black(t) ? 1 : 0)};
// }

// static inline bool check_rb_ok(node* root) {
//     if (is_nil(root)) return true;
//     auto [ok, _bh] = rb_check_rec_report(root);
//     if (!ok || root->color != BLACK) {
//         std::cerr << "Red-Black properties violated at step #" << g_step << ".\n";
//         if (root->color != BLACK) std::cerr << "Root is not BLACK.\n";
//         print_last_ops(30);
//         std::cerr << "Seed=0x" << std::hex << g_seed << std::dec << "\n";
//         std::cerr << "=== TREE (rotated; right on top) ===\n";
//         dump_tree(root);
//         std::cerr << "=== INORDER (val[color]) ===\n";
//         dump_inorder(root);
//         std::cerr << "\n";
//         return false;
//     }
//     root->parent = NIL;  // normalize
//     return true;
// }

// int main() {
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(nullptr);

//     init_nil();
//     node* root = NIL;
//     std::vector<int> ref; // oracle

//     // ---------- deterministic smoke ----------
//     // Insert 0..9 at the end
//     for (int i = 0; i < 10; ++i) { insert(root, (int)ref.size(), i); ref.push_back(i); }
//     assert_tree_equals_vec(root, ref);  check_rb_ok(root);

//     // Reverse middle [3..7]
//     range_reverse(root, 3, 7); std::reverse(ref.begin()+3, ref.begin()+8);
//     assert_tree_equals_vec(root, ref);  check_rb_ok(root);

//     // Add range [2..6] by +5
//     add_range(root, 2, 6, 5); for (int i=2;i<=6;++i) ref[i]+=5;
//     assert_tree_equals_vec(root, ref);  check_rb_ok(root);

//     // Delete at 0, then insert at 0
//     deletenode(root, 0); ref.erase(ref.begin()+0);
//     insert(root, 0, 42); ref.insert(ref.begin()+0, 42);
//     assert_tree_equals_vec(root, ref);  check_rb_ok(root);

//     // Reverse entire array
//     if (!ref.empty()) { range_reverse(root, 0, (int)ref.size()-1); std::reverse(ref.begin(), ref.end()); }
//     assert_tree_equals_vec(root, ref);  check_rb_ok(root);

//     // ---------- randomized stress ----------
//     // Fixed seed for reproducibility (change if you like)
//     std::mt19937_64 rng(0xA17E5BAD5FFFULL);
//     const int INIT_N = 100;     // initial elements
//     const int OPS    = 100000;   // number of random operations

//     // rebuild random initial array
//     root = NIL; ref.clear();
//     for (int i = 0; i < INIT_N; ++i) {
//         int val = (int)(rng()%2000) - 1000;
//         insert(root, i, val);
//         ref.insert(ref.begin()+i, val);
//     }
//     assert_tree_equals_vec(root, ref);  check_rb_ok(root);

//     // helper lambdas for oracle
//     auto oracle_add = [&](int L, int R, int d){
//         for (int i=L;i<=R;++i) ref[i] += d;
//     };
//     auto oracle_sum = [&](int L, int R){
//         long long s=0; for (int i=L;i<=R;++i) s += ref[i]; return s;
//     };
//     auto oracle_reverse = [&](int L, int R){
//         std::reverse(ref.begin()+L, ref.begin()+R+1);
//     };

//     for (int step = 1; step <= OPS; ++step) {
//         int op = (int)(rng() % 5);  // 0=insert 1=erase 2=add 3=sum 4=rev
//         if (ref.empty() and op != 0) op = 0;

//         OpRec rec{};
//         if (op == 0) { // INSERT [0..n]
//             int n = (int)ref.size();
//             int pos = (int)(rng() % (n + 1));
//             int val = (int)(rng()%2000) - 1000;
//             rec.op = OP_INSERT; rec.a = pos; rec.b = val;

//             g_ops.push_back(rec);
//             insert(root, pos, val);
//             ref.insert(ref.begin()+pos, val);

//         } else if (op == 1) { // ERASE [0..n-1]
//             int n = (int)ref.size();
//             int pos = (int)(rng() % n);
//             rec.op = OP_ERASE; rec.a = pos;

//             g_ops.push_back(rec);
//             deletenode(root, pos);
//             ref.erase(ref.begin()+pos);

//         } else if (op == 2) { // ADD [L..R]
//             int n = (int)ref.size();
//             int L = (int)(rng() % n);
//             int R = (int)(rng() % n);
//             if (L > R) std::swap(L, R);
//             int d = (int)(rng()%200) - 100;
//             rec.op = OP_ADD; rec.a = L; rec.b = R; rec.c = d;

//             g_ops.push_back(rec);
//             add_range(root, L, R, d);
//             for (int i=L;i<=R;++i) ref[i]+=d;

//         } else if (op == 3) { // SUM [L..R]
//             int n = (int)ref.size();
//             int L = (int)(rng() % n);
//             int R = (int)(rng() % n);
//             if (L > R) std::swap(L, R);
//             rec.op = OP_SUM; rec.a = L; rec.b = R;

//             long long t = sum_range(root, L, R);
//             long long v = 0; for (int i=L;i<=R;++i) v+=ref[i];
//             rec.ret = t; g_ops.push_back(rec);
//             if (t != v) {
//                 std::cerr << "SUM mismatch at step #" << step
//                           << " ["<<L<<","<<R<<"] tree="<<t<<" vec="<<v<<"\n";
//                 print_last_ops(30);
//                 std::vector<int> tv; inorder_to_vec(root, tv);
//                 std::cerr << "Tree: "; for (int x: tv) std::cerr << x << " "; std::cerr << "\n";
//                 std::cerr << "Vec : "; for (int x: ref) std::cerr << x << " "; std::cerr << "\n";
//                 std::cerr << "Seed=0x" << std::hex << g_seed << std::dec << "\n";
//                 return 1;
//             }

//         } 
//         // else { // REVERSE [L..R]
//         //     int n = (int)ref.size();
//         //     int L = (int)(rng() % n);
//         //     int R = (int)(rng() % n);
//         //     if (L > R) std::swap(L, R);
//         //     rec.op = OP_REV; rec.a = L; rec.b = R;

//         //     g_ops.push_back(rec);
//         //     range_reverse(root, L, R);
//         //     std::reverse(ref.begin()+L, ref.begin()+R+1);
//         // }

//         // validate after each op
//         if (!check_rb_ok(root)) return 1;
//         assert_tree_equals_vec(root, ref);

//         ++g_step; // move to next step only after a successful validation
//     }


//     std::cout << "All tests passed.\n";
//     return 0;
// }
// // ========================== END TEST HARNESS ==========================





#include <bits/stdc++.h>
using namespace std;

int maxPathSumWithSkip(int N, vector<int> A, vector<vector<int>> edges) {
    vector<vector<int>> g(N);
    for (auto &e : edges) {
        g[e[0]].push_back(e[1]);
        g[e[1]].push_back(e[0]);
    }
    vector<long long> down0(N), down1(N);
    long long ans = LLONG_MIN;
    function<void(int,int)> dfs = [&](int u, int p) {
        vector<int> ch;
        for (int v : g[u]) if (v != p) {
            dfs(v, u);
            ch.push_back(v);
        }
        long long best0_nonneg = 0, best1_nonneg = 0, best0_pos = LLONG_MIN;
        for (int v : ch) {
            best0_nonneg = max(best0_nonneg, down0[v]);
            best1_nonneg = max(best1_nonneg, down1[v]);
            best0_pos = max(best0_pos, down0[v]);
        }
        if (best0_nonneg < 0) best0_nonneg = 0;
        if (best1_nonneg < 0) best1_nonneg = 0;
        long long d0 = A[u] + best0_nonneg;
        long long opt1 = A[u] + best1_nonneg;
        long long opt2 = LLONG_MIN;
        if (best0_pos > 0) opt2 = best0_pos;
        long long d1 = max(opt1, opt2);
        down0[u] = d0;
        down1[u] = d1;
        ans = max({ans, (long long)A[u], d0, d1});
        vector<long long> c0, c1;
        for (int v : ch) {
            c0.push_back(max(0LL, down0[v]));
            c1.push_back(max(0LL, down1[v]));
        }
        long long best1c0 = 0, best2c0 = 0;
        int id1 = -1;
        for (int i = 0; i < (int)c0.size(); i++) {
            if (c0[i] > best1c0) { best2c0 = best1c0; best1c0 = c0[i]; id1 = i; }
            else if (c0[i] > best2c0) best2c0 = c0[i];
        }
        if (best2c0 > 0) ans = max(ans, A[u] + best1c0 + best2c0);
        if (best2c0 > 0) ans = max(ans, best1c0 + best2c0);
        long long best_cross = LLONG_MIN;
        for (int i = 0; i < (int)c1.size(); i++) {
            if (c1[i] <= 0) continue;
            long long other = (i != id1 ? best1c0 : best2c0);
            if (other <= 0) continue;
            best_cross = max(best_cross, c1[i] + other);
        }
        if (best_cross > LLONG_MIN / 2) ans = max(ans, A[u] + best_cross);
    };
    dfs(0, -1);
    return (int)ans;
}
