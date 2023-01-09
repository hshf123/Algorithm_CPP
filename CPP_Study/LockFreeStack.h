#pragma once

#include <atomic>
using namespace std;

template<class T>
class LockFreeStack
{
	struct Node
	{
		Node(const T& value) : data(value), next(nullptr) {	}

		T data;
		Node* next;
	};

public:
	void Push(const T& value)
	{
		Node* node = new Node(value);

		while (_head.compare_exchange_weak(node->next, node) == false)
		{
			/*
			if (_head == node->next)
			{
				_head = node;
				return true;
			}
			else
			{
				node->next = _head;
				return false;
			}
			*/
		}
	}

	bool TryPop(T& value)
	{
		++_popCount;
		Node* prevHead = _head;

		while (prevHead && _head.compare_exchange_weak(prevHead, prevHead->next) == false)
		{
			/*
			if (_head == prevHead)
			{
				_head = prevHead->next;
				return true;
			}
			else
			{
				prevHead = _head;
				return false;
			}
			*/
		}

		if (prevHead == nullptr)
		{
			--_popCount;
			return false;
		}

		value = prevHead->data;
		TryDelete(prevHead);
		return true;
	}

	void TryDelete(Node* prevHead)
	{
		if (_popCount == 1)
		{
			Node* node = _pendingList.exchange(nullptr);

			if (--_popCount == 0)
				DeleteNodes(node);
			else if (node)
				ChainPendingNodeList(node);

			delete prevHead;
		}
		else
		{
			ChainPendingNode(prevHead);
			--_popCount;
		}
	}

	void ChainPendingNodeList(Node* first, Node* last)
	{
		last->next = _pendingList;

		while (_pendingList.compare_exchange_weak(last->next, first) == false)
		{
			/*
			if (_pendingList == last->next)
			{
				_pendingList = first;
				return true;
			}
			else
			{
				first = _pendingList;
				return false;
			}
			*/
		}
	}

	void ChainPendingNodeList(Node* node)
	{
		Node* last = node;
		while (last->next)
			last = last->next;

		ChainPendingNodeList(node, last);
	}

	void ChainPendingNode(Node* node)
	{
		ChainPendingNodeList(node, node);
	}

	static void DeleteNodes(Node* node)
	{
		while (node)
		{
			Node* next = node->next;
			delete node;
			node = next;
		}
	}

private:

	atomic<Node*> _head;

	atomic<int> _popCount = 0;
	atomic<Node*> _pendingList = nullptr;
};

