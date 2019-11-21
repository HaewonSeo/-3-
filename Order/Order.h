#pragma once

#include <iostream>
#include <string>
#include <time.h>
#include "SortedMenuList.h"
using namespace std;

class Order {
public:
	Order(string clientid="null")
	{
		oId = clientid;
		SetOrderTotalPrice();
		SetOrderTime();
	}

	
	/**
	*	@brief	Order�� Client�� Id�� ��ȯ
	*	@pre	order�� client�� ����
	*	@post	none
	*	@param	none
	*	@return order�� client�� id�� ��ȯ
	*/
	string GetOrderId() const {
		return oId;
	}

	/**
	*	@brief	Order�� ������ ���� (MenuList���� �޴��� ������ ��ȯ�Ͽ�)
	*	@pre	MenuList�� �ʱ�ȭ
	*	@post	none
	*	@param	none
	*	@return Order�� ������ ����
	*/
	void SetOrderTotalPrice() {
		oTotalPrice = menuList.GetTotal();
	}

	/**
	*	@brief	Order�� ������ ��ȯ
	*	@pre	MenuList�� �ʱ�ȭ
	*	@post	none
	*	@param	none
	*	@return Order�� ������ ��ȯ
	*/
	int GetOrderTotalPrice() const {
		return oTotalPrice;
	}

	/**
	*	@brief	Order�� �ð��� ����
	*	@pre	order ��ü�� ����
	*	@post	none
	*	@param	none
	*	@return none
	*/
	void SetOrderTime() {
		oTime = time(NULL);	
	}

	/**
	*	@brief	Order�� �ð��� ���
	*	@pre	order ��ü�� ����
	*	@post	none
	*	@param	none
	*	@return none
	*/
	void PrintOrderTime() {
		struct tm *date;
		date = localtime(&oTime);
		//��/��/�� ��:��:�� �������� ���
		printf("%d/%d/%d %d:%d:%d\n", date->tm_year + 1900, date->tm_mon + 1, date->tm_mday, date->tm_hour, date->tm_min, date->tm_sec);
	}

	/**
	*	@brief	Order�� �ð��� time_t �������� ��ȯ
	*	@pre	order ��ü�� ����
	*	@post	none
	*	@param	none
	*	@return Order�� �ð��� ��ȯ
	*/
	time_t GetOrderTime() const {
		return oTime;
	}

	/**
	*	@brief	Order�� ������ ���
	*	@pre	order���� menulist�� �ʱ�ȭ
	*	@post	none
	*	@param	none
	*	@return Order�� ������ ���
	*/
	void PrintOrder() {
		cout << endl;
		cout << "### Order ID : " << oId << endl;
		cout << "### Order Total Price : " << oTotalPrice << endl;
		menuList.PrintMenuList();
	}

	

private:
	SortedMenuList menuList;
	string oId; // client id 
	int oTotalPrice;// total price of order
	time_t oTime; // client�� order�� �ð� 
};