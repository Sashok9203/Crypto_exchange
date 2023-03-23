#pragma once
#include <string>
#include "Exchange.h" 
#include "Trader.h"
#include <map>
#include <iostream>
class CRTrader : public Trader
{
private:
	struct TCoin
	{
		Coin coin;
		int tradeTrandLimit;
		int curentTradeTrand;
		int averageTrand;
		float count;
		float buyMoney;
		TCoin():TCoin(Coin(),0,0) {}
		TCoin(const Coin& coin,int tradeTrandLimit,int buyMoney):coin(coin), 
			tradeTrandLimit(tradeTrandLimit), buyMoney(buyMoney), curentTradeTrand(0),count(0),averageTrand(0) {}
	};
	std::string name;
	std::map<CrType, TCoin> currency;
	int money;
	
public:
	CRTrader(const std::string name, int money) :name(name), money(money) {}
	std::string getName() const { return name; }
	
	void  startTrade(Exchange& exc, CrType cr, int tradeTrand,int buyMoney);
	void  stopTrade(Exchange& exc, CrType cr);
	void  quotesUpdate(const Coin& coin)   override;
	float buyCrypto(Exchange& ex, CrType cr,int money) override;
	int   sellCrypto(Exchange& ex, CrType cr,float coins) override;
	void  show() const;

};

