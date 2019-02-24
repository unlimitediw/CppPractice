#include <utility>
#include <vector>


using namespace std;

class Node{

};

template<typename K>
class _HashFunc{
    size_t operator()(const K& key){
        return key;
    }
};

template<> //模版的特化
struct _HashFunc<string>
{
    size_t operator()(const string& key){
        return BKDRHash(key.c_str());
    }

    //字符串hash算法
    size_t BKDRHash(const char* str){
        register size_t hash = 0;
        while(*str){
            hash = hash * 131 + *str;
            str++;
        }
        return hash;
    }
};


template<typename K, typename V>
struct HashNode {
    HashNode(const pair<K, V> &_kv) : _kv(_kv) {}

    pair<K, V> _kv;
    HashNode<K, V> *_next;

    //may include the member initializer list, whose syntax is the colon character :, followed by the comma-separated list of one or more member-initializers,
    HashNode(pair<K, V> p)
            : _next(NULL), _kv(p)
    //next 为空， _kv为p
    {}
};

//需要自己定义HashFunc
//因为string是无法直接hash的，需要仿模函数转换
template<typename K, typename V, class HashFunc = _HashFunc <K>> //第三个参数是仿函数，为了实现存储str
class HashTable{
protected:
    //用一个vector作为一个指针数组来存储节点的指针，_size来保存当前哈希表中有效元素个数
    vector<Node*> _table;
    size_t _size;


    //Insert
    pair<Node*, bool> Insert(const pair<K,V>& p){
        if(_size == _table.size()){
            CheckCapacity();
        }
        size_t index = GetIndex(p.first); //定位下标，除留余数法

        Node* cur = _table[index];
        while(cur){
            //防沉余
            if(cur->_kv.first == p.first){
                return make_pair(cur,false);
            }
            cur = cur->_next;
        }

        Node* tmp = new Node(p);

        tmp->_next = _table[index]; //头插 到尾部自循环？
        _table[index] = tmp;

        ++_size;
        return make_pair(_table[index],true);
    }

    Node* Find(const K& key){
        size_t index = GetIndex(key);
        Node* cur = _table[index];
        while(cur){
            if(cur->_kv.first == key){

            }
        }
    }

    const size_t GetIndex(const K& key) const{
        HashFunc hf;
        size_t hash = hf(key);
        return hash % _table.size();
    }

    void CheckCapacity(){
        HashTable<K,V,HashFunc> ht(_table.size());
        for(size_t i = 0;i < _table.size(); ++i){
            Node* cur = _table[i];
            while(cur){
                ht.Insert(cur->_kv);
                cur = cur->_next;
            }
        }

        _table.swap(ht._table);
    }
};

