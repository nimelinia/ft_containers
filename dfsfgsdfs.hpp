//
// Created by Streetmentioner Copycat on 8/21/21.
//

#ifndef PROJECT_DFSFGSDFS_HPP
#define PROJECT_DFSFGSDFS_HPP

#endif //PROJECT_DFSFGSDFS_HPP
void _rotateLeft(node *rotateNode) {
	node *rightRotateNode = rotateNode->_right;
	rotateNode->_right = rightRotateNode->_left;
	if (rightRotateNode->_left != _null) {
		rightRotateNode->_left->_parent = rotateNode;
	}
	rightRotateNode->_parent = rotateNode->_parent;
	if (rotateNode->_parent == _null) {
		_tree = rightRotateNode;
	}
	else if (rotateNode == rotateNode->_parent->_left) {
		rotateNode->_parent->_left = rightRotateNode;
	}
	else {
		rotateNode->_parent->_right = rightRotateNode;
	}
	rightRotateNode->_left = rotateNode;
	rotateNode->_parent = rightRotateNode;
};

void _rotateRight(node *rotateNode) {
	node *leftRotateNode = rotateNode->_left;
	rotateNode->_left = leftRotateNode->_right;
	if (leftRotateNode->_right != _null) {
		leftRotateNode->_right->_parent = rotateNode;
	}
	leftRotateNode->_parent = rotateNode->_parent;
	if (rotateNode->_parent == _null) {
		_tree = leftRotateNode;
	}
	else if (rotateNode == rotateNode->_parent->_right) {
		rotateNode->_parent->_right = leftRotateNode;
	}
	else {
		rotateNode->_parent->_left = leftRotateNode;
	}
	leftRotateNode->_right = rotateNode;
	rotateNode->_parent = leftRotateNode;
};