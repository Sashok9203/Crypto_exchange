#include <iostream>
#include "CRTrader.h"
#include "CRExchange.h"
#include <Windows.h>
int main()
{
    CRExchange exc(40000, 30000, 25000, 10000, 4000);
    CRTrader trader("Nick", 100000);
    trader.startTrade(exc, Bitcoin, 4, 40000);
    trader.startTrade(exc, CrType::Cardano, 3, 25000);
    while (true)
    {
        Sleep(1000);
        exc.exchangeTic(-10, 10);
        trader.show();
    }
}

