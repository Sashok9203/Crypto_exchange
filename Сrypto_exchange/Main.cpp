#include <iostream>
#include "CRTrader.h"
#include "CRExchange.h"
#include <Windows.h>
int main()
{
    int time = 60;
    CRExchange exc(40000, 30000, 25000, 10000, 4000);
    CRTrader trader("Nick", 100000);
    CRTrader trader2("Bil", 120000);
    try
    {
        trader.startTrade(exc, CrType::Bitcoin, 4, 40000);
        trader.startTrade(exc, CrType::Cardano, 3, 25000);
        trader2.startTrade(exc, CrType::Ethereum, 8, 30000);
        trader2.startTrade(exc, CrType::Avalanche, 3, 10000);
    }
    catch (const std::exception&){}
    while (time)
    {
        Sleep(1000);
        exc.exchangeTic(-10, 10);
        if (trader.isTrade())trader.show();
        if (trader2.isTrade())trader2.show();
        if (time == 2)
        {
            trader.sellCrypto(exc, Bitcoin, trader.getCoinsCount(Bitcoin));
            trader.stopTrade(exc, Bitcoin);
        }
        else if (time == 20)
        {
            trader2.sellCrypto(exc, Avalanche, trader.getCoinsCount(Avalanche));
            trader2.stopTrade(exc, Avalanche);
        }
        else if (time == 50)
        {
            trader.sellCrypto(exc, Cardano, trader.getCoinsCount(Cardano));
            trader.stopTrade(exc, Cardano);
            trader2.sellCrypto(exc, Ethereum, trader.getCoinsCount(Ethereum));
            trader2.stopTrade(exc, Ethereum);
        }
        --time;
    }
}

