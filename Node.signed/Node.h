#ifndef NODE_H_
#define NODE_H_

/***** Convert this to a class template to handle
 ***** multiple types of data stored in the nodes. */

using namespace std;

template <class T>
class Node
{
public:
    Node(T value);
    ~Node();

    T data;
    Node *next;
};

template <class T>
Node<T>::Node(T value) : data(value), next(nullptr)
{
}

template <class T>
Node<T>::~Node()
{
}


#endif /* NODE_H_ */
