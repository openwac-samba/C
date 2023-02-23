struct bt_node;

typedef struct bt_node
{
    void* key;
    void* content;
    int bal;
    struct bt_node* r;
    struct bt_node* l;
}bt_node; 

bt_node* push_bt (bt_node* n, void* key, void* content, int (* compare) (void*, void*), void (* insert) (void**, void*))
{
    if (!n)
    {
        n= new_node ();
        insert (&n->content, content);
        //Fix balance
    }
    else
    {
        int c= compare (n->key, key);
        if (!(c= compare))                                                           //Compare determined the keys to match
            insert (&n->content, content);
        else
            if (c> 0)
                n->r= push_bt (n->r, key, content, compare, insert);
            else
                n->l= push_bt (n->l, key, content, compare, insert);
    }
    return n;
}