#pragma once
#include<iostream>
#include<stdlib.h>
using namespace std;

class Pokemon
{
private:	
	float damage;
	int hp_goc;
	float defence;
	string Type;
	string Pokename;	
	bool turn = false;	// false la chua toi turn - true la da qua turn

public:
	Pokemon();
	Pokemon(string Pokename, float damage, float defence, int hp, string Type);

	string getName();
	void setName(string Pokename);

	float getDame(float damage);
	void setDame();

	int getHp();
	void setHp(int dame);

	float getDefence(float defence);
	void setDefence();
	
	void Info(Pokemon &pkm1);	// bat dau danh nhau

	string Fight(Pokemon &pkm1);

	void getInfo();	// xuat thong tin cua pokemon

	int getSkill();

	void Reset(Pokemon &pkm1);

	void First_Attack(Pokemon &pkm1); 	// luot danh cua pokemon

	void End();

	void getAttack(Pokemon &pkm1, int skill);

};

