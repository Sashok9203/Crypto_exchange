#include "CRTrader.h"



void CRTrader::startTrade(Exchange& exc, CrType cr, int tradeTrandLimit,int buyMoney)
{
	TCoin tcoin(exc.Subscribe(cr, this), tradeTrandLimit, buyMoney);
	currency.insert({ cr, tcoin });
}

void CRTrader::stopTrade(Exchange& exc, CrType cr)
{
	exc.UnSubscribe(cr,this);
	if(currency.count(cr))currency.erase(cr);
}

float CRTrader::buyCrypto(Exchange& ex, CrType cr,int money)
{
	if (this->money < money || money < 0) money = this->money;
	this->money -= money;
	return ex.buyCrypto(cr,money);
}

int CRTrader::sellCrypto(Exchange& ex, CrType cr,float coins)
{
	if (currency[cr].count < coins || coins < 0) coins = currency[cr].count;
	currency[cr].count -= coins;
	return ex.sellCrypto(cr,coins);
}

void CRTrader::quotesUpdate(const Coin& coin)
{
	++currency[coin.crypto].curentTradeTrand;
	currency[coin.crypto].averageTrand += coin.trend;
	if (currency[coin.crypto].curentTradeTrand == currency[coin.crypto].tradeTrandLimit)
	{
		if (currency[coin.crypto].averageTrand < 0)
		{
			if (currency[coin.crypto].count != 0) money += sellCrypto(*coin.ex, coin.crypto, currency[coin.crypto].count);
		}
		else if (currency[coin.crypto].averageTrand > 0)
		{
			if (currency[coin.crypto].count == 0) currency[coin.crypto].count += buyCrypto(*coin.ex, coin.crypto, currency[coin.crypto].buyMoney);
		}
		currency[coin.crypto].curentTradeTrand = 0;
		currency[coin.crypto].averageTrand = 0;
		currency[coin.crypto].coin.price = coin.price;
	}
}

void CRTrader::show() const
{
	std::cout << "\n\n\   << Trader \"" << name << "\" >>" << std::endl;
	std::cout << "      Money : " << money << " $" << std::endl << std::endl;
	if (!currency.empty())
	{
		for (auto& val : currency)
		{
			switch (val.first)
			{
			case Bitcoin:
				std::cout << "   -= Bitcoin =-" << std::endl;
				break;
			case Ethereum:
				std::cout << "   -= Ethereum =-" << std::endl;
				break;
			case Solana:
				std::cout << "   -= Solana =-" << std::endl;
				break;
			case Cardano:
				std::cout << "   -= Cardano =-" << std::endl;
				break;
			case Avalanche:
				std::cout << "   -= Avalanche =-" << std::endl;
			}
			std::cout << "      Buy price         : " << (val.second.count? val.second.coin.price : 0) << std::endl;
			std::cout << "      Count             : " << val.second.count << std::endl;
			std::cout << "      Trade trend       : " << val.second.tradeTrandLimit << std::endl;
			std::cout << "      Aver.price change : " << val.second.averageTrand << " points" << std::endl;
			std::cout << "      Trade money       : " << val.second.buyMoney << " $" << std::endl << std::endl;
		}
	}
}
