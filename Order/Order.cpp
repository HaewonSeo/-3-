#include "pch.h"
#include "Order.h"


//Constructor
Order::Order(string clientid = "null")
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
string Order::GetOrderId() const {
	return oId;
}

/**
*	@brief	Order�� ������ ���� (MenuList���� �޴��� ������ ��ȯ�Ͽ�)
*	@pre	MenuList�� �ʱ�ȭ
*	@post	none
*	@param	none
*	@return Order�� ������ ����
*/
void Order::SetOrderTotalPrice() {
	oTotalPrice = menuList.GetTotal();
}

/**
*	@brief	Order�� ������ ��ȯ
*	@pre	MenuList�� �ʱ�ȭ
*	@post	none
*	@param	none
*	@return Order�� ������ ��ȯ
*/
int Order::GetOrderTotalPrice() const {
	return oTotalPrice;
}

/**
*	@brief	Order�� �ð��� ����
*	@pre	order ��ü�� ����
*	@post	none
*	@param	none
*	@return none
*/
void Order::SetOrderTime() {
	oTime = time(NULL);
}

/**
*	@brief	Order�� �ð��� ���
*	@pre	order ��ü�� ����
*	@post	none
*	@param	none
*	@return none
*/
void Order::PrintOrderTime() {
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
time_t Order::GetOrderTime() const {
	return oTime;
}

/**
*	@brief	Order�� ������ ���
*	@pre	order���� menulist�� �ʱ�ȭ
*	@post	none
*	@param	none
*	@return Order�� ������ ���
*/
void Order::PrintOrder() const {
	cout << endl;
	cout << "### Order ID : " << oId << endl;
	cout << "### Order Total Price : " << oTotalPrice << endl;
	menuList.PrintMenuList();
}