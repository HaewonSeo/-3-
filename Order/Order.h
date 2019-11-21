#pragma once

#include <iostream>
#include <string>
#include <time.h>
#include "SortedMenuList.h"
using namespace std;

class Order {
public:

	//Constructor
	Order(string clientid = "null");

	
	/**
	*	@brief	Order�� Client�� Id�� ��ȯ
	*	@pre	order�� client�� ����
	*	@post	none
	*	@param	none
	*	@return order�� client�� id�� ��ȯ
	*/
	string GetOrderId() const;

	/**
	*	@brief	Order�� ������ ���� (MenuList���� �޴��� ������ ��ȯ�Ͽ�)
	*	@pre	MenuList�� �ʱ�ȭ
	*	@post	none
	*	@param	none
	*	@return Order�� ������ ����
	*/
	void SetOrderTotalPrice();

	/**
	*	@brief	Order�� ������ ��ȯ
	*	@pre	MenuList�� �ʱ�ȭ
	*	@post	none
	*	@param	none
	*	@return Order�� ������ ��ȯ
	*/
	int GetOrderTotalPrice() const;
	/**
	*	@brief	Order�� �ð��� ����
	*	@pre	order ��ü�� ����
	*	@post	none
	*	@param	none
	*	@return none
	*/
	void SetOrderTime();

	/**
	*	@brief	Order�� �ð��� ���
	*	@pre	order ��ü�� ����
	*	@post	none
	*	@param	none
	*	@return none
	*/
	void PrintOrderTime();
	/**
	*	@brief	Order�� �ð��� time_t �������� ��ȯ
	*	@pre	order ��ü�� ����
	*	@post	none
	*	@param	none
	*	@return Order�� �ð��� ��ȯ
	*/
	time_t GetOrderTime() const;
	

	/**
	*	@brief	Order�� ������ ���
	*	@pre	order���� menulist�� �ʱ�ȭ
	*	@post	none
	*	@param	none
	*	@return Order�� ������ ���
	*/
	void PrintOrder() const;

	

private:
	SortedMenuList menuList;
	string oId; // client id 
	int oTotalPrice;// total price of order
	time_t oTime; // client�� order�� �ð� 
};