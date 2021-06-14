// find diameter in a connected tree
pair<int , int> find_farthest(int ver , int par = -1, int dist = 0){
    pair<int , int> mx = {dist , ver};
    for(auto child : g[ver]){
        if(child == par) continue;
        pair<int , int> t = find_farthest(child , ver, dist + 1);
        mx = max(mx , t);
    }
    return mx;
}
int find_diameter(int src){
    return find_farthest(find_farthest(src).second).first;
}
