#include "Exchange.h"
#include "Trader.h"
#include "CRExchange.h"

void CRExchange::change(Coin& coin)
{
	int trend = randomRange(-10.0, 10.0);
	coin.price += trend;
	coin.trend = trend;
	qUpdate(coin);
}



void CRExchange::chowExchange() const
{
	system("cls");
	std::cout << "  -=  Cryptocurrency exchange  =-" << std::endl;
	std::cout << "    Bitcoin    (BTC)    : " << coins[0].price << std::endl;
	std::cout << "    Ethereum   (ETH)    : " << coins[1].price << std::endl;
	std::cout << "    Solana     (SOL)    : " << coins[2].price << std::endl;
	std::cout << "    Cardano    (ADA)    : " << coins[3].price << std::endl;
	std::cout << "    Avalanche  (AVAX)   : " << coins[4].price << std::endl;
}

void CRExchange::qUpdate(const Coin& coin)
{
	for (auto val : traders[(int)coin.crypto])
		val.second->quotesUpdate(coin);
}

void CRExchange::exchangeTic(int min, int max)
{
	for(auto& val:coins)
		change(val);
	chowExchange();
}

const Coin& CRExchange::Subscribe(CrType cr,  Trader* tr)
{
	
	if (traders[(int)cr].count(tr)) throw std::exception(" Trader already subscribed");
	traders[(int)cr].emplace(tr, tr);
	return coins[(int)cr];
}

void CRExchange::UnSubscribe(CrType cr, Trader* tr)
{
	if (!traders[(int)cr].count(tr)) throw std::exception(" Trader does not subscribed");
	traders[(int)cr].erase(tr);
}

float CRExchange::buyCrypto(CrType cr, int money)
{
	return (float)money/coins[(int)cr].price;
}

int CRExchange::sellCrypto(CrType cr, float coin)
{
	return round(coins[(int)cr].price * coin);
}


