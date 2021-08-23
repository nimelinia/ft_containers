//
// Created by Streetmentioner Copycat on 8/17/21.
//

#ifndef REDBLACKTREE_HPP
#define REDBLACKTREE_HPP

#include <iomanip>
#include <iostream>
#include "pair.hpp"

namespace ft
{
	template <class Content>
	struct rbtNode
	{
		Content*	value;
		rbtNode*	m_right;
		rbtNode*	m_left;
		rbtNode*	m_parent;
		bool 		m_rcolour;

		rbtNode() : value(), m_right(0), m_left(0), m_parent(0), m_rcolour(false)  {}
		rbtNode(rbtNode *other) : value(other->value), m_right(other->m_right), m_left(other->m_left),
			m_parent(other->m_parent), m_rcolour(other->m_rcolour) {}
	};

	template <class Key, class Value, class Content, class Compare = std::less<Key>,
			class Alloc = std::allocator<pair<const Key,Value> > >
	class redblacktree
	{
		typedef ptrdiff_t															difference_type;
		typedef Key																	key_type;
		typedef Value																mapped_type;
		typedef Content																value_type;
		typedef rbtNode<Content>													node_type;
		typedef	Compare																key_compare;
		typedef Alloc																allocator_type;
		typedef	value_type&															reference;
		typedef	const value_type&													const_reference;
		typedef	value_type*															pointer;
		typedef	const value_type*													const_pointer;
		typedef	size_t																size_type;
		typedef typename allocator_type::template rebind<rbtNode<Content> >::other	node_allocator;

		class value_compare
		{
		protected:
			friend class	redblacktree<const Key, Value, Content, Compare, Alloc>;
			Compare			compare;
			value_compare(Compare c) : compare(c) {}
		public:
			typedef bool		result_type;
			typedef value_type 	first_argument_type;
			typedef value_type 	second_argument_type;
			bool operator() (const value_type & x, const value_type& y) const { return compare(x.first, y.first); }
		};
//		typedef tree_iterator<value_type, pointer, reference, Compare >				iterator;
//		typedef tree_terator<value_type, const_pointer, const_reference, Compare >	const_iterator;
//		typedef ReverseIterator<iterator>											reverse_iterator;
//		typedef ReverseIterator<const_iterator>										const_reverse_iterator;

	protected:
		node_type		*nil;
		node_type		*m_root;
		node_type		*m_begin;
		node_type		*m_end;

		size_type		m_size;
		allocator_type	m_alloc;
		key_compare		m_compare;

	public:
		redblacktree() : nil(0), m_root(nil), m_begin(nil), m_end(nil), m_size(0)
		{
		}

		~redblacktree()
		{
			if (m_root != 0)
			{
				m_alloc.destroy(m_root->value);
//				node_allocator allocator;

			}
//			m_alloc.deallocate(m_root->value, 1);
		}
	protected:

		node_type*				createNode(value_type &val)
		{
			node_type* x;
			node_allocator allocator;
			x = allocator.allocate(1);
			x->value = m_alloc.allocate(1);
			m_alloc.construct(x->value, val);
			return (x);
		}

		node_type*				insertNode(value_type value)
		{
			node_type *current, *parent, *x;

			current = m_root;
			parent = 0;
			while (current != nil) {
				if (value.first == current->value->first)
				{
					m_alloc.destroy(current->value);
					m_alloc.construct(current->value, value);
					return (current);
				}
				parent = current;
				if (m_compare(value.first, current->value->first))
					current = current->m_left;
				else
					current = current->m_right;
			}

			x = createNode(value);
			x->m_parent = parent;
			x->m_left = nil;
			x->m_right = nil;
			x->m_rcolour = true;

			if (parent)
			{
				if(m_compare(value.first, parent->value->first))
					parent->m_left = x;
				else
					parent->m_right = x;
			}
			else
				m_root = x;
			if (m_root == x)
			{
				m_begin = x;
				m_end = x;
			}
			if (m_begin == x->m_parent && x->m_parent->m_left == x)
				m_begin = x;
			if (m_end == x->m_parent && x->m_parent->m_right == x)
				m_end = x;
			balance_after_insert(x);
			m_size++;
			return(x);
		}

		void					deleteNode(node_type *node_for_delete)
		{
			node_type *x, *y;

			if (!node_for_delete || node_for_delete == nil)
				return;


			if (node_for_delete->m_left == nil || node_for_delete->m_right == nil)
				y = node_for_delete;
			else
			{
				y = node_for_delete->m_right;
				while (y->m_left != nil)
					y = y->m_left;
			}

			if (y->m_left != nil)
				x = y->m_left;
			else if (node_for_delete != m_root)
				x = y->m_right;
			else if (node_for_delete->m_left)
				x = node_for_delete->m_left;
			else
				x = node_for_delete->m_right;
			if (x)
				x->m_parent = y->m_parent;
			if (y->m_parent)
			{
				if (y == y->m_parent->m_left)
					y->m_parent->m_left = x;
				else
					y->m_parent->m_right = x;
			}
			else
				m_root = x;
			if (node_for_delete == m_begin)
			{
				if (m_begin->m_right)
					m_begin = m_begin->m_right;
				while (m_begin->m_left)
					m_begin = m_begin->m_left;
				if (m_begin == node_for_delete && m_begin->m_parent)
					m_begin = m_begin->m_parent;
				while (m_begin->m_parent && m_compare(m_begin->m_parent->value->first, m_begin->value->first))
					m_begin = m_begin->m_parent;
			}
			if (node_for_delete == m_end)
			{
				if (m_end->m_left)
					m_end = m_end->m_left;
				while (m_end->m_right)
					m_end = m_end->m_right;
				if (m_end == node_for_delete && m_end->m_parent)
					m_end = m_end->m_parent;
				while (m_end->m_parent && m_compare(m_end->value->first, m_end->m_parent->value->first))
					m_end = m_end->m_parent;
			}
			if (y != node_for_delete)
			{
				node_for_delete->value = y->value;
				if (node_for_delete->m_right->m_left->value == x->value)
					node_for_delete->m_right->m_left = NULL;
			}
			if (!y->m_rcolour && x)
				balance_after_delete(x);
			m_size--;
			m_alloc.destroy(y->value);
			m_alloc.deallocate(y->value, 1);
			node_allocator allocator;
			allocator.destroy(y);
			allocator.deallocate(y, 1);
		}

		node_type* findNode(value_type value)
		{
			node_type* current = m_root;

			while (current != nil)
			{
				if (*current->value == value)
					return (current);
				else
					if (m_compare(value.first, current->value->first))
						current = current->m_left;
					else
						current = current->m_right;
			}
			return (0);
		}

		node_type* findNodebyKey(key_type &key)	const
		{
			node_type* it(m_root);

			while (it != nil && it != nil)
			{
				if (m_compare(key, it->value->first))
					it = it->m_left;
				else if (m_compare(it->value->first, key))
					it = it->m_right;
				else
					return (it);
			}
			return (m_end->m_right);
		}

		void					balance_after_insert(node_type *node_ins)
		{
			bool rotate = false;

			while (node_ins != m_root && node_ins->m_parent->m_rcolour)
			{
				if (node_ins->m_parent->m_parent && node_ins->m_parent == node_ins->m_parent->m_parent->m_left)
				{
					node_type *buf = node_ins->m_parent->m_right;
					if (buf && buf->m_rcolour)
					{
						node_ins->m_parent->m_rcolour = false;
						buf->m_rcolour = false;
						node_ins->m_parent->m_parent->m_rcolour = true;
						node_ins = node_ins->m_parent;
					}
					else
					{
						if (node_ins == node_ins->m_parent->m_right)
						{
							node_ins = node_ins->m_parent;
							rotate_left(node_ins);
							rotate = true;
						}
						node_ins->m_parent->m_rcolour = false;
						node_ins->m_parent->m_parent->m_rcolour = true;
//						rotate_right(node_ins->m_parent);
						if (rotate)
							rotate_right(node_ins->m_parent->m_parent);
						else
							rotate_right(node_ins->m_parent);
					}
				}
				else
				{
					if (node_ins->m_parent->m_parent)
					{
						node_type *buf = node_ins->m_parent->m_left;
						if (buf && buf->m_rcolour)
						{
							node_ins->m_parent->m_rcolour = false;
							buf->m_rcolour = false;
							node_ins->m_parent->m_parent->m_rcolour = true;
							node_ins = node_ins->m_parent;
						}
						else
						{
							if (node_ins == node_ins->m_parent->m_left)
							{
								node_ins = node_ins->m_parent;
								rotate_right(node_ins);
								rotate = true;
							}

							node_ins->m_parent->m_rcolour = false;
							node_ins->m_parent->m_parent->m_rcolour = true;
//							rotate_left(node_ins->m_parent);
							if (rotate)
								rotate_left(node_ins->m_parent->m_parent);
							else
								rotate_left(node_ins->m_parent);
						}
					} else
						break;
//					{
//						balancing(node_ins->m_parent);
//						node_ins = node_ins->m_parent;
//					}

				}
				rotate = false;
			}
			m_root->m_rcolour = false;
		}

		void					balance_after_delete(node_type *node_del)
		{

			while (node_del != m_root && !node_del->m_rcolour)
			{
				if (node_del == node_del->m_parent->m_left)
				{
					node_type *buf = node_del->m_parent->m_right;
					if (buf && buf->m_rcolour)
					{
						buf->m_rcolour = false;
						node_del->m_parent->m_rcolour = true;
						rotate_left(node_del->m_parent);																// проверить, что моя функция делает то, что нужно
						buf = node_del->m_parent->m_right;
					}
					if (buf && buf->m_left && buf->m_right && !buf->m_left->m_rcolour && !buf->m_right->m_rcolour)
					{
						buf->m_rcolour = true;
						node_del = node_del->m_parent;
					}
					else
					{
						if (buf && buf->m_right && buf->m_left && !buf->m_right->m_rcolour)
						{
							buf->m_left->m_rcolour = false;
							buf->m_rcolour = true;
							rotate_right(buf);																				// проверить, что моя функция делает то, что нужно и смотреть, не перекрашиваю я ли лишний раз
							buf = node_del->m_parent->m_right;
						}
						if (buf && buf->m_right)
						{
							buf->m_rcolour = node_del->m_parent->m_rcolour;
							buf->m_right->m_rcolour = false;
						}
						node_del->m_parent->m_rcolour = false;
						if (node_del->m_parent->m_right)
							rotate_left(node_del->m_parent);
						node_del = m_root;
					}
				}
				else
				{
					node_type *buf = node_del->m_parent->m_left;
					if (buf->m_rcolour)
					{
						buf->m_rcolour = false;
						node_del->m_parent->m_rcolour = true;
						rotate_right(node_del->m_parent);
						buf = node_del->m_parent->m_left;
					}
					if (buf && !buf->m_right->m_rcolour && !buf->m_left->m_rcolour)
						node_del = node_del->m_parent;
					else
					{
						if (buf && !buf->m_left->m_rcolour)
						{
							buf->m_right->m_rcolour = false;
							buf->m_rcolour = true;
							rotate_left(buf);
							buf = node_del->m_parent->m_left;
						}
						if (buf)
						{
							buf->m_rcolour = node_del->m_parent->m_rcolour;
							buf->m_left->m_rcolour = false;
						}
						node_del->m_parent->m_rcolour = false;
						rotate_right(node_del->m_parent);
						node_del = m_root;
					}
				}
			}
			node_del->m_rcolour = false;
		}


	private:
		void					rotate_left(node_type *node)																// родитель, у которого два красных ребенка
		{
			node_type* tmp;

			tmp = node->m_right;
			if (tmp)
				node->m_right = tmp->m_left;
			if (tmp && tmp->m_left != nil)
				tmp->m_left->m_parent = node;
			if (tmp != nil)
				tmp->m_parent = node->m_parent;
			if (node->m_parent)
			{
				if (node == node->m_parent->m_left)
					node->m_parent->m_left = tmp;
				else
					node->m_parent->m_right = tmp;
			}
			else
				m_root = tmp;
			if (tmp)
				tmp->m_left = node;
			if (node != nil)
				node->m_parent = tmp;
		}

		void					rotate_right(node_type *node)																// до конца не разобралась, что делать с цветами
		{
			node_type* tmp;

			tmp = node->m_left;
			if (tmp)
				node->m_left = tmp->m_right;
			if (tmp && tmp->m_right != nil)
				tmp->m_right->m_parent = node;
			if (tmp != nil)
				tmp->m_parent = node->m_parent;
			if (node->m_parent)
			{
				if (node == node->m_parent->m_right)
					node->m_parent->m_right = tmp;
				else
					node->m_parent->m_left = tmp;
			}
			else
				m_root = tmp;
			if (tmp)
				tmp->m_right = node;
			if (node != nil)
				node->m_parent = tmp;
		}

		void					swap_colour(node_type *node)
		{
			node->m_left->m_rcolour = false;
			node->m_right->m_rcolour = false;
			node->m_rcolour = true;
		}

	public:
		void _print(node_type *p, int indent)
		{
			if (p != NULL && p != nil) {
				if (p->m_right != nil)
				{
					_print(p->m_right, indent + 8);
				}
				if (indent) {
					std::cout << std::setw(indent) << ' ';
				}
				if (p->m_right != nil) std::cout << " /\n" << std::setw(indent) << ' ';
				if (p->m_rcolour)
					std::cout << "\033[1;31m" << *p->value << "\033[0m" << "\n ";
				else
					std::cout << *p->value << "\n ";
				if (p->m_left != nil)
				{
					std::cout << std::setw(indent) << ' ' << " \\\n";
					_print(p->m_left, indent + 8);
				}
			}
		}
		void					balancing(node_type *node)
		{
			if (node->m_left->m_rcolour && node->m_left->m_left->m_rcolour)
				rotate_right(node);
			else if (node->m_right->m_rcolour && node->m_right->m_right->m_rcolour)
				rotate_left(node);
			else if(node->m_left->m_rcolour && node->m_right->m_rcolour)
				swap_colour(node);
			else if(!node->m_left->m_rcolour && node->m_right->m_rcolour)
				rotate_left(node);
		}
	};
}

#endif //REDBLACKTREE_HPP
