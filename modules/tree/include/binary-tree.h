/***************************************************************************
 *   Copyright (C) 2016 by Ícaro Magalhães
 *
 *   João Pessoa - PB - Brasil
 *
 *   \file binary-tree.h
 *   \author Ícaro Lima Magalhães <icaro.lmag@gmail.com>
 *   \date 21/07/2016 - refactored/moved
 *
 ***************************************************************************/

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

namespace compendium
{

    /**
     * \brief The class represents an undirected graph of vertices.
     */
    enum BTreeTransversal
    { PREFIX, INFIX, POSTFIX };

    template <class T> class BTree
    {

    public:

        struct node
        {

            T value;
            node *left = nullptr;
            node *right = nullptr;

            node(T data)
            {
                value = data;
                left = right = nullptr;
            }

        };

        BTree<T>()
        {

            root = nullptr;
            BTree_elements = 0;
        }

        BTree<T>(std::vector<T> v)
        {
            BTree<T>();

            for(auto it = v.begin(); it != v.end(); ++it)
                insert(*it);
        }

        void insert(const T val)
        {

            if(root != nullptr)
            {
                insert(root, val);
                ++BTree_elements;
            }
            else
            {
                root = new node(val);
            }

        }

        bool search(const T val) const
        {
            return search(root, val);
        }

        void btree_transversal(BTreeTransversal mode, bool to_print)
        {
            std::vector<T> storage;
            switch(mode)
            {
                case PREFIX:
                    preorder_read(root, storage);
                    break;
                case INFIX:
                    inorder_read(root, storage);
                    break;
                case POSTFIX:
                    postorder_read(root, storage);
                    break;
            }

            if(to_print)
            {
                print_tree_vector(storage);
            }

        }

        void preorder_read(const node *const btree, std::vector<T> &storage)
        {
            if(btree == nullptr)
            {
                return;
            }

            storage.push_back(btree->value);
            preorder_read(btree->left, storage);
            preorder_read(btree->right, storage);
        }

        void inorder_read(const node *const btree, std::vector<T> &storage)
        {

            if(btree == nullptr)
            {
                return;
            }

            inorder_read(btree->left, storage);

            storage.push_back(btree->value);

            inorder_read(btree->right, storage);
        }

        void postorder_read(const node *const btree, std::vector<T> &storage)
        {

            if(btree == nullptr)
            {
                return;
            }

            postorder_read(btree->left, storage);
            postorder_read(btree->right, storage);

            storage.push_back(btree->value);

        }

        int get_qt_elements() const { return BTree_elements; }

    private:
        node *root;
        int BTree_elements;

        void print_tree_vector(const std::vector<T> &v) const
        {

            int space = 0;

            for_each(v.begin(), v.end(),
                [&](const T _item)
                {
                    if(space) std::cout << " ";
                    else space = 1;
                    std::cout << _item;
                }
            );

            std::cout << std::endl;

        }

        bool search(const node *const btree, const T val) const
        {
            if(btree == nullptr)
            {
                return false;
            }
            else if(btree->value == val)
            {
                return true;
            }
            else if(btree->value > val)
            {
                return search(btree->left, val);
            }
            else
            {
                return search(btree->right, val);
            }
        }


        void insert(node *btree, const T val)
        {

            if(val < btree->value)
            {
                if(btree->left == nullptr)
                {
                    btree->left = new node(val);
                    ++BTree_elements;
                }
                else
                {
                    insert(btree->left, val);
                }
            }
            else
            {
                if(btree->right == nullptr)
                {
                    btree->right = new node(val);
                    ++BTree_elements;
                }
                else
                {
                    insert(btree->right, val);
                }
            }

        }

    };

}

#endif /* BINARY_TREE_H */
