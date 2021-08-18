//
// Created by Streetmentioner Copycat on 8/17/21.
//

#ifndef REDBLACKTREE_HPP
#define REDBLACKTREE_HPP

#include "pair.hpp"

namespace ft
{
	struct rbtBase
	{
		rbtBase*	m_right;
		rbtBase*	m_left;
		rbtBase*	m_parent;
		bool 		m_rcolour;																								// если true, то rea
	};
#define NIL &sentinel
rbtBase sentinel = { NIL, NIL, 0, false};

	template <class Key, class T>
	struct rbtNode
	{
		std::pair<const Key, T>	value;																						// убрать std, когда напишу свой pair
		rbtBase				base;
	};

	template <class Key, class Value, class Content, class Compare = std::less<Key>,
			class Alloc = std::allocator<std::pair<const Key,Value> > >
	class redblacktree : public rbtBase
	{
		typedef ptrdiff_t															difference_type;
		typedef Key																	key_type;
		typedef Value																mapped_type;
		typedef Content																value_type;
		typedef rbtNode<key_type, value_type>										node_type;
		typedef	Compare																key_compare;
		typedef Alloc																allocator_type;
		typedef	value_type&															reference;
		typedef	const value_type&													const_reference;
		typedef	value_type*															pointer;
		typedef	const value_type*													const_pointer;
		typedef	size_t																size_type;

		typedef tree_iterator<value_type, pointer, reference, Compare >				iterator;
		typedef tree_terator<value_type, const_pointer, const_reference, Compare >	const_iterator;
		typedef ReverseIterator<iterator>											reverse_iterator;
		typedef ReverseIterator<const_iterator>										const_reverse_iterator;

	protected:
		node_type		*m_root;
		node_type		*m_begin;
		node_type		*m_end;

		size_type		m_size;
		allocator_type	m_alloc;
		key_compare		m_compare;

	public:
		redblacktree() : m_root(NIL), m_begin(NIL), m_end(NIL), m_size(0)
		{
		}

	protected:

		node_type*				insertNode(value_type value)
		{
			node_type *current, *parent, *x;

			current = m_root;
			parent = 0;
			while (current != NIL) {
				if (value == m_root->value)
					return (current);
				parent = current;
				if (value < current->value)
					current = current->base.m_left;
				else
					current = current->base.m_right;
			}

			m_alloc.allocate(x);
			x->value = value;
			x->base.m_parent = parent;
			x->base.m_left = NIL;
			x->base.m_right = NIL;
			x->base.m_rcolour = true;

			if (parent)
			{
				if(value < parent->value)
					parent->left = x;
				else
					parent->right = x;
			}
			else
				m_root = x;

			balance_after_insert(x);
			return(x);
		}

		void					deleteNode(node_type *node_for_delete)
		{
			node_type *x, *y;

			if (!node_for_delete || node_for_delete == NIL)
				return;


			if (node_for_delete->base.m_left == NIL || node_for_delete->base.m_right == NIL)
				y = node_for_delete;
			else
			{
				y = node_for_delete->base.m_right;
				while (y->base.m_left != NIL)
					y = y->base.m_left;
			}

			if (y->base.m_left != NIL)
				x = y->left;
			else
				x = y->right;

			x->base.m_parent = y->base.m_parent;
			if (y->base.m_parent)
			{
				if (y == y->base.m_parent->m_left)
					y->base.m_parent->m_lefts = x;
				else
					y->base.m_parent->m_right = x;
			}
			else
				m_root = x;

			if (y != node_for_delete)
				node_for_delete->value = y->value;
			if (!y->base.m_rcolour)
				balance_after_delete(x);
			m_alloc.destroy(y);
		}

		node_type* findNode(value_type value)
		{
			node_type current;

			while (current != NIL)
			{
				if (current.value == value)
					return (current);
				else
					if (value < current.value)
						current = current.base.m_left;
					else
						current = current.base.m_right;
			}
			return (0);
		}

		void					balance_after_insert(node_type *node_ins)
		{
			while (node_ins != m_root && node_ins->base.m_parent->m_rcolour)
			{
				if (node_ins->parent == node_ins->parent->parent->left)
				{
					node_type *buf = node_ins->base.m_parent->m_right;
					if (buf->base.m_rcolour)
					{
						node_ins->base.m_parent->m_rcolour = false;
						buf->base.m_rcolour = false;
						node_ins->base.m_parent->m_parent->m_rcolour = true;
						node_ins = node_ins->base.m_parent->m_parent;
					}
					else
					{
						if (node_ins == node_ins->base.m_parent->m_right)
						{
							node_ins = node_ins->base.m_parent;
							rotate_left(node_ins);
						}
						node_ins->base.m_parent->m_rcolour = false;
						node_ins->base.m_parent->m_parent->m_rcolour = true;
						rotate_right(node_ins->base.m_parent->m_parent);
					}
				}
				else
				{
					node_type *buf = node_ins->base.m_parent->m_left;
					if (buf->base.m_rcolour)
					{
						node_ins->base.m_parent->m_rcolour = false;
						buf->base.m_rcolour = false;
						node_ins->base.m_parent->m_parent->m_rcolour = true;
						node_ins = node_ins->base.m_parent->m_parent;
					}
					else
					{
						if (node_ins == node_ins->base.m_parent->m_left)
						{
							node_ins = node_ins->base.m_parent;
							rotate_right(node_ins);
						}

						node_ins->base.m_parent->m_rcolour = false;
						node_ins->base.m_parent->m_parent->m_parent->m_rcolour = true;
						rotate_left(node_ins->base.m_parent->m_parent);
					}
				}
			}
			m_root->base.m_rcolour = false;
		}

		void					balance_after_delete(node_type *node_del)
		{

			while (node_del != m_root && !node_del->base.m_rcolour)
			{
				if (node_del == node_del->base.m_parent->m_left)
				{
					node_type *buf = node_del->base.m_parent->m_right;
					if (buf->base.m_rcolour)
					{
						buf->base.m_rcolour = false;
						node_del->base.m_parent->m_rcolour = true;
						rotate_left(node_del->base.m_parent);																// проверить, что моя функция делает то, что нужно
						buf = node_del->base.m_parent->m_right;
					}
					if (!buf->base.m_left->m_rcolour && !buf->base.m_right->m_rcolour)
					{
						buf->base.m_rcolour = true;
						node_del = node_del->base.m_parent;
					}
					else
					{
						if (!buf->base.m_right->m_rcolours)
						{
							buf->base.m_left->m_rcolour = false;
							buf->base.m_rcolour = true;
							rotate_right(buf);																				// проверить, что моя функция делает то, что нужно и смотреть, не перекрашиваю я ли лишний раз
							buf = node_del->base.m_parent->m_right;
						}
						buf->base.m_rcolour = node_del->base.m_parent->m_rcolour;
						node_del->base.m_parent->m_rcolour = false;
						buf->base.m_right->m_rcolour = false;
						rotate_left(node_del->base.m_parent);
						node_del = m_root;
					}
				}
				else
				{
					node_type *buf = node_del->base.m_parent->m_left;
					if (buf->base.m_rcolour)
					{
						buf->base.m_rcolour = false;
						node_del->base.m_parent->m_rcolour = true;
						rotate_right(node_del->base.m_parent);
						buf = node_del->base.m_parent->m_left;
					}
					if (!buf->base.m_right->m_rcolour && !buf->base.m_left->m_rcolour)
						node_del = node_del->base.m_parent;
					else
					{
						if (!buf->base.m_left->m_rcolour)
						{
							buf->base.m_right->m_rcolour = false;
							buf->base.m_rcolour = true;
							rotate_left(buf);
							buf = node_del->base.m_parent->m_left;
						}
						buf->base.m_rcolour = node_del->base.m_parent->m_rcolour;
						node_del->base.m_parent->m_rcolour = false;
						buf->base.m_left->m_rcolour = false;
						rotate_right(node_del->base.m_parent);
						node_del = m_root;
					}
				}
			}
			node_del->base.m_rcolour = false;
		}


	private:
		void					rotate_left(node_type *node)																// родитель, у которого два красных ребенка
		{
			node_type* tmp;

			tmp = node->base.m_right;
			node->base.m_right = tmp->base.m_left;
			if (tmp->base.m_left != NIL)
				tmp->base.m_left->m_parent = node;
			if (tmp != NIL)
				tmp->base.m_parent = node->base.m_parent;
			if (node->base.m_parent)
			{
				if (node == node->base.m_parent->m_left)
					node->base.m_parent->m_left = tmp;
				else
					node->base.m_parent->m_right = tmp;
			}
			else
				m_root = tmp;
			tmp->base.m_left = node;
			if (node != NIL)
				node->base.m_parent = tmp;
		}

		void					rotate_right(node_type *node)																// до конца не разобралась, что делать с цветами
		{
			node_type* tmp;

			tmp = node->base.m_left;
			node->base.m_left = tmp->base.m_right;
			if (tmp->base.m_right != NIL)
				tmp->base.m_right->m_parent = node;
			if (tmp != NIL)
				tmp->base.m_parent = node->base.m_parent;
			if (node->base.m_parent)
			{
				if (node == node->base.m_parent->m_right)
					node->base.m_parent->m_right = tmp;
				else
					node->base.m_parent->m_left = tmp;
			}
			else
				m_root = tmp;
			tmp->base.m_right = node;
			if (node != NIL)
				node->base.m_parent = tmp;
		}

		void					swap_colour(node_type *node)
		{
			node->base.m_left->m_rcolour = false;
			node->base.m_right->m_rcolour = false;
			node->base.m_rcolour = true;
		}

		void					balancing(node_type *node)
		{
			if (node->base.m_left->m_rcolour && node->base.m_left.m_left.m_rcolour)
				rotate_right();
			else if(node->base.m_left.m_rcolour && node->base.m_right.m_rcolour)
				swap_colour(node);
			else if(!node->base.m_left->m_rcolour && node->base.m_right->m_rcolour)
				rotate_left();
		}
	};
}

#endif //REDBLACKTREE_HPP
