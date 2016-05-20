#include "graph.h"

void Graph::addEdge(unsigned int i, unsigned int j){
    if(i>=getNbVertices() || j>=getNbVertices())
        throw GraphException("Errn : Vertices of arcs not defined");
    adj[i].push_back(j);
    nbEdges++;
    // Ou adj.insert(adj.end(),j);
}

void Graph::removeEdge(unsigned int i, unsigned int j){
    if(i>=getNbVertices() || j>=getNbVertices())
        throw GraphException("Errn : Vertices of arcs not defined");
    list <unsigned int>::iterator it = find (adj[i].begin(), adj[i].end(), j);
    if(it!=adj[i].end()){
        adj[i].erase(it);
        nbEdges--;
    }

}

const list<unsigned int> Graph::getSuccessors(unsigned int i) const{
    if(i>=getNbVertices())
        throw GraphException("Errn : Vector not defined");
    return adj[i];
}

const list<unsigned int> Graph::getPredecessors(unsigned int j) const{
    if(j>=getNbVertices())
        throw GraphException("Errn : Vector not defined");
    list <unsigned int> res;
    for(unsigned int i=0; i<adj.size(); i++){
        if (find(adj[i].begin(), adj[i].end(), j)!=adj[i].end())
            res.insert(res.end(),i);
    }
    return res;
}

ostream& operator<<(ostream& f, const Graph& G){
    f<<"Graph"<<G.getName()<<" ("<<G.getNbVertices()<<" vertices and "<<G.getNbEdges()<<" edges"<<"\n";
    for(unsigned int i=0; i<G.getNbVertices();i++){
        f<<i<<": ";
        for(list<unsigned int>::const_iterator it=G.getSuccessors(i).begin(); it!=G.getSuccessors(i).end(); ++it)
            f<<*it<<" ";
    }
    return f;
}

template <class V>
void GraphG<V>::addVertex(const V &i){
    adj[i];//=set<V>();
    //ou adj.insert(make_pair(i, set<V>());
    //OU map(V,set<V>())::iterator it=adj.find(i);
    //if (it==adj.end()) adj[i]=set<V>();
}

template <class V>
void GraphG<V>::addEdge(const V &i, const V &j){
    bool rep = adj[i].insert(j).second;
    if(rep) nbEdges++;
}

template <class V>
void GraphG<V>::removeEdge(const V &i, const V &j){
    typename map<V, set<V> >::iterator it=adj.find(i);
    if(it!=adj.end()){
        nbEdges--;
        it->second.erease(j);
    }
}

template<class V>
void GraphG<V>::removeVertex(const V &i){
    for(typename map<V,set<V> >::const_iterator it=adj.begin();it!=adj.end();it++)
        removeEdge(it->first, i);
    adj.erase(i);
}

template<class V>
void GraphG<V>::print(ostream &f) const{
    f<<"Graph "<<getName()<<" ("<<getNbVectors()<<" vertices and "<<getNbEdges()<<" edges)\n";
    for(typename map<V, set<V> >::const_iterator it=adj.begin();it!=adj.end();it++){
        f<<it->first<<" : ";
        for(typename set<V>::const_iterator it2=it->second.begin();it2!=it->second.end();it2++){
            f<<*it2<<" ";
        }
        f<<"\n";
    }
}
/*
template<class V>
ostream& operator<<(ostream& f, const GraphG<V>& G){
    G.print(f);
    return f;
}
*/
template<class V>
typename GraphG<V>::successor_iterator GraphG<V>::begin_successor(const V &x) const{
    typename map<V, set<V> >::const_iterator it=adj.find(x);
    if(it!=adj.end()) return successor_iterator(it->second.begin());
    throw GraphException("Error: Vertex not defined");
}

template<class V>
typename GraphG<V>::successor_iterator GraphG<V>::end_successor(const V& x) const{
    typename map<V, set<V> >::const_iterator it=adj.find(x);
    if(it!=adj.end()) return successor_iterator(it->second.end());
    throw GraphException("Error: Vertex not defined");
}

template<class V>
ostream& operator<<(ostream& f, const GraphG<V>& G){
    f<<"Graph "<<G.getName()<<" ("<<G.getNbVectors()<<" vertices and "<<G.getNbEdges()<<" edges)\n";
    for_each(G.begin_vertex(), G.end_vertex(),monPrint<V>(f,G));
    return f;
}



