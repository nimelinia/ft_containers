//
// Created by Streetmentioner Copycat on 8/17/21.
//

#ifndef REDBLACKTREE_HPP
#define REDBLACKTREE_HPP

#include "pair.hpp"

namespace ft
{
	enum rbtColour
	{
		rbtBlack;
		rbtRed;
	};

	struct rbtBase
	{
		rbtBase*	m_right;
		rbtBase*	m_left;
		rbtBase*	m_parent;
		char		m_colour;
	};

	template <class Key, class T>
	struct rbtNode
	{
		pair<const Key, T>	value;
	};

	class redblacktree : public rbtBase
	{
		typedef ptrdiff_t												difference_type;
		typedef size_t													size_type;
		typedef Key														key_type;
		typedef rbtNode::value											value_type;
		typedef rbtNode<value_type>										node_type;
		typedef value_type&												reference;
		typedef const value_type&										const_reference;
		typedef value_type*												pointer;
		typedef const value_type*										const_pointer;

	};
}

#endif //REDBLACKTREE_HPP
