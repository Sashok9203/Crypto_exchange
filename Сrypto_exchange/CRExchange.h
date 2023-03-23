#pragma once
#include "myLib.h"
#include "Exchange.h"
#include <string>
#include <map>




class CRExchange : public Exchange
{
private:
	Coin coins[CEnd];
	std::map<Trader*, Trader*> traders[CrType::CEnd]{};
	void change(Coin& coin);
	void chowExchange() const;
	void qUpdate(const Coin& coin);
public:
	CRExchange(int startBitPrice, int startEthPrice, int startSolPrice, int startCarPrice, int startAvaPrice)
		:coins{ { this,Bitcoin, startBitPrice },
				{ this,Ethereum, startEthPrice },
				{ this,Solana, startSolPrice },
				{ this,Cardano,startCarPrice },
				{ this,Avalanche,startAvaPrice } } {}
	void  exchangeTic(int min,int max);
	const Coin& Subscribe(CrType cr, Trader* tr );
	void  UnSubscribe(CrType cr, Trader* tr);
	float buyCrypto(CrType cr, int money);
	int   sellCrypto(CrType cr, float coins);
};


