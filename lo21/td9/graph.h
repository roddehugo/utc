#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <string>
#include <stdexcept>
#include <map>
#include <set>
using namespace std;

class GraphException : public exception
{
    string info;
public:
    GraphException(const string& i) throw():info(i) {}
    virtual ~GraphException() throw() {}
    const char* what() const throw()
    {
        return info.c_str();
    }
};


class Graph
{
    vector<list<unsigned int> > adj;
    unsigned int nbEdges;
    string name;
public:
    Graph(const string& n, unsigned int nb):adj(nb), nbEdges(0), name(n) {}
    const string& getName() const
    {
        return name;
    }
    unsigned int getNbVertices() const
    {
        return adj.size();
    }
    unsigned int getNbEdges() const
    {
        return nbEdges;
    }
    void addEdge(unsigned int i, unsigned int j);
    void removeEdge(unsigned int i, unsigned int j);
    const list<unsigned int> getSuccessors(unsigned int i) const;
    const list<unsigned int> getPredecessors(unsigned int i) const;
};
ostream& operator<<(ostream& f, const Graph& G);


template <class V>
class GraphG
{
    map<V,set<V> > adj;
    unsigned int nbEdges;
    string name;
public:
    GraphG(const string &n):name(n), nbEdges(0) {}
    const string& getName() const
    {
        return name;
    }
    unsigned int getNbVectors() const
    {
        return adj.size();
    }
    unsigned int getNbEdges() const
    {
        return nbEdges;
    }
    void addVertex(const V& i);
    void addEdge(const V& i, const V& j);
    void removeEdge(const V& i, const V& j);
    void removeVertex(const V& i);
    void print(ostream& f) const;

    class vertex_iterator : public map<V, set<V> >::const_iterator
    {
    public :
        vertex_iterator():map<V, set<V> >::const_iterator() {}
        vertex_iterator(typename map<V, set<V> >::const_iterator it): map<V, set<V> >::const_iterator(it) {}
        const V& operator *() const
        {
            return map<V, set<V> >::const_iterator::operator *().first;
        }
    };

    vertex_iterator begin_vertex() const
    {
        return vertex_iterator(adj.begin());
    }
    vertex_iterator end_vertex() const
    {
        return vertex_iterator(adj.end());
    }

    class successor_iterator : public map<V, set<V> >::const_iterator
    {
    public :
        successor_iterator():set<V>::const_iterator() {}
        successor_iterator(typename set<V>::const_iterator it): set<V>::const_iterator(it) {}
    };

    successor_iterator  begin_successor(const V& x) const;
    successor_iterator end_successor(const V& x) const;

};

template<class V>
ostream& operator<<(ostream& f, const GraphG<V>& G);

template<class V>
class monPrint
{
    const GraphG<V>& G;
    ostream& flux;
public:
    monPrint(ostream& f, const GraphG<V>& G):flux(f),G(G) {}
    void operator()(const V& x)
    {
        flux<<x<<" : ";
        for(typename GraphG<V>::successor_iterator it=G.begin_successor(x); it!=G.end_successor(x); ++it) {
            flux << *it <<" ";
        }
        flux<<"\n";
    }
};


#endif // GRAPH_H
