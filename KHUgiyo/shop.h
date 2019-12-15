
#pragma once
#include <string>
#include "OrderQueue.h"
#include "SortedMenuList.h"
#include "Buffer.h"
using namespace std;

class shop {
private:

	string ShopName; // ���� �̸�
	int TotalIncome; // �� ����
	OrderQueue ShopOrder; // �ֹ� ���� ť
	SortedMenuList ShopMenu; // ������ �޴� ����Ʈ
	Buffer* bufferptr; // ���ۿ� �����ϴ� ������
	
	int curCommand; // run �Լ��� Ŀ�ǵ带 �Է¹޴� �޼���
	shop* sibling;
	shop* child;




public:
	// ������
	shop(int flag = 1) {
		ShopName = "";
		TotalIncome = 0;
		bufferptr = Buffer::getInstance();

		sibling = NULL;
		child = NULL;
	};

	//�Ҹ���
	~shop() {};


	void run() {
		while (1) {
			curCommand = GetCommand();

			switch (curCommand) {
			case 1:
				GetOrder();
				DisplayOrder();
				break;
			case 2:
				Setorder();
				break;
			case 3:
				ShowTotalIncome();
				break;
			case 0:
				return;
			default:
				cout << "\tIllegal selection" << endl;
				break;
			}
		}
	}

	int GetCommand() {
		//���� �ٲٱ�
		int command;
		cout << endl << endl;
		cout << "\t--ID -- Command -----" << endl;
		cout << "\t   1 : �ֹ� Ȯ��" << endl;
		cout << "\t   2 : �ֹ� ó��" << endl;
		cout << "\t   3 : �Ѹ��� Ȯ��" << endl;
		cout << "\t   0 : �α׾ƿ�" << endl;

		cout << endl << "\t Choose a command : ";
		cin >> command;
		cout << endl;

		return command;

	}

	SortedMenuList* returnList() {
		return &ShopMenu;
	}

	/**
	  *    @brief   ������ �̸��� �����ϴ� �Լ��Դϴ�.
	  *    @pre none
	  *    @post ���� ��ü�� �̸��� �������ݴϴ�
	  *    @return    none
	  */

	void SetShopName(string name) {
		ShopName = name;
	}

	/**
	  *    @brief   ������ �޴� �����ϴ� �Լ��Դϴ�. �Է����� ���ο� �޴���ü�� �Է� �޽��ϴ�.
	  *    @pre none
	  *    @post ���� ��ü�� �޴� �������ݴϴ�
	  *    @return    none
	  */
	void SetShopMenu(Menu new_menu) {
		ShopMenu.Add(new_menu);
	}


	/**
	  *    @brief   ������ �̸��� �����մϴ�
	  *    @pre ���� �̸��� ���õ��־�� �մϴ�
	  *    @post ���� �̸��� ��ȯ�մϴ�
	  *    @return    ShopName
	  */
	string GetName() {
		return ShopName;
	}


	/**
	  *    @brief   ���� �ֹ� ���¸� ������ִ� �Լ��Դϴ�.
	  *    @pre none
	  *    @post Order�� ������ ������ݴϴ�.
	  *    @return    none
	  */
	void DisplayOrder() {
		ShopOrder.PrintOrderQueue();
	}

	void ShowMenu() {
		ShopMenu.PrintMenuList();
	}


	/**
	  *    @brief   ������ �޴� ����Ʈ�� �����ϴ� �Լ��Դϴ�..
	  *    @pre �޴�����Ʈ�� �����Ǿ� �־�� �մϴ�.
	  *    @post �޴� ����Ʈ�� ������ �����մϴ�.
	  *    @return    none
	  */
	  //void ChangeMenueList();

	  //void ShowEachMenuIncome(){}

	  /**
		*    @brief   ���� �Ѹ����� ����ϴ� �Լ� �Դϴ�.
		*    @pre �Ѹ������ �����Ǿ� �־���մϴ�
		*    @post �Ѹ������ ����մϴ�.
		*    @return    none
		*/

	void ShowTotalIncome() {
		cout << "�� ������� : " << TotalIncome << "�� �Դϴ�." << endl;
		cout << "##�޴��� ���� ��Ȳ##" << endl;
		ShopMenu.PrintMenuListCount();
	}

	// ����Ŭ�������� ���� �̸��� Ű������ ���Ͼ� ��ġ�� �ؼ� ������ ��ť��Ű�� �Լ� ���� Buffer.h�� �޼��� �Լ� ���
	void GetOrder() {
		cout << "���� �ֹ��� Ȯ���մϴ�." << endl;
		Order* new_order = new Order("dummy", ShopName);
		if (bufferptr->retrieve(*new_order))
			ShopOrder.Enqueue(*new_order);
		else
			cout << "���� �ֹ��� �����ϴ�" << endl;


	}


	// ����ť���� �ֹ��� ��ť, �ֹ� ���� ��� �Լ�
	void Setorder() {
		cout << "�ֹ��� ó���մϴ�." << endl;
		Order setorder;
		SortedMenuList* ordermenu = new SortedMenuList; // ������ �޴�����Ʈ�� �����ϴ� ����.

		if (ShopOrder.IsEmpty()) {
			cout << "���� �ֹ��� �����ϴ�." << endl;
			return;
		}
		ShopOrder.Dequeue(setorder);// �ϴ� ��ť��Ų��.
		TotalIncome += setorder.GetOrderTotalPrice(); // �Ѹ��� ���.
		setorder.GetOrderArray(ordermenu); // ������ �޴� ����Ʈ ����


		// ������ �޴��� ������ �Ŵ����� ��� ���Ƽ� ��ġ�ϴ� �޴��� �ִٸ� ī���� ���ش�.
		for (int i = 0; i < ShopMenu.GetLength(); i++) {
			for (int j = 0; j < ordermenu->GetLength(); j++) {
				if ((ShopMenu.returnmenu(i)->GetName()) == (ordermenu->returnmenu(j)->GetName())) {
					ShopMenu.returnmenu(i)->Counting();
				}
			}
		}

		setorder.PrintOrder();// �ֹ� Ȯ�� ���� ���
		
	}

	shop* GetSibling()
	{
		return sibling;
	}

	shop* GetChild()
	{
		return child;
	}



	void SetSibling(shop* inSibling)
	{
		sibling = inSibling;
	}

	void SetChild(shop* inChild)
	{
		child = inChild;
	}

	void Display()
	{
		cout << "<" << GetName() << ">" << endl;

	}
	void DisplayChild()
	{
		if (this->GetChild() == NULL)
		{
			cout << "���԰� �����ϴ�." << endl;
		}
		else
		{
			shop* temp = this->GetChild();
			while (1)
			{
				temp->Display();
				if (temp->GetSibling() == NULL) break;
				temp = temp->GetSibling();
			}
		}
	}

};