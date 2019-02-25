#include <utility>
#include <vector>


using namespace std;
/*
//学习代码
class Node{

};

template<typename K>
class _HashFunc{
    //size_t unsigned integer
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
                return cur;
            }
            cur = cur->_next;
        }
    }

    bool Erase(const K& key){
        size_t index = GetIndex(key);
        Node* cur = _table[index];
        Node* prev = NULL;

        while(cur){
            if(cur->_kv.first == key){
                if(prev == NULL){
                    _table[index] = cur->_next;
                }
                else{
                    prev->_next = cur->_next;
                }
                delete cur;
                --_size;
                return true;
            }
            prev = cur;
            cur = cur->_next;
        }
        return false;
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
 */

#include <vector>
#include <assert.h>

template<typename K, typename V>
struct HashNode{
    pair<K,V> _kv;
    HashNode<K,V>* _next;
    HashNode(pair<K,V> p)
            :_next(NULL)
            , _kv(p)
    {}
};

template<class K, class V, class HashFunc>
class HashTable;

template <typename K, typename V, typename HashFunc, typename Ref, typename Ptr>
struct HashTableIterator{
    typedef HashTableIterator<K,V,HashFunc,Ref,Ptr> Self;
    typedef HashTable<K,V,HashFunc> HashTable;
    typedef HashNode<K,V> Node;

    HashTableIterator(){}
    HashTableIterator(Node* ptr, const HashTable* table)
            : _ptr(ptr)
            , _hashtable(table)
    {}

    Ref operator*(){
        return _ptr->_kv;
    }

    Ptr operator->(){
        return &(operator*());
    }

    Self& operator++(){
        _ptr = _Next(_ptr);
        return *this;
    }

    Self operator++(int){
        Self tmp = *this;
        ++*this;
        return tmp;
    }

    bool operator==(const Self& s){
        return _ptr == s._ptr;
    }

    bool operator!=(const Self& s){
        return _ptr != s._ptr;
    }

    Node* _ptr;
    const HashTable* _hashtable;

protected:

    Node* _Next(Node* cur){
        assert(cur);
        Node* old = cur;
        cur = cur->_next;

        if(!cur){
            size_t index = _hashtable->GetIndex(old->_kv.first);
            while(!cur && ++index < _hashtable->GetTable()->size()) cur = _hashtable->GetTable()->operator[](index);
        }
        return cur;
    }
};

template<typename K>
struct _HashFunc
{
    size_t operator()(const K& key){
        return key;
    }
};

template<>
struct _HashFunc<string>
{
    size_t operator()(const string& key){
        return BKDRHash(key.c_str());
    }

    size_t BKDRHash(const char* str){
        register size_t hash = 0;
        while(*str){
            hash = hash * 131 + *str;
            str++;
        }
        return hash;
    }
};

template<typename K, typename V,class HashFunc = _HashFunc<K>>
class HashTable{
    typedef HashNode<K,V> Node;
public:
    typedef HashTableIterator<K,V,HashFunc,pair<K,V>&,pair<K,V>*> Iterator;
    typedef HashTableIterator<K,V,HashFunc,const pair<K,V>&, const pair<K,V>*> ConstIterator;
public:
    HashTable()
        :_size(0)
    {}

    HashTable(size_t size)
        :_size(0)
    {
        _table.resize(GetNextSize(size));
    }

    pair<Node*,bool> Insert(const pair<K,V>& p){
        if(_size == _table.size()){
            CheckCapacity();
        }
        size_t index = GetIndex(p.first);
        Node* cur = _table[index];
        while(cur){
            if(cur->_kv.first == p.first)
            {
                return make_pair(cur,false);
            }
            cur = cur->_next;
        }

        Node* tmp = new Node(p);
        tmp->_next = _table[index];
        _table[index] = tmp;

        ++_size;
        return make_pair(_table[index],true);
    }


    Node* Find(const K& key)
    {
        size_t index = GetIndex(key);

        Node* cur = _table[index];
        while (cur)
        {
            if (cur->_kv.first == key)
            {
                return cur;
            }

            cur = cur->_next;
        }

        return NULL;
    }

    bool Erase(const K& key)
    {
        size_t index = GetIndex(key);
        Node* cur = _table[index];
        Node* prev = NULL;

        while (cur)
        {
            if (cur->_kv.first == key)
            {
                if (prev == NULL)
                {
                    _table[index] = cur->_next;
                }
                else
                {
                    prev->_next = cur->_next;
                }
                delete cur;
                --_size;
                return true;
            }

            prev = cur;
            cur = cur->_next;
        }
        return false;
    }

    V& operator[](const K& key){
        pair<Node*,bool> ret;
        ret = Insert(make_pair(key,V()));

        return ret.first->_kv.second;
    }

    Iterator Begin() {
        for (size_t i = 0; i < _table.size(); ++i) {
            if (_table[i]) return Iterator(_table[i], this);
        }
        return End();
    }

    Iterator End(){
        return Iterator(NULL,this);
    }

    ConstIterator Begin() const{
        for(size_t i = 0;i<_table.size();++i) if(_table[i]) return ConstIterator(_table[i], this);
        return End();
    }

    ConstIterator End() const {
        return ConstIterator(NULL,this);
    }

    ~HashTable(){
        Clear();
    }

    void Clear(){
        for(size_t i =0;i <_table.size();++i){
            Node* cur = _table[i];
            Node* del = NULL;
            while(cur){
                del = cur;
                cur = cur->_next;
                delete del;
            }
            _table[i] = NULL;
        }
    }

    const size_t GetIndex(const K& key) const{
        HashFunc hf;
        size_t hash = hf(key);
        return hash % table_size();
    }

    const vector<Node*>* GetTable() const{
        return &_table;
    }

protected:

    void CheckCapacity(){
        HashTable<K,V,HashFunc> ht(_table.size());
        for(size_t i =0;i<_table.size();++i){
            Node* cur = _table[i];
            while(cur){
                ht.Insert(cur->_kv);
                cur = cur->_next;
            }
        }
        _table.swap(ht._table);
    }


    unsigned long GetNextSize(unsigned long size) //使用素数作为哈希表的大小可以减少哈希冲突
    {
        const int _PrimeSize = 28;
        static const unsigned long _PrimeList[_PrimeSize] =
                {
                        53ul, 97ul, 193ul, 389ul, 769ul,
                        1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
                        49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
                        1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
                        50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
                        1610612741ul, 3221225473ul, 4294967291ul
                };

        for (int i = 0; i < _PrimeSize; ++i)
        {
            if (_PrimeList[i] > size)
            {
                return _PrimeList[i];
            }
        }
        return 0;
    }
protected:
    vector<Node*> _table;
    size_t _size;
};




















































