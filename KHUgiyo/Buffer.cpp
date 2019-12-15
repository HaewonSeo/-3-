#include "Buffer.h"
#include "pch.h"

bool Buffer::instanceFlag = false;
Buffer* Buffer::instance = NULL;

Buffer* Buffer::getInstance() {
	if (!instance) {
		instance = new Buffer();
		instanceFlag = true;
	}
	return instance;
}

bool Buffer::IsFull() {
	if (cursize == max)
		return 1;
	else
		return 0;
}

bool Buffer::IsEmpty() {
	if (cursize == 0)
		return 1;
	else
		return 0;
}

int Buffer::add(Order NewOrder) {
	if (IsFull()) {
		cout << "���۰� �������ֽ��ϴ�." << endl;
		return -1;
	}
	buffer[cursize] = NewOrder;
	cursize++;
	return 1;
}

int Buffer::retrieve(Order& dummy) {
	if (IsEmpty()) {
		cout << "���۰� ����ֽ��ϴ�." << endl;
		return 0;
	}
	int ind = 0;
	bool found = false;
	while (ind < cursize && !found) {//linear search
		if (dummy.GetShopId() == buffer[ind].GetShopId()) { // if hit
			cout << "�ֹ��� �˻�" << endl;
			dummy = buffer[ind]; // copy
			int dex = ind; // delete and tighten up
			while (dex < cursize) {
				buffer[dex] = buffer[dex + 1];
				dex++;
			}
			found = true;
			cursize--;
		}
		ind++;
	}
	return 1;
}