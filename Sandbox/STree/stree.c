struct bt_node;

typedef struct bt_node
{
    void* key;
    void* content;
    struct bt_node* r;
    struct bt_node* l;
}bt_node; 

