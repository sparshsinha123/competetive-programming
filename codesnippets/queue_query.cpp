template <typename T, class F = function<T(const T&, const T&)>>
struct stack_query{
    stack<T> val_stack , query_stack;
    F func;

    stack_query(){
        stack_query(nullptr);
    }
    stack_query(const F &f) : func(f) {}

    void push(T val){
        if(val_stack.empty()){
            val_stack.push(val);
            query_stack.push(val);
        } else{
            val_stack.push(val);
            query_stack.push(func(val , query_stack.top()));
        }
    }

    void pop(){
        assert(!val_stack.empty());
        val_stack.pop();
        query_stack.pop();
    }

    T top() const{
        return val_stack.top();
    }

    T query(){
        return query_stack.top();
    }

    bool empty(){
        return val_stack.empty();
    }

};


template <typename T, class F = function<T(const T&, const T&)>>
struct queue_query{

    stack_query<T> stk[2];
    F func;

    queue_query(const F &f) : func(f) {
        stk[0] = stack_query<T> (f);
        stk[1] = stack_query<T> (f);
    }

    void push(T val){
        stk[0].push(val);
    }

    void pop(){
        if(!stk[1].empty()){
            stk[1].pop();
            return;
        }
        while(!stk[0].empty()){
            stk[1].push(stk[0].top());
            stk[0].pop();
        }
        stk[1].pop();
    }

    T query(){
        if(stk[0].empty())
            return stk[1].query();
        else if(stk[1].empty()){
            return stk[0].query();
        } else return func(stk[0].query() , stk[1].query());
    }
  
};
