﻿// ConsoleApplication3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using std::cout; using std::endl; using std::cin;

class UserData {
private:
	char* name;
	int id;
	int money;
public:
	UserData();
	UserData(char* name, int id, int money);
	UserData(UserData& copy);
	~UserData();
	void moneySet(int point);
	int getID() const;
	int getMoney() const;
	char* getName() const;
};

UserData::UserData() {
	name = NULL;
	id = -1;
	money = 0;
}

UserData::UserData(char* name, int id, int money) {
	this->name = new char[20];
	for (int i = 0; i < 20; ++i)
		this->name[i] = name[i];
	this->id = id;
	this->money = money;
}

UserData::UserData(UserData& copy) {
	name = new char[20];
	for (int i = 0; i < 20; ++i)
		name[i] = copy.name[i];
	id = copy.id;
	money = copy.money;
}

UserData::~UserData() {
	delete[] name;
	id = -1;
	money = 0;
}

void UserData::moneySet(int point) {
	int temp;
	cout << "금액을 입력하세요: ";
	cin >> temp;
	if (point == 1) {
		money += temp;
		cout << "입금이 완료되었습니다!" << endl;
	}
	else {
		if (money >= temp) {
			money -= temp;
			cout << "출금이 완료되었습니다!" << endl;
		}
		else
			cout << "보유금액이 부족합니다!" << endl;
	}
}

int UserData::getID() const {
	return id;
}

int UserData::getMoney() const {
	return money;
}

char* UserData::getName() const {
	return name;
}

class Tool {
private:
	UserData *data[10];
	int dataCount = 0;
	int idSearch() const;
	void nameSet(char* name);
	int idSet();
	int moneySet();
public:
	bool newAccount();
	void moneyInsert();
	void moneyWithdraw();
	void allShow() const;
	void menu() const;
};

int Tool::idSearch() const {
	int temp;

	cout << "ID를 입력하세요: ";
	cin >> temp;
	for (int i = 0; i < dataCount; ++i)
		if (data[i]->getID() == temp)
			return i;
	return -1;
}

void Tool::nameSet(char* name) {
	cout << "이름을 입력하세요: ";
	cin >> name;
}

int Tool::idSet() {
	int temp;
	cout << "ID를 입력하세요: ";
	cin >> temp;
	return temp;
}

int Tool::moneySet() {
	int temp;
	cout << "금액을 입력하세요: ";
	cin >> temp;
	return temp;
}

bool Tool::newAccount() {
	if (dataCount >= 10) {
		cout << "데이터의 수용량이 가득 찼습니다!" << endl;
		return false;
	}

	char name[20];
	nameSet(name);
	data[dataCount] = new UserData(name, idSet(), moneySet());
	dataCount++;
	return true;
}

void Tool::moneyInsert() {
	int tempID;

	tempID = idSearch();
	if (tempID != -1)
		data[tempID]->moneySet(1);
}

void Tool::moneyWithdraw() {
	int tempID;

	tempID = idSearch();
	if (tempID != -1)
		data[tempID]->moneySet(0);
}

void Tool::allShow() const {
	for (int i = 0; i < dataCount; ++i) {
		cout << "이름: " << (data[i]->getName()) << endl;
		cout << "아이디: " << data[i]->getID() << endl;
		cout << "보유금액: " << data[i]->getMoney() << endl;
		cout << endl;
	}
}

void Tool::menu() const {
	cout << "-----MENU-----" << endl;
	cout << "1.계좌개설" << endl;
	cout << "2.입금" << endl;
	cout << "3.출금" << endl;
	cout << "4.계좌정보 전체 출력" << endl;
	cout << "5.프로그램 종료" << endl << endl;
}

int main()
{
	Tool tool;
	int point, exit = 0;

	while (true) {
		tool.menu();
		cin >> point;

		switch (point)
		{
		case 1:
			tool.newAccount();
			break;
		case 2:
			tool.moneyInsert();
			break;
		case 3:
			tool.moneyWithdraw();
			break;
		case 4:
			tool.allShow();
			break;
		case 5:
			exit = 1;
			break;
		}

		if (exit == 1)
			break;
	}
}