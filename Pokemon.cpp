#include "Pokemon.h"

Pokemon::Pokemon()
{
	this->Pokename = "";
	this->damage = 0;
	this->defence = 0;
	this->hp_goc = 0;
	this->Type = "";
}

Pokemon::Pokemon(string Pokename, float damage, float defence, int hp_goc, string Type)
{	
	this->Pokename = Pokename;
	this->damage = damage;
	this->defence = defence;
	this->hp_goc= hp_goc;
	this->Type = Type;
}

void Pokemon::setName(string Pokename)
{
	this->Pokename = Pokename;
}

string Pokemon::getName()
{
    return Pokename;
}
// void Pokemon::Attack()
// {
	
// }
string Pokemon::Fight(Pokemon &pkm1)
{
    int i = 1;
    this -> Info(pkm1);
    cout << "---------------------------------GAME FIGHT!---------------------------------------\n";
    cout << "\n-------------------------------- Round " << i << "-------------------------------\n";
    i++;
    this ->First_Attack(pkm1);  // tim ra pokemon nao danh dau tien
    do
    { 
        // xuat ra thong tin cua 2 pokemon sau moi round
        cout << "\n-------------------------------- Round " << i << "-------------------------------\n";
        this -> Info(pkm1);
        if(this -> turn == true)    // lan luot tiep theo
        {
            cout <<"\n------------- Luot cua " << this -> getName() <<"-------------------\n\n";
            this -> getAttack(pkm1, this -> getSkill());    // this attack pkm1
            this -> turn = false;
            pkm1.turn = true;
        }
        else{
            cout <<"\n-------------- Luot cua " << pkm1.getName() <<"--------------------\n\n";
            pkm1.getAttack(*this, pkm1.getSkill());    // this attack pkm1
            pkm1.turn = false;
            this -> turn = true;
        }
        
        i++;
        
    } while (this -> hp_goc > 0 && pkm1.hp_goc > 0); 
    // if(this -> hp_goc <= 0) pkm1.End();
    // else this -> End();
    if(this -> hp_goc <= 0) return pkm1.getName() + " IS WINNER!";
    else return this -> getName() + " IS WIINER!";
}

void Pokemon::Info(Pokemon &pkm1)
{
	static int turn = 0;
	cout << "Thong tin cua 2 PokeMon" << endl;
	cout << "Pokemon 1: "; this->getInfo();
	cout << "Pokemon 2: "; pkm1.getInfo();
}
void Pokemon::First_Attack(Pokemon &pkm1){
    if((this-> damage < pkm1.damage && this -> defence < pkm1.defence)  // tim ra pokemon yeu hon
        || ((this -> Type == "fire" && pkm1.Type == "Water") && (this -> damage < pkm1.damage))
            ||((this -> Type == "fire" && pkm1.Type == "Water") && (this -> defence < pkm1.defence)))
    {
        cout <<"\n------------------------ Luot cua " << this -> getName() << "--------------------\n" << endl;
        this -> getAttack(pkm1, this -> getSkill());    // this danh pkm1
        cout <<"Tan cong thanh cong!\n";
        this ->turn = false ;    // da qua turn
        pkm1.turn = true;       // den luot cua pkm1
    }
    else{
        cout <<"\n------------------------ Luot cua " << pkm1.getName() << "----------------------\n" << endl;
        pkm1.getAttack(*this, pkm1.getSkill());    // this danh pkm1
        pkm1.turn = false ;    // da qua turn
        this -> turn = true;       // den luot cua pkm1
    }
}

void Pokemon::getInfo()
{
	cout << "Name: " << Pokename << ", HP Goc: " << hp_goc << ", Defence: " << defence << ", Damage: " << damage << ", Type: " << Type << endl;
}

void Pokemon::Reset(Pokemon &pkm1)
{
	if(this -> Type == "Water" && pkm1.Type == "Fire")
    {
        this -> damage += this -> damage * 2/10;
        this -> defence += this -> defence * 2/10;
    }
    else{
        pkm1.damage += pkm1.damage * 2/10;
        pkm1.defence += pkm1.defence * 2/10;
    }
}

void Pokemon::getAttack(Pokemon &pkm1, int skill)
{

	if(this -> Type == "Water" && pkm1.Type == "Fire")
    {
        this -> damage += this -> damage * 2/10;
        this -> defence += this -> defence * 2/10;
    }
    else{
        pkm1.damage += pkm1.damage * 2/10;
        pkm1.defence += pkm1.defence * 2/10;
    }
    if(skill == 1)
    {
        cout << pkm1.getName() <<" chiu " << (this -> damage * 1.5) + (-10 + rand() % 31) - pkm1.defence << "!!!!!!\n";
        pkm1.hp_goc -= ((this -> damage * 1.5) + (-10 + rand() + 31) - pkm1.defence);
        
    }
    else 
    {
        pkm1.hp_goc -= ((this -> damage * 2) + (-10 + rand() + 31) - pkm1.defence);
        cout << this -> getName() <<" chiu " << (this -> damage * 2) + (-10 + rand() % 31) - pkm1.defence<< "!!!!!!\n";
    }
    
}

int Pokemon::getSkill()
{
    int skill;
    if (this -> getName() == "BeXuanMaiLonTo")
	{
		cout << "Skill 1: Cu da loc xoay!!\n";
		cout << "Skill 2: Dam vo alooo!\n";
	}
	else{
		cout << "Skill 1: Phong lon vao mom!!\n";
		cout << "Skill 2: Xuc Binh xang!\n";
	}
    do{
			cout << "Nhap ki nang (1 - 2): ";
			cin >> skill;
			if (skill >= 3 || skill < 0) cout << "May nhap nguu!!!!\n";
	} 
    while (skill >= 3 || skill < 0);
    return skill;
}
void Pokemon::End()
{
    cout << "\n------------------------" << this -> getName() << " IS WINER!!!!!!!!!!!!!" << "----------------" << endl;
}
