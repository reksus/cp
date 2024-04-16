struct vector_hash {
    template<class T>
    size_t operator()(const vector<T>& v) const {
        auto h1 = hash<T>{}(v[0]);
        auto h2 = hash<T>{}(v[1]);
        if (h1 ^ h2 != 0)
            return h1 ^ h2;
        else
            return h1;
    }
};

struct tuple_hash {
    template<class T, class U>
    size_t operator()(const tuple<T, U>& t) const {
        auto h1 = hash<T>{}(get<0>(t));
        auto h2 = hash<U>{}(get<1>(t));
        if (h1 ^ h2 != 0)
            return h1 ^ h2;
        else
            return h1;
    }
};