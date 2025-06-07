#include<iostream>

using namespace std;

class weapon {
private:
	
public:

	virtual void useWeaponAttack(weapon *gun) {
		cout << "Kicking with my fists\n";
	}
};

class pistol : public weapon {
public:
	void useWeaponAttack(weapon* gun) {
		cout << "Shooting with pistol(one shot)\n";
	}
};


class semipistol : public pistol{
public:
	void useWeaponAttack(weapon* gun) override {
		cout << "Shooting with semi(triple shot)\n";
	}
};

class knife : public weapon {
public:
	void useWeaponAttack(weapon* gun) override {
		cout << "Stabbing with knife\n";
	}
};

class player {
private:
	string name;
public:
	player(string name) {
		this->name = name;
	}

	void Attack(weapon *gun) {
		cout << name << ": "; gun->useWeaponAttack(gun);
	}
};
int main() {

	player player("Poqua");
	weapon *playerWeapon;
	int weaponChoose;
	pistol pistol_M;;
	semipistol semipistol_M;
	knife knife_M;


	cout << "[1] Pistol\n[2] Semi\n[3] Knife\n";
	cout << "Choose your weapon: "; cin >> weaponChoose;
	

	
	switch (weaponChoose)
	{
	case 1:
		playerWeapon = &pistol_M;
		break;
	case 2:
		playerWeapon = &semipistol_M;
		break;
	case 3:
		playerWeapon = &knife_M;
		break;
	default:
		playerWeapon = new weapon;
		break;
	}

	player.Attack(playerWeapon);
	delete playerWeapon;

	return 0;
}